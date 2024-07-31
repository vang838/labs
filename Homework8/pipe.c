#include "file.h"

/**********************************************
 * helper function printErrorMessage 
 * Prints an error message and exits the program with a fail
 * 
 * @param RuntimeException terminates the program once the function is called
 * @param message Message that is printing when an error occurrs
**********************************************/
void printErrorMessage(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

/************************************************
 * function pipe_commands
 * Redirects cat to wc or sort through pipe
 * Expects 5 arguments
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * 
 ************************************************/
void pipe_commands(int argc, char *argv[]) 
{
    if( strcmp( argv[3], "|" ) != 0 )
    {
        printf("Error: Expected pipe | argument\n");
        exit(EXIT_FAILURE);
    }

    int pipefd[2];
    if( pipe( pipefd ) == -1 ) { printErrorMessage("Error creating pipe\n"); }

    pid_t pid1, pid2;
    if( (pid1 = fork() ) == -1) { printErrorMessage("Error creating fork for pid1\n"); }

    if ( pid1 == 0 )
    {
        if( dup2( pipefd[writeEND], STDOUT_FILENO ) == -1 ) { printErrorMessage("Error duplicating pipe write end to stdout\n"); }

        close( pipefd[readEND] );
        close( pipefd[writeEND] );

        char *catARGS[] = { "cat", argv[2], NULL };
        execvp( catARGS[0], catARGS );
        printErrorMessage("Error executing cat\n");
    }

    if( (pid2 = fork() ) == -1 ) { printErrorMessage("Error creating fork for pid2\n"); }

    if( pid2 == 0 ) 
    { 
        if( dup2( pipefd[readEND], STDIN_FILENO ) == -1 ) { printErrorMessage("Error duplicating pipe read end to stdin"); } 

        close( pipefd[readEND] );
        close( pipefd[writeEND] ); 

        if( strcmp(argv[4], "wc") == 0 )
        {
            char *wcARGS[] = { "wc", argv[5], NULL };
            execvp( wcARGS[0], wcARGS );
        }   

        else if( strcmp(argv[4], "sort") == 0 )
        {
            char *sortARGS[] = { "sort", NULL };
            execvp( sortARGS[0], sortARGS );
        }

        else 
        {
            printf( "Error: Unsupported command %s\n", argv[4] );
            exit(EXIT_FAILURE);
        }
        printErrorMessage("Error executing wc or sort\n");
    }

    close( pipefd[readEND] );
    close( pipefd[writeEND] );

    int status;
    waitpid( pid1, &status, 0 );
    waitpid( pid2, &status, 0 );

    // return 0;
}

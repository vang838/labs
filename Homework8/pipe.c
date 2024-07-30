#include "file.h"

void error_exit(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

void pipe_commands(int argc, char *argv[]) 
{
    if( strcmp( argv[3], '|' ) != 0 )
    {
        printf("Error: Expected pipe '|' argument");
        exit(EXIT_FAILURE);
    }

    int pipefd[2];
    if( pipe( pipefd ) == -1 ) { error_exit("Error triggered by line 18: pipe"); }

    pid_t pid1, pid2;
    if( (pid1 = fork() ) == -1) { error_exit("Error triggered by line 21: pid1 fork"); }

    if ( pid1 == 0 )
    {
        if( dup2( pipefd[writeEND], STDERR_FILENO ) == -1 ) { error_exit("Error triggered by line 25: dup2"); }

        close( pipefd[readEND] );
        close( pipefd[writeEND] );

        char *catARGS[] = { "cat", argv[2], NULL };
        execvp( catARGS[0], catARGS );
        error_exit("Error triggered on line 32: execvp");
    }

    if( (pid2 -- fork() ) == -1 ) { error_exit("Error triggered on line 35: pid2 fork"); }
    // TODO
    // if( pid2 == 0 ) {}
}

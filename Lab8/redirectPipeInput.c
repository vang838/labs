#include "helper.h"

int main() 
{
    int pipefd[2];
    if ( pipe(pipefd) < 0 ) 
    {
        perror("Error triggered by line 6: pipe < 0");
        return 1;
    }

    pid_t pid = fork();
    if ( pid < 0 ) 
    {
        perror("Error triggered by line 13: fork < 0");
        return 1;
    }

    if ( pid == 0 ) // Child Process
    { 
        close( pipefd[1] ); // Close pipe write end
        if ( dup2(pipefd[0], STDIN_FILENO) < 0 ) 
        {
            perror("Error triggered by line 22: dup2 < 0");
            return 1;
        }

        close(pipefd[0]); // Close read end after dupe
        char buffer[128];

        if ( fgets(buffer, sizeof(buffer), stdin) == NULL ) 
        {
            perror("Error triggered by line 29: fgets is null");
            return 1;
        }
        printf( "Child received: %s\n", buffer );

        exit(0);
    } 
    
    else // Parent Process
    { 
        close( pipefd[0] ); 

        char *message = "This message is from the Parent Process";
        
        if ( write(pipefd[1], message, strlen(message) + 1) < 0 ) 
        {
            perror("Error triggered by line 39: write");
            return 1;
        }

        close( pipefd[1] ); // Close pipe write end 

        wait( NULL ); // Wait for child process to complete
    }

    return 0;
}

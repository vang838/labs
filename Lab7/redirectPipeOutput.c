#include "helper.h"

int main()
{
    int pipefd[2];
    if( pipe(pipefd) < 0 )
    {
        perror("Error triggered by line 6: pipe < 0");
        return 1;
    }

    pid_t pid = fork();
    if( pid < 0 )
    {
        perror("Error triggered by line 13: pip");
        return 1;
    }

    if ( pid == 0 )
    {
        close( pipefd[0] );
        if( dup2(pipefd[1], STDOUT_FILENO) < 0 )
        {
            perror("Error triggered by line 24: dup2 < 0");
            return 1;
        }

        printf("This message is from the child process.\n");
        close( pipefd[1] );
        exit(0);
    }

    else 
    {
        close( pipefd[1] );
        char buffer[128];
        read( pipefd[0], buffer, sizeof(buffer) );
        printf("Parent received: %s", buffer);
        close( pipefd[0] );
    }
    return 0;
}
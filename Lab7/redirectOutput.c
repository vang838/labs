#include "helper.h"

int main()
{
    int fd = open( "output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644 );
    if(fd < 0)
    {
        perror("Error triggered by line 5:  Unable to open");
        return 1;
    }

    if( dup2(fd, STDOUT_FILENO) < 0 )
    {
        perror("Error triggered on line 12: dup2");
        return 1;
    }

    printf("This line was redirected by redirectOutput.c\n");

    close(fd);
    return 0;
}
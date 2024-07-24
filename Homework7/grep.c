#include "file.h"

void grepPlus(int argc, char *argv[]) 
{
    if (argc < 4) 
    { 
        fprintf(stderr, "Usage: ./main grep <directory> <pattern> [-i] [-n]\n");
        exit(EXIT_FAILURE);
    }

    char *directory = argv[2];
    char *pattern = argv[3];
    int caseInsensitive = 0;
    int printLineNumbers = 0;

    for (int i = 4; i < argc; i++) 
    {
        if (strcmp(argv[i], "-i") == 0) { caseInsensitive = 1; } 
        
        else if (strcmp(argv[i], "-n") == 0) { printLineNumbers = 1; } 
        
        else 
        {
            printf("Usage: ./main grep <directory> <pattern> [-i] [-n]\n");
            exit(EXIT_FAILURE);
        }
    }

    // Validate pattern length
    if (strlen(pattern) == 0 || strlen(pattern) > MAX_PATTERN_LENGTH) 
    {
        printf("Pattern must be between 1 and 10 characters.\n");
        exit(EXIT_FAILURE);
    }

    DIR *dir;
    struct dirent *entry;
    pid_t pids[MAX_FILES];
    int fileCount = 0;
    int childCount = 0;

    dir = opendir(directory);
    if (dir == NULL) 
    {
        perror("Open Directory has failed");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL && fileCount < MAX_FILES) 
    {
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != NULL) 
        {
            pid_t pid = fork();
            if (pid < 0) 
            {
                perror("fork");
                exit(EXIT_FAILURE);
            } 
            
            else if (pid == 0) // Child process
            { 
                char filePath[MAX_PATH_LENGTH];
                snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);

                // Build arguments for execvp & allocate space for flags/file path
                char *grepArgs[MAX_FILES + 5]; 
                int index = 0;

                grepArgs[index++] = "grep";

                if (caseInsensitive) grepArgs[index++] = "-i";
                if (printLineNumbers) grepArgs[index++] = "-n";
                
                grepArgs[index++] = "-H"; // Ensure -H is always included
                grepArgs[index++] = pattern;
                grepArgs[index++] = filePath;

                grepArgs[index] = NULL; // Terminate the argument list

                execvp("grep", grepArgs);
                perror("execvp");
                exit(EXIT_FAILURE);
            } 
            
            else // Parent process
            { 
                pids[childCount++] = pid;
                fileCount++;
            }
        }
    }

    closedir(dir);

    // Wait for all child processes
    for (int i = 0; i < childCount; i++) 
    {
        int status;
        waitpid(pids[i], &status, 0);
    }

    // Print child PIDs and summary
    printf("\nChild process PIDs:");
    for (int i = 0; i < childCount; i++) { printf(" %d", pids[i]); }

    printf("\nNumber of files searched: %d\n", fileCount);
    printf("Number of processes created: %d\n", childCount);
}

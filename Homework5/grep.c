#include "text.h"

void makeLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

/*******************************************************
 * Helper Function: performGrep
 * Description: Performs the grep operation of searching for a pattern in a given file
 * 
 * @param pattern | the string to search for
 * @param filename | the file to search the pattern in
 * @param case_Insensitive | Flag indicating if search is case sensitive or not
 * @param printLineNum | Flag indicating if line numbers should be printed with lines
 * @param ouputFileName | If specified, the name of the output file where matching lines will be appended to
 * 
 *******************************************************/
void performGrep(const char *pattern, const char *filename, int case_Insensitive, int printLineNum, const char *outputFileName) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }

    FILE *outputFile = NULL;
    if (outputFileName) 
    {
        outputFile = fopen(outputFileName, "w");
        if (!outputFile) {
            printf("Error: Unable to open output file '%s'\n", outputFileName);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    char line[MAX_LINE_LENGTH];
    int lineNum = 0;
    int foundMatch = 0;

    while (fgets(line, sizeof(line), file)) 
    {
        lineNum++;
        char tempLine[MAX_LINE_LENGTH];
        char tempPattern[MAX_PATTERN_LENGTH + 1];
        strcpy(tempLine, line);
        strcpy(tempPattern, pattern);

        if (case_Insensitive) {
            makeLowercase(tempLine);
            makeLowercase(tempPattern);
        }

        if (strstr(tempLine, tempPattern)) 
        {
            foundMatch = 1;
            line[strcspn(line, "\n")] = '\0';
            if (outputFile) 
            {
                if (printLineNum) printf("%d: %s\n", lineNum, line);
                else printf("%s\n", line);
            } 
            
            else 
            {
                if (printLineNum) printf("%d: %s\n", lineNum, line);
                else printf("%s\n", line);
            }
        }
    }

    if (!foundMatch) 
    {
        if (outputFile) printf("No matches found for pattern \"%s\" in file %s\n", pattern, filename);
        else printf("No matches found for pattern \"%s\" in file %s\n", pattern, filename);
    }

    fclose(file);
    if (outputFile) fclose(outputFile);
}
/***********************************************************
 * Function: grepLite
 * Description: Calls performGrep function if command line arguments are valid
 * 
 * @param argc | number of command line arguments
 * @param argv | array that stores command line arguments
************************************************************/
void grepLite(int argc, char *argv[]) 
{
    if (argc < 3 || strlen(argv[1]) > MAX_PATTERN_LENGTH) 
    {
        printf("Usage: %s <pattern> <filename> with optional [-i] for case insensitive search, [-n] for line number\n", argv[0]);
        return;
    }

    int caseInsensitive = 0;
    int print_Line_Num = 0;
    char *output_File_Name = NULL;
    char *pattern = argv[1];
    char *fileName = argv[2];

    // size_t length = strlen(fileName);
    // if(length < 4 || strcmp(fileName + length - 4, ".txt") != 0)
    // {
    //     char fileNameWithExtension[MAX_LINE_LENGTH];
    //     snprintf(fileNameWithExtension, sizeof(fileNameWithExtension), "%s.txt", fileName);
    //     fileName = fileNameWithExtension;
    // }

    for (int i = 3; i < argc; i++) 
    {
        if (strcmp(argv[i], "-i") == 0) caseInsensitive = 1;
        
        else if (strcmp(argv[i], "-n") == 0) print_Line_Num = 1;
        
        else if (strcmp(argv[i], ">") == 0) 
        {
            if (i + 1 < argc) 
            {
                output_File_Name = argv[i + 1];
                i++;
            } 
            
            else 
            {
                printf("Error: Output file not specified after '>'.\n");
                return;
            }
        } 

        else if (strcmp(argv[i], "-") == 0) 
        {
            printf("Usage: %s <pattern> <filename> with optional [-i] for case insensitive search, [-n] for line number\n", argv[0]);
            return;
        } 
        
        else 
        {
            printf("Usage: %s <pattern> <filename> with optional [-i] for case insensitive search, [-n] for line number\n", argv[0]);
            return;
        }
    }

    char full_File_Name[MAX_LINE_LENGTH];
    snprintf(full_File_Name, sizeof(full_File_Name), "%s.txt", fileName);

    performGrep(pattern, full_File_Name, caseInsensitive, print_Line_Num, output_File_Name);
}

#include "file.h"

int countLines(FILE *fp)
{
    int lines = 0; // Track number of lines read 
    char currentCharacter; // Variable to stores the current character from the file
    char prev = '\0'; // Variable that stores the previously read character
    
    while ((currentCharacter = fgetc(fp)) != EOF)
    {
        if(currentCharacter == '\n') 
        {
            lines++; // increment lines if current character is a new character
        }

        prev = currentCharacter;
    }
    
    if(prev != '\n' && prev != EOF) 
    {
        lines++; // Increments last for the last line in the file
    }

    return lines;
}

int countWords(FILE *fp)
{
    int words = 0;
    char currentCharacter;
    char prev = ' ';

    while((currentCharacter = fgetc(fp)) != EOF)
    {
        if((currentCharacter == ' ' || currentCharacter == '\n' || currentCharacter == '\t') && (prev != ' ' && prev != '\n' && prev != '\t')) 
        {
            words++;
        }

        prev = currentCharacter;
    }
    
    if(prev != '\n' && prev != ' ' && prev != '\t') 
    {
        words++;
    }

    return words;
}

int countCharacters(FILE *fp)
{
    int characters = 0;
    int currentCharacter;

    while((currentCharacter = fgetc(fp)) != EOF)
    {
        characters++;
    }
    return characters;
}
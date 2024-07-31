/*********************************************
 * Author: vang838@uwm.edu
 * 
 * Created: 6/25/24
 * 
 * cipherHelper.c
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************
 * Function: EncryptMessage
 * 
 * Description:
 * Variable text and variable key as inputs.  Shifts each letter in the string by the specified key
 * while ignoring non-alphabetic characters.  Supports both upper and lowercase.
 ********************************************/
void encryptMessage(char text[], int key)
{
    for(int i = 0; text[i] != '\0'; i++)
    {
        if( ( text[i] >= 'a' - key && text[i] <= 'z' )|| ( text[i] >= 'A' - key && text[i] <= 'Z' ))
        {
            text[i] = text[i] + key;
        }

        if( ( text[i] < 'a' - key && text[i] >= 'a' - key ) )
        {
            text[i] = text[i] - 26;
        }

        if( text[i] < 'A' && text[i] >= 'A' - key)
        {
            text[i] = text[i] - 26;
        }
    }
    printf("Encrypted Message: %s\n", text);
}

/*********************************************
 * Function: decryptMessage
 * 
 * Description:
 * Variable text and variable key as inputs.  Shifts each letter in the string by the specified key
 * while ignoring non-alphabetic characters.  Supports both upper and lowercase.
 ********************************************/
void decryptMessage(char text[], int key) 
{
    for(int i = 0; text[i] != '\0'; i++)
    {
        if( ( text[i] >= 'a' - key && text[i] <= 'z' )|| ( text[i] >= 'A' - key && text[i] <= 'Z' ))
        {
            text[i] = text[i] - key;
        }

        if( ( text[i] < 'a' - key && text[i] >= 'a' - key ) )
        {
            text[i] = text[i] + 26;
        }

        if( text[i] < 'A' && text[i] >= 'A' - key)
        {
            text[i] = text[i] + 26;
        }
    }
    printf("Decrypted Message: %s\n", text); 
}
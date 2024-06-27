/*********************************************
 * Author: vang838@uwm.edu
 * 
 * Created: 6/25/24
 * 
 * cipher.c
 ********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"
#define MAX_TEXT_LENGTH 1024

int main() 
{
    int choice;
    int key;
    char text[MAX_TEXT_LENGTH];

    printf("Would you like to encrypt or decrypt a message?\n");
    printf("1: Encrypt      2: Decrypt\n");
    printf("\nChoice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            printf("\nEnter a message to encrypt: ");
            scanf("%s", text);

            printf("\nEnter a key: ");
            scanf("%d", &key);

            encryptMessage(text, key);
            break;
        }

        case 2:
        {
            printf("\nEnter a message to decrypt: ");
            scanf("%s", text);

            printf("\nEnter a key: ");
            scanf("%d", &key);

            decryptMessage(text, key);
            break;
        }

        default:
                printf("\nInvalid Choice");
    }
    return 0;
}
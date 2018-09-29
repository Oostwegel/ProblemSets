#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int KEY = 0;
const int INPUT_LEN = 255; 
const int ALPHABET_LEN = 26;

int main (int count, char* args[])
{

    char plainText[INPUT_LEN];
    char *cipherText;

    if ( count < 2 || count > 2)
    {
        printf("There is no key");
        return 1;
    }
    
    KEY = atoi(args[1]);

    printf("Enter plain text: ");
    fgets (plainText, INPUT_LEN, stdin);

    int strLength = strlen(plainText);
    cipherText = malloc(strLength);

    for (int i = 0; i < strLength; i++ ){

        if(plainText[i] == '\0' || plainText[i] == '\n'|| plainText[i] == '\r')
            break;

        if(isalpha(plainText[i]))
        {
            int asciiUpperOrLower = 97; // Default lower    

            if(isupper(plainText[i]))
                asciiUpperOrLower = 65;

            int alphabetBaseletter = (((int)plainText[i] - asciiUpperOrLower + KEY) % ALPHABET_LEN);
            
            cipherText[i] = alphabetBaseletter + asciiUpperOrLower;
        }
        else
            cipherText[i] = plainText[i];
    }

    // Set string terminator.
    cipherText[strLength - 1] = '\0' ;

    printf("%s", cipherText);

    return 0;

}



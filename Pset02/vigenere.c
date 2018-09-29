#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

const int INPUT_LEN = 255; 
const int ALPHABET_LEN = 26;

int main (int count, char *args[])
{
    char plainText[INPUT_LEN];
    char *keyWord = malloc(strlen(args[1]));

    if (count != 2)
    {
        printf("There is no key");
        return 1;
    }
    
    strcpy(keyWord, args[1]);
    int keyWord_LEN = strlen(keyWord);

    printf("Enter plain text: ");
    fgets (plainText, INPUT_LEN, stdin);

    int strLength = strlen(plainText);
    char *cipherText = malloc(strLength + 1);

    printf("%s", plainText);

    int nonAlphaCount = 0;
    for (int i = 0; i < strLength; i++ ){

        if(plainText[i] == '\0' || plainText[i] == '\n'|| plainText[i] == '\r')
            break;

        if(isalpha(plainText[i]))
        {
            // Default lower 
            int asciiUpperOrLower = 97;   
            int keyUpperOrLower = 97;    

            if(isupper(plainText[i]))
                asciiUpperOrLower = 65;

            if(isupper(keyWord[i % keyWord_LEN]))
                keyUpperOrLower = 65;

            int Key = keyWord[(i - nonAlphaCount) % keyWord_LEN] - keyUpperOrLower;
            int alphabetBaseletter = ((plainText[i] - asciiUpperOrLower + Key) % ALPHABET_LEN);
            
            cipherText[i] = alphabetBaseletter + asciiUpperOrLower;
        }
        else{
            cipherText[i] = plainText[i];
            nonAlphaCount++;
        }
            
    }

    // Set string terminator.
    cipherText[strLength - 1] = '\0' ;

    printf("%s", cipherText);

    return 0;

}
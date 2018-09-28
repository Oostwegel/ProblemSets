#include <stdio.h>
#include <string.h>
#include <ctype.h>

int KEY = 0;
const int INPUT_LENGTH = 255; 
const int ALPHABET_LEN = 26;

void cleanAndPrint(char*, int);

int main (int count, char* args[])
{

    char plainText[INPUT_LENGTH];
    char cipherText[INPUT_LENGTH];

    if ( count < 2 || count > 3)
    {
        printf("There is no key");
        return 1012;
    }
    
    KEY = (int)args[1];

    printf("Enter plain text: ");
    fgets (plainText, INPUT_LENGTH, stdin);

    int strLength = strlen(plainText);
    for (int i = 0; i < strLength; i++ ){

        if(plainText[i] == '\0' || plainText[i] == '\n'|| plainText[i] == '\r')
            break;

        if(isalpha(plainText[i]))
        {
            int alphabetMaxletter = (((int)plainText[i] + KEY) % ALPHABET_LEN) + 97;
            
            if(isupper(plainText[i]))
               alphabetMaxletter = alphabetMaxletter - 32;
            
            cipherText[i] = alphabetMaxletter;
        }
        else
            cipherText[i] = plainText[i];
    }

    printf("%s\n", cipherText);
    cleanAndPrint(cipherText, strLength);

    return 0;

}


void cleanAndPrint(char* string, int len)
{
    int strLength = (int) sizeof(string);
    for(int i = 0; i < strLength; i++)
        if(i > len) string[i] = '\0';

    printf("%s", string);
}
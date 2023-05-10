#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char rotate(char typedChar, int key) 
{
    if (isupper(typedChar)) 
    {
        int A = 65;
        int Z = 90;
        bool isGreater = typedChar + key > Z;

        if (isGreater)
        {
            int uppCiphered = ( (typedChar + key) - Z) + (A - 1);
            printf("%c", uppCiphered);
        }
        else
        {
            printf("%c", (typedChar + key));
        }
    }

    if (islower(typedChar)) 
    {
        int a = 97;
        int z = 122;
        bool isGreater = typedChar + key > z;      

        if (isGreater)
        {
            int lowCiphered = ( (typedChar + key) - z) + (a - 1);
            printf("%c", lowCiphered);
        }
        else
        {
            printf("%c", (typedChar + key));
        }
    }
    return typedChar;
}

int main(int argc, string argv[]) 
{
    if (argv[1] == NULL) 
    {
        printf("%s", "Usage: ./caesar key\n");
        return 1;
    }

    int lengthOfArgument = strlen(argv[1]);
    for (int i = 0; i < lengthOfArgument; i++) 
    {
        if (argv[1][i] == '.' || argv[1][i] == ',' || lengthOfArgument < 1)
        {
            printf("%s", "Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    if ( key <= 0 )
    {
        printf("%s", "Usage: ./caesar key\n");
        return 1;
    }

    if (argc > 2) 
    {
        printf("%s", "Usage: ./caesar key\n");
        return 1;
    }

    string message = get_string("Message: ");

    int lengthOfMessage = strlen(message);
    for (int i = 0; i < lengthOfMessage; i++) 
    {
        if (message[i] == ' ' || isdigit(message[i]) == 1 || message[i] == '!')
        {
            printf("%c", message[i] );
        }
        else 
        {
            rotate(message[i], key);
        }
    }
    printf("%s"," \n");
}

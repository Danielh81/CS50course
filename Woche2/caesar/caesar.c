#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char rotate(char c, int n) 
{
    if (isupper(c)) 
    {
        printf("%s", "upper\n");
    }
    else 
    {
        printf("%s", "lower\n");
    }

    if (isalpha(c + n))
    {
        printf("%s", "alpha\n");
    }
    else
    {
        printf("%s", "NOalpha\n");
    }

    return c;
}

int main(int argc, string argv[]) 
{
//----------------------------------------------------------------------------------------------------------------
// string message = get_string("Message: ");
// int cipherkey = get_int("Enter Key: ");

// int length = strlen(message);
// int ciphertext;
// int i = 0;

// printf("Message is: %i %i %i %i\n", message[0] + cipherkey, message[1] + cipherkey, message[2] + cipherkey, message[3] + cipherkey);
// printf("Length: %i\n", length);

// for (i = 0; i < length; i++)
// {
//     printf("%i\n", message[i]);
//     ciphertext = message[i] + cipherkey;
//     printf("OI: %i\n", ciphertext);
//     printf("new texT: %c\n", ciphertext);
//     printf("--------\n");
// }
// --------------------------------------------------------------------------------------------------------------

// printf("!%s ", argv[1]);

if (argv[1] == NULL) 
{
    printf("%s", "UsaGE: ./caesar key\n");
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
    printf("%s", "UsagE: ./caesar key\n");
    return 1;
}


if ( /* argc < 1 || */ argc > 2  ) 
{
    printf("%s", "Usage: ./caesar key\n");
    return 1;
}

char lowerCaseAlphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char upperCaseAlphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string message = get_string("Message: ");
int lengthOfMessage = strlen(message);

for (int i = 0; i < lengthOfMessage; i++) 
{
    if (message[i] == ' ' || isdigit(message[i]) == 1)
    {
        printf("%c", message[i] );
    }
    else 
    {
        printf("%c \n", message[i] + key);
    }

    rotate(message[i], key);
}

printf("%s"," \n");
printf("Letters: %i\n", lengthOfMessage);

}


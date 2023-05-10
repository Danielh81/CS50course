#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) 
{
    if (argv[1] == NULL)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int lengthOfKey = strlen(argv[1]);

    for (int i = 0; i < lengthOfKey; i++)
    {
        if (lengthOfKey < 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        if (argc > 2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        if (isdigit(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        for (int j = 0; j < lengthOfKey; j++)
        {
            if ( i == j)
            {
                continue;
            }
            if (key[i] == key[j])
            {
            printf("Key must not contain repeated characters.\n");
            return 1; 
            }
        }
    }

    string text = get_string("Your text: ");
    int lengthOfText = strlen(text);
    int textInNumber = atoi(text);
    int positioning;
    char cipher;

    for (int i = 0; i < lengthOfText; i++)
    {
        if (text[i] == ' ' || isdigit(text[i]) == 1 || text[i] == '!' || text[i] == '?' || text[i] == ',' || text[i] == '.')
        {
            printf("%c", text[i]);
        }
        
        int A = 65;
        int Z = 90;
        if (isupper(text[i]))
        {
            positioning = text[i] - A;
            cipher = key[positioning];
            printf("%c", toupper(cipher));           
        }
        
        int a = 97;
        int z = 122;
        if (islower(text[i]))
        {
            positioning = text[i] - a;
            cipher = key[positioning];
            printf("%c", tolower(cipher));
        }
    }
        printf("\n");
}

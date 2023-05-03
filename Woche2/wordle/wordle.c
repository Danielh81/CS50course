#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define LISTSIZE 1000
#define EXACT 2
#define CLOSE 1
#define WRONG 0

#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define MAGENTA "\e[38;2;255;255;255;1m\e[39;45;1;3m"
#define RESET   "\e[0;39m"

int check_word(string guess, int wordsize, int status[], string choice);

int main(int argc, string argv[])
{
    char wordsize = 0;
    wordsize = atoi(argv[1]);

    if (argv[1] == NULL || argc > 2)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }

    if (isalpha(argv[1][0]) == 1)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }

    if (wordsize < 5 || wordsize > 8 )
    {
        printf("Must be Number 5 - 8\n");
        return 1;
    }

    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // printf(MAGENTA"The word is: %s"RESET"\n", choice);    // Lösung

    int guesses = wordsize + 1;
    bool won = false;

    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    int j = 0;
    for (int i = 0; i < guesses; i++)
    {
        string guess = get_string("Guess %i: ", i + 1);
        
        if (strlen(guess) < wordsize || strlen(guess) > wordsize) 
        {
            i--;
            continue;
        }

        bool hasDigit = false;
        for ( j = 0; j < strlen(guess); j++)
        {            
            if (isdigit(guess[j]) || !isalpha(guess[j]))
            {
                printf("Bitte nur Buchstaben\n");
                hasDigit = true;
                break;
            }
            else 
            {
                guess[j] = tolower(guess[j]);
            }
        }

        if (hasDigit) i--;

        int status[wordsize];
        int score = check_word(guess, wordsize, status, choice);

        if (score == EXACT * wordsize)
        {
            won = true;
            printf(MAGENTA"You win! Score: %i"RESET"\n", score);
            return 0;
        }
    }
    printf(MAGENTA"You lose! The word was: %s"RESET"\n", choice);
    return 0;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;
    int i, j;
    for (i = 0; i < wordsize; i++)
    {
        if (isdigit(guess[i]) || !isalpha(guess[i]))
        {
            return 1;
        }
    }

    for (i = 0; i < wordsize; i++)
    {   
        if (choice[i] == guess[i])
        {
            printf(GREEN"%c"RESET"", guess[i]);
            score = score + EXACT;
        }       
        else
        {
            bool found = false;
            for (j = 0; j < wordsize; j++)
            {
                if (choice[j] == guess[i])
                {
                    found = true;
                    printf(YELLOW"%c"RESET"", guess[i]);
                    score = score + CLOSE;
                    break;
                }
            }
            if (!found) 
            {
            printf(RED"%c"RESET"", guess[i]);
            score = score + WRONG;
            }
        }
    }

    printf("\n");
    printf("Score: %i\n", score);
    return score;
}

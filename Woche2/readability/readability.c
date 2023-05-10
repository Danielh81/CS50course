#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(void) 
{
    string text = get_string("Enter Text: ");
    int lettersCompleteText = strlen(text);
    float words = 1;
    float sentence = 0;
    float noLetter = 0;

    for (int i = 0; i < lettersCompleteText; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }

        if (text[i] ==  '.' || text[i] == '!' || text[i] == '?' || text[i] == ' ' || text[i] == ',' || text[i] == '\'')
        {
            noLetter++;
        }
    }
    printf("%.f Letters\n", (lettersCompleteText - noLetter));
    printf("%.f Words\n", words);
    printf("%.f Sentences\n", sentence);

    float averageLetters = ((lettersCompleteText - noLetter) / words) * 100;
    float averageSentence = (sentence / words) * 100;
    float grade = 0.0588 * averageLetters - 0.296 * averageSentence - 15.8;

    if (grade >= 16)
    {
        printf("Grade 16+ \n");
    }

    if (grade <= 1)
    {
        printf("Before Grade 1 \n");
    }

    if (grade > 1 && grade < 16) 
    {
        printf("Grade %.f \n", round(grade));
    }
}

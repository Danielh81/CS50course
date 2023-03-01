#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    long card;
    do
    {
        card = get_long("Card Number: ");
    }
    while (card < 0);

    int digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8;

    digit1 = (card % 100 / 10) * 2;
    digit2 = (card % 10000 / 1000) * 2;
    digit3 = (card % 1000000 / 100000) * 2;
    digit4 = (card % 100000000 / 10000000) * 2;
    digit5 = (card % 10000000000 / 1000000000) * 2;
    digit6 = (card % 1000000000000 / 100000000000) * 2;
    digit7 = (card % 100000000000000 / 10000000000000) * 2;
    digit8 = (card % 10000000000000000 / 1000000000000000) * 2;

    int sum1 = digit1 + digit2 + digit3 + digit4 + digit5 + digit6 + digit7 + digit8;

    int digit9, digit10, digit11, digit12, digit13, digit14, digit15, digit16;

    digit9 = (card % 10);
    digit10 = (card % 1000 / 100);
    digit11 = (card % 100000 / 10000);
    digit12 = (card % 10000000 / 1000000);
    digit13 = (card % 1000000000 / 100000000);
    digit14 = (card % 100000000000 / 10000000000);
    digit15 = (card % 10000000000000 / 1000000000000);
    digit16 = (card % 1000000000000000 / 100000000000000);

    int sum2 = digit9 + digit10 + digit11 + digit12 + digit13 + digit14 + digit15 + digit16;

    int sumGes = sum1 + sum2;

    printf("Prüfzahl = %i\n", sumGes);
}
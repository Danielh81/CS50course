#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long enteredNumber;
    long cardNumber;

    do
    {
        enteredNumber = get_long("Card Number: ");
    } while (enteredNumber <= 0);

    int cardNumberLength = 0;
    long cardNumberToDetermineLength = enteredNumber;

    while (cardNumberToDetermineLength != 0)
    {
        cardNumberToDetermineLength = cardNumberToDetermineLength / 10;
        ++cardNumberLength;
    };

    int orangeNumberSum = 0;
    int blueNumberSum = 0;
    long cardNumberToDetermineCheckNumber = enteredNumber;

    while (cardNumberToDetermineCheckNumber > 0)
    {
        printf("orange: %li\n", cardNumberToDetermineCheckNumber % 10);
        printf("blue: %li\n", cardNumberToDetermineCheckNumber % 100 / 10);
        cardNumberToDetermineCheckNumber = cardNumberToDetermineCheckNumber / 100;
        for (int i = 0; i < cardNumberLength; i++)
        {
            
        }
    }





    printf("length of number = %i\n", cardNumberLength);
    printf("CC = %li\n", enteredNumber);
    printf("cardNumberToDetermineLength = %li\n", cardNumberToDetermineLength);
    printf("orangeSum: %i\n", orangeNumberSum);

    // int length;

    // do
    // {
    //     length = get_int("Length: ");
    // }
    // while (length < 1);

    // int twice[length];
    // twice[0] = 1;
    // printf("%i\n", twice[0]);

    // for (int i = 1; i < length; i++)
    // {
    //     twice[i] = 2 * twice[i - 1];
    //     printf("%i\n", twice[i]);
    // }

    /* TODO
    1. eingegebene Nummer in ein Variable speichern
    2. for Schleife erstelle
    3. in der while Schleife auf den VORletzten Wert zugreifen  (i-1 ODER % Modulo (bei Modulo / 10 um keine Komma Zahl zu bekommen))
    3.a Zahl * 2 rechnen
    4. 2 Zahlen weiter springen, ... bis zum Anfang des Arrays
    4.a  Wenn Zahl über 9, dann die Zahl Stelle 1 + Stelle 2 (zB 12 wäre dann 1+2)
    5. Summe der Zahlen speichern
    6. neue Schleife, diesmal letzte Zahl zuerst
    7. 2 Zahlen weiter springen... bis zur ersten Zahl hin
    7.a Alle Zahlen addieren (diesmal keine Multiplikation)
    8. Summe von Schleife 1 + Summe von Schleife 2 addieren.

    9. Wenn Abfragen zum überprüfen ob Prüfzahl korrekt = Endet Summe der Schleife 1+2 mit einer 0, dann korrekt (durch 10 teilbar)
    9.a Wenn erste Zahl der Kartennummer 4 && Anzahl der Zahlen 13 || 16 dann VISA
    9.b Wenn ersten Zahlen der Kartennummer 34 oder 37 && Anzahl der Zahlen 15 dann AMEX
    9.c Wenn ersten Zahlen der Kartennummer 51 - 55 && Anzahl der Zahlen 16 Zahlen, dann Mastercard

    */
}

#include <cs50.h>
#include <stdio.h>

int checkForFirstDigits(long enteredNumber) {
    while (enteredNumber > 100) {
        enteredNumber = enteredNumber / 10;
    }

    return enteredNumber;
}

int getLengthOfNumber(long enteredNumber) {
    int digitCounter = 0;
    while (enteredNumber > 0) {
        enteredNumber = enteredNumber / 10;
        digitCounter++;
    }

    return digitCounter;
}

int main(void)
{
    long enteredNumber;

    do
    {
        enteredNumber = get_long("Card Number: ");
    } 
    while (enteredNumber <= 0);

    int cardNumberLength = getLengthOfNumber(enteredNumber);
    printf("Card Number Length %d\n", cardNumberLength);
    int firstDigits = checkForFirstDigits(enteredNumber);
    int orangeNumberSum = 0;
    int blueNumberSum = 0;
    long cardNumberToDetermineCheckNumber = enteredNumber;
    int checkSum = 0;

    while (cardNumberToDetermineCheckNumber > 0)
    {
        orangeNumberSum = orangeNumberSum + (cardNumberToDetermineCheckNumber % 10);

        if (2 * (cardNumberToDetermineCheckNumber % 100 / 10) > 9)
        {

            int doubleSumBlue = 2 * (cardNumberToDetermineCheckNumber % 100 / 10);
            int sumOfDoubleSumIfOverTen = 0;

            while (doubleSumBlue)
            {
                sumOfDoubleSumIfOverTen = sumOfDoubleSumIfOverTen + (doubleSumBlue % 10);
                doubleSumBlue /= 10;
            }
                blueNumberSum = blueNumberSum + sumOfDoubleSumIfOverTen;
        }

        else 
        {
            int doubleSumBlue = 2 * (cardNumberToDetermineCheckNumber % 100 / 10);
            blueNumberSum = blueNumberSum + doubleSumBlue;
        }
        
        checkSum = orangeNumberSum + blueNumberSum;
        cardNumberToDetermineCheckNumber = cardNumberToDetermineCheckNumber / 100;
    }   

        if (checkSum % 10 == 0)
        {   
            
            printf("Es ist eine gültige Karte. \n");
            if ((cardNumberLength == 13) || (cardNumberLength == 16) && (firstDigits / 10 == 4))
            {
                printf("Es ist eine VISA \n");

                return 0;
            }

            if  ((firstDigits == 34) || (firstDigits == 37) && (cardNumberLength == 15))
            {
                printf("Es ist eine American Express \n");

                return 0;
            }

            if ((firstDigits >= 51) && (firstDigits <= 55) && (cardNumberLength == 16))
            {
                printf("Es ist eine Mastercard \n");

                return 0;
            }
        }
        else 
        {
            printf("Es ist keine gültige Karte. \n");

            return 1;
        }

        blueNumberSum = blueNumberSum + (cardNumberToDetermineCheckNumber % 100 / 10);


}

            /*

            HELP

            Number: 123456789

            // 1   3   5   7   9    - orange loop
            //     2   4   6   8    - blue loop
            //    (4) (8)  12  16   - doubleSumBlue
            //             3   7    - sumOfDoubleSumIfOverTen



            Numbers to check:

            AMEX: 371449635398431

            VISA: 4111111111111111

            Mastercard: 5555555555554444

            
            */
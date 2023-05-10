#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string message = get_string("Enter Message: ");

    int binaryRemainder;
    int messageLength = strlen(message);
    
    for (int i = 0; i < messageLength; i++)
    {
        char binaryNumber[7];
        int counter = 6;

        while (message[i] > 0)
        {
            binaryRemainder = message[i] % 2;
            message[i] /= 2;

            if (binaryRemainder == 1) 
            {
                binaryNumber[counter] = '1';
            }
            if (binaryRemainder == 0)
            {
                binaryNumber[counter] = '0';
            }
            counter--;
        }

        int arrayLength = (sizeof(binaryNumber) / sizeof(binaryNumber[0]));
        
        for (int count = 0; count < arrayLength; count++) 
        {
            if (binaryNumber[count] == '1')
                printf("\U0001F7E1");
            else
                printf("\U000026AB");
        }

        printf("\n");
    }
}

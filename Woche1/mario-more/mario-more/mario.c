#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int start;
    do 
    {
        start = get_int("Start size: ");
    }
    while (start <= 0 || start >= 9);


    for (int i = 0; i < start; i++) {
        for(int j = 0; j < start; j++) {
            if(i + j < start - 1) {
                printf("  ");
            }
            else {
                printf(" #");
            }
        }
        printf(" ");

        for(int x = 0; x < start; x++) {
            if(i - x >= 0) {
                printf(" #");
            }
            }

        printf(" \n");
    }

}
#include <stdio.h>
#include <stdbool.h>

#define INCORRECT_GUESS_COUNT 3


bool find_positive(int *number) {
    int selection = -1;

    printf("Enter a positive number: ");

    if (scanf("%d", &selection) != 1) {
        while(getchar() != '\n') ;
        printf("Invalid input.\n");
        return false;
    }
    if (selection < 0) {
        printf("You must enter a positive number.\n");
        return false;
    } else {
        *number = selection;
        return true;
    }
}


int main() {
    int number = 0;
    int i = 0;

    printf("Guess how much money i have!\n");
    while (i < INCORRECT_GUESS_COUNT) {
        if (find_positive(&number)) {
            printf("Wrong, i have %d euros.\n", number*2+20);
        } else {
            i++;
        }
    }
    printf("I give up! cya l8rz\n");
    return 0;
}
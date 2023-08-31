#include <stdio.h>

#define RANGE_LOW 1
#define RANGE_HIGH 6

int read_range(int low, int high) {
        int selection = 0;
        do {
        printf("Select a number between %d and %d: ", low, high);
        if (scanf("%d", &selection) != 1) {
            while(getchar() != '\n');
            printf("Your input was not a number.\n");
        }
        if (selection < low || selection > high) {
            printf("Your number was not between %d and %d\n", low, high);
        }
    } while(selection < low || selection > high);
    return selection;
}

int main() {
    
    printf("Lets play!\n");

    int number = read_range(RANGE_LOW, RANGE_HIGH);
    
    if (number == RANGE_HIGH) {
        printf("I got %d. It's a tie!\n", RANGE_HIGH);
        return 0;
    }
    printf("I got %d. I win!\n", number+1);
    
    return 0;
}
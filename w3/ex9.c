#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20


int find_first(const unsigned int *numbers, unsigned int wanted) {
    int i = 0;

    while (numbers[i] != 0) {
        if (numbers[i] == wanted) return i;
        i++;
    }
    return -1;
}


int main() {

    unsigned int numbers[ARRAY_SIZE];

    for (int i=0; i<ARRAY_SIZE-1; i++) {
        numbers[i] = 1 + rand() % 20;
        printf("%d\n", numbers[i]);
    }
    numbers[ARRAY_SIZE] = 0;

    unsigned int selection;

    do {
        printf("Enter a number you want to find: ");
        while (scanf("%u", &selection) != 1) {
            while (getchar() != '\n') ;
            printf("Invalid input.\n");
        }
    } while (selection == 0);

    printf("%u", find_first(numbers, selection));

    return 0;
}
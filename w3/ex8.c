#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 15


void print_numbers(const int *numbers, int count) {
    for (int i=0; i < count; i++) {
        printf("%8d\n", numbers[i]);
    }
}


int main() {

    int array[ARRAY_SIZE];

    for (int i=0; i<ARRAY_SIZE; i++) {
        array[i] = rand()%99999999;
    }

    print_numbers(array, ARRAY_SIZE);

    return 0;
}
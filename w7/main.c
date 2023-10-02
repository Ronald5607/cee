#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "debug.h"

#define USER_INPUT_LENGTH 32

void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}


int main() {

    int number = 0;
    char input[USER_INPUT_LENGTH] = {};
    do {
        printf("Enter debug level: ");
        read_string(input, USER_INPUT_LENGTH);
        if (!sscanf(input, "%d", &number)) {
            printf("Invalid input.\n");
        }
    } while (number < 0 || number > 4);

    set_debug_level(number);
    for (int i=0; i<5; i++) {
        int random = rand() % 5;
        dprintf(random, "test %d\n", i);
    }

    return 0;
}
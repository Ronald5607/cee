#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_MAX 32

void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}

int read_integer(char *string, int size) {
    int number = 0;
    int sscanf_return = 0;
    while (sscanf_return <= 0) {
        printf("Give number(0-15): ");
        read_string(string, size);
        sscanf_return = sscanf(string, "%d", &number);
        if (sscanf_return <= 0) {
            printf("Invalid input.\n");
        }
    }
    return number;
}


int main() {
    int number = 9;
    char input[INPUT_MAX] = {};

    while (number >= 0) {
        number = read_integer(input, INPUT_MAX);
        if (number >= 0 && number <= 15) {
            int random_number = rand();
            printf("0x%x\n", random_number);
            random_number = (random_number >> number) & 0x3f;
            printf("0x%.8x\n", random_number);
        } else if (number > 15) {
            printf("Too large\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

#define string_length 256

void read_string(char * user_string) {
    fgets(user_string, string_length, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}

int main() {

    char user_string[string_length] = {};

    while (strcmp(user_string, "stop") != 0) {
        printf("Enter a string: ");
        read_string(user_string);
        printf("%llu\n", strlen(user_string));
    }
}
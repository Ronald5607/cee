#include <stdio.h>
#include <string.h>

void read_string(char * user_string) {
    fgets(user_string, 256, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}

int main() {

    char user_string[256] = {};

    while (strcmp(user_string, "stop") != 0) {
        printf("Enter a string: ");
        read_string(user_string);
        printf("%lu\n", strlen(user_string));
    }
}
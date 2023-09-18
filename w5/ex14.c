#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define USER_INPUT_LENGTH 80
#define MAX_LINES 100


void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}


int main() {

    char file_to_open[USER_INPUT_LENGTH] = {};

    printf("Enter a Path to a file: ");
    read_string(file_to_open, USER_INPUT_LENGTH);

    FILE *opened_file;
    opened_file = fopen(file_to_open, "r");

    if (opened_file == NULL) {
        fputs("Error opening the file\n", stderr);
        return 1;
    }

    char strings[MAX_LINES][USER_INPUT_LENGTH] = {};
    int i = 0;
    while (fgets(strings[i], USER_INPUT_LENGTH, opened_file) && i < MAX_LINES) {
        int j = 0;
        while (strings[i][j] != '\0') {
            strings[i][j] = toupper(strings[i][j]);
            j++;
        }
        i++;
    }
    fclose(opened_file);
    opened_file = fopen(file_to_open, "w");

    if (opened_file == NULL) {
        fputs("Error opening the file\n", stderr);
        return 1;
    }

    fputc('\n', opened_file);

    for (int i; i<MAX_LINES; i++) {
        fputs(strings[i], opened_file);
    }
    fclose(opened_file);

    return 0;
}
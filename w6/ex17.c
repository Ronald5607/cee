#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define OUTPUT_SIZE 32+1
#define MAX_WORD_SIZE 64
#define CHARACTER 128


char create_printable() {

    int printable;
    do {
        // getting a random ASCII character, isprint checks ASCII value which is between 0 and 127
        printable = rand() % CHARACTER;
    } while (!isprint(printable) && isspace(printable));
    return printable;
}

bool generate_password(char *output, int size, const char *word) {
    // leaving room for the password and zero character
    if ((strlen(word) * 2 + 2) > size) return false;
    int i = 0;
    while (word[i] != '\0') {
        output[2*i] = create_printable();
        output[2*i+1] = word[i];
        i++;
    }
    output[2*i] = create_printable();
    output[2*i+1] = '\0';
    return true;
    
}

void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}


int main() {
    // seeding rand with current time so it doesnt produce same output each time
    srand(time(NULL));

    char word[MAX_WORD_SIZE] = {};
    char password[OUTPUT_SIZE] = {};

    while (strcmp(word, "stop") != 0) {
        printf("Give me a word: ");
        read_string(word, MAX_WORD_SIZE);
        if (strcmp(word, "stop") != 0) {
            if (generate_password(password, OUTPUT_SIZE, word)) {
                printf("Your password is:\n");
                printf("%s\n", password);
            } else {
                printf("Could not generate password\n");
            }
        }
    }
    return 0;
}
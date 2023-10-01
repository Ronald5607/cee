#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRUCTS 40
#define USER_INPUT_LENGTH 128
#define MAX_LINE_WIDTH 256
#define MAX_NAME_WIDTH 50

typedef struct menu_item_ {
    char name[MAX_NAME_WIDTH];
    double price;
} menu_item;


void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}


int main() {

    menu_item items[MAX_STRUCTS];
    char file_to_open[USER_INPUT_LENGTH] = {};

    printf("Enter a Path to a file: ");
    read_string(file_to_open, USER_INPUT_LENGTH);

    FILE *opened_file;
    opened_file = fopen(file_to_open, "r");

    if (opened_file == NULL) {
        fputs("Error opening the file\n", stderr);
        return 1;
    }
    char line[MAX_LINE_WIDTH] = {};
    int i = 0;
    while (fgets(line, MAX_LINE_WIDTH, opened_file) && i < MAX_STRUCTS) {
        char *token = strtok(line, ";");
        if (token != NULL) {
            char *second_token = strtok(NULL, ";");
            if (second_token != NULL) {
                strncpy(items[i].name, token, MAX_NAME_WIDTH);
                // strncpy doesnt add terminating zero to the string if source is longer than size
                items[i].name[MAX_NAME_WIDTH-1] = '\0';
                sscanf(second_token, "%lf", &items[i].price);
                i++;
            }
        }
    }
    fclose(opened_file);
    printf("Price:   Name:\n");
    for (int j; j<i; j++) {
        printf("%8.2lf %s\n", items[j].price, items[j].name);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int name_compare(const void *elem1, const void *elem2) {
    menu_item *cast_elem1 = (menu_item *)elem1;
    menu_item *cast_elem2 = (menu_item *)elem2;

    char str1[MAX_NAME_WIDTH] = {};
    char str2[MAX_NAME_WIDTH] = {};
    int i = 0;
    while (cast_elem1->name[i] != '\0') {
        str1[i] = tolower(cast_elem1->name[i]);
        i++;
    }
    i = 0;
    while (cast_elem2->name[i] != '\0') {
        str2[i] = tolower(cast_elem2->name[i]);
        i++;
    }
    return strcmp(str1, str2);
}

int price_compare(const void *elem1, const void *elem2) {
    menu_item *cast_elem1 = (menu_item *)elem1;
    menu_item *cast_elem2 = (menu_item *)elem2;
    double subtraction = cast_elem1->price - cast_elem2->price;
    if (subtraction < 0) return -1;
    if (subtraction > 0) return 1;
    return 0;
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

    int number = 0;
    char input[USER_INPUT_LENGTH] = {};
    do {
        printf("1) Sort by price\n");
        printf("2) Sort by name\n");
        printf("Select sorting method:\n");
        read_string(input, USER_INPUT_LENGTH);
        if (!sscanf(input, "%d", &number)) {
            printf("Invalid input.\n");
        }
    } while (number < 1 || number > 2);
    // compare pointer is selected with ternary operator. could do this with switch case or if statements but i wont
    int (*compare_pointer)(const void *, const void *) = (number-1) ? name_compare : price_compare;
    qsort(items, i, sizeof(menu_item), compare_pointer);
    printf("Price:   Name:\n");
    for (int j; j<i; j++) {
        printf("%8.2lf %s\n", items[j].price, items[j].name);
    }

    return 0;
}
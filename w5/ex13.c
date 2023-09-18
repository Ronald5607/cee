#include <stdio.h>
#include <string.h>

#define USER_INPUT_LENGTH 128
#define MAX_LINE_WIDTH 64

void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}

int main() {
    char user_input[USER_INPUT_LENGTH] = {};

    printf("Enter a Path to a file: ");
    read_string(user_input, USER_INPUT_LENGTH);

    FILE *opened_file = fopen(user_input, "r");

    if (opened_file == NULL) {
        fputs("Error opening the file\n", stderr);
        return 1;
    }

    char line[MAX_LINE_WIDTH] = {};
    int number_from_line = 0;
    int max_number = 0;
    int min_number = 0;
    int count_of_numbers = 0;
    while (fgets(line, MAX_LINE_WIDTH, opened_file)) {
        if (sscanf(line, "%d", &number_from_line)) {
            if (number_from_line < min_number) {
                min_number = number_from_line;
            } else if (number_from_line > max_number) {
                max_number = number_from_line;
            }
            count_of_numbers++;
        }
    }
    fclose(opened_file);
    
    printf("Minimum number was: %d\n",min_number);
    printf("Maximum number was: %d\n",max_number);
    printf("Count of numbers was: %d\n", count_of_numbers);

    return 0;

}
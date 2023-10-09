#include <stdio.h>
#include <string.h>


#define USER_INPUT_LENGTH 128
#define MAX_LINE_WIDTH 264

void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}
/*
modifies given string to contain data.
returns number from the end of the line if no data could be retrieved return -1
*/
int get_data(char *line) {
    int size_of_line = strlen(line);
    if (line[0] != '$') return -1; // line does not start with $.
    char *token = strtok(line+1, "*");
    char *second_token = strtok(NULL, "*");
    int number;
    if (token != NULL && sscanf(second_token, "%x", &number)) {
        // token character count is quaranteed to be less than or equal to line so no need to append zero character.
        strncpy(line, token, size_of_line+1); // line character count plus zero character.
        return number;
    }
    return -1;
}

int get_checksum(char *line) {
    if (line[0] == '\0') return 0;
    int checksum = line[0];
    int i = 1;
    while (line[i] != '\0') {
        checksum ^= line[i];
        i++;
    }
    return checksum;
}

int main() {

    char file_to_open[USER_INPUT_LENGTH] = {};

    printf("Enter a Path to a file containing NMEA data: ");
    read_string(file_to_open, USER_INPUT_LENGTH);

    FILE *opened_file;
    opened_file = fopen(file_to_open, "r");

    if (opened_file == NULL) {
        fputs("Error opening the file\n", stderr);
        return 1;
    }
    char line[MAX_LINE_WIDTH] = {};
    char data[MAX_LINE_WIDTH] = {};
    int number = -1;
    int checksum = 0;
    while (fgets(line, MAX_LINE_WIDTH, opened_file)) {
        *strchr(line, '\n') = '\0'; // get rid of newline character.
        strncpy(data, line, strlen(line)+1); // strlen(line)+1 <= size of data, no need to append zero
        number = get_data(data);
        if (number >= 0) {
            checksum = get_checksum(data);
            if (checksum == number) {
                printf("[ OK ] %s\n", line);
            } else {
                printf("[FAIL] %s\n", line);
            }
        }
    }


    fclose(opened_file);
    return 0;
}
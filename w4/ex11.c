#include <stdio.h>
#include <string.h>

#define user_string_length 128
#define change_string_length 3

int change_char(char *string_to_update, const char *change_string) {

    int i = 0;
    int number = 0;

    while (string_to_update[i] != '\0') {
        if (string_to_update[i] == change_string[0]) {
            string_to_update[i] = change_string[1];
            number++;
        }
        i++;
    }
    return number;
}


void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}


int main() {

    char user_string[user_string_length] = {};
    char change_string[change_string_length] = {};

    printf("Enter a string: ");
    read_string(user_string, user_string_length);
    printf("Enter two characters (last one will replace all instances of the first): ");
    read_string(change_string, change_string_length);

    int changed = change_char(user_string, change_string);
    if (changed != 0) {
        printf("%d characters replaced.\n", changed);
        printf("%s", user_string);
    } else {
        printf("No modifications made.\n");
    }

}
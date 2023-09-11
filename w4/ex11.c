#include <stdio.h>
#include <string.h>


int change_char(char *string_to_update, const char *change_string) {

    if (strlen(change_string) != 2) return 0;

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

    char user_string[128] = {};
    char change_string[3] = {};

    printf("Enter a string: ");
    read_string(user_string, 128);
    printf("Enter two characters (last one will replace all instances of the first): ");
    read_string(change_string, 3);

    int changed = change_char(user_string, change_string);
    if (changed != 0) {
        printf("%d characters replaced.\n", changed);
        printf("%s", user_string);
    } else {
        printf("No modifications made.\n");
    }

}
#include <stdio.h>
#include <string.h>

#define str_length 128
#define cmp_str_length 128

int count_words(const char *str, const char *cmp_str) {
    char *found = strstr(str, cmp_str);
    int count = 0;
    while (found != NULL) {
        count++;
        found = strstr(found+strlen(cmp_str), cmp_str);
    }
    return count;
}

void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}


int main() {
    char str[str_length] = "";
    char cmp_str[cmp_str_length] = "";
    int count = 0;


    while (strcmp(cmp_str, "stop") != 0) {

        printf("Enter a string: ");
        read_string(str, str_length);

        printf("Enter a word: ");
        read_string(cmp_str, cmp_str_length);

        if (strcmp(cmp_str, "stop") != 0) {
            count = count_words(str, cmp_str);
            printf("Your string had %d copies of %s\n", count, cmp_str);
        }
    }
    return 0;
}
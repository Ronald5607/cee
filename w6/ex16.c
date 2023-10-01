#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 128

typedef struct nnode {
    int number;
    struct nnode *next;
} node;

node *add_integer_node(node *current, int number) {
    node *new_node = malloc(sizeof(node));
    new_node->number = number;
    if (current != NULL) {
        current->next = new_node;
    }
    return new_node;
}

void free_nodes(node *start) {
    node *current = start;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void read_string(char * user_string, int size) {
    fgets(user_string, size, stdin);
    if (user_string[strlen(user_string)-1] == '\n') {
        user_string[strlen(user_string)-1] = '\0';
    }
}


int main() {
    node *numbers_start = NULL;
    node *numbers_current = NULL;
    char input[INPUT_LENGTH] = {};
    int numbor = 0;

    while (strcmp(input, "end") != 0) {
        printf("Enter number: ");
        read_string(input, INPUT_LENGTH);
        if (sscanf(input ,"%d", &numbor) != 0) {
            numbers_current = add_integer_node(numbers_current, numbor);
            if (numbers_start == NULL) {
                numbers_start = numbers_current;
            }
        } else if(strcmp(input, "end") != 0) {
            printf("Invalid input\n");
        }
    }
    node *iter = numbers_start;
    while (iter != NULL) {
        printf("%d\n", iter->number);
        iter = iter->next;
    }
    free_nodes(numbers_start);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>


int make_menu(void) {
    int selection = 0;
    do {
        printf("Select option:\n 1) D6\n 2) D10\n 3) Quit\n");
        if (scanf("%d", &selection) != 1) {
            while(getchar() != '\n');
            printf("Invalid input.\n");
        }
    } while(selection < 1 || selection > 3);
    return selection;
}

int get_roll(int die_sides) {
    int roll;
    do {
        roll = 1 + rand() / ((RAND_MAX + 1u) / die_sides);
    } while (roll > die_sides);
    return roll;
}

int main() {
    int main_selection;
    int roll;

    do {
        main_selection = make_menu();

        if (main_selection == 1) {
            roll = get_roll(6);
        } else {
            roll = get_roll(10);
        }
        printf("You rolled %d\n\n", roll);
    } while (main_selection != 3);
}
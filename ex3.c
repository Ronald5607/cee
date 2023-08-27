#include <stdio.h>
#include <stdbool.h>

int main() {

    int student_count = 0;
    printf("How many students: ");
    scanf("%d", &student_count);

    int student_array[student_count];
    for (int i=0; i < student_count; i++) {
        student_array[i] = -1;
    }

    int selected = -1;
    int grade;
    while (selected != 0) {
        printf("\nEnter student number (1 - %d) or 0 to stop: ", student_count);
        scanf("%d", &selected);

        if (selected < 0 || selected > student_count) {
            printf("Invalid student number!\n\n");
        } else if (selected == 0) {
            break;
        } else {
            do {    
                printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", selected);
                scanf("%d", &grade);
                if (grade < -1 || grade > 5) {
                    printf("Invalid grade!\n");
                }
            } while (grade < -1 || grade > 5);

            if (grade == -1) {
                printf("\n");
            } else {
                student_array[selected-1] = grade;
            }
        }
    }

    printf("Student Grade\n");
    for (int i=0; i < student_count; i++) {
        printf("%d", i+1);
        if (student_array[i] == -1) {
            printf("       N/A\n");
        } else {
            printf("%8d\n", student_array[i]);
        }
    }
    return 0;
}
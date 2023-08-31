#include <stdio.h>

int read_integer(void) {
    int number;
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("Invalid input.\n");
    }
    return number;
}

int main() {
    int number;
    float sum = 0;
    int divisor = 0;

    do {
        printf("Enter positive numbers or negative to stop: ");
        number = read_integer();
        if (number >= 0) {
            sum += number;
            divisor++;
        }
    } while (number >= 0);

    float average = sum / divisor;
    printf("You entered %d positive numbers. The average is: %.3f", divisor, average);
    return 0;
}

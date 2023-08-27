#include <stdio.h>
#include <stdbool.h>


int main() {

    float bus_ticket_price;
    float taxi_price;
    float moneys;

    printf("Enter price of bus ticket: ");
    scanf("%f",&bus_ticket_price);

    printf("Enter price of taxi: ");
    scanf("%f", &taxi_price);

    printf("How much money do you have?: ");
    scanf("%f", &moneys);

    bool done = false;

    while(!done) {

        printf("You have %.2f euros left.\n", moneys);

        if((bus_ticket_price > moneys) && (taxi_price > moneys)) {
            printf("Walk.\n");
            done = true;
            break;
        }

        int selection;

        printf("Do you want to take\n");
        printf("1) Bus (%.2f) euros\n", bus_ticket_price);
        printf("2) Taxi (%.2f) euros\n", taxi_price);

        do {
        scanf("%d", &selection);
        } while (selection != 1 && selection != 2);

        switch (selection) {
        case 1:
            if (moneys - bus_ticket_price < 0) {
                printf("You don't have enough money for bus ticket.\n");
            } else {
                moneys = moneys - bus_ticket_price;
                printf("You took the bus.\n");
            }
            break;
        case 2:
            if (moneys - taxi_price < 0) {
                printf("You don't have enough money for taxi.\n");
            } else {
            moneys = moneys - taxi_price;
            printf("You took the taxi.\n");
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
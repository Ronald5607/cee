#include <stdio.h>
#include <stdbool.h>

#define MONTHS 12

int main() {

    float incomes[MONTHS];
    float taxes[MONTHS];

    float tax_rate;
    float income_limit;
    float tax_after_limit;

    printf("Enter tax rate: ");
    scanf("%f", &tax_rate);

    printf("Enter income limit: ");
    scanf("%f", &income_limit);

    printf("Enter tax rate after limit: ");
    scanf("%f", &tax_after_limit);

    for (int i = 0; i<MONTHS; i++) {
        printf("Enter income for month %d: ", i+1);
        scanf("%f", &incomes[i]);
    }
    printf("month    income       tax\n");

    float sum = 0;
    bool is_over = false;
    float rate_used = tax_rate/100;
    for (int i = 0; i<MONTHS; i++) {
        sum += incomes[i];
        if (sum > income_limit && !is_over) {

            float income_over = sum - income_limit;
            float income_under = incomes[i] - income_over;
            float tax = income_under * tax_rate/100 + income_over * tax_after_limit/100;

            printf("%5d %9.2f %9.2f\n", i+1, incomes[i], tax);
            
            rate_used = tax_after_limit/100;
            is_over = true;
        } else {
            float tax = incomes[i] * rate_used;
            printf("%5d %9.2f %9.2f\n", i+1, incomes[i], tax);
        }
    }
}
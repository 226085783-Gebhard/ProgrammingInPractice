#include <stdio.h>

int main() {
    double revenue;
    double expenses;
    double balance;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    balance = revenue - expenses;

    printf("\n--- BUDGET REPORT ---\n");
    printf("Revenue  : $%.2f\n", revenue);
    printf("Expenses : $%.2f\n", expenses);
    printf("Balance  : $%.2f\n", balance);

    return 0;
}
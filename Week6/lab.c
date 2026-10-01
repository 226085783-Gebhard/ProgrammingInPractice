#include <stdio.h>
#include <string.h>

int main() {
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    /* ---------- A. EMPLOYEE SALARIES ---------- */
    float total = 0;
    float highest, lowest, average, target;
    int found = 0;

    printf("=== A. Employee Salaries ===\n");
    for (int i = 0; i < 50; i++) {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
        total = total + salaries[i];
    }

    printf("\nAll salaries:\n");
    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    highest = salaries[0];
    lowest = salaries[0];
    for (int i = 1; i < 50; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }
    average = total / 50;

    printf("\nTotal salary: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &target);
    for (int i = 0; i < 50; i++) {
        if (salaries[i] == target) {
            found = 1;
            printf("\nSalary found at index %d (employee %d).\n", i, i + 1);
            break;
        }
    }
    if (!found) {
        printf("\nSalary not found.\n");
    }

    /* ---------- B. DEPARTMENT BUDGETS ---------- */
    float budgetTotal = 0;
    float budgetAverage;
    float temp;

    printf("\n=== B. Department Budgets ===\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter budget %d: ", i + 1);
        scanf("%f", &budgets[i]);
        budgetTotal = budgetTotal + budgets[i];
    }

    printf("\nAll budgets:\n");
    for (int i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    budgetAverage = budgetTotal / 10;
    printf("\nTotal budget: %.2f\n", budgetTotal);
    printf("Average budget: %.2f\n", budgetAverage);

    /* Bubble sort, lowest to highest */
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted (lowest to highest):\n");
    for (int i = 0; i < 10; i++) {
        printf("Sorted budget %d: %.2f\n", i + 1, budgets[i]);
    }

    /* ---------- C. VEHICLE REGISTRATIONS ---------- */
    char searchReg[20];
    int regFound = 0;

    printf("\n=== C. Vehicle Registrations ===\n");
    for (int i = 0; i < 20; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nAll registrations:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d. %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);
    for (int i = 0; i < 20; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            regFound = 1;
            printf("\nRegistration found at position %d.\n", i + 1);
            break;
        }
    }
    if (!regFound) {
        printf("\nRegistration not found.\n");
    }

    return 0;
}

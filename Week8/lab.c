#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define VAT_RATE 0.15f

/* Supplier data (from Week 7) */
char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* Function prototypes */
void displayWelcome(void);
void displayMenu(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
void addSupplier(void);
void displaySupplier(void);
void searchSupplier(void);
void supplierMenu(void);
void salaryOption(void);
void vatOption(void);
void budgetOption(void);
void employeeOption(void);
int readInt(void);
float readFloat(void);
void readLine(char text[], int size);

int main() {
    int choice;

    displayWelcome();

    do {
        displayMenu();
        choice = readInt();

        switch (choice) {
        case 1:
            salaryOption();
            break;
        case 2:
            vatOption();
            break;
        case 3:
            budgetOption();
            break;
        case 4:
            employeeOption();
            break;
        case 5:
            supplierMenu();
            break;
        case 6:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

/* ---------- Display functions ---------- */

void displayWelcome(void) {
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu(void) {
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

/* ---------- Calculation functions ---------- */

float calculateVAT(float amount) {
    return amount * VAT_RATE;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

/* Returns the position of the employee, or -1 if not found */
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}

/* ---------- Menu option functions ---------- */

void salaryOption(void) {
    float basic, housing, transport;

    printf("Basic salary: ");
    basic = readFloat();
    printf("Housing allowance: ");
    housing = readFloat();
    printf("Transport allowance: ");
    transport = readFloat();

    printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
}

void vatOption(void) {
    float amount;

    printf("Enter amount: ");
    amount = readFloat();
    printf("VAT: %.2f\n", calculateVAT(amount));
}

void budgetOption(void) {
    float revenue, expenses, balance;

    printf("Enter revenue: ");
    revenue = readFloat();
    printf("Enter expenses: ");
    expenses = readFloat();

    balance = calculateBudget(revenue, expenses);
    printf("Budget balance: %.2f\n", balance);

    if (balance > 0) {
        printf("Status: SURPLUS\n");
    } else if (balance < 0) {
        printf("Status: DEFICIT\n");
    } else {
        printf("Status: BALANCED\n");
    }
}

void employeeOption(void) {
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = sizeof(employeeIDs) / sizeof(employeeIDs[0]);
    int id, position;

    printf("Enter employee ID: ");
    id = readInt();

    position = searchEmployee(id, employeeIDs, size);
    if (position == -1) {
        printf("Employee not found.\n");
    } else {
        printf("Employee found at position %d.\n", position);
    }
}

/* ---------- Supplier management (Week 7 module) ---------- */

void supplierMenu(void) {
    int choice;

    do {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice) {
        case 1:
            addSupplier();
            break;
        case 2:
            displaySupplier();
            break;
        case 3:
            searchSupplier();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list is full (%d suppliers).\n", MAX_SUPPLIERS);
        return;
    }

    printf("Enter supplier name: ");
    readLine(supplierNames[supplierCount], 100);
    printf("Enter email: ");
    readLine(supplierEmails[supplierCount], 100);
    printf("Enter phone: ");
    readLine(supplierPhones[supplierCount], 30);
    printf("Enter town: ");
    readLine(supplierTowns[supplierCount], 50);

    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier(void) {
    char description[300];

    if (supplierCount == 0) {
        printf("No suppliers have been added yet.\n");
        return;
    }

    printf("\n--- SUPPLIER DETAILS ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town : %s\n", supplierTowns[i]);

        strcpy(description, supplierNames[i]);
        strcat(description, " operates in ");
        strcat(description, supplierTowns[i]);
        strcat(description, ".");
        printf("%s\n", description);
    }
}

void searchSupplier(void) {
    char key[100];

    if (supplierCount == 0) {
        printf("No suppliers have been added yet.\n");
        return;
    }

    printf("Enter supplier name to search: ");
    readLine(key, 100);

    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(supplierNames[i], key) == 0) {
            printf("Supplier found at position %d.\n", i + 1);
            return;
        }
    }
    printf("Supplier not found.\n");
}

/* ---------- Input helpers ---------- */

int readInt(void) {
    char buffer[100];
    int value;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        exit(0);
    }
    if (sscanf(buffer, "%d", &value) != 1) {
        return -1;
    }
    return value;
}

float readFloat(void) {
    char buffer[100];
    float value;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        exit(0);
    }
    if (sscanf(buffer, "%f", &value) != 1) {
        return 0;
    }
    return value;
}

void readLine(char text[], int size) {
    if (fgets(text, size, stdin) == NULL) {
        exit(0);
    }
    text[strcspn(text, "\n")] = '\0';
}

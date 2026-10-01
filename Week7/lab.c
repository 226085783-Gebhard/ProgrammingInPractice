#include <stdio.h>
#include <string.h>

#define MAX 5

int main() {
    char names[MAX][100];
    char emails[MAX][100];
    char phones[MAX][30];
    char towns[MAX][50];
    char input[100];
    char searchName[100];
    char description[300];
    int count = 0;
    int choice = 0;
    int found;

    do {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        choice = 0;
        sscanf(input, "%d", &choice);

        switch (choice) {
        case 1:
            if (count >= MAX) {
                printf("Supplier list is full (%d suppliers).\n", MAX);
                break;
            }

            printf("Enter supplier name: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            strcpy(names[count], input);

            printf("Enter email: ");
            fgets(emails[count], sizeof(emails[count]), stdin);
            emails[count][strcspn(emails[count], "\n")] = '\0';

            printf("Enter phone: ");
            fgets(phones[count], sizeof(phones[count]), stdin);
            phones[count][strcspn(phones[count], "\n")] = '\0';

            printf("Enter town: ");
            fgets(towns[count], sizeof(towns[count]), stdin);
            towns[count][strcspn(towns[count], "\n")] = '\0';

            count++;
            printf("Supplier added.\n");
            break;

        case 2:
            if (count == 0) {
                printf("No suppliers have been added yet.\n");
                break;
            }
            printf("\n--- SUPPLIER DETAILS ---\n");
            for (int i = 0; i < count; i++) {
                printf("\nSupplier %d\n", i + 1);
                printf("Name : %s\n", names[i]);
                printf("Email: %s\n", emails[i]);
                printf("Phone: %s\n", phones[i]);
                printf("Town : %s\n", towns[i]);

                /* Build a sentence using strcpy and strcat */
                strcpy(description, names[i]);
                strcat(description, " operates in ");
                strcat(description, towns[i]);
                strcat(description, ".");
                printf("%s\n", description);
            }
            break;

        case 3:
            if (count == 0) {
                printf("No suppliers have been added yet.\n");
                break;
            }
            printf("Enter supplier name to search: ");
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(names[i], searchName) == 0) {
                    printf("Supplier found at position %d.\n", i + 1);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Supplier not found.\n");
            }
            break;

        case 4:
            if (count == 0) {
                printf("No suppliers have been added yet.\n");
                break;
            }
            for (int i = 0; i < count; i++) {
                printf("%s - name length: %zu\n", names[i], strlen(names[i]));
            }
            break;

        case 5:
            printf("Goodbye.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

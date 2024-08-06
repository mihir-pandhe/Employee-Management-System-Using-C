#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("\n--- Employee Management System ---\n");
    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Search Employee\n");
    printf("4. Edit Employee\n");
    printf("5. Delete Employee\n");
    printf("6. Exit\n");
    printf("----------------------------------\n");
    printf("Select an option: ");
}

int main()
{
    int choice;
    while (1)
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Add Employee selected.\n");
            break;
        case 2:
            printf("View Employees selected.\n");
            break;
        case 3:
            printf("Search Employee selected.\n");
            break;
        case 4:
            printf("Edit Employee selected.\n");
            break;
        case 5:
            printf("Delete Employee selected.\n");
            break;
        case 6:
            printf("Exiting system...\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    return 0;
}

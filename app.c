#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

typedef struct
{
    int id;
    char name[50];
    char department[50];
    double salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee()
{
    if (employeeCount < MAX_EMPLOYEES)
    {
        printf("Enter Employee ID: ");
        scanf("%d", &employees[employeeCount].id);
        printf("Enter Employee Name: ");
        scanf("%s", employees[employeeCount].name);
        printf("Enter Employee Department: ");
        scanf("%s", employees[employeeCount].department);
        printf("Enter Employee Salary: ");
        scanf("%lf", &employees[employeeCount].salary);
        employeeCount++;
        printf("Employee added successfully.\n");
    }
    else
    {
        printf("Employee list is full.\n");
    }
}

void viewEmployees()
{
    if (employeeCount == 0)
    {
        printf("No employees to display.\n");
        return;
    }

    printf("\n--- Employee List ---\n");
    for (int i = 0; i < employeeCount; i++)
    {
        printf("ID: %d, Name: %s, Department: %s, Salary: %.2lf\n",
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
    printf("---------------------\n");
}

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
            addEmployee();
            break;
        case 2:
            viewEmployees();
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

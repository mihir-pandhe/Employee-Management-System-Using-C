#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void addEmployee();
void viewEmployees();
void searchEmployeeByID();
void searchEmployeeByName();
void editEmployee();
void deleteEmployee();
void menu();
void executeChoice(int choice);
int getIntInput(const char *prompt);
double getDoubleInput(const char *prompt);
void clearInputBuffer();

int main()
{
    int choice;
    while (1)
    {
        menu();
        choice = getIntInput("Select an option: ");
        executeChoice(choice);
    }
    return 0;
}

void addEmployee()
{
    if (employeeCount < MAX_EMPLOYEES)
    {
        employees[employeeCount].id = getIntInput("Enter Employee ID: ");
        printf("Enter Employee Name: ");
        scanf("%49s", employees[employeeCount].name);
        printf("Enter Employee Department: ");
        scanf("%49s", employees[employeeCount].department);
        employees[employeeCount].salary = getDoubleInput("Enter Employee Salary: ");
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

void searchEmployeeByID()
{
    int id = getIntInput("Enter Employee ID to search: ");
    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("Employee found: ID: %d, Name: %s, Department: %s, Salary: %.2lf\n",
                   employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee with ID %d not found.\n", id);
    }
}

void searchEmployeeByName()
{
    char name[50];
    int found = 0;
    printf("Enter Employee Name to search: ");
    scanf("%49s", name);
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employees[i].name, name) == 0)
        {
            printf("Employee found: ID: %d, Name: %s, Department: %s, Salary: %.2lf\n",
                   employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee with Name %s not found.\n", name);
    }
}

void editEmployee()
{
    int id = getIntInput("Enter Employee ID to edit: ");
    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("Editing Employee with ID: %d\n", id);
            printf("Enter new Employee Name: ");
            scanf("%49s", employees[i].name);
            printf("Enter new Employee Department: ");
            scanf("%49s", employees[i].department);
            employees[i].salary = getDoubleInput("Enter new Employee Salary: ");
            printf("Employee details updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee with ID %d not found.\n", id);
    }
}

void deleteEmployee()
{
    int id = getIntInput("Enter Employee ID to delete: ");
    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            for (int j = i; j < employeeCount - 1; j++)
            {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee with ID %d not found.\n", id);
    }
}

void menu()
{
    printf("\n--- Employee Management System ---\n");
    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Search Employee by ID\n");
    printf("4. Search Employee by Name\n");
    printf("5. Edit Employee\n");
    printf("6. Delete Employee\n");
    printf("7. Exit\n");
    printf("----------------------------------\n");
}

void executeChoice(int choice)
{
    switch (choice)
    {
    case 1:
        addEmployee();
        break;
    case 2:
        viewEmployees();
        break;
    case 3:
        searchEmployeeByID();
        break;
    case 4:
        searchEmployeeByName();
        break;
    case 5:
        editEmployee();
        break;
    case 6:
        deleteEmployee();
        break;
    case 7:
        printf("Exiting system...\n");
        exit(0);
    default:
        printf("Invalid option. Please try again.\n");
        break;
    }
}

int getIntInput(const char *prompt)
{
    int input;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1)
        {
            clearInputBuffer();
            return input;
        }
        else
        {
            printf("Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
        }
    }
}

double getDoubleInput(const char *prompt)
{
    double input;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%lf", &input) == 1)
        {
            clearInputBuffer();
            return input;
        }
        else
        {
            printf("Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
        }
    }
}

void clearInputBuffer()
{
    while (getchar() != '\n')
        ;
}

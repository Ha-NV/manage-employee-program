/**
 * @file manage_employee.c
 * @brief This file contains the implementation of functions to manage employees and departments.
 *
 * This file contains the implementation of functions to manage employees and departments. It includes functions to:
 * - Display a main menu to the user.
 * - Add a new employee to the system.
 * - Display a list of employees sorted by working performance.
 * - Display a list of departments.
 * - Delete an employee from the system.
 * - Delete a department from the system.
 * - Display the payroll of all employees.
 * - Check if a string is empty.
 * - Calculate the salary of an employee.
 * - Clear the console screen.
 * - Format a number with commas.
 *
 * The file also includes the definition of structures to represent employees and departments,
 * as well as the definition of some constants.
 * @author Viet Ha Nguyen
 * @date 3/20/2024
 * @bug No known bugs
 */

#include <stdio.h>              /* Include standard input and output library for printf, printf, ... */
#include <stdint.h>             /* Include standard integer types library for fixed-width integers like int8_t, uint64_t, etc. */
#include <string.h>             /* Include string manipulation library for functions like strlen, strcmp,... */
#include "manage_employee.h"    /* Include the header file for this specific employee management module. */
#include "input_handler.h"		/* Include input handler header file for handling user input */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MAX_EMPLOYEES 100       /* Maximum number of employees that can be handled. */
#define MAX_DEPARTMENTS 50      /* Maximum number of departments that can be handled. */
#define MAX_ID_LENGTH 100       /* Maximum length of ID strings for employees and departments. */
#define MAX_NAME_LENGTH 50      /* Maximum length of name strings for employees. */

/**
 * @brief Structure to represent an employee.
 *
 * This structure holds information about an employee including their ID, name,
 * base salary, number of working days, department ID, working performance, bonus,
 * and number of days they came late to work.
 */
typedef struct Employee {
    int8_t id[MAX_ID_LENGTH];              /* Employee's ID. */
    int8_t name[MAX_NAME_LENGTH];          /* Employee's name. */
    uint64_t salary_base;                   /* Employee's base salary. */
    uint16_t working_days;                  /* Number of days the employee worked. */
    int8_t department_id[MAX_ID_LENGTH];   /* ID of the department that the employee belongs to. */
    float working_performance;              /* Employee's working performance. */
    uint64_t bonus;                         /* Bonus received by the employee. */
    uint16_t late_coming_days;              /* Number of days the employee came late to work. */
} Employee_t;

/**
 * @brief Structure to represent a department.
 *
 * This structure holds information about a department including its ID and the bonus salary
 * allocated to the department.
 */
typedef struct Department {
    int8_t id[MAX_ID_LENGTH];              /* Department's ID. */
    uint64_t bonus_salary;                  /* Bonus salary allocated to the department. */
} Department_t;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint64_t calculateSalary(struct Employee Employee_param);


/*******************************************************************************
 * Variables
 ******************************************************************************/
Employee_t employees_arr[MAX_EMPLOYEES];        /* Array to store employee records */
Department_t departments_arr[MAX_DEPARTMENTS];  /* Array to store department records */
uint32_t total_employees = 0;                   /* Counter for the total number of employees currently stored */
uint32_t total_departments = 0;                 /* Counter for the total number of departments currently stored */


/*******************************************************************************
 * Definition
 ******************************************************************************/
/**
 * @brief Displays the main menu options to the user.
 *
 * This function prints the main menu options to the console, allowing the user
 * to navigate through the program's features. The options include viewing lists
 * of employees and departments, adding a new employee, deleting an employee or
 * department by their respective IDs, showing the payroll, and exiting the program.
 */
void showMenu()
{
    printf("\n");
    printf("*----------PROGRAM TO MANAGE EMPLOYEES----------*\n");
    printf("|                                               |\n");
    printf("| 1. Shows list of employees.                   |\n");
    printf("| 2. Shows list of departments.                 |\n");
    printf("| 3. Add new employee.                          |\n");
    printf("| 4. Delete employee by employee's ID.          |\n");
    printf("| 5. Delete department by department's ID.      |\n");
    printf("| 6. Shows payroll.                             |\n");
    printf("| 7. Exit program.                              |\n");
    printf("|_______________________________________________|\n");
    printf("\n");
}

/**
 * @brief Shows the list of employees sorted by working performance.
 *
 * This function checks if there are employees to show or not and then sorts them
 * based on working performance.
 * It then prints out each employee's details. Fields such as bonus, salary base
 * will be formatted with "," to illustrate money unit
 * If there are no employee, it prints a message indicating so.
 */
void showEmployees()
{
    uint32_t i = 0;         /* Initialize loop counter */
    uint32_t j = 0;         /* Initialize loop counter */
    Employee_t temp;        /* Temporary variable to hold employee details during sorting */

    /* Check if employees have */
    if (total_employees == 0)
    {
        /* Print a message if there are no employees */
        printf("No employees to show!!!\n");
    }
    else
    {
        // Loop to sort employees based on working performance
        for (i = 0; i < total_employees - 1; i++)
        {
            for (j = i + 1; j < total_employees; j++)
            {
                if (employees_arr[i].working_performance < employees_arr[j].working_performance)
                {
                    temp = employees_arr[i];
                    employees_arr[i] = employees_arr[j];
                    employees_arr[j] = temp;
                }
            }
        }

        /* Loop to show each employee's details */
        for (i = 0; i < total_employees; i++)
        {
            printf("----\n");
            /* Print the employee's ID */
            printf("ID: %s\n", employees_arr[i].id);
            /* Print the department's ID */
            printf("Department's ID: %s\n", employees_arr[i].department_id);
            /* Print the employee's full name */
            printf("Full name: %s\n", employees_arr[i].name);
            /* Print the employee's salary base in VND, value formatted with ","
            (using formatNumberWithCommas() function) to illustrate money unit */
            printf("Salary base: %s (VND)\n", formatNumberWithCommas(employees_arr[i].salary_base));
            /* Print the number of working days */
            printf("Number of working days: %hu (days)\n", employees_arr[i].working_days);
            /* Print the employee's working performance */
            printf("Working performance: %.1f\n", employees_arr[i].working_performance);
            /* Print the employee's bonus in VND, value formatted with ","
            (using formatNumberWithCommas() function) to illustrate money unit */
            printf("Bonus: %s (VND)\n", formatNumberWithCommas(employees_arr[i].bonus));
            /* Print the number of late working days */
            printf("Number of late working days: %hu (days)\n", employees_arr[i].late_coming_days);
            printf("----\n");
        }
    }
}

/**
 * @brief Shows the list of departments.
 *
 * This function checks if there are any departments to show. If there are, it loops
 * through each department and prints their details.
 * If there are no departments, it prints a message indicating so.
 */
void showDepartments()
{
    uint32_t i = 0;             /* Index for looping through departments */

    /* Check if there are any departments */
    if (total_departments == 0)
    {
        /* Print a message if there are no departments */
        printf("No department to show!!!\n");
    }
    else
    {
        /* Loop through each department */
        for (i = 0; i < total_departments; i++)
        {
            printf("----\n");
            /* Print the department's ID */
            printf("Department's ID: %s\n", departments_arr[i].id);
            /* Print the department's bonus, value formatted with "," to illustrate money */
            printf("Department's bonus: %s (VND)\n", formatNumberWithCommas(departments_arr[i].bonus_salary));
            printf("----\n");
        }
    }
}


/**
 * @brief Adds a new employee to the program
 *
 * This function prompts the user for employee details, checks for unique ID,
 * and adds the employee to the global employees array. If the department ID
 * does not exist, it prompts for department details and adds a new department.
 */
void addEmployee()
{
    uint32_t i = 0;                         /* Index for looping through employees */
    uint16_t id_exists = 0;                 /* Flag to check if ID already exists */
    uint16_t department_id_exists = 1;      /* Flag to check if department ID exists */
    int8_t buffer[100];                    /* Buffer to store input temporarily */
    Employee_t newEmployee;                 /* Struct to store new employee details */
    uint16_t validInput = 0;                /* Flag to check if input is valid */

    printf("Adding new employee . . . \n");
    /* Loop to ensure unique and non-empty employee's ID is entered */
    do
    {
        id_exists = 0;                      /* Reset flag for each iteration */

        printf("Enter ID: ");
        fflush(stdin);
        /* Get ID from user */
        fgets(newEmployee.id, sizeof(newEmployee.id), stdin);
        /* Check if ID field is empty */
        if (isStringEmpty(newEmployee.id) == 1)
        {
            /* Print a message if the input is empty */
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
        else
        {
            /* Loop through existing employees */
            for (i = 0; i < total_employees; i++)
            {
                /* ID match found */
                if (strcmp(newEmployee.id, employees_arr[i].id) == 0)
                {
                    /* Set flag if ID match found */
                    id_exists = 1;
                    printf("\nID already exists!!!\n\n");
                    printf("Please enter another ID again.\n");
                    /* Exit loop instead of using break statement*/
                    i = total_employees;
                }
            }
        }
    } /* Repeat if ID is empty or exists */
    while (isStringEmpty(newEmployee.id) == 1 || id_exists == 1);

    /* This loop ensures that the employee's department ID is entered and is not left blank */
    do
    {
        printf("Enter department's ID: ");
        fflush(stdin);
        /* Get department ID from user */
        fgets(newEmployee.department_id, sizeof(newEmployee.department_id), stdin);
        /* Check if department ID is empty */
        if (isStringEmpty(newEmployee.department_id) == 1)
        {
            /* Print a message if the input is empty */
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
        else
        {
            /* Do nothing */
        }
    } /* Repeat if department ID is empty */
    while ((isStringEmpty(newEmployee.department_id) == 1));

    /* This loop ensures that the employee's full name is entered and is not left blank */
    do
    {
        validInput = 0;
        printf("Enter your full name: ");
        fflush(stdin);
        /* Get name from user */
        fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
        /* Remove newline character */
        newEmployee.name[strcspn(newEmployee.name, "\n")] = 0;
        if (strlen(newEmployee.name) > 0)
        {
            validInput = 1;
        }
        else
        {
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
    } /* Repeat if input is empty*/
    while (validInput == 0);

    /* This loop ensures that the employee's salary base is entered and is not left blank */
    do
    {
        printf("Enter salary base: ");
        fflush(stdin);
        /* Get salary base from user */
        fgets(buffer, sizeof(buffer), stdin);
        /* Check if input is empty */
        if (isStringEmpty(buffer) == 1)
        {
            /* Print a message if the input is empty */
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
        else if (isWholeNumber(buffer) == 0)
        {
            /* Print a message if the input is not a whole number more than 0 */
            printf("\nPlease enter a whole number more than 0 !!!\n");
        }
        else
        {
            /* Parse salary base from buffer */
            sscanf(buffer, "%llu", &newEmployee.salary_base);
        }
    } /* Repeat if input is empty or is not a whole number more than 0 */
    while ((isStringEmpty(buffer) == 1) || (isWholeNumber(buffer) == 0));

    /* This loop ensures that the employee's working day is entered and is not left blank */
    do
    {
        printf("Enter number of working days: ");
        fflush(stdin);
        /* Get number of working days from user */
        fgets(buffer, sizeof(buffer), stdin);
        /* Check if input is empty */
        if (isStringEmpty(buffer) == 1)
        {
            /* Print a message if the input is empty */
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
        /* Check if input is whole number more than 0 */
        else if (isWholeNumber(buffer) == 0)
        {
            /* Print a message if the input is not a whole number more than 0 */
            printf("\nPlease enter a whole number more than 0 !!!\n");
        }
        else
        {
            /* Parse number of working days from buffer */
            sscanf(buffer, "%hu", &newEmployee.working_days);
        }
    } /* Repeat if input is empty or is not a whole number more than 0 */
    while ((isStringEmpty(buffer) == 1) || (isWholeNumber(buffer) == 0));

    /* This loop ensures that the employee's working performance is entered and is not left blank */
    do
    {
        validInput = 0;
        printf("Enter working performance: ");
        fflush(stdin);
        /* Get working performance from user */
        fgets(buffer, sizeof(buffer), stdin);
        /* Check if input is empty */
        if (isStringEmpty(buffer) == 1)
        {
            /* Print a message if the input is empty */
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
        else
        {
            /* Parse working performance from buffer */
            sscanf(buffer, "%f", &newEmployee.working_performance);
            /* Check if input more than 0 */
            if (newEmployee.working_performance > 0)
            {
                /* If input more than 0, set flag to exit loop */
                validInput = 1;
            }
            else
            {
                printf("You must enter a number that more than 0 !!!\n");
            }
        }
    } while (validInput == 0);   /* Repeat if input is empty */

    /* This loop ensures that the employee's bonus is entered and is not left blank */
    do
    {
        printf("Enter bonus: ");
        fflush(stdin);
        /* Get bonus from user */
        fgets(buffer, sizeof(buffer), stdin);
        /* Check if input is empty */
        if (isStringEmpty(buffer) == 1)
        {
            /* Print a message if the input is empty */
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
        else if (isWholeNumber(buffer) == 0)
        {
            /* Print a message if the input is not a whole number more than 0 */
            printf("\nPlease enter a whole number more than 0 !!!\n");
        }
        else
        {
            /* Parse bonus from buffer */
            sscanf(buffer, "%llu", &newEmployee.bonus);
        }
    } /* Repeat if input is empty or is not a whole number more than 0 */
    while ((isStringEmpty(buffer) == 1) || (isWholeNumber(buffer) == 0));

    /* This loop ensures that the employee's late coming days is entered and is not left blank */
    do
    {
        printf("Enter number of late coming days: ");
        fflush(stdin);
        /* Get number of late coming days from user */
        fgets(buffer, sizeof(buffer), stdin);
        /* Check if input is empty */
        if (isStringEmpty(buffer) == 1)
        {
            /* Print a message if the input is empty */
            printf("\nYou must not leave blank this information ...\n");
            printf("\nPlease enter again ...\n");
        }
        else if (isWholeNumber(buffer) == 0)
        {
            /* Print a message if the input is not a whole number more than 0 */
            printf("\nPlease enter a whole number more than 0 !!!\n");
        }
        else
        {
            /* Parse number of late coming days from buffer */
            sscanf(buffer, "%hu", &newEmployee.late_coming_days);
        }
    } /* Repeat if input is empty or is not a whole number more than 0 */
    while ((isStringEmpty(buffer) == 1) || (isWholeNumber(buffer) == 0));

    /* Add new employee to array */
    employees_arr[total_employees] = newEmployee;
    /* Increment total employees count */
    total_employees += 1;
    printf("----\n");
    printf("Added new employee ...\n\n");

    /* Check if department exists */
    /* Loop through existing departments */
    for (i = 0; i < total_departments; i++)
    {
        /* Check if department ID matches */
        if (strcmp(newEmployee.department_id, employees_arr[i].department_id) != 0)
        {
            /* Set flag if department ID does not match */
            department_id_exists = 0;
            /* Exit loop */
            i = total_departments;
        }
    }
    /* If department ID does not exist or no departments exist */
    if ((department_id_exists == 0) || (total_departments == 0))
    {
        printf("Department's ID does not exist, create a new one ...\n");

        /* Struct to store new department details */
        Department_t newDepartment;

        /* This loop ensures that the department bonus is entered and is not left blank */
        do
        {
            printf("Enter department's bonus: ");
            fflush(stdin);
            /* Get department's bonus from user */
            fgets(buffer, sizeof(buffer), stdin);
            /* Check if input is empty */
            if (isStringEmpty(buffer) == 1)
            {
                printf("You must not leave blank this information ...\n");
                printf("Please enter again ...\n");
            }
            else if (isWholeNumber(buffer) == 0)
            {
                /* Print a message if the input is not a whole number more than 0 */
                printf("\nPlease enter a whole number more than 0 !!!\n");
            }
            else
            {
                /* Parse department's bonus from buffer */
                sscanf(buffer, "%llu", &newDepartment.bonus_salary);
            }
        } /* Repeat if input is empty or is not a whole number more than 0 */
        while ((isStringEmpty(buffer) == 1) || (isWholeNumber(buffer) == 0));

        /* Copy department ID from employee to new department */
        strcpy(newDepartment.id, newEmployee.department_id);

        /* Add new department to array */
        departments_arr[total_departments] = newDepartment;

        /* Increment total departments count */
        total_departments += 1;

        printf("----\n");
        printf("Created new department ...\n");
        printf("Added new employee ...\n");
    }
}


/**
 * @brief Deletes an employee from program.
 *
 * This function prompts the user for the ID of the employee they want to delete.
 * If the ID is found, the employee is removed from the global employees array.
 * If the ID is not found, a message is printed indicating so.
 */
void deleteEmployee()
{
    int8_t id_to_Delete[MAX_ID_LENGTH];    /* Buffer to store the ID of the employee to delete */
    uint32_t i = 0;                         /* Index for looping through employees */
    uint32_t j = 0;                         /* Index for shifting employees after the deleted one */
    int16_t found = 0;                      /* Flag to check if the employee with the given ID is found */

    /* Check if there are any employees */
    if (total_employees == 0)
    {
        /* Print a message if there are no employees */
        printf("No employee to delete!!!");
    }
    else
    {
        /* This loop ensures that the ID is entered and is not left blank */
        do
        {
            printf("Input employee's ID which you want to delete: ");
            fflush(stdin);
            /* Get the ID from the user */
            fgets(id_to_Delete, sizeof(id_to_Delete), stdin);
            /* Check if the input is empty */
            if (isStringEmpty(id_to_Delete) == 1)
                    {
                        /* Print a message if the input is empty */
                        printf("\nYou must not leave blank this information ...\n");
                        printf("\nPlease enter again ...\n");
                    }
            else
            {
                /* Do nothing */
            }
        } while (isStringEmpty(id_to_Delete) == 1);  /* Repeat if input is empty */

        /* Loop through each employee */
        for (i = 0; i < total_employees; i++)
        {
            /* Check if the employee's ID matches the ID to delete */
            if (strcmp(id_to_Delete, employees_arr[i].id) == 0)
            {
                /* Shift the employees after the deleted one */
                for (j = i; j < total_employees - 1; j++)
                {
                    employees_arr[j] = employees_arr[j + 1];
                }
                /* Decrement the total number of employees */
                total_employees -= 1;
                /* Set the flag to indicate that the employee with the given ID is found */
                found = 1;

                /* Exit for-loop instead of using break statement */
                i = total_employees;
            }
            else
            {
                /* Do nothing */
            }
        }

        /* Check if the employee with the given ID is found */
        if (found == 1)
        {
            /* Print a message if the employee is deleted successfully */
            printf("Deleted successfully . . .\n");
        }
        else
        {
            /* Print a message if no employee has the given ID */
            printf("No employee has ID %s\n", id_to_Delete);
        }
    }
}

/**
 * @brief Deletes a department from the program.
 *
 * This function prompts the user for the ID of the department to delete,
 * checks if the department exists, and deletes it if it does not have any employees.
 * If the department has employees, it prints a message indicating that the department cannot be deleted.
 * If the department does not exist, it prints a message indicating that the department does not exist.
 */
void deleteDepartment()
{
    int8_t idDepartment_to_Delete[MAX_ID_LENGTH];  /* Buffer to store the ID of the department to delete */
    uint32_t i = 0;                 /* Index for looping through departments */
    uint32_t j = 0;                 /* Index for looping through employees */
    uint32_t k = 0;                 /* Index for shifting departments after the deleted one */
    int16_t found = 0;              /* Flag to indicate if the department with the given ID is found */
    int16_t employee_exist = 0;     /* Flag to indicate if the department has employees */

    /* Check if there are any departments to delete */
    if (total_departments == 0)
    {
        /* Print a message if there are no departments to delete */
        printf("No department to delete!!!");
    }
    else
    {
        /* This loop ensures that the deparment ID is entered and is not left blank */
        do
        {
            printf("Input department's ID which you want to delete: ");
            fflush(stdin);
            /* Get the department ID from the user */
            fgets(idDepartment_to_Delete, sizeof(idDepartment_to_Delete), stdin);
            /* Check if the input is empty */
            if (isStringEmpty(idDepartment_to_Delete) == 1)
                    {
                        /* Print a message if the input is empty */
                        printf("\nYou must not leave blank this information ...\n");
                        printf("\nPlease enter again ...\n");
                    }
            else
            {
                /* Do nothing */
            }
        } while (isStringEmpty(idDepartment_to_Delete) == 1);   /* Repeat if input is empty */

        /* Loop through each department */
        for (i = 0; i < total_departments; i++)
        {
            /* Check if the department's ID matches the ID to delete */
            if (strcmp(idDepartment_to_Delete, departments_arr[i].id) == 0)
            {
                /* Loop through each employee */
                for (j = 0; j < total_employees; j++)
                {
                    /* Check if there are employee who is in department want to delete */
                    if (strcmp(departments_arr[i].id, employees_arr[j].department_id) == 0)
                    {
                        /* Set the flag to indicate that the department has employees */
                        employee_exist = 1;
                        /* Set the flag to indicate that the department with the given ID is found */
                        found = 1;
                        /* Exit for-loop instead of using break statement */
                        j = total_employees;
                        i = total_departments;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }

                /* Check if the department has no employees */
                if (employee_exist == 0)
                {
                    /* Shift the departments after the deleted one */
                    for (k = i; k < total_departments - 1; k++)
                    {
                        departments_arr[k] = departments_arr[k+1];
                    }
                    /* Decrement the total number of departments */
                    total_departments -= 1;
                    /* Set the flag to indicate that the department with the given ID is found */
                    found = 1;
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* code */
            }
        }

        /* Check if the department with the given ID is found and has no employees */
        if (found == 1 && employee_exist == 0)
        {
            /* Print a message if the department is deleted successfully */
            printf("Deleted department successfully ...\n");
        }
        /* Check if the department with the given ID is found but has employees */
        else if (found == 1 && employee_exist == 1)
        {
            /* Print a message if the department has employees */
            printf("You cannot delete a department that has employees\n");
        }
        else
        {
            /* Print a message if no department has the given ID */
            printf("No department has ID %s\n", idDepartment_to_Delete);
        }
    }
}

/**
 * @brief Shows the payroll of all employees.
 *
 * This function checks if there are any employees to show the payroll.
 * If there are, it loops through each employee, calculates their actual salary by using
 * static function calculateSalary() and prints their details.
 * If there are no employees, it prints a message indicating so.
 */
void showPayroll()
{
    uint32_t i = 0;                     /* Index for looping through employees */
    uint64_t actual_salary = 0;         /* Actual salary of the employee */

    /* Check if there are any employees */
    if (total_employees == 0)
    {
        /* Print a message if there are no employees */
        printf("No employee to show payroll!!!\n");
    }
    else
    {
        /* Loop through each employee */
        for (i = 0; i < total_employees; i++)
        {
            /* Calculate the actual salary of the employee using calculateSalary() function */
            actual_salary = calculateSalary(employees_arr[i]);

            printf("\n----\n");
            /* Print the employee's ID */
            printf("ID: %s\n", employees_arr[i].id);
            /* Print the actual salary of the employee, this value is formatted with commas
            to illustrate money */
            printf("Actual salary received: %s (VND)\n", formatNumberWithCommas(actual_salary));
            printf("----\n");
        }
    }
}

/**
 * @brief This function calculates the salary of an employee based on their performance and other factors.
 *
 * This function takes an Employee_t struct as a parameter and calculates the salary based on
 * the employee's performance, working days, bonus, and other factors.
 * It returns the calculated salary as a unsigned long long integer.
 *
 * @param Employee_param The employee for whom the salary is to be calculated.
 * @return unsigned long long integer The calculated salary.
 */
static uint64_t calculateSalary(struct Employee Employee_param)
{
    uint32_t i = 0;                         /* Index for looping through departments */
    uint64_t bonus_department = 0;          /* Bonus allocated to the department */
    uint64_t late_coming_penalty = 0;       /* Penalty for late coming */
    uint64_t income_without_bonus = 0;      /* Income without bonus */
    uint64_t total_income = 0;              /* Total income */
    uint64_t totalIncome_without_tax = 0;   /* Total income without tax */
    uint64_t tax = 0;                       /* Tax */
    uint64_t actual_salary = 0;             /* Actual salary */

    /* Find department's bonus */
    /* Loop through existing departments */
    for (i = 0; i < total_departments; i++)
    {
        /* Check if department ID matches */
        if (strcmp(Employee_param.department_id, departments_arr[i].id) == 0)
        {
            /* Set bonus_department to the bonus of the matching department */
            bonus_department = departments_arr[i].bonus_salary;
        }
    }

    /* Calculate late_coming_penalty */
    /* Check if the number of late coming days is less than or equal to 3 */
    if (Employee_param.late_coming_days <= 3)
    {
        late_coming_penalty = Employee_param.late_coming_days * 10000;
    }
    else
    {
        late_coming_penalty = Employee_param.late_coming_days * 20000;
    }

    /* Calculate income_without_bonus */
    income_without_bonus = (Employee_param.salary_base * Employee_param.working_days) * Employee_param.working_performance;
    /* Calculate total_income */
    total_income = income_without_bonus + Employee_param.bonus + bonus_department - late_coming_penalty;
    /* Calculate totalIncome_without_tax */
    totalIncome_without_tax = total_income * 0.895;

    /* Calculate tax */
    /* Check if totalIncome_without_tax is greater than 0 and less than or equal to 11000000 */
    if (totalIncome_without_tax > 0 && totalIncome_without_tax <= 11000000)
    {
        tax = 0;
    }
    /* Check if totalIncome_without_tax is greater than 11000000 and less than or equal to 16000000 */
    else if (totalIncome_without_tax > 11000000 && totalIncome_without_tax <= 16000000)
    {
        tax = totalIncome_without_tax * 0.05;
    }
    else
    {
        tax = totalIncome_without_tax * 0.1;
    }

    /* Calculate actual_salary */
    actual_salary = totalIncome_without_tax - tax;

    return actual_salary;
} /* EOF */


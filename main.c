/**
 * @file main.c
 * @brief This file contains the main function of the program.
 *
 * This file contains the main function of the program. It initializes a variable to hold the user's choice,
 * and then enters a loop to display the main menu, get the user's choice, and execute the corresponding function.
 * The loop continues until the user chooses to exit the program.
 * @author Viet Ha Nguyen
 * @date 3/20/2024
 * @bug No known bugs
 */
#include <stdio.h>            /* Include standard input and output library for printf, scanf, ... */
#include <stdint.h>           /* Include standard integer types library for fixed-width integers like int8_t, uint64_t, etc. */
#include "input_handler.h"    /* Include input handler header file for handling user input */
#include "manage_employee.h"  /* Include manage employee header file for managing employees */

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief The main function of the program.
 *
 * This function is the entry point of the program. It initializes a variable to hold the user's choice,
 * and then enters a loop to display the main menu, get the user's choice, and execute the corresponding function.
 * The loop continues until the user chooses to exit the program.
 *
 * @return 0 if the program exits successfully.
 */

int main(void)
{
    int8_t choice;             /* Variable to hold the user's choice */

    do
    {
        /* Display the main menu */
        showMenu();
        printf("Please select your desired function: ");
        /* Get the user's choice */
        choice = getSingleCharInput();
        printf("---------------------------------\n");
        switch (choice) {
            case '1':
                /* Show the list of employees */
                showEmployees();
                /* Clear the console screen */
                clear_console();
                break;
            case '2':
                /* Show the list of departments */
                showDepartments();
                /* Clear the console screen */
                clear_console();
                break;
            case '3':
                /* Add a new employee */
                addEmployee();
                // /* Clear the console screen */
                clear_console();
                break;
            case '4':
                /* Delete an employee */
                deleteEmployee();
                /* Clear the console screen */
                clear_console();
                break;
            case '5':
                /* Delete a department */
                deleteDepartment();
                /* Clear the console screen */
                clear_console();
                break;
            case '6':
                /* Display the payroll of all employees */
                showPayroll();
                /* Clear the console screen */
                clear_console();
                break;
            case '7':
                /* Exit the program */
                printf("Exit program.\n");
                break;
            default:
                /* Prompt the user to enter a valid choice */
                printf("Input is not valid. Please enter again!!!\n");
                /* Clear the console screen */
                clear_console();
        }
    } /* Repeat until the user chooses to exit the program */
    while (choice != '7');

    /* Return 0 to indicate successful program exit */
    return 0;
} /* EOF */


/**
 * @file manage_employee.h
 * @brief This file contains the function prototypes for managing employees.
 *
 * This file contains the function prototypes for managing employees. It includes
 * functions to display the main menu, show the list of employees, show the list of departments,
 * add a new employee, delete an employee, and delete a department.
 *
 * @author Viet Ha Nguyen
 * @date 3/30/2024
 * @bug No known bugs
 */

#ifndef MANAGE_EMPLOYEE_H
#define MANAGE_EMPLOYEE_H

/*******************************************************************************
 * Prototype
 ******************************************************************************/
void showMenu();

/**
 * @brief Shows the list of employees sorted by working performance.
 *
 * This function checks if there are employees to show or not and then sorts them
 * based on working performance.
 * It then prints out each employee's details. Fields such as bonus, salary base
 * will be formatted with "," to illustrate money unit
 * If there are no employee, it prints a message indicating so.
 */
void showEmployees();

/**
 * @brief Shows the list of departments.
 *
 * This function checks if there are any departments to show. If there are, it loops
 * through each department and prints their details.
 * If there are no departments, it prints a message indicating so.
 */
void showDepartments();

/**
 * @brief Adds a new employee to the program
 *
 * This function prompts the user for employee details, checks for unique ID,
 * and adds the employee to the global employees array. If the department ID
 * does not exist, it prompts for department details and adds a new department.
 */
void addEmployee();

/**
 * @brief Deletes an employee from program.
 *
 * This function prompts the user for the ID of the employee they want to delete.
 * If the ID is found, the employee is removed from the global employees array.
 * If the ID is not found, a message is printed indicating so.
 */
void deleteEmployee();

/**
 * @brief Deletes a department from the program.
 *
 * This function prompts the user for the ID of the department to delete,
 * checks if the department exists, and deletes it if it does not have any employees.
 * If the department has employees, it prints a message indicating that the department cannot be deleted.
 * If the department does not exist, it prints a message indicating that the department does not exist.
 */
void deleteDepartment();

/**
 * @brief Shows the payroll of all employees.
 *
 * This function checks if there are any employees to show the payroll.
 * If there are, it loops through each employee, calculates their actual salary by using
 * static function calculateSalary() and prints their details.
 * If there are no employees, it prints a message indicating so.
 */
void showPayroll();

#endif /* MANAGE_EMPLOYEE_H */


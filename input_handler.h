/**
 * @file input_handler.h
 * @brief This file contains the function prototypes for handling user input.
 *
 * This file contains the function prototypes for handling user input. It includes
 * functions to get a single character input, format a number with commas, check if a string is empty,
 * and check if a string is a whole number.
 *
 * @author Viet Ha Nguyen
 * @date 3/30/2024
 * @bug No known bugs
 */
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

/*******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include <stdio.h>           /* Include standard input and output library for printf, printf, ... */
#include <stdbool.h>         /* for bool datatype */
#include <string.h>          /* for strcspn() function */
#include <ctype.h>           /* for isdigit () function */
#include <stdint.h>          /* Include standard integer types library for fixed-width integers like int8_t, uint64_t, etc. */

/*******************************************************************************
 * Prototype
 ******************************************************************************/
/**
 * @brief Gets a single character input from the user.
 *
 * This function prompts the user to enter a single character.
 * It then checks if the input is valid and if not, prompts the user to try again.
 * Once a valid input is received, it returns the first character of the input.
 *
 * @return character The first character of the user's input.
 */
int8_t getSingleCharInput();


/**
 * @brief Formats a number with commas.
 *
 * This function takes a number as input and formats it with commas.
 * It then returns the formatted number as a string.
 *
 * @param number The number to be formatted.
 * @return string The formatted number as a string.
 */
int8_t* formatNumberWithCommas(uint64_t number);


/**
 * @brief Checks if a string is empty.
 *
 * This function checks if a string is empty by removing newline and space characters and
 * then checking the length.
 * If the string is empty, it returns 1, otherwise it returns 0.
 *
 * @param str The string to check.
 * @return 1 if the string is empty, 0 if it is not.
 */
uint32_t isStringEmpty(int8_t *str);


/**
 * @brief This function checks if a string represents a whole number more than 0.
 * @param string_number The string to be checked.
 * @return 1 if the string represents a whole number more than 0, 0 otherwise.
 */
uint32_t isWholeNumber(int8_t *string_number);


/**
 * @brief Clears the console screen.
 *
 * This function prompting the user to press any key to continue.
 * It then clears the input buffer, waits for a key press, and clears the console screen.
 */
void clear_console();

#endif /* INPUT_HANDLER_H */


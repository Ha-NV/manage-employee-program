/**
 * @file input_handler.c
 * @brief This file contains the implementation of the functions for handling user input.
 *
 * This file contains the implementation of the functions for handling user input. It includes
 * functions to get a single character input, format a number with commas, check if a string is empty,
 * and check if a string is a whole number.
 *
 * @author Viet Ha Nguyen
 * @date 3/30/2024
 * @bug No known bugs
 */
#include "input_handler.h"		/* Include header file */
/*******************************************************************************
 * Definition
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
int8_t getSingleCharInput()
{
    int8_t user_input[2]; /* This array is used to store the input character and a null terminator \0.
    It has a size of 2 to store one the character and the null terminator.*/

    uint32_t validInput = 0; /* Flag to check if the input is valid. */

    /* Loop until a valid single character input is received. */
    do
    {
        fflush(stdin);
        /* Read input from user */
        scanf("%s", user_input);

        /*
         * Checking if user_input[1] is '\0' character or not
         * If more than one character was entered, it prints a message
         * asking the user to enter only a single character and
         * require for input again.
         */
        if (user_input[1] != '\0')
        {
            printf("\nPlease enter only a single character. Try again: ");
        }
        /* If a single character is entered, set flag to exit loop. */
        else
        {
            validInput = 1;
        }
    } /* Repeat until get a valid single character */
    while (validInput == 0);

    /* return the first character of user_input, which is user_input[0].*/
    return user_input[0];
}


/**
 * @brief Formats a number with commas.
 *
 * This function takes a number as input and formats it with commas.
 * It then returns the formatted number as a string.
 *
 * @param number The number to be formatted.
 * @return string The formatted number as a string.
 */
int8_t* formatNumberWithCommas(uint64_t number)
{
    static int8_t formattedStr[40];            /* Adjusted size to static to return from function */
    int8_t numStr[40];                         /* Variable to store string that number convertted */
    uint32_t numLen;                            /* Variable to store length of number string */
    uint32_t commaCount;                        /* Variable to count number of comma to insert */
    uint32_t j = 0;                             /* Index for formattedStr */
    uint32_t i = 0;

    /* Convert the number to a string */
    sprintf(numStr, "%llu", number);
    /* Calculate the length of the number string */
    numLen = strlen(numStr);
    /* Calculate how many commas we need */
    commaCount = (numLen - 1) / 3;

    /* Loop through each digit of the number string */
    for (i = 0; i < numLen; i++)
    {
        /* Insert a comma before every 3 digits, except at the start */
        if (i > 0 && ((numLen - i) % 3 == 0))
        {
            /* Insert a comma before every 3 digits, except at the start */
            formattedStr[j++] = ',';
        }
        /* Copy the original digit */
        formattedStr[j++] = numStr[i];
    }
    /* Insert Null-terminate the string */
    formattedStr[j] = '\0';

    return formattedStr; /* Return the formatted string instead of printing it */
}


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
uint32_t isStringEmpty(int8_t *str)
{
    /* Remove newline and space characters */
    str[strcspn(str, "\n")] = 0;
    str[strcspn(str, " ")] = 0;
    /* Check if the string is empty */
    if (strlen(str) == 0)
    {
        return 1;
    }
}


/**
 * @brief This function checks if a string represents a whole number more than 0.
 * @param string_number The string to be checked.
 * @return 1 if the string represents a whole number more than 0, 0 otherwise.
 */
uint32_t isWholeNumber(int8_t *string_number)
{
    int8_t *end;               /* Pointer to the end of the string */
    uint32_t isNumber = 0;      /* Flag to check if the string is a number */
    int64_t num = 0;            /* Variable to store the converted number */

    /* Convert the string to a long long integer and store the result in 'num' */
    num = strtoll(string_number, &end, 10);

    /* If the end of the string is not reached, the number is negative,
    or the number is not the same as the original string, it is not a whole number. */
    if (*end != '\0' || num < 0 || num != strtoull(string_number, &end, 10))
    {
        isNumber = 0;
    }
    else
    {
        isNumber = 1;
    }
    return isNumber;
}


/**
 * @brief Clears the console screen.
 *
 * This function prompting the user to press any key to continue.
 * It then clears the input buffer, waits for a key press, and clears the console screen.
 */
void clear_console()
{
    printf("\n------------------------------");
    printf("\nPress ANY key to Continue. . .");
    fflush(stdin);
    getch();
    system("cls");
} /* EOF */


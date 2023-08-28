/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  [Your Name]
 *         File:  Calculator.c
 *        Layer:  Application
 *      Version:  1.00
 *
 *  Description:  Calculator Main File.
 *
 *********************************************************************************************************************/


#include "../LIB/Std_Types.h"
#include "../LIB/Platform_Types.h"
#include "Calculator_Interface.h"
#include "Calculator_Private.h"
#include "Calculator_Cfg.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../LIB/UTILS.h"

/* Static variables for the calculator */

static OPERATION_type operations[OPERATIONS_NUM]; /* this array contains all operations.*/
static s32 operands[OPERATIONS_NUM + 1]; /*operands array to store all operands.*/

static s32 result; /*this variable store final result of calculation.*/
static u8 operandIndex;
static u8 operationIndex;
static bool operandIsLast; /*this flag is raised if last input was operand.*/
static bool isNegative; /* this flag is raised when minus sign is entered.*/
static bool didDivByZero; /* this flag is raised when user divide by zero.*/
static bool resultRequested; /*this flag is raised when = is pressed.*/
static bool resultDisplayed; /*this flag is raised when result is displayed.*/
static bool allowDisplay; /*this flag is raised to allow displaying on LCD.*/


/* Function: Calculator_init
 * Description: Initializes the calculator application.
 * Input: None
 * Output: None
 */

void Calculator_init(void)
{
    print_Entery();
    resetCalculator();
}

/* Function: Calculator_Runnable
 * Description: Runnable function for the calculator application.
 * Input: None
 * Output: None
 */

void Calculator_Runnable(void)
{
    u8 keyPressed;

    keyPressed = KEYPAD_GetKey();

    if (keyPressed != 'T')
    {
        switch (keyPressed)
        {
        case '0' ... '9':
            handleNumberPressed(keyPressed);
            break;
        case '=':
            calculate_priority();
            break;

        case 'C':
            resetCalculator();
            allowDisplay = FALSE;
            break;

        default:
            handleOperation(keyPressed);
            break;
        }

        if (allowDisplay)
        {
            LCD_WriteChar(keyPressed);
        }
        else
        {
            allowDisplay = TRUE;
        }

        if (resultRequested)
        {
            LCD_GoTo(1, 0);
            if (!operandIsLast)
            {
                LCD_WriteString("MISSING OPERAND");
            }
            else if (didDivByZero)
            {
                LCD_WriteString("DIVIDE BY ZERO");
            }
            else
            {
                LCD_WriteNumber(result);
            }
            resultRequested = FALSE;
            resultDisplayed = TRUE;
        }
    }

}


/* Function: handleNumberPressed
 * Description: Handles a numeric key press.
 * Input: keyPressed - The numeric key pressed.
 * Output: None
 */

void handleNumberPressed(u8 keyPressed)
{

    s32 concatinationResult;

    if (resultDisplayed)
    {
        resetCalculator();
    }

    if (isNegative)
    {
        concatinationResult = (operands[operandIndex] * 10)
                - (keyPressed - '0');

    }
    else
    {
        concatinationResult = (operands[operandIndex] * 10)
                + (keyPressed - '0');

    }

    if (concatinationResult <= MAX_S16 && concatinationResult >= MIN_S16)
    {
        operands[operandIndex] = concatinationResult;
        operandIsLast = TRUE;
    }
    else
    {
        allowDisplay = FALSE;
    }

}


/* Function: handleOperation
 * Description: Handles an arithmetic operation.
 * Input: operation - The operation to be handled.
 * Output: None
 */

void handleOperation(u8 operation)
{
    bool handleOperation = TRUE;

    if ((resultDisplayed && didDivByZero) || (!operandIsLast))
    {
        handleOperation = FALSE;
    }
    else if (resultDisplayed)
    {
        resetCalculator();
        operands[0] = result;
        LCD_WriteString("ANS");
        operandIsLast = TRUE;
    }

    if (handleOperation && operationIndex < OPERATIONS_NUM)
    {
        switch (operation)
        {

        case '*':
            operations[operationIndex] = MUL;
            break;
        case '/':
            operations[operationIndex] = DIV;
            break;
        case '+':
            operations[operationIndex] = ADD;
            break;
        case '-':
            operations[operationIndex] = SUB;
            break;
        default:
            break;
        }
        operandIndex++;
        operationIndex++;
        operandIsLast = FALSE;
        isNegative = FALSE;
    }
    else if (operation == '-' && operationIndex < OPERATIONS_NUM && !isNegative)
    {
        isNegative = TRUE;
    }
    else
    {
        allowDisplay = FALSE;
    }

}

/* Function: calculate_priority
 * Description: Calculates expressions with priority operations.
 * Input: None
 * Output: None
 */

void calculate_priority(void)
{
    int i, k = 0;

    if (!resultDisplayed)
    {

        for (i = 0; i < OPERATIONS_NUM && !didDivByZero; i++)
        {
            if ((operations[i] == DIV) | (operations[i] == MUL))
            {
                switch (operations[i])
                {
                case DIV:
                    if (operands[k + 1] == 0)
                    {
                        didDivByZero = TRUE;
                    }
                    else
                    {
                        operands[k] = operands[k] / operands[k + 1];
                    }
                    break;
                case MUL:
                    operands[k] = operands[k] * operands[k + 1];
                    break;
                default:
                    break;
                }
                operands[k + 1] = 0;
                operations[i] = FINISHED;
                moveIntTolast(operands, k + 1, OPERATIONS_NUM + 1);
            }
            else
            {
                k++;
            }
        }

        k = 0;
        for (i = 0; i < OPERATIONS_NUM && !didDivByZero; i++)
        {
            if (operations[k] == FINISHED)
            {
                moveOperationToLast(operations, k, OPERATIONS_NUM);
            }
            else
            {
                k++;
            }
        }

        /*repeat but on add and subtract*/
        for (i = 0; i < OPERATIONS_NUM && !didDivByZero; i++)
        {
            if ((operations[0] == ADD) | (operations[0] == SUB))
            {
                switch (operations[0])
                {
                case ADD:
                    operands[0] = operands[0] + operands[1];

                    break;
                case SUB:
                    operands[0] = operands[0] - operands[1];
                    break;
                default:
                    break;
                }
                operands[1] = 0;
                operations[0] = FINISHED;
                moveIntTolast(operands, 1, OPERATIONS_NUM + 1);
                moveOperationToLast(operations, 0, OPERATIONS_NUM);
            }
        }

        resultRequested = TRUE;
        result = operands[0];
    }
    else
    {
        allowDisplay = FALSE;
    }
}

/* Function: calculate
 * Description: Calculates expressions.
 * Input: None
 * Output: None
 */

void calculate(void)
{
    u8 i;

    if (!resultDisplayed)
    {
        result = operands[0];

        for (i = 0; i < operationIndex; i++)
        {
            switch (operations[i])
            {
            case DIV:
                if (operands[i + 1] == 0)
                {
                    didDivByZero = TRUE;
                }
                else
                {
                    result /= operands[i + 1];
                }
                break;
            case MUL:
                result *= operands[i + 1];
                break;
            case ADD:
                result += operands[i + 1];
                break;
            case SUB:
                result -= operands[i + 1];
                break;
            }
        }
        resultRequested = TRUE;
    }
    else
    {
        allowDisplay = FALSE;
    }

}


/* Function: resetCalculator
 * Description: Resets the calculator state.
 * Input: None
 * Output: None
 */

void resetCalculator(void)
{
    u8 i;

    LCD_Clear();
    operandIndex = 0;
    operationIndex = 0;
    operandIsLast = FALSE;
    isNegative = FALSE;
    didDivByZero = FALSE;
    resultRequested = FALSE;
    resultDisplayed = FALSE;
    allowDisplay = TRUE;

    for (i = 0; i < OPERATIONS_NUM + 1; i++)
    {
        operands[i] = 0;
    }
}

/* Function: resetCalculator
 * Description: Resets the calculator state.
 * Input: None
 * Output: None
 */

void print_Entery(void){
    LCD_GoTo(0, 3);
    LCD_WriteString("CALCULATOR");
    LCD_GoTo(1, 2);
    LCD_WriteString("MOMEN & MAZEN");
    delay(4000);
    LCD_Clear();
}


/* Function: moveIntTolast
 * Description: Moves an integer to the last position in an array.
 * Input: arr - Pointer to the array
 *        index - Index of the integer to move
 *        size - Size of the array
 * Output: None
 */

void moveIntTolast(s32 *arr, int index, int size)
{

    int i;
    for (i = index; i < size - 1; i++)
    {
        swapS32(&arr[i], &arr[i + 1]);
    }
}


/* Function: moveOperationToLast
 * Description: Moves an operation to the last position in an array.
 * Input: arr - Pointer to the array
 *        index - Index of the operation to move
 *        size - Size of the array
 * Output: None
 */

void moveOperationToLast(OPERATION_type *arr, int index, int size)
{
    int i;

    for (i = index; i < size - 1; i++)
    {
        swapOperation(&arr[i], &arr[i + 1]);
    }
}

/* Function: swapS32
 * Description: Swaps two s32 values.
 * Input: p1 - Pointer to the first s32 value
 *        p2 - Pointer to the second s32 value
 * Output: None
 */

void swapS32(s32 *p1, s32 *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


/* Function: swapOperation
 * Description: Swaps two OPERATION_type values.
 * Input: p1 - Pointer to the first OPERATION_type value
 *        p2 - Pointer to the second OPERATION_type value
 * Output: None
 */

void swapOperation(OPERATION_type *p1, OPERATION_type *p2)
{
    OPERATION_type temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


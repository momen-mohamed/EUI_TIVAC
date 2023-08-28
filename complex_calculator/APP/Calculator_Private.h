/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Momen Mohamed
 *         File:  Calculator_Private.h
 *        Layer:  Application
 *      Version:  1.00
 *
 *  Description:  Private file containing some calculator functionality prototype
 *
 *********************************************************************************************************************/

#ifndef APP_CALCULATOR_PRIVATE_H_
#define APP_CALCULATOR_PRIVATE_H_



typedef enum{
    DIV = 1,
    MUL,
    ADD,
    SUB,
    FINISHED
}OPERATION_type;


void handleNumberPressed(u8 keyPressed);
void resetCalculator(void);
void handleOperation(u8 operation);
void calculate(void);
void calculate_priority(void);
void moveIntTolast(s32 *arr, int index, int size);
void moveOperationToLast(OPERATION_type *arr, int index, int size);
void swapS32(s32 *p1, s32 *p2);
void swapOperation(OPERATION_type *p1, OPERATION_type *p2);
void print_Entery(void);




#endif /* APP_CALCULATOR_PRIVATE_H_ */

#include "../LIB/Platform_Types.h"
#include "../LIB/Std_Types.h"
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/SYSTICK/systick.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../LIB/UTILS.h"
#include "STOP_WATCH.h"

static u32 count = 0;




GPIO_PinValue_t value = GPIO_PIN_LOW;
STOPWATCH_Status currentState = STOP;
LAPS_type currentLap = LAP1;


void callBack(void);


/* Function: STOP_WATCH_Init
 * Description: Initializes the StopWatch.
 * Input: None
 * Output: None
 */

void STOP_WATCH_Init(void)
{
    printStopWatchEntery();
    SysTickSetCallBack(callBack);
}


/* Function: STOP_WATCH_Runnable
 * Description: Main runnable function for the StopWatch application.
 * Input: None
 * Output: None
 */

void STOP_WATCH_Runnable(void)
{
    static u8 button1Flag = 0;
    static u8 button2Flag = 0;

    GPIO_PinValue_t firstButtonValue;
    GPIO_PinValue_t secondButtonValue;

    GPIO_GetPinValue(GPIO_PORTF, GPIO_PIN4, &firstButtonValue);
    GPIO_GetPinValue(GPIO_PORTF, GPIO_PIN0, &secondButtonValue);

    if (firstButtonValue == GPIO_PIN_LOW)
    {
        if (button1Flag == (u8)0)
        {

            if (currentState == START)
            {
                SysTickDisable();
                currentState = STOP;
            }
            else if (currentState == STOP)
            {
                SysTickEnable();
                currentState = START;

            }else{

            }

            button1Flag = (u8)1;
        }
    }
    else
    {
        button1Flag = (u8)0;
    }

    if (secondButtonValue == GPIO_PIN_LOW)
    {
        if (button2Flag == (u8)0)
        {

            if (currentState == STOP)
            {
                resetWatch();
            }
            else if (currentState == START)
            {
                switch (currentLap)
                {
                case LAP1:
                    printWatchAt((u8)0, (u8)9, count, LAP);
                    currentLap = LAP2;
                    break;
                case LAP2:
                    printWatchAt((u8)1, (u8)0, count, LAP);
                    currentLap = LAP3;
                    break;
                case LAP3:
                    printWatchAt((u8)1, (u8)9, count, LAP);
                    currentLap = LAP1;
                    break;
                default:
                    break;
                }
            }else{

            }

            button2Flag = (u8)1;
        }
    }
    else
    {
        button2Flag = (u8)0;
    }
    printWatchAt(0, 0, count, COUNT);
}

/* Function: resetWatch
 * Description: Resets the StopWatch.
 * Input: None
 * Output: None
 */

void resetWatch(void)
{

    LCD_Clear();
    currentLap = LAP1;
    SysTickDisable();
    SysTickPeriodSet((u32)16000000);
    count = (u32)0;
}

/* Function: printWatchAt
 * Description: Prints the watch count or lap at a specific line and cell.
 * Input: line - Line number (0 or 1)
 *        cell - Cell number (0 to 15)
 *        count - Watch count or lap value to print
 *        type - Type of watch (COUNT or LAP)
 * Output: None
 */

void printWatchAt(u8 line, u8 cell, u32 count, WATCH_type type)
{
     u32 minute = 0;
     u8 second = 0;

    LCD_GoTo(line, cell);
    if (type == LAP)
    {
        LCD_WriteString("L:");
    }
    minute = count / (u32)60;
    second = (u8)(count % (u32)60);
    LCD_WriteNumber((s32)minute / 10);
    LCD_WriteNumber((s32)minute % 10);
    LCD_WriteString(":");
    LCD_WriteNumber((s32)second / 10);
    LCD_WriteNumber((s32)second % 10);
}


/* Function: printStopWatchEntry
 * Description: Prints the StopWatch entry message.
 * Input: None
 * Output: None
 */

void printStopWatchEntery(void)
{
    LCD_GoTo((u8)0, (u8)1);
    LCD_WriteString("**STOP WATCH**");
    LCD_GoTo((u8)1,(u8) 1);
    LCD_WriteString("MOMEN MOHAMED");
    delay((u32)5000);
    LCD_Clear();
}

/* Function: callBack
 * Description: Callback function for SysTick interrupt.
 * Input: None
 * Output: None
 */

void callBack(void)
{
    count++;
}


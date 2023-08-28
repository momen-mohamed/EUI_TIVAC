/* File: SysTick.c
 * Author: Momen Mohamed
 * Layer: MCAL
 * Description: SysTick driver implementation for TM4C123G microcontroller.
 */

#include "../../LIB/Platform_Types.h"
#include "../../LIB/Std_Types.h"
#include "tm4c123gh6ph2.h"


static void (*SysTickISR_ptr)(void);

/* Function: SysTickEnable
 * Description: Enables the SysTick timer with system clock source.
 * Input: None
 * Output: None
 */

void SysTickEnable(void)
{
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE|NVIC_ST_CTRL_CLK_SRC;
}


/* Function: SysTickDisable
 * Description: Disables the SysTick timer.
 * Input: None
 * Output: None
 */
void SysTickDisable(void)
{
    NVIC_ST_CTRL_R &= ~(NVIC_ST_CTRL_ENABLE);
}

/* Function: SysTickIntEnable
 * Description: Enables SysTick interrupt.
 * Input: None
 * Output: None
 */

SysTickIntEnable(void)
{
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;
}

/* Function: SysTickIntDisable
 * Description: Disables SysTick interrupt.
 * Input: None
 * Output: None
 */

void SysTickIntDisable(void)
{
    NVIC_ST_CTRL_R &= ~(NVIC_ST_CTRL_INTEN);
}

/* Function: SysTickPeriodSet
 * Description: Sets the SysTick timer period.
 * Input: ui32Period - Period value to set
 * Output: None
 */

void SysTickPeriodSet(u32 ui32Period)
{

    if (ui32Period > 0 && ui32Period <= 16777216)
    {
        NVIC_ST_RELOAD_R = ui32Period - 1;
    }

}

/* Function: SysTickSetCallBack
 * Description: Sets a callback function to be executed when SysTick interrupt occurs.
 * Input: pfnHandler - Pointer to the callback function
 * Output: None
 */

void SysTickSetCallBack(void (*pfnHandler)(void)){
    SysTickISR_ptr = pfnHandler;
}

/* Function: SysTickISR
 * Description: SysTick interrupt service routine.
 * Input: None
 * Output: None
 */

void SysTickISR(void){
    if(SysTickISR_ptr != NULLPTR){
        SysTickISR_ptr();
    }
}


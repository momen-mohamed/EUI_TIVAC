#include "tm4c123gh6ph2.h"
#include "LIB/Platform_Types.h"
#include "LIB/Std_Types.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "LIB/UTILS.h"
#include "MCAL/SYSTICK/systick.h"
#include "APP/STOP_WATCH.h"

#define CONFIG_NUM 12

int main(void)
{

    const GPIO_Config_t Config[CONFIG_NUM] =
            {

            { GPIO_PORTA, GPIO_PIN4, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
              GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
              GPIO_ALTFUNC0 },
              { GPIO_PORTA, GPIO_PIN5, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTA, GPIO_PIN6, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTA, GPIO_PIN7, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },

              { GPIO_PORTE, GPIO_PIN0, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTE, GPIO_PIN1, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTE, GPIO_PIN2, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTE, GPIO_PIN3, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },

              { GPIO_PORTD, GPIO_PIN6, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTD, GPIO_PIN7, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },

              { GPIO_PORTF, GPIO_PIN4, GPIO_PIN_INPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },

              { GPIO_PORTF, GPIO_PIN0, GPIO_PIN_INPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },

            };

    /*Init GPIO */

    GPIO_Init(Config, CONFIG_NUM);

    /*Init LCD */
    LCD_Init();

    /*Init systick timer*/

    SysTickPeriodSet(16000000);
    SysTickIntEnable();

    /*StopWatch Init*/
    STOP_WATCH_Init();

    while (1)
    {
        STOP_WATCH_Runnable();
    }
}

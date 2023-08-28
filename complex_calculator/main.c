#include "LIB/Platform_Types.h"
#include "LIB/Std_Types.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "LIB/UTILS.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KeyPad/KeyPad_Interface.h"
#include "APP/Calculator_Interface.h"

#define CONFIG_NUM 18

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

              //key pad config
              { GPIO_PORTB, GPIO_PIN0, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTB, GPIO_PIN1, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTB, GPIO_PIN2, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTB, GPIO_PIN3, GPIO_PIN_OUTPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_FLOATING, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTB, GPIO_PIN4, GPIO_PIN_INPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTB, GPIO_PIN5, GPIO_PIN_INPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTB, GPIO_PIN6, GPIO_PIN_INPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },
              { GPIO_PORTB, GPIO_PIN7, GPIO_PIN_INPUT, GPIO_PIN_DIGITAL,
                GPIO_PIN_PUSHPULL, GPIO_PIN_PULLUP, GPIO_2MA_DRIVE,
                GPIO_ALTFUNC0 },

            };

    GPIO_Init(Config, CONFIG_NUM);
    LCD_Init();
    KEYPAD_Init();
    Calculator_init();


    while (1)
    {
        Calculator_Runnable();
    }
}

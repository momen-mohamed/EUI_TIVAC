
#ifndef MCAL_SYSTICK_SYSTICK_H_
#define MCAL_SYSTICK_SYSTICK_H_


/*****************************************************************************
*
*The following are defines for the bit fields in the NVIC_ST_CTRL register.
*
*****************************************************************************/

#define NVIC_ST_CTRL_COUNT      0x00010000  // Count Flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt Enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Enable


/*****************************************************************************/

void SysTickEnable(void);
void SysTickDisable(void);
void SysTickIntEnable(void);
void SysTickIntDisable(void);
void SysTickPeriodSet(u32 ui32Period);
void SysTickSetCallBack(void (*pfnHandler)(void));


#endif /* MCAL_SYSTICK_SYSTICK_H_ */

/****************************************************************
 *
 * www.payitforward.edu.vn
 *
 ****************************************************************/
/****************************************************************
 *
 * PIF TUTORIALS - TIVA ARM CORTEX-M4 TM4C123G
 *
 ****************************************************************/

/****************************************************************
 *
 *	Module		: <TIMER_blining_LED.c>
 *	Description	: Blinking blue LED using Timer
 *  Tool		: CCS 6.0
 *	Chip		: Tiva C Series TM4C123G
 * 	History		: 31/10/2014
 *  Version     : 1.0
 *
 *	Author		: Do Huu Phuong Trung, Pay It Forward Club
 *	Notes		:
 *
 *
 ****************************************************************/


 /****************************************************************
 * IMPORT
 ****************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"

 /****************************************************************
 * EXTERN
 ****************************************************************/

void Timer0IntHandler(void);

/*****************************************************************
GLOBAL VARIABLE
******************************************************************/


/*****************************************************************
* ROUTINES
******************************************************************/

/* -- void Timer0IntHandler(void) --------------------------------------
 *
 * Description	: Timer 0 interrupts handler .
 * Parameters	: none
 * Return		: don't care
 */
void Timer0IntHandler(void)
{
	// Clear the timer interrupt
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

	// Read the current state of the GPIO pin and
	// write back the opposite state
	if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2))
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
	}
	else
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);
	}
}

/******************************************************************************
 * MAIN
 *****************************************************************************/
int main(void)
{
	uint32_t ui32Period;

	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);

	ui32Period = (SysCtlClockGet() / 10) / 2;
	TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period -1);

	IntEnable(INT_TIMER0A);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	IntMasterEnable();

	TimerEnable(TIMER0_BASE, TIMER_A);

	while(1)
	{
	}
}

/****************************************************************
 * END OF main.c
 ****************************************************************/

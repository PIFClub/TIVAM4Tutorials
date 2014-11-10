/****************************************************************
 *
 * www.payitforward.edu.vn
 *
 ****************************************************************/
/****************************************************************
 *
 * PIF TIVA TUTORIAL
 *
 ****************************************************************/

/****************************************************************
 *
 *	Module		: main.c
 *	Description	:
 *  Tool		: CCS 5.
 *	Chip		: TIVA C TM4C123G
 * 	History		: 01/11/2014
 *  Version     : 1.0
 *
 *	Author		: CTCNGH, Pay it Forward Club
 *	Notes		:
 *
 *
 ****************************************************************/

 /****************************************************************
 * DEFINE
 ****************************************************************/
#define LED_RED		GPIO_PIN_1
#define LED_GREEN	GPIO_PIN_2
#define LED_BLUE	GPIO_PIN_3


 /****************************************************************
 * IMPORT
 ****************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"





/******************************************************************************
 * MAIN
 *****************************************************************************/
 void main (void)
{
	 	 int tick=LED_RED;
	 	// Configure clock 40 MHz
	 	SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	 	//PortF Enable
	 	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	 	//Config GPIO that connect to LED - PIN 1,2,3
	 	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_RED|LED_GREEN|GPIO_PIN_3);
	 	//Turn off all LEDs
	 	GPIOPinWrite(GPIO_PORTF_BASE,  LED_RED|LED_GREEN|GPIO_PIN_3, 0);
	 	//Infinite loop
	 	while(1)
	 	{

	 		GPIOPinWrite(GPIO_PORTF_BASE, LED_RED|LED_GREEN|GPIO_PIN_3, tick);
	 		tick<<=1;
	 		if(tick>GPIO_PIN_3)
	 			tick=LED_RED;
	 		//Delay 1s
	 		//SysCtlDelay(count) delay 3*count cycles
	 		SysCtlDelay(SysCtlClockGet()/3);
	 	}

}

/****************************************************************
 * END OF main.c
 ****************************************************************/

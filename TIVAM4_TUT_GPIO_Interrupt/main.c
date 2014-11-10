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
#define SW1			GPIO_PIN_4
#define SW2 		GPIO_PIN_0

#define PART_TM4C123GH6PM

/****************************************************************
 * IMPORT
 ****************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"

/******************************************************************************
 * SUB ROUTINE
 *****************************************************************************/
void ButtonISR(void)
{
		static int tick = LED_RED;
		GPIOIntClear(GPIO_PORTF_BASE, SW1);
		GPIOPinWrite(GPIO_PORTF_BASE, LED_RED|LED_GREEN|LED_BLUE, tick);
		tick<<=1;
		if(tick>GPIO_PIN_3)
			tick=LED_RED;
		//Delay 1s
		SysCtlDelay(SysCtlClockGet()/3);
}


/******************************************************************************
 * MAIN
 *****************************************************************************/
void main (void)
{
	// Configure clock 40 MHz
	SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	//PortF Enable
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	//Config GPIO that connect to LED - PIN 1,2,3
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_RED|LED_GREEN|LED_BLUE);
	//Turn off all LEDs
	GPIOPinWrite(GPIO_PORTF_BASE,  LED_RED|LED_GREEN|LED_BLUE, 0);
	//Config Buttons
	GPIODirModeSet(GPIO_PORTF_BASE,  SW1, GPIO_DIR_MODE_IN);
	GPIOPadConfigSet(GPIO_PORTF_BASE, SW1, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
	//Config GPIO Interrupt for SW1
	GPIOIntTypeSet(GPIO_PORTF_BASE,SW1, GPIO_FALLING_EDGE);
	GPIOIntRegister(GPIO_PORTF_BASE,&ButtonISR);
	GPIOIntEnable(GPIO_PORTF_BASE, SW1);
	IntEnable(INT_GPIOF);
	IntMasterEnable();

	//Infinite loop
	while(1)
	{

	}

}

/****************************************************************
 * END OF main.c
 ****************************************************************/

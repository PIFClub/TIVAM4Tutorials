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
 *	Module		: <SPI_EXAMPLE.c>
 *	Description	: The code will send three characters on the master Tx then polls the receive FIFO until
3 characters are received on the master Rx. UART signals are configured for displaying console messages.
 *  Tool		: CCS 5.1
 *	Chip		: MSP430G2xxx
 * 	History		: 01/10/2012
 *  Version     : 1.0
 *
 *	Author		: Nguyen Thanh Binh, Pay It Forward Club
 *	Notes		: UART signals are not required for operation of SSI.
 *
 *
 ****************************************************************/

 /****************************************************************
 * Number of bytes to send and receive.
 ****************************************************************/

 #define NUM_SSI_DATA            3

 /****************************************************************
 * IMPORT
 ****************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"


 /****************************************************************
 * EXTERN
 ****************************************************************/


/*****************************************************************
GLOBAL VARIABLE
******************************************************************/



/*****************************************************************
* ROUTINES
******************************************************************/

/* -- void InitConsole(void) --------------------------------------
 *
 * Description	: sets up UART0 to be used for a console to display information when the example is running.
 * Parameters	: none
 * Return		: don't care
 */
void InitConsole(void)
{
    // Enable GPIO port A which is used for UART0 pins.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Configure the pin muxing for UART0 functions on port A0 and A1.
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    // Enable UART
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // Use the internal 16MHz oscillator as the UART clock source.
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    // Select the alternate (UART) function for these pins.
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Initialize the UART for console I/O.
    UARTStdioConfig(0, 115200, 16000000);
}

/******************************************************************************
 * MAIN
 *****************************************************************************/
 int
main(void)
{
    uint32_t pui32DataTx[NUM_SSI_DATA];
    uint32_t pui32DataRx[NUM_SSI_DATA];
    uint32_t ui32Index;

    // Set the clocking to run directly from the external crystal/oscillator
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);

    // Set up the serial console to use for displaying messages.
    InitConsole();

    // Display the setup on the console.
    UARTprintf("SSI ->\n");
    UARTprintf("  Mode: SPI\n");
    UARTprintf("  Data: 8-bit\n\n");

    // Enable SSI0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);

    // SSI0 is used with PortA[5:2].
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Configure SSI0 functions on port A2, A3, A4, and A5.
    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
    GPIOPinConfigure(GPIO_PA3_SSI0FSS);
    GPIOPinConfigure(GPIO_PA4_SSI0RX);
    GPIOPinConfigure(GPIO_PA5_SSI0TX);

    // Configure the GPIO settings for the SSI pins.
    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_3 |
                   GPIO_PIN_2);

    // Configure and enable the SSI port for SPI master mode.
    SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0,
                       SSI_MODE_MASTER, 1000000, 8);

    // Enable the SSI0 module.
    SSIEnable(SSI0_BASE);

    // Read any residual data from the SSI port.
    while(SSIDataGetNonBlocking(SSI0_BASE, &pui32DataRx[0]))
    {
    }

    // Initialize the data to send.
    pui32DataTx[0] = 'p';
    pui32DataTx[1] = 'i';
    pui32DataTx[2] = 'f';

    // Display indication that the SSI is transmitting data.
    UARTprintf("Sent:\n  ");

    // Send 3 bytes of data.
    for(ui32Index = 0; ui32Index < NUM_SSI_DATA; ui32Index++)
    {
        // Display the data that SSI is transferring.
        UARTprintf("'%c' ", pui32DataTx[ui32Index]);

        // Send the data
        SSIDataPut(SSI0_BASE, pui32DataTx[ui32Index]);
    }

    // Wait until SSI0 is done transferring all the data in the transmit FIFO.
    while(SSIBusy(SSI0_BASE))
    {
    }

    // Display indication that the SSI is receiving data.
    UARTprintf("\nReceived:\n  ");

    // Receive 3 bytes of data.
    for(ui32Index = 0; ui32Index < NUM_SSI_DATA; ui32Index++)
    {
        // Receive the data
        SSIDataGet(SSI0_BASE, &pui32DataRx[ui32Index]);

        // Since we are using 8-bit data, mask off the MSB.
        pui32DataRx[ui32Index] &= 0x00FF;

        // Display the data that SSI0 received.
        UARTprintf("'%c' ", pui32DataRx[ui32Index]);
    }
    UARTprintf("\n\n");

    return(0);
}

/****************************************************************
 * END OF <standard_form>.c
 ****************************************************************/

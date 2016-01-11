/* UART */
#include "uart.h"

void
uart_init()
{
	/* Clock */
	SIM_SCGC4 |= SET(10);
	SIM_SOPT2 |= SET(26);
	SIM_SOPT2 &= CLEAR(27);

	/* Disable UART */
	UART0_C2 = 0;

	/* Baud rate */
	/* OSR = 26 */
	UART0_C4 |= 25;
	/* SBR = 8 */
	UART0_BDH = 0x0;
	UART0_BDL = 0x8;

	/* 8N1 */
	UART0_C1 &= CLEAR(4);
	UART0_C1 &= CLEAR(1);
	UART0_BDH &= CLEAR(5);

	/* Port A: clock, RX & TX in UART mode */
	SIM_SCGC5 |= SET(9);
	PORTA_PCR1 |= SET(9);
	PORTA_PCR1 &= CLEAR(8) + CLEAR(10);
	PORTA_PCR2 |= SET(9);
	PORTA_PCR2 &= CLEAR(8) + CLEAR(10);
	/* polling: pull enable */
	PORTA_PCR1 &= CLEAR(0);
	PORTA_PCR1 &= CLEAR(1);
	PORTA_PCR2 &= CLEAR(0);
	PORTA_PCR2 &= CLEAR(1);

	/* enable UART */
	UART0_C2 = 0x0C;
}

void
uart_putchar(char c)
{
	while(!(UART0_S1 & UART_RDRF_MASK));
	c = UART0_D;
	while(!(UART0_S1 & UART_TDRE_MASK) && !(UART0_S1 & UART_TC_MASK));
	UART0_D = c;
}

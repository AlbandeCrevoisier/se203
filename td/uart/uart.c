/* UART */
#include "uart.h"

void
uart_init()
{
	/* Clock */
	SIM_SCGC4 |= SET(10);
	SIM_SOPT2 |= SET(26);
	SIM_SOPT2 &= CLEAR(27);
	SIM_SOPT2 |= SET(16);

	/* Disable UART */
	UART0_C2 = 0;

	/* Baud rate */
    /* 38 400 */
	/* SBR = 25 */
	UART0_BDH = 0x0;
	UART0_BDL = 25;
	/* OSR = 25 */
	UART0_C4 = 24;

	/* 8N1 */
	UART0_C1 = 0x00;
	UART0_C3 = 0x00;
	UART0_S1 |= 0x1F;
	UART0_S2 |= 0xC0;
	UART0_MA1 = 0x00;
	UART0_MA2 = 0x00;

	/* Port A: clock, RX & TX in UART mode */
	SIM_SCGC5 |= SET(9);
	for (int i = 0; i < 3; i++)
		SIM_SOPT5 &= CLEAR(i);
	PORTA_PCR1 |= SET(9);
	PORTA_PCR1 &= CLEAR(8);
	PORTA_PCR1 &= CLEAR(10);
	PORTA_PCR2 |= SET(9);
	PORTA_PCR2 &= CLEAR(8);
	PORTA_PCR2 &= CLEAR(10);
	/* polling: pull enable */
	PORTA_PCR1 |= SET(0);
	PORTA_PCR1 |= SET(1);
	PORTA_PCR2 |= SET(0);
	PORTA_PCR2 |= SET(1);

	/* enable UART */
	UART0_C2 = 0x0C;
}

void
uart_putchar(char c)
{

	while(!(UART0_S1 & UART_TDRE_MASK) || !(UART0_S1 & UART_TC_MASK));
	UART0_D = c;
}

unsigned char
uart_getchar(void)
{
	UART0_S1 = SET(3);
	while(!(UART0_S1 & UART_RDRF_MASK));
	return UART0_D;
}

void
uart_puts(const char *s)
{
	int i= 0;
	while (s[i] != '\0')
		uart_putchar(s[i++]);
}

void
uart_gets(char *s, int size)
{
	char c;
	int i;
	for(i = 0; i < size; i++) {
		c = uart_getchar();
		if (c == '\n' || c == '\r') {
			s[i++] = c;
			break;
		} else if (c == 0) {
			break;
		} else {
			s[i] = c;
		}
	}
	s[i] = '\0';
}

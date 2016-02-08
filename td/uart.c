/* UART */
#include "uart.h"

#define SIM_SOPT2		(*(volatile uint32_t *)	0x40048004)
#define SIM_SOPT5		(*(volatile uint32_t *)	0x40048010)
#define SIM_SCGC4		(*(volatile uint32_t *)	0x40048034)
#define SIM_SCGC5		(*(volatile uint32_t *)	0x40048038)
#define UART0_C1		(*(volatile uint8_t *)		0x4006A002)
#define UART0_C2		(*(volatile uint8_t *)		0x4006A003)
#define UART0_C3		(*(volatile uint8_t *)		0x4006A006)
#define UART0_C4		(*(volatile uint8_t *)		0x4006A00A)
#define UART0_BDH		(*(volatile uint8_t *)		0x4006A000)
#define UART0_BDL		(*(volatile uint8_t *)		0x4006A001)
#define UART0_S1		(*(volatile uint8_t *)		0x4006A004)
#define UART0_S2		(*(volatile uint8_t *)		0x4006A005)
#define UART0_D		(*(volatile uint8_t *)		0x4006A007)
#define PORTA_PCR1	(*(volatile uint32_t *)	0X40049004)
#define PORTA_PCR2	(*(volatile uint32_t *)	0x40049008)
#define UART0_MA1		(*(volatile uint8_t *)		0x4006A008)
#define UART0_MA2		(*(volatile uint8_t *)		0x4006A009)

#define UART_RDRF_MASK	0x20
#define UART_TC_MASK		0x40
#define UART_TDRE_MASK	0x80

#define SET(x)   (1 << x)
#define CLEAR(x) (~(1 << x))

VPFV functiontocall_handler;

/* Main baud rates:
 * 115 200 :	SBR = 8,		OSR = 26.
 * 38 400 :	SBR = 25,		OSR = 25.
 * 9 600 :		SBR = 125,	OSR = 20.
 * TODO : write a function that computes those value for a given baud rate.
 */
void
uart_init(VPFV functocall_handler)
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
	UART0_BDH = 0;
	UART0_BDL = 25;
	/* OSR = 25 */
	UART0_C4 = 24;

	/* 8N1 */
	UART0_C1  = 0x00;
	UART0_C3  = 0x00;
	UART0_S1  = 0x1F;
	UART0_S2 |= 0xC0;
	UART0_MA1 = 0x00;
	UART0_MA2 = 0x00;

	/* Port A: clock, RX & TX in UART mode, polling mode, pull up */
	SIM_SCGC5 |= SET(9);
	for (int i = 0; i < 3; i++)
		SIM_SOPT5 &= CLEAR(i);
	PORTA_PCR1 = 0x203;
	PORTA_PCR2 = 0x203;

	/* Activate IRQ */
	enable_irq();
	irq_enable(12);

	/* Handler init */
	functiontocall_handler = functocall_handler;

	/* enable UART and UART IRQ*/
	UART0_C2 = 0x8C;

	/* Flush */
	UART0_D;
}

void
uart_putchar(char c)
{

	while(!(UART0_S1 & UART_TDRE_MASK) || !(UART0_S1 & UART_TC_MASK))
		;
	UART0_D = c;
}

unsigned char
uart_getchar(void)
{
	UART0_S1 = SET(3);
	while(!(UART0_S1 & UART_RDRF_MASK))
		;
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

void
UART0_IRQHandler(void)
{
	//TODO : get the byte
	functiontocall_handler();	
}

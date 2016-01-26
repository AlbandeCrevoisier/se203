/* Matrix */
#include "matrix.h"

void
matrix_init(void)
{

	int i;

	/* Clocks port A, B, C, and D */
	SIM_SCGC5 |= (SET(9) + SET(10) + SET(11) + SET(12));

	/* GPIO mode */
	PORTB_PCR0 = 0x103;
	PORTB_PCR1 = 0x103;
	PORTB_PCR2 = 0x103;
	PORTC_PCR8 = 0x103;
	PORTC_PCR9 = 0x103;
	PORTA_PCR13 = 0x103;
	PORTD_PCR2 = 0x103;
	PORTD_PCR4 = 0x103;
	PORTD_PCR6 = 0x103;
	PORTD_PCR7 = 0x103;
	PORTD_PCR5 = 0x103;
	PORTA_PCR12 = 0x103;
	PORTA_PCR4 = 0x103;

	/* output mode */
	GPIOB_PDDR |= SET(0);
	GPIOB_PDDR |= SET(1);
	GPIOB_PDDR |= SET(2);
	GPIOC_PDDR |= SET(8);
	GPIOC_PDDR |= SET(9);
	GPIOA_PDDR |= SET(13);
	GPIOD_PDDR |= SET(2);
	GPIOD_PDDR |= SET(4);
	GPIOD_PDDR |= SET(6);
	GPIOD_PDDR |= SET(7);
	GPIOD_PDDR |= SET(5);
	GPIOA_PDDR |= SET(12);
	GPIOA_PDDR |= SET(4);

	/* init */
	RST(0);
	LAT(1);
	SB(1);
	SCK(0);
	SDA(1);
	C0(0);
	C1(0);
	C2(0);
	C3(0);
	C4(0);
	C5(0);
	C6(0);
	C7(0);

	/* ~100ms */
	for (i = 0; i < NOP_NB; i++)
		asm volatile ("nop");

	RST(1);
}

void
SB(int i)
{
	switch (i) {
	case 0 : GPIOB_PCOR |= SET(0);
	case 1 : GPIOB_PSOR |= SET(0);
	/* Toggle */
	case 7 : GPIOB_PTOR |= SET(0);
	}
}

void
LAT(int i)
{
	switch (i) {
	case 0 : GPIOB_PCOR |= SET(1);
	case 1 : GPIOB_PSOR |= SET(1);
	/* Toggle */
	case 7 : GPIOB_PTOR |= SET(1);
	}
}

void
RST(int i)
{
	switch (i) {
	case 0 : GPIOB_PCOR |= SET(2);
	case 1 : GPIOB_PSOR |= SET(2);
	/* Toggle */
	case 7 : GPIOB_PTOR |= SET(2);
	}
}

void
SCK(int i)
{
	switch (i) {
	case 0 : GPIOC_PCOR |= SET(8);
	case 1 : GPIOC_PSOR |= SET(8);
	/* Toggle */
	case 7 : GPIOC_PTOR |= SET(8);
	}
}

void
SDA(int i)
{
	switch (i) {
	case 0 : GPIOC_PCOR |= SET(9);
	case 1 : GPIOC_PSOR |= SET(9);
	/* Toggle */
	case 7 : GPIOC_PTOR |= SET(9);
	}
}

void
C0(int i)
{
	switch (i) {
	case 0 : GPIOA_PCOR |= SET(13);
	case 1 : GPIOA_PSOR |= SET(13);
	/* Toggle */
	case 7 : GPIOA_PTOR |= SET(13);
	}
}

void
C1(int i)
{
	switch (i) {
	case 0 : GPIOD_PCOR |= SET(2);
	case 1 : GPIOD_PSOR |= SET(2);
	/* Toggle */
	case 7 : GPIOD_PTOR |= SET(2);
	}
}

void
C2(int i)
{
	switch (i) {
	case 0 : GPIOD_PCOR |= SET(4);
	case 1 : GPIOD_PSOR |= SET(4);
	/* Toggle */
	case 7 : GPIOD_PTOR |= SET(4);
	}
}

void
C3(int i)
{
	switch (i) {
	case 0 : GPIOD_PCOR |= SET(6);
	case 1 : GPIOD_PSOR |= SET(6);
	/* Toggle */
	case 7 : GPIOD_PTOR |= SET(6);
	}
}

void
C4(int i)
{
	switch (i) {
	case 0 : GPIOD_PCOR |= SET(7);
	case 1 : GPIOD_PSOR |= SET(7);
	/* Toggle */
	case 7 : GPIOD_PTOR |= SET(7);
	}
}

void
C5(int i)
{
	switch (i) {
	case 0 : GPIOD_PCOR |= SET(5);
	case 1 : GPIOD_PSOR |= SET(5);
	/* Toggle */
	case 7 : GPIOD_PTOR |= SET(5);
	}
}

void
C6(int i)
{
	switch (i) {
	case 0 : GPIOA_PCOR |= SET(12);
	case 1 : GPIOA_PSOR |= SET(12);
	/* Toggle */
	case 7 : GPIOA_PTOR |= SET(12);
	}
}

void
C7(int i)
{
	switch (i) {
	case 0 : GPIOA_PCOR |= SET(4);
	case 1 : GPIOA_PSOR |= SET(4);
	/* Toggle */
	case 7 : GPIOA_PTOR |= SET(4);
	}
}

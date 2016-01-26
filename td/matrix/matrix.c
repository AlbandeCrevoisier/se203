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
	ROW0(0);
	ROW1(0);
	ROW2(0);
	ROW3(0);
	ROW4(0);
	ROW5(0);
	ROW6(0);
	ROW7(0);

	/* ~100ms */
	for (i = 0; i < NOP100MS; i++)
		asm volatile ("nop");

	RST(1);
	bank0_init();

	test_pixels();
}

void
bank0_init(void)
{
	int i, j;
	for (i = 0; i < NBROW; i++)
		for (j = 0; j < 24; j++)
			send_byte(0xFF, 0);
	pulse_LAT();
}

void
SB(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOB_PCOR |= SET(0);
			break;

	case 1:	/* Set */
			GPIOB_PSOR |= SET(0);
			break;

	case 7:	/* Toggle */
			GPIOB_PTOR |= SET(0);
			break;
	}
}

void
LAT(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOB_PCOR |= SET(1);
			break;

	case 1:	/* Set */
			GPIOB_PSOR |= SET(1);
			break;

	case 7:	/* Toggle */
			GPIOB_PTOR |= SET(1);
			break;
	}
}

void
RST(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOB_PCOR |= SET(2);
			break;

	case 1:	/* Set */
			GPIOB_PSOR |= SET(2);
			break;

	case 7:	/* Toggle */
			GPIOB_PTOR |= SET(2);
			break;
	}
}

void
SCK(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOC_PCOR |= SET(8);
			break;

	case 1:	/* Set */
			GPIOC_PSOR |= SET(8);
			break;

	case 7:	/* Toggle */
			GPIOC_PTOR |= SET(8);
			break;
	}
}

void
SDA(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOC_PCOR |= SET(9);
			break;

	case 1:	/* Set */
			GPIOC_PSOR |= SET(9);
			break;

	case 7:	/* Toggle */
			GPIOC_PTOR |= SET(9);
			break;
	}
}

void
ROW0(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOA_PCOR |= SET(13);
			break;

	case 1:	/* Set */
			GPIOA_PSOR |= SET(13);
			break;

	case 7:	/* Toggle */
			GPIOA_PTOR |= SET(13);
			break;
	}
}

void
ROW1(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOD_PCOR |= SET(2);
			break;

	case 1:	/* Set */
			GPIOD_PSOR |= SET(2);
			break;

	case 7:	/* Toggle */
			GPIOD_PTOR |= SET(2);
			break;
	}
}

void
ROW2(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOD_PCOR |= SET(4);
			break;

	case 1:	/* Set */
			GPIOD_PSOR |= SET(4);
			break;

	case 7:	/* Toggle */
			GPIOD_PTOR |= SET(4);
			break;
	}
}

void
ROW3(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOD_PCOR |= SET(6);
			break;

	case 1:	/* Set */
			GPIOD_PSOR |= SET(6);
			break;

	case 7:	/* Toggle */
			GPIOD_PTOR |= SET(6);
			break;
	}
}

void
ROW4(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOD_PCOR |= SET(7);
			break;

	case 1:	/* Set */
			GPIOD_PSOR |= SET(7);
			break;

	case 7:	/* Toggle */
			GPIOD_PTOR |= SET(7);
			break;
	}
}

void
ROW5(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOD_PCOR |= SET(5);
			break;

	case 1:	/* Set */
			GPIOD_PSOR |= SET(5);
			break;

	case 7:	/* Toggle */
			GPIOD_PTOR |= SET(5);
			break;
	}
}

void
ROW6(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOA_PCOR |= SET(12);
			break;

	case 1:	/* Set */
			GPIOA_PSOR |= SET(12);
			break;

	case 7:	/* Toggle */
			GPIOA_PTOR |= SET(12);
			break;
	}
}

void
ROW7(int i)
{
	switch (i) {
	case 0:	/* Clear */
			GPIOA_PCOR |= SET(4);
			break;

	case 1:	/* Set */
			GPIOA_PSOR |= SET(4);
			break;

	case 7:	/* Toggle */
			GPIOA_PTOR |= SET(4);
			break;
	}
}

void
pulse_SCK(void)
{
	/* 24 MHz : 1 nop ~= 40ns. SCK requires >25ns. */
	SCK(0);
	asm volatile ("nop");
	SCK(1);
	asm volatile ("nop");
	SCK(0);
	asm volatile ("nop");
}

void
pulse_LAT(void)
{
	/* 24 MHz : 1 nop ~= 40ns. Lat requires >25ns and >7ns. */
	LAT(1);
	asm volatile ("nop");
	LAT(0);
	asm volatile ("nop");
	LAT(1);
	asm volatile ("nop");
}

void
deactivate_rows(void)
{
	ROW0(0);
	ROW1(0);
	ROW2(0);
	ROW3(0);
	ROW4(0);
	ROW5(0);
	ROW6(0);
	ROW7(0);
}

void
activate_row(int r)
{
	switch (r) {
	case 0:	ROW0(1);
			break;

	case 1:	ROW1(1);
			break;

	case 2:	ROW2(1);
			break;

	case 3:	ROW3(1);
			break;

	case 4:	ROW4(1);
			break;

	case 5:	ROW5(1);
			break;

	case 6:	ROW6(1);
			break;

	case 7:	ROW7(1);
			break;
	}
}

void
send_byte(uint8_t val, int bank)
{
	int i;
	int bank_size = bank ? 8 : 6;
	int bit;
	SB(bank);
	for (i = 0; i < bank_size; i++) {
		bit = (val >> i);
		bit &= 1;
		SDA(bit);
		pulse_SCK();
	}
}

/* val : array of 8 * rgb_color */
void
mat_set_row(int r, const rgb_color *val)
{
	int i;
	for (i = 7; i > -1; i--) {
		send_byte((val[i]).b, 1);
		send_byte(val[i].g, 1);
		send_byte(val[i].r, 1);
	}
	activate_row(r);
	pulse_LAT();
}

void
test_pixels(void)
{
	int i;
	rgb_color row[8];
	
	/* red */
	for (i = 0; i < NBROW; i++) {
		row[i].r = 1;
		row[i].g = 0;
		row[i].b = 0;
	}
	for (i = 0; i < NBROW; i++)
		mat_set_row(i, row);
	for (i = 0; i < NOP1S; i++)
		asm volatile ("nop");

	/* green */
	for (i = 0; i < NBROW; i++) {
		row[i].r = 0;
		row[i].g = 1;
		row[i].b = 0;
	}
	for (i = 0; i < NBROW; i++)
		mat_set_row(i, row);
	for (i = 0; i < NOP1S; i++)
		asm volatile ("nop");

	/* blue */
	for (i = 0; i < NBROW; i++) {
		row[i].r = 0;
		row[i].g = 0;
		row[i].b = 1;
	}
	for (i = 0; i < NBROW; i++)
		mat_set_row(i, row);
	for (i = 0; i < NOP1S; i++)
		asm volatile ("nop");
}

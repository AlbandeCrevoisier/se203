/* Matrix */
#include matrix.h

void
matrix_init(void)
{
	/* Clocks port A, B, C, and D */
	SIM_SCGC5 |= (SET(9) + SET(10) + SET(11) + SET(12));

	gpio_mode(SB);
	gpio_mode(LAT);
	gpio_mode(RST);
	gpio_mode(SCK);
	gpio_mode(SDA);
	gpio_mode(C0);
	gpio_mode(C1);
	gpio_mode(C2);
	gpio_mode(C3);
	gpio_mode(C4);
	gpio_mode(C5);
	gpio_mode(C6);
	gpio_mode(C7);

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
	
}

void
gpio_mode(*(volatile uint32_t *) p)
{
	p |= SET(8);
	p &= CLEAR(9);
	p &= CLEAR(10);
}

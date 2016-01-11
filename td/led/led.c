/* LED */
#define SET(x) (1 << x)
#include "led.h"

void
led_init(void)
{
	/* Clock for Port D and E: on. */
	SIM_SCGC5 |= 0x3000;

	/* mode GPIO */
	PORTD_PCR5 |= 0x100;
	PORTE_PCR29 |= 0x100;

	/* mode output */
	GPIOD_PDDR |= SET(5);
	GPIOE_PDDR |= SET(29);

	/* Turn on the LED. */
	led_on();
}

void
led_on(void)
{
	GPIOD_PCOR |= SET(5);
	GPIOE_PCOR |= SET(29);
}

void
led_off(void)
{
	GPIOD_PSOR |= SET(5);
	GPIOE_PSOR |= SET(29);
}

void
led_toggle(void)
{
	GPIOD_PTOR |= SET(5);
	GPIOE_PTOR |= SET(29);
}

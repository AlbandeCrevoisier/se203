/* LED */
#include "../include/led.h"

void
led_init(void)
{
	/* Clock for Port D and E: on. */
	SIM_SCGC5 |= 0x3000;

	/* mode GPIO */
	PORTD_PCR5 |= 0x100;
	PORTE_PCR29 |= 0x100;

	/* mode output */
	GPIOD_PDDR |= 0x10;
	GPIOE_PDDR |= 0x20000000;

	/* Turn on the LED. */
	GPIOD_PSOR |= 0x10;
	GPIOD_PSOR |= 0x20000000;
}

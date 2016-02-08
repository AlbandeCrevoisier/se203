/* buttons */
#include "buttons.h"

#define PCMCD_IRQ 31

#define SIM_SCGC5		(*(volatile uint32_t *) 0x40048038)
#define PORTC_PCR3	(*(volatile uint32_t *) 0x4004B00C)
#define PORTE_PCR29	(*(volatile uint32_t *) 0x4004D074)
#define GPIOC_PDDR	(*(volatile uint32_t *) 0x400FF094)
#define GPIOE_PDDR	(*(volatile uint32_t *) 0x400FF114)
#define GPIOE_PSOR	(*(volatile uint32_t *) 0x400FF104)
#define GPIOE_PCOR	(*(volatile uint32_t *) 0x400FF108)
#define GPIOE_PTOR	(*(volatile uint32_t *) 0x400FF10C)

#define SET(x)   (1 << x)
#define CLEAR(x) (~(1 << x))

void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);

void
button_init(void)
{
	/* clock on */
	SIM_SCGC5 |= SET(11);

	/* mode GPIO, pull-up, IRQ on falling edge */
	PORTC_PCR3 = 0xA0103;

	/* mode input */
	GPIOC_PDDR &= CLEAR(3);

	/* activate IRQ on PORTC (and D) */
	irq_enable(PCMCD_IRQ);
}

void
led_init(void)
{
	/* clock on */
	SIM_SCGC5 |= SET(13);

	/* mode GPIO */
	PORTE_PCR29 = 0x103;

	/* mode output */
	GPIOE_PDDR |= SET(29);
}

void
led_on(void)
{
    GPIOE_PCOR |= SET(29);
}

void
led_off(void)
{
    GPIOE_PSOR |= SET(29);
}

void
led_toggle(void)
{
    GPIOE_PTOR |= SET(29);
}

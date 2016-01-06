/* LED */
#ifndef LED_H
#define LED_H

#include <stdint.h>

#define SIM_SCGC5 (*(volatile uint32_t *)0x40048038)
#define PORTD_PCR5 (*(volatile uint32_t *) 0x4004C014)
#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004D074)
#define GPIOD_PDDR (*(volatile uint32_t *) 0x400F0D4)
#define GPIOE_PDDR (*(volatile uint32_t *) 0x4004D074)
#define GPIOD_PSOR (*(volatile uint32_t *) 0x400FF0C4)
#define GPIOE_PSOR (*(volatile uint32_t *) 0x400FF104)

void
led_init(void);

#endif //LED_H

/* LED */
#ifndef LED_H
#define LED_H

#include <stdint.h>

#define SIM_SCGC5 (*(volatile uint32_t *) 0x40048038)
#define PORTD_PCR5 (*(volatile uint32_t *) 0x4004C014)
#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004D074)
#define GPIOD_PDDR (*(volatile uint32_t *) 0x400FF0D4)
#define GPIOE_PDDR (*(volatile uint32_t *) 0x400FF114)
#define GPIOD_PSOR (*(volatile uint32_t *) 0x400FF0C4)
#define GPIOE_PSOR (*(volatile uint32_t *) 0x400FF104)
#define GPIOD_PCOR (*(volatile uint32_t *) 0x400FF0C8)
#define GPIOE_PCOR (*(volatile uint32_t *) 0x400FF108)
#define GPIOD_PTOR (*(volatile uint32_t *) 0x400FF0CC)
#define GPIOE_PTOR (*(volatile uint32_t *) 0x400FF10C)

#define SET(x) (1 << x)
#define CLEAR(x) (~(1 << x))

void
led_init(void);

void
led_on(void);

void
led_off(void);

void
led_toggle(void);

#endif //LED_H

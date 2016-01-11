/* UART */
#ifndef UART_H
#define UART_H

#include <stdint.h>

#define UART0_C2 (*(volatile uint8_t *) 0x4006A003)
#define SIM_SOPT2 (*(volatile uint32_t *) 0x40048004)
#define SIM_SCGC4 (*(volatile uint32_t *) 0x40048034)
#define UART0_C4 (*(volatile uint8_t *) 0x4006A00A)
#define UART0_BDH (*(volatile uint8_t *) 0x4006A000)
#define UART0_BDL (*(volatile uint8_t *) 0x4006A001)
#define UART0_C1 (*(volatile uint8_t *) 0x4006A002)
#define SIM_SCGC5 (*(volatile uint32_t *) 0x40048038)
#define PORTA_PCR1 (*(volatile uint32_t *) 0X40049004)
#define PORTA_PCR2 (*(volatile uint32_t *) 0x40049008)

#define SET(x) (1 << x)
#define CLEAR(x) (~(1 << x))

void
uart_init(void);

#endif //UART_H

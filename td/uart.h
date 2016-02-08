/* UART */
#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "irq.h"

/* function pointer : void function(void) */
typedef void (*VPFV)(void);

void			uart_init(VPFV);
void			uart_putchar(char c);
unsigned	char uart_getchar(void);
void			uart_puts(const char *s);
void			uart_gets(char *s, int size);

void			UART0_IRQHandler(void);

extern uint8_t received_byte;

#endif /* UART_H */

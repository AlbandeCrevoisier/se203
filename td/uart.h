/* UART */
#ifndef UART_H
#define UART_H

#include <stdint.h>

void     uart_init(void);
void     uart_putchar(char c);
unsigned char uart_getchar(void);
void     uart_puts(const char *s);
void     uart_gets(char *s, int size);

#endif //UART_H

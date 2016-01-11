/* UART main */
#include "uart.h"
#include "../clocks/clocks.h"

int
main(void)
{
	clocks_init();
	uart_init();
	uart_putchar('A');
	uart_putchar(uart_getchar());
}

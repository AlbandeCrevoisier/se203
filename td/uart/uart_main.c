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
	const char *s = "Hello world!";
	uart_puts(s);
	char *t = "";
	uart_gets(t, 10);
	uart_puts(t);
}

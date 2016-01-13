/* UART main */
#include "uart.h"
#include "../clocks/clocks.h"
#include <stdint.h>

#define TEST_SIZE 1000

int
main(void)
{
	int i;
	uint32_t s = 0;

	clocks_init();
	uart_init();

	for (i = 0; i < TEST_SIZE; i++)
		s += uart_getchar();

	return s;
}

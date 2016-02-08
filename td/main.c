/* main */
#include "irq.h"
#include "clocks.h"
#include "matrix.h"
#include "buttons.h"
#include "uart.h"

void UART0_IRQHandler(void);

int
main(void)
{

	clocks_init();
	matrix_init();
	irq_init();
	button_init();
	uart_init();

	while (1)
		print_matrix();

	deactivate_rows();

	return 0;
}

void
UART0_IRQHandler(void)
{
	static int i = 0;
	if (uart_byte == 0xFF) {
		i = 0;
	} else {
		if ((i % NBCOL) % NBLED_PIXEL == 0)
			matrix[i / NBCOL][i % NBCOL].r = uart_byte;
		else if ((i % NBCOL) % NBLED_PIXEL == 1)
			matrix[i / NBCOL][i % NBCOL].r = uart_byte;
		else if ((i % NBCOL) % NBLED_PIXEL == 2)
			matrix[i / NBCOL][i % NBCOL].r = uart_byte;
		i++;
	}
}

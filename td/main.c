/* main */
#include "irq.h"
#include "clocks.h"
#include "matrix.h"
#include "buttons.h"
#include "uart.h"

int
main(void)
{
	clocks_init();
	matrix_init(&received_byte);
	irq_init(uart_set_matrix);
	button_init();
	uart_init();

	while (1)
		print_matrix();

	deactivate_rows();

	return 0;
}

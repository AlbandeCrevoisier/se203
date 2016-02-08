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
	irq_init();
	button_init();
	uart_init(uart_set_matrix);

	while (1)
		print_matrix();

	deactivate_rows();

	return 0;
}

/* Matrix main */
#include "clocks.h"
#include "irq.h"
#include "matrix.h"

int
main(void)
{
	clocks_init();
	matrix_init();
	irq_init();

	test_pixels();

	return 0;
}

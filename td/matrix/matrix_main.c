/* Matrix main */
#include "matrix.h"
#include "../clocks/clocks.h"

int
main(void)
{
	int i, j;
	extern uint8_t _binary_image_raw_start;
	rgb_color matrix[8][8];

	clocks_init();	
	matrix_init();

	/* copy image.raw */
	for (i = 0; i < NBROW; i++) {
		for (int j = 0; j < NBCOL; j++) {
			matrix[i][j].r = (uint8_t) *(&_binary_image_raw_start + (3 * i) + (j * NBCOL));
			matrix[i][j].g = (uint8_t) *(&_binary_image_raw_start + (3 * i + 1) + (j * NBCOL));
			matrix[i][j].b = (uint8_t) *(&_binary_image_raw_start + (3 * i + 2) + (j * NBCOL));
		}
	}

	/* print image */
	while (1) {
		for (i = 0; i < NBROW; i++) {
			mat_set_row(i, matrix[i]);
			for (j = 0; j < NOP; j++)
				asm volatile ("nop");
			deactivate_row(i);
		}
	}
}

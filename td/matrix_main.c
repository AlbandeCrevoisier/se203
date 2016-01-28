/* Matrix main */
#include "matrix.h"
#include "clocks.h"

int
main(void)
{
    int i, j, k;
    extern uint8_t _binary_image_raw_start;
    uint8_t *tmp = &_binary_image_raw_start;
    rgb_color matrix[8][8];

    clocks_init();    
    matrix_init();

    /* copy image.raw */
    for (i = 0; i < NBROW; i++) {
        for (int j = 0; j < NBCOL; j++) {
            matrix[i][j].r = *(tmp++);
            matrix[i][j].g = *(tmp++);
            matrix[i][j].b = *(tmp++);
        }
    }

    /* print image */
    for (k = 0; k < 1000; k++) {
        for (i = 0; i < NBROW; i++) {
            mat_set_row(i, matrix[i]);
            for (j = 0; j < NOP1MS; j++)
                asm volatile ("nop");
            deactivate_row(i);
        }
    }

    deactivate_rows();
}

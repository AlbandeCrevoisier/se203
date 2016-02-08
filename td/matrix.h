/* Matrix */
#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

#define NOP1MS	6000
#define NBROW	8
#define NBCOL 	8

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} rgb_color;

extern rgb_color matrix[8][8];

/* received byte by the UART */
void matrix_init(*uint8_t);
void test_pixels(void);
void mat_set_row(int, const rgb_color*);
void deactivate_rows(void);
void test_pixels(void);
void print_matrix(void);

#endif /* MATRIX_H */

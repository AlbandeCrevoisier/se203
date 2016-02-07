/* Matrix */
#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} rgb_color;

void matrix_init(void);
void test_pixels(void);
void mat_set_row(int, const rgb_color*);
void deactivate_rows(void);

#define NOP1MS 6000
#define NBROW  8
#define NBCOL  8

void test_pixels(void);

#endif //MATRIX_H

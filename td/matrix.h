/* Matrix */
#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} rgb_color;

#define NOP1MS 6000
#define NBROW  8
#define NBCOL  8

void matrix_init(void);
void bank0_init(void);
void deactivate_row(int);
void deactivate_rows(void);
void activate_row(int);
void send_byte(uint8_t, int);
void mat_set_row(int, const rgb_color*);
void test_pixels(void);

#endif //MATRIX_H

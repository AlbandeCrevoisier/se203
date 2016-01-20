/* Matrix */
#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

#define SIM_SCGC5 (*(volatile uint32_t *) 0x40048038)
#define GPIOA_PSOR (*(volatile uint32_t *) 0x400FF004)
#define GPIOA_PCOR (*(volatile uint32_t *) 0x400FF008)
#define GPIOA_PTOR (*(volatile uint32_t *) 0x400FF00C)
#define GPIOA_PDDR (*(volatile uint32_t *) 0x400FF014)
#define GPIOB_PSOR (*(volatile uint32_t *) 0x400FF044)
#define GPIOB_PCOR (*(volatile uint32_t *) 0x400FF048)
#define GPIOB_PTOR (*(volatile uint32_t *) 0x400FF04C)
#define GPIOB_PDDR (*(volatile uint32_t *) 0x400FF054)
#define GPIOC_PSOR (*(volatile uint32_t *) 0x400FF084)
#define GPIOC_PCOR (*(volatile uint32_t *) 0x400FF088)
#define GPIOC_PTOR (*(volatile uint32_t *) 0x400FF08C)
#define GPIOC_PDDR (*(volatile uint32_t *) 0x400FF094)
#define GPIOD_PSOR (*(volatile uint32_t *) 0x400FF0C4)
#define GPIOD_PCOR (*(volatile uint32_t *) 0x400FF0C8)
#define GPIOD_PTOR (*(volatile uint32_t *) 0x400FF0CC)
#define GPIOD_PDDR (*(volatile uint32_t *) 0x400FF0D4)
#define PORTB_PCR0 (*(volatile uint32_t *) 0x4004A000)	/* SB */
#define PORTB_PCR1 (*(volatile uint32_t *) 0x4004A004)	/* LAT */
#define PORTB_PCR2 (*(volatile uint32_t *) 0x4004A008)	/* RST */
#define PORTC_PCR8 (*(volatile uint32_t *) 0x4004B020)	/* SCK */
#define PORTC_PCR9 (*(volatile uint32_t *) 0x4004B024)	/* SDA */
#define PORTA_PCR13 (*(volatile uint32_t *) 0x40049034)	/* C0 */
#define PORTD_PCR2 (*(volatile uint32_t *) 0x4004C008)	/* C1 */
#define PORTD_PCR4 (*(volatile uint32_t *) 0x4004C010)	/* C2 */
#define PORTD_PCR6 (*(volatile uint32_t *) 0x4004C018)	/* C3 */
#define PORTD_PCR7 (*(volatile uint32_t *) 0x4004C01C)	/* C4 */
#define PORTD_PCR5 (*(volatile uint32_t *) 0x4004C014)	/* C5 */
#define PORTA_PCR12 (*(volatile uint32_t *) 0x40049030)	/* C6 */
#define PORTA_PCR4 (*(volatile uint32_t *) 0x40049010)	/* C7 */

#define SET(x) (1 << x)
#define CLEAR(x) (~(1 << x))

void	matrix_init();
void	SB(int);
void	LAT(int);
void	RST(int);
void	SCK(int);
void	SDA(int);
void	C0(int);
void	C1(int);
void	C2(int);
void	C3(int);
void	C4(int);
void	C5(int);
void	C6(int);
void	C7(int);


#endif MATRIX_H

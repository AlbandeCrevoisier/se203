/* Matrix */
#include "matrix.h"

#define NOP500MS 3000000
#define NOP100MS 600000

#define SIM_SCGC5   (*(volatile uint32_t *) 0x40048038)
#define GPIOA_PSOR  (*(volatile uint32_t *) 0x400FF004)
#define GPIOA_PCOR  (*(volatile uint32_t *) 0x400FF008)
#define GPIOA_PTOR  (*(volatile uint32_t *) 0x400FF00C)
#define GPIOA_PDDR  (*(volatile uint32_t *) 0x400FF014)
#define GPIOB_PSOR  (*(volatile uint32_t *) 0x400FF044)
#define GPIOB_PCOR  (*(volatile uint32_t *) 0x400FF048)
#define GPIOB_PTOR  (*(volatile uint32_t *) 0x400FF04C)
#define GPIOB_PDDR  (*(volatile uint32_t *) 0x400FF054)
#define GPIOC_PSOR  (*(volatile uint32_t *) 0x400FF084)
#define GPIOC_PCOR  (*(volatile uint32_t *) 0x400FF088)
#define GPIOC_PTOR  (*(volatile uint32_t *) 0x400FF08C)
#define GPIOC_PDDR  (*(volatile uint32_t *) 0x400FF094)
#define GPIOD_PSOR  (*(volatile uint32_t *) 0x400FF0C4)
#define GPIOD_PCOR  (*(volatile uint32_t *) 0x400FF0C8)
#define GPIOD_PTOR  (*(volatile uint32_t *) 0x400FF0CC)
#define GPIOD_PDDR  (*(volatile uint32_t *) 0x400FF0D4)
#define PORTB_PCR0  (*(volatile uint32_t *) 0x4004A000) /* SB  */
#define PORTB_PCR1  (*(volatile uint32_t *) 0x4004A004) /* LAT */
#define PORTB_PCR2  (*(volatile uint32_t *) 0x4004A008) /* RST */
#define PORTC_PCR8  (*(volatile uint32_t *) 0x4004B020) /* SCK */
#define PORTC_PCR9  (*(volatile uint32_t *) 0x4004B024) /* SDA */
#define PORTA_PCR13 (*(volatile uint32_t *) 0x40049034) /* C0  */
#define PORTD_PCR2  (*(volatile uint32_t *) 0x4004C008) /* C1  */
#define PORTD_PCR4  (*(volatile uint32_t *) 0x4004C010) /* C2  */
#define PORTD_PCR6  (*(volatile uint32_t *) 0x4004C018) /* C3  */
#define PORTD_PCR7  (*(volatile uint32_t *) 0x4004C01C) /* C4  */
#define PORTD_PCR5  (*(volatile uint32_t *) 0x4004C014) /* C5  */
#define PORTA_PCR12 (*(volatile uint32_t *) 0x40049030)  /* C6  */
#define PORTA_PCR4  (*(volatile uint32_t *) 0x40049010) /* C7  */

#define SET(x)   (1 << x)
#define CLEAR(x) (~(1 << x))

#define SB(x)   (x ? (GPIOB_PSOR |= SET(0))  : (GPIOB_PCOR |= SET(0)))
#define LAT(x)  (x ? (GPIOB_PSOR |= SET(1))  : (GPIOB_PCOR |= SET(1)))
#define RST(x)  (x ? (GPIOB_PSOR |= SET(2))  : (GPIOB_PCOR |= SET(2)))
#define SCK(x)  (x ? (GPIOC_PSOR |= SET(8))  : (GPIOC_PCOR |= SET(8)))
#define SDA(x)  (x ? (GPIOC_PSOR |= SET(9))  : (GPIOC_PCOR |= SET(9)))
#define ROW0(x) (x ? (GPIOA_PSOR |= SET(13)) : (GPIOA_PCOR |= SET(13)))
#define ROW1(x) (x ? (GPIOD_PSOR |= SET(2))  : (GPIOD_PCOR |= SET(2)))
#define ROW2(x) (x ? (GPIOD_PSOR |= SET(4))  : (GPIOD_PCOR |= SET(4)))
#define ROW3(x) (x ? (GPIOD_PSOR |= SET(6))  : (GPIOD_PCOR |= SET(6)))
#define ROW4(x) (x ? (GPIOD_PSOR |= SET(7))  : (GPIOD_PCOR |= SET(7)))
#define ROW5(x) (x ? (GPIOD_PSOR |= SET(5))  : (GPIOD_PCOR |= SET(5)))
#define ROW6(x) (x ? (GPIOA_PSOR |= SET(12)) : (GPIOA_PCOR |= SET(12)))
#define ROW7(x) (x ? (GPIOA_PSOR |= SET(4))  : (GPIOA_PCOR |= SET(4)))

void bank0_init(void);
void pulse_SCK(void);
void pulse_LAT(void);
void deactivate_row(int);
void activate_row(int);
void send_byte(uint8_t, int);

void
matrix_init(void)
{

    int i;

    /* Clocks port A, B, C, and D */
    SIM_SCGC5 |= (SET(9) | SET(10) | SET(11) | SET(12));

    /* GPIO mode */
    PORTB_PCR0  = 0x103;
    PORTB_PCR1  = 0x103;
    PORTB_PCR2  = 0x103;
    PORTC_PCR8  = 0x103;
    PORTC_PCR9  = 0x103;
    PORTA_PCR13 = 0x103;
    PORTD_PCR2  = 0x103;
    PORTD_PCR4  = 0x103;
    PORTD_PCR6  = 0x103;
    PORTD_PCR7  = 0x103;
    PORTD_PCR5  = 0x103;
    PORTA_PCR12 = 0x103;
    PORTA_PCR4  = 0x103;

    /* output mode */
    GPIOB_PDDR |= SET(0);
    GPIOB_PDDR |= SET(1);
    GPIOB_PDDR |= SET(2);
    GPIOC_PDDR |= SET(8);
    GPIOC_PDDR |= SET(9);
    GPIOA_PDDR |= SET(13);
    GPIOD_PDDR |= SET(2);
    GPIOD_PDDR |= SET(4);
    GPIOD_PDDR |= SET(6);
    GPIOD_PDDR |= SET(7);
    GPIOD_PDDR |= SET(5);
    GPIOA_PDDR |= SET(12);
    GPIOA_PDDR |= SET(4);

    /* init */
    RST(0);
    LAT(1);
    SB(1);
    SCK(0);
    SDA(1);
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);

    /* ~100ms */
    for (i = 0; i < NOP100MS; i++)
        asm volatile ("nop");

    RST(1);
    bank0_init();
}

void
bank0_init(void)
{
    int i;
    for (i = 0; i < (144/8); i++)
        send_byte(0xFF, 0);
    pulse_LAT();
}

void
pulse_SCK(void)
{
    /* 24 MHz : 1 nop ~= 40ns. SCK requires >25ns. */
    SCK(0);
    SCK(1);
    SCK(0);
}

void
pulse_LAT(void)
{
    /* 24 MHz : 1 nop ~= 40ns. Lat requires >25ns and >7ns. */
    LAT(1);
    LAT(0);
    LAT(1);
}

void
deactivate_rows(void)
{
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);
}

void
activate_row(int r)
{
    switch (r) {
    case 0: ROW0(1);
            break;
    case 1: ROW1(1);
            break;
    case 2: ROW2(1);
            break;
    case 3: ROW3(1);
            break;
    case 4: ROW4(1);
            break;
    case 5: ROW5(1);
            break;
    case 6: ROW6(1);
            break;
    case 7: ROW7(1);
            break;
    }
}

void
deactivate_row(int r)
{
    switch (r) {
    case 0: ROW0(0);
            break;
    case 1: ROW1(0);
            break;
    case 2: ROW2(0);
            break;
    case 3: ROW3(0);
            break;
    case 4: ROW4(0);
            break;
    case 5: ROW5(0);
            break;
    case 6: ROW6(0);
            break;
    case 7: ROW7(0);
            break;
    }
}

void
send_byte(uint8_t val, int bank)
{
    int i;
    SB(bank);
    for (i = 0; i < 8; i++) {
        SDA(val & (1 << (7 - i)));
        pulse_SCK();
    }
}

/* val : array of 8 * rgb_color */
void
mat_set_row(int row, const rgb_color *val)
{
    int i;
    for (i = 7; i > -1; i--) {
        send_byte((val[i]).b, 1);
        send_byte(val[i].g, 1);
        send_byte(val[i].r, 1);
    }
    deactivate_rows();
    activate_row(row);
    pulse_LAT();
}

void
test_pixels(void)
{
    int i, j;
    rgb_color row[8];
    
    /* red */
    for (i = 0; i < NBCOL; i++) {
        row[i].r = 0xFF;
        row[i].g = 0;
        row[i].b = 0;
    }
    for (i = 0; i < NBROW; i++) {
        mat_set_row(i, row);
        for (j = 0; j < NOP500MS; j++)
            asm volatile ("nop");
    }

    /* green */
    for (i = 0; i < NBCOL; i++) {
        row[i].r = 0;
        row[i].g = 0xFF;
        row[i].b = 0;
    }
    for (i = 0; i < NBROW; i++) {
        mat_set_row(i, row);
        for (j = 0; j < NOP500MS; j++)
            asm volatile ("nop");
    }

    /* blue */
    for (i = 0; i < NBCOL; i++) {
        row[i].r = 0;
        row[i].g = 0;
        row[i].b = 0xFF;
    }
    for (i = 0; i < NBROW; i++) {
        mat_set_row(i, row);
        for (j = 0; j < NOP500MS; j++)
            asm volatile ("nop");
    }

    deactivate_rows();
}

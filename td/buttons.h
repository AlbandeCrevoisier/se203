/* buttons */
#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>
#include "irq.h"

void PCMCD_IRQHandler(void);

void button_init(void);

#endif /* BUTTONS_H */

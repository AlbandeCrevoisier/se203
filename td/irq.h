/* IRQ */
#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>

#define enable_irq() (asm ("cpsie i"))
#define disable_irq() (asm ("cpsid i"))

#endif // IRQ_H

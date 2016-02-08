/* IRQ */
#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>

#define enable_irq() asm ("cpsie i")
#define disable_irq() asm ("cpsid i")

void irq_init(void);
void irq_enable(int irq_nb);
void irq_disable(int irq_nb);

#endif /* IRQ_H */

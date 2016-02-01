/* IRQ */
#include "irq.h"

#define MAKE_DEFAULT_HANDLER(X) \
	(__attribute__((weak))\
	void\
	X_IRQHandler(void) {\
	disable_irq();\
	while(1);})

extern uint8_t _stack, _start;

__attribute__((weak))
void
handler(void)
{
	disable_irq();
	while(1);
}

MAKE_DEFAULT_HANDLER(NMI_Handler)
MAKE_DEFAULT_HANDLER(HardFault_Handler)
MAKE_DEFAULT_HANDLER(SVC_Handler)
MAKE_DEFAULT_HANDLER(PendSV_Handler)
MAKE_DEFAULT_HANDLER(SysTick_Handler)
MAKE_DEFAULT_HANDLER(DMA0)
MAKE_DEFAULT_HANDLER(DMA1)
MAKE_DEFAULT_HANDLER(DMA2)
MAKE_DEFAULT_HANDLER(DMA3)
MAKE_DEFAULT_HANDLER(FTFA)
MAKE_DEFAULT_HANDLER(PMC)
MAKE_DEFAULT_HANDLER(LLWU)
MAKE_DEFAULT_HANDLER(I2C0)
MAKE_DEFAULT_HANDLER(I2C1)
MAKE_DEFAULT_HANDLER(SPI0)
MAKE_DEFAULT_HANDLER(SPI1)
MAKE_DEFAULT_HANDLER(UART0)
MAKE_DEFAULT_HANDLER(UART1)
MAKE_DEFAULT_HANDLER(UART2)
MAKE_DEFAULT_HANDLER(ADC0)
MAKE_DEFAULT_HANDLER(CMP0)
MAKE_DEFAULT_HANDLER(TPM0)
MAKE_DEFAULT_HANDLER(RTC0)
MAKE_DEFAULT_HANDLER(RTC1)
MAKE_DEFAULT_HANDLER(PIT)
MAKE_DEFAULT_HANDLER(I2S0)
MAKE_DEFAULT_HANDLER(USBOTG)
MAKE_DEFAULT_HANDLER(DAC0)
MAKE_DEFAULT_HANDLER(TSI0)
MAKE_DEFAULT_HANDLER(MCG)
MAKE_DEFAULT_HANDLER(LPTMR0)
MAKE_DEFAULT_HANDLER(SLCD)
MAKE_DEFAULT_HANDLER(PCMA)
MAKE_DEFAULT_HANDLER(PCMCD)

void *vector_table[] = {
	/* Stack and Reset handler */
	&_stack,	/* Top of stack */
	_start,	/* Reset handler */

	/* ARM internal exceptions */
	NMI_Handler,
	HardFault_Handler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	SVC_Handler,
	0,
	0,
	PendSV_Handler,		/* Pending SVC handler */
	SysTick_Handler,

	/* KL46 external interrupts */
	DMA0_IRQHandler,		/* DMA channel 0 transfer complete and error */
	DMA1_IRQHandler,		/* DMA channel 1 transfer complete and error */
	DMA2_IRQHandler,		/* DMA channel 2 transfer complete and error */
	DMA3_IRQHandler,		/* DMA channel 3 transfer complete and error */
	FTFA_IRQHandler,		/* Command complete and read collision */
	PMC_IRQHandler,
	LLWU_IRQHandler,		/* Low Leakage Wakeup */
	I2C0_IRQHandler,
	I2C1_IRQHandler,
	SPI0_IRQHandler,		/* Single interrupt vector for all sources */
	SPI1_IRQHandler,		/* Single interrupt vector for all sources */
	UART0_IRQHandler,		/* Status and error */
	UART1_IRQHandler,		/* Status and error */
	UART2_IRQHandler,		/* Status and error */
	ADC0_IRQHandler,
	CMP0_IRQHandler,
	TPM0_IRQHandler,
	TPM1_IRQHandler,
	TMP2_IRQHandler,
	RTC0_IRQHandler,		/* Alarm interrupt */
	RTC1_IRQHandler,		/* Seconds interrupt */
	PIT_IRQHandler,		/* Single interrupt vector for all channels */
	I2S0_IRQHandler,		/* Single interrupt vector for all channels */
	USBOTG_IRQHandler,
	DAC0_IRQHandler,
	TSI0_IRQHandler,
	MCG_IRQHandler,
	LPTMR0_IRQHandler,
	SLCD_IRQHandler,
	PCMA_IRQHandler,		/* Pin detect (Port A) */
	PCMCD_IRQHandler		/* Pin detect (Single interrupt vector for Port C and Port D) */
	};

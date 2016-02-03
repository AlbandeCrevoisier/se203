/* IRQ */
#include "irq.h"

#define MAKE_DEFAULT_HANDLER(X) \
	__attribute__((weak)) \
	void \
	X##Handler(void) {\
	disable_irq();\
	while(1);}

MAKE_DEFAULT_HANDLER(NMI_)
MAKE_DEFAULT_HANDLER(HardFault_)
MAKE_DEFAULT_HANDLER(SVC_)
MAKE_DEFAULT_HANDLER(PendSV_)
MAKE_DEFAULT_HANDLER(SysTick_)
MAKE_DEFAULT_HANDLER(DMA0_IRQ)
MAKE_DEFAULT_HANDLER(DMA1_IRQ)
MAKE_DEFAULT_HANDLER(DMA2_IRQ)
MAKE_DEFAULT_HANDLER(DMA3_IRQ)
MAKE_DEFAULT_HANDLER(FTFA_IRQ)
MAKE_DEFAULT_HANDLER(PMC_IRQ)
MAKE_DEFAULT_HANDLER(LLWU_IRQ)
MAKE_DEFAULT_HANDLER(I2C0_IRQ)
MAKE_DEFAULT_HANDLER(I2C1_IRQ)
MAKE_DEFAULT_HANDLER(SPI0_IRQ)
MAKE_DEFAULT_HANDLER(SPI1_IRQ)
MAKE_DEFAULT_HANDLER(UART0_IRQ)
MAKE_DEFAULT_HANDLER(UART1_IRQ)
MAKE_DEFAULT_HANDLER(UART2_IRQ)
MAKE_DEFAULT_HANDLER(ADC0_IRQ)
MAKE_DEFAULT_HANDLER(CMP0_IRQ)
MAKE_DEFAULT_HANDLER(TPM0_IRQ)
MAKE_DEFAULT_HANDLER(TPM1_IRQ)
MAKE_DEFAULT_HANDLER(TPM2_IRQ)
MAKE_DEFAULT_HANDLER(RTC0_IRQ)
MAKE_DEFAULT_HANDLER(RTC1_IRQ)
MAKE_DEFAULT_HANDLER(PIT_IRQ)
MAKE_DEFAULT_HANDLER(I2S0_IRQ)
MAKE_DEFAULT_HANDLER(USBOTG_IRQ)
MAKE_DEFAULT_HANDLER(DAC0_IRQ)
MAKE_DEFAULT_HANDLER(TSI0_IRQ)
MAKE_DEFAULT_HANDLER(MCG_IRQ)
MAKE_DEFAULT_HANDLER(LPTMR0_IRQ)
MAKE_DEFAULT_HANDLER(SLCD_IRQ)
MAKE_DEFAULT_HANDLER(PCMA_IRQ)
MAKE_DEFAULT_HANDLER(PCMCD_IRQ)

void *vector_table[] = {
	/* Stack and Reset handler */
	&_stack,	/* Top of stack */
	&_start,	/* Reset handler */

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
	TPM2_IRQHandler,
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

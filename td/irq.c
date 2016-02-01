/* IRQ */
#include "irq.h"

void *vector_table[] = {
	/* Stack and Reset handler */
	&_stack,			/* Top of stack */
	_start,			/* Reset handler */

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
	PendSV_Handler,	/* Pending SVC handler */
	SysTick_Handler,

	/* KL46 external interrupts */
	DMA0_IRQHandler,
	DMA1_IRQHandler,
	DMA2_IRQHandler,
	DMA3_IRQHandler,
	DMA4_IRQHandler,
	DMA5_IRQHandler,
	DMA6_IRQHandler,
	DMA7_IRQHandler,
	DMA8_IRQHandler,
	DMA9_IRQHandler,
	DMA10_IRQHandler,
	DMA11_IRQHandler,
	DMA12_IRQHandler,
	DMA13_IRQHandler,
	DMA14_IRQHandler,
	DMA15_IRQHandler,
	DMA16_IRQHandler,
	DMA17_IRQHandler,
	DMA18_IRQHandler,
	DMA19_IRQHandler,
	DMA20_IRQHandler,
	DMA21_IRQHandler,
	DMA22_IRQHandler,
	DMA23_IRQHandler,
	DMA24_IRQHandler,
	DMA25_IRQHandler,
	DMA26_IRQHandler,
	DMA27_IRQHandler,
	DMA28_IRQHandler,
	DMA29_IRQHandler,
	DMA30_IRQHandler,
	DMA31_IRQHandler
	};

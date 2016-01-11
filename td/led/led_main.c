#include "led.h"

int
main(void)
{
	led_init();
	led_on();
	led_off();
	led_toggle();
}

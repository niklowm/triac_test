/*
 * led.c
 *
 * Created: 2016-08-23 22:09:23
 *  Author: niting
 */ 

#include <asf.h>

void led_on(uint8_t b)
{
	if (!b)
	{
		ioport_set_pin_level(LED0_GPIO, IOPORT_PIN_LEVEL_HIGH);
	}
	else
	{
		ioport_set_pin_level(LED0_GPIO, IOPORT_PIN_LEVEL_LOW);
	}
}
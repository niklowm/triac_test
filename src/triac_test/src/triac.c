#include <asf.h>
#include "triac.h"


void triac_init(zero_cross_handler_t zero_cross_handler)
{
	// init trig...
	ioport_set_pin_dir(GPIO_TRIAC_TRIG, IOPORT_DIR_OUTPUT);
	ioport_set_pin_mode(GPIO_TRIAC_TRIG, 0);
	
	// init zero detect...
	ioport_set_pin_dir(GPIO_TRIAC_ZERO_CROSS, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(GPIO_TRIAC_ZERO_CROSS, (IOPORT_MODE_PULLUP | IOPORT_MODE_DEBOUNCE));
	ioport_set_pin_sense_mode(GPIO_TRIAC_ZERO_CROSS, (IOPORT_SENSE_RISING));
	
	// Configure Pushbutton 1
	pmc_enable_periph_clk(PIN_PUSHBUTTON_1_ID);
	pio_set_debounce_filter(PIN_PUSHBUTTON_1_PIO, PIN_PUSHBUTTON_1_MASK, 10);
	
	/* Interrupt on rising edge  */
	pio_handler_set(PIOA, ID_PIOA, PIO_PA11, (PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE), zero_cross_handler);
	NVIC_EnableIRQ((IRQn_Type) ID_PIOA);
	pio_handler_set_priority(PIOA, (IRQn_Type) ID_PIOA, 0);
	pio_enable_interrupt(PIOA, PIO_PA11);
}

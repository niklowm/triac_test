
#ifndef TRIAC_H
#define TRIAC_H

// todo: select real pins...
#define GPIO_TRIAC_TRIG			(PIO_PA11_IDX)
#define GPIO_TRIAC_ZERO_CROSS	(PIO_PA11_IDX)

typedef void (*zero_cross_handler_t)(uint32_t, uint32_t);


void triac_init();

#endif // TRIAC_H

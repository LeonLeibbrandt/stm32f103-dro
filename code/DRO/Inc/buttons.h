#ifndef BUTTONS_H
#define BUTTONS_H

#include "stm32f1xx_hal.h"

#include <inttypes.h>
#include <stdbool.h>

typedef struct {
	GPIO_TypeDef *port;
	uint16_t pin;
	uint32_t ticks;
	GPIO_PinState updown;
} button;

extern volatile button *buttons[2][3];
extern volatile uint32_t button_ticks;
extern volatile uint8_t button_poll;
extern volatile bool buttonIRQDisabled;


void buttons_setup();
void check_buttons(uint16_t pins, uint8_t poll, uint16_t pin, uint8_t index);


#endif

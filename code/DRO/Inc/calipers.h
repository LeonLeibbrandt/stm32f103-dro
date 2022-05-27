#ifndef CALIPERS_H
#define CALIPERS_H

#include "stm32f1xx_hal.h"

#include <inttypes.h>
#include <stdbool.h>

typedef struct {
  GPIO_TypeDef *port;
  uint16_t clk_pin;
  uint16_t dat_pin;
  IRQn_Type irq;
  int16_t current;
  int16_t value;
  int16_t offset;
  int16_t invert;
  uint32_t last;
  uint8_t bit;
  bool reading;
  bool changed;
} caliper;

extern volatile caliper *calipers[3];

extern void read_21bit_caliper(volatile caliper *cal);

#endif

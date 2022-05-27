#include "../../DRO/Inc/calipers.h"

#include <math.h>
#include <stdio.h>

#include <main.h>
#include <gpio.h>

volatile caliper *calipers[3] =
  {
	&(caliper){CAL0DAT_GPIO_Port, CAL0CLK_Pin, CAL0DAT_Pin, EXTI0_IRQn, 0, 0, 0, -1, 0, 0, false, true}, // X
	&(caliper){CAL1DAT_GPIO_Port, CAL1CLK_Pin, CAL1DAT_Pin, EXTI1_IRQn, 0, 0, 0, -1, 0, 0, false, true}, // Y
	&(caliper){CAL2DAT_GPIO_Port, CAL2CLK_Pin, CAL2DAT_Pin, EXTI2_IRQn, 0, 0, 0,  1, 0, 0, false, true}  // Z
  };


void read_21bit_caliper(volatile caliper *cal)
{
	uint32_t local_system_millis = HAL_GetTick();
	uint32_t delay = local_system_millis - cal->last;
	cal->last = local_system_millis;
	if (delay > 90) {
#ifdef DEBUG
		// printf("Starting %d -> %lu -> %lu\n", cal->clk_pin, local_system_millis, delay);
#endif
		cal->reading = true;
		cal->bit = 0;
		cal->value = 0;
	}
	else
	{
		if (cal->reading)
		{
			++cal->bit;
			if (cal->bit > 0 && cal->bit <= 20)
			{
				if (HAL_GPIO_ReadPin(cal->port, cal->dat_pin) == GPIO_PIN_SET)
				{
					cal->value |= 1 << (cal->bit-1);
				}
			}
			if (cal->bit == 21)
			{
				if (HAL_GPIO_ReadPin(cal->port, cal->dat_pin) == GPIO_PIN_SET)
					cal->value = cal->value * -1 * cal->invert;
				else
					cal->value = cal->value * cal->invert;
				if (cal->current != (cal->value - cal->offset))
				{
					cal->current = cal->value - cal->offset;
					cal->changed = true;
				}
				cal->reading = false;
			}
		}
	}
}

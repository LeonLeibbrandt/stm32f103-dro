#include <stdio.h>

#include <main.h>
#include "../../DRO/Inc/buttons.h"
#include "../../DRO/Inc/calipers.h"

const uint8_t DEBOUNCE = 50;

volatile button *buttons[2][3] =
  {
   {
    &(button){BUTTIN2_GPIO_Port, BUTTIN2_Pin, 0, GPIO_PIN_RESET},
    &(button){BUTTIN1_GPIO_Port, BUTTIN1_Pin, 0, GPIO_PIN_RESET},
    &(button){BUTTIN1_GPIO_Port, BUTTIN0_Pin, 0, GPIO_PIN_RESET}
   },
   {
    &(button){BUTTIN2_GPIO_Port, BUTTIN2_Pin, 0, GPIO_PIN_RESET},
    &(button){BUTTIN1_GPIO_Port, BUTTIN1_Pin, 0, GPIO_PIN_RESET},
    &(button){BUTTIN0_GPIO_Port, BUTTIN0_Pin, 0, GPIO_PIN_RESET}
   }
  };

volatile uint8_t button_poll = 0;
volatile uint32_t button_ticks = 0;
volatile bool buttonIRQDisabled = false;

void buttons_setup()
{
	HAL_GPIO_WritePin(BUTTOUT1_GPIO_Port, BUTTOUT0_Pin | BUTTOUT1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(BUTTOUT1_GPIO_Port, BUTTOUT0_Pin, GPIO_PIN_SET);
	buttonIRQDisabled = false;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	volatile button* current = NULL;
	uint8_t index = 0;
	for (uint8_t i_indx = 0; i_indx < 3; i_indx++)
	{
		if (buttons[button_poll][i_indx]->pin == GPIO_Pin)
		{
			current = buttons[button_poll][i_indx];
			index = i_indx;
			break;
		}
	}

	if (current != NULL)
	{
		// Get Current Value of line
		GPIO_PinState updown = HAL_GPIO_ReadPin(current->port, current->pin);
		if (updown == GPIO_PIN_SET)
		{
			HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
			buttonIRQDisabled = true;
			button_ticks = 0;
			if (button_poll == 0)
			{
				calipers[index]->offset = calipers[index]->value;
				calipers[index]->current = calipers[index]->value - calipers[index]->offset;
				calipers[index]->changed = true;
			  }
			  else
			  {
				calipers[index]->offset = (calipers[index]->value + calipers[index]->offset) / 2;
				calipers[index]->current = calipers[index]->value - calipers[index]->offset;
				calipers[index]->changed = true;
		 	  }

		}
	}
}


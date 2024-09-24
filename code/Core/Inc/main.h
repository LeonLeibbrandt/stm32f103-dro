/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define CAL0CLK_Pin GPIO_PIN_0
#define CAL0CLK_GPIO_Port GPIOA
#define CAL0CLK_EXTI_IRQn EXTI0_IRQn
#define CAL0DAT_Pin GPIO_PIN_1
#define CAL0DAT_GPIO_Port GPIOA
#define CAL1CLK_Pin GPIO_PIN_2
#define CAL1CLK_GPIO_Port GPIOA
#define CAL1CLK_EXTI_IRQn EXTI2_IRQn
#define CAL1DAT_Pin GPIO_PIN_3
#define CAL1DAT_GPIO_Port GPIOA
#define CAL2CLK_Pin GPIO_PIN_4
#define CAL2CLK_GPIO_Port GPIOA
#define CAL2CLK_EXTI_IRQn EXTI4_IRQn
#define CAL2DAT_Pin GPIO_PIN_5
#define CAL2DAT_GPIO_Port GPIOA
#define CAL1SW_Pin GPIO_PIN_6
#define CAL1SW_GPIO_Port GPIOA
#define CAL2SW_Pin GPIO_PIN_7
#define CAL2SW_GPIO_Port GPIOA
#define CAL3SW_Pin GPIO_PIN_8
#define CAL3SW_GPIO_Port GPIOA
#define BUTTOUT0_Pin GPIO_PIN_5
#define BUTTOUT0_GPIO_Port GPIOB
#define BUTTOUT1_Pin GPIO_PIN_6
#define BUTTOUT1_GPIO_Port GPIOB
#define BUTTIN0_Pin GPIO_PIN_7
#define BUTTIN0_GPIO_Port GPIOB
#define BUTTIN0_EXTI_IRQn EXTI9_5_IRQn
#define BUTTIN1_Pin GPIO_PIN_8
#define BUTTIN1_GPIO_Port GPIOB
#define BUTTIN1_EXTI_IRQn EXTI9_5_IRQn
#define BUTTIN2_Pin GPIO_PIN_9
#define BUTTIN2_GPIO_Port GPIOB
#define BUTTIN2_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

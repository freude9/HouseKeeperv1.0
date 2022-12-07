/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#define BUZZER_Pin GPIO_PIN_0
#define BUZZER_GPIO_Port GPIOA
#define RGB_B_Pin GPIO_PIN_1
#define RGB_B_GPIO_Port GPIOA
#define BATT_VOLT_Pin GPIO_PIN_0
#define BATT_VOLT_GPIO_Port GPIOB
#define NX_PWR_Pin GPIO_PIN_10
#define NX_PWR_GPIO_Port GPIOB
#define LOAD_PWR_Pin GPIO_PIN_11
#define LOAD_PWR_GPIO_Port GPIOB
#define MCU_KEY_Pin GPIO_PIN_12
#define MCU_KEY_GPIO_Port GPIOB
#define RGB_G_Pin GPIO_PIN_13
#define RGB_G_GPIO_Port GPIOB
#define RGB_R_Pin GPIO_PIN_8
#define RGB_R_GPIO_Port GPIOA
#define NX_nPWR_ON_Pin GPIO_PIN_15
#define NX_nPWR_ON_GPIO_Port GPIOA
#define NX_nRST_Pin GPIO_PIN_3
#define NX_nRST_GPIO_Port GPIOB
#define WS2812_Pin GPIO_PIN_4
#define WS2812_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

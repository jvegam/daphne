/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 * @Author         : Fabian Castano
 * @Institution    : University of Antioquia
 * @Project        : DUNE-Daphne
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
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
#include "fifo_rx3.h"
#include "fifo_tx3.h"

#include "adc.h"
#include "spi.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
/** ****************************************************************************
 ** **************** FLAGS *****************************************************
 ** ****************************************************************************/
// Bits to use some flags
typedef union {
	unsigned int flag;

	struct {
		unsigned char flag00 :1; // counter to 1
		unsigned char flag01 :1; // counter to 1
		unsigned char flag02 :1; // counter to 1
		unsigned char flag03 :1; // counter to 1
		unsigned char flag04 :1; // counter to 1
		unsigned char flag05 :1; // counter to 1
		unsigned char flag06 :1; // counter to 1
		unsigned char flag07 :1; // counter to 1
		unsigned char flag08 :1; // counter to 1
		unsigned char flag09 :1; // counter to 1
		unsigned char flag10 :1; // counter to 1
		unsigned char flag11 :1; // counter to 1
		unsigned char flag12 :1; // counter to 1
		unsigned char flag13 :1; // counter to 1
		unsigned char flag14 :1; // counter to 1
		unsigned char flag15 :1; // counter to 1
		unsigned char flag16 :1; // counter to 1
		unsigned char flag17 :1; // counter to 1
		unsigned char flag18 :1; // counter to 1
		unsigned char flag19 :1; // counter to 1
		unsigned char flag20 :1; // counter to 1
		unsigned char flag21 :1; // counter to 1
		unsigned char flag22 :1; // counter to 1
		unsigned char flag23 :1; // counter to 1
		unsigned char flag24 :1; // counter to 1
		unsigned char flag25 :1; // counter to 1
		unsigned char flag26 :1; // counter to 1
		unsigned char flag27 :1; // counter to 1
		unsigned char flag28 :1; // counter to 1
		unsigned char flag29 :1; // counter to 1
		unsigned char flag30 :1; // counter to 1
		unsigned char flag31 :1; // counter to 1
	} Bits;
} STR_FLAGS;

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
#define USER_Btn_Pin GPIO_PIN_13
#define USER_Btn_GPIO_Port GPIOC
#define USER_Btn_EXTI_IRQn EXTI15_10_IRQn
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_MDC_GPIO_Port GPIOC
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_REF_CLK_GPIO_Port GPIOA
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_MDIO_GPIO_Port GPIOA
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_CRS_DV_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define CS1_Pin GPIO_PIN_1
#define CS1_GPIO_Port GPIOB
#define RMII_TXD1_Pin GPIO_PIN_13
#define RMII_TXD1_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD
#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG
#define USB_SOF_Pin GPIO_PIN_8
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_ID_Pin GPIO_PIN_10
#define USB_ID_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TX_EN_GPIO_Port GPIOG
#define RMII_TXD0_Pin GPIO_PIN_13
#define RMII_TXD0_GPIO_Port GPIOG
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define LD2_Pin GPIO_PIN_7
#define LD2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define HIGH   1
#define LOW    0
#define TRUE   1
#define FALSE  0

/** *******************************************************************************
 *  Flags define
 *  @brief   : use the definition of falgs in main.c (volatile STR_FLAGS _Events;)
 *               and use in the other files as external variable
 ** *******************************************************************************/
extern volatile STR_FLAGS _Events;
#define fl_ext_it_btn             _Events.Bits.flag00 //ok  // Flag to handle external interrupt in user button
#define fl_usart3_rx              _Events.Bits.flag01 //ok  // Flag to handle usart3 rx interrupt
#define fl_usart3_tx              _Events.Bits.flag02 //ok  // Flag to handle usart3 tx interrupt
#define fl_tim3_per               _Events.Bits.flag03 //ok  // Flag to handle timer3 period interrupt
#define fl_adc1_ch3               _Events.Bits.flag04 //ok  // Flag to handle adc1ch3 acquisition interrupt
#define fl_adc1_smp               _Events.Bits.flag05 //ok  // Flag to initiate the sample in ADC1
#define fl_adc1_print             _Events.Bits.flag06 //ok  // Flag to handle adc1 usart3 print
#define fl_spi1_isr               _Events.Bits.flag07 //ok  // Flag to handle spi1 rxtx interrupt
//#define fl_08                   _Events.Bits.flag08 //ok
//#define fl_09                   _Events.Bits.flag09 //ok
//#define fl_10                   _Events.Bits.flag10 //ok
//#define fl_11                   _Events.Bits.flag11 //ok
//#define fl_12                   _Events.Bits.flag12 //ok
//#define fl_13                   _Events.Bits.flag13 //ok
//#define fl_14                   _Events.Bits.flag14 //ok
//#define fl_15                   _Events.Bits.flag15 //ok
//#define fl_16                   _Events.Bits.flag16 //ok
//#define fl_17                   _Events.Bits.flag17 //ok
//#define fl_18                   _Events.Bits.flag18 //ok
//#define fl_19                   _Events.Bits.flag19 //ok
//#define fl_20                   _Events.Bits.flag20 //ok
//#define fl_21                   _Events.Bits.flag21 //ok
//#define fl_22                   _Events.Bits.flag22 //ok
//#define fl_23                   _Events.Bits.flag23 //ok
//#define fl_24                   _Events.Bits.flag24 //ok
//#define fl_25                   _Events.Bits.flag25 //ok
//#define fl_26                   _Events.Bits.flag26 //ok
//#define fl_27                   _Events.Bits.flag27 //ok
//#define fl_28                   _Events.Bits.flag28 //ok
//#define fl_29                   _Events.Bits.flag29 //ok
//#define fl_30                   _Events.Bits.flag30 //ok
//#define fl_31                   _Events.Bits.flag31 //ok

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

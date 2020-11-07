/**
 ******************************************************************************
 * File Name          : USART.h
 * Description        : This file provides code for the configuration
 *                      of the USART instances.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
#define USE_FIFO_USART3        TRUE

// defines for special characters
#define LF                              0x0A        //Character new line
#define CR                              0x0D        //Character carriage return
#define CHAR_NULL                       0x00        //Character null

#define _CTR_CHAR_USART3                LF          // Control character to interpret the data

/* USER CODE END Private defines */

void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */
void USART3_UART_SendChar(uint8_t *val);
void USART3_UART_SendLoad(char *load, int len);

// functions to handle the serial interruption
void USART3_UART_TX_ISR(void);
void USART3_UART_RX_ISR(void);

void USART3_Interrupt_Init(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

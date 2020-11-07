/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : fifo_rx3.h
 * @brief          : Fifo RX USART3 header file
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
#ifndef __fifo_rx3_H
#define __fifo_rx3_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "main.h"

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
// FIFO size
#define FIFO_SIZE                   4800

// delete previous definitions
#ifdef FIFO_INIT
#undef FIFO_INIT
#undef FIFO_PUT
#undef FIFO_GET
#endif

// define function names
#define FIFO_INIT                   Fifo_Rx_Init
#define FIFO_PUT                    Fifo_Rx_Put
#define FIFO_GET                    Fifo_Rx_Get

/* USER CODE END Private defines */

/* USER CODE BEGIN Prototypes */
// FIFO RX Functions
void Fifo_Rx3_Init(void);
volatile unsigned char Fifo_Rx3_Put(volatile unsigned char);
volatile unsigned char Fifo_Rx3_Get(volatile unsigned char*);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ fifo_rx3_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

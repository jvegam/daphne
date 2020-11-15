/**
 ******************************************************************************
 * File Name          : USART.c
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
// includes
#if USE_FIFO_USART3
#include "fifo_rx3.h"
#include "fifo_tx3.h"
#endif

// extern variables
extern volatile STR_FLAGS _Events;

// private data buffer
uint8_t U3RXBUFF[10];  // buffer to receive data from USART3
uint8_t U3TXBUFF[10];  // buffer to transmit data to USART3

/* USER CODE END 0 */

UART_HandleTypeDef huart3;

/* USART3 init function */

void MX_USART3_UART_Init(void) {

	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart3) != HAL_OK) {
		Error_Handler();
	}

}

void HAL_UART_MspInit(UART_HandleTypeDef *uartHandle) {

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	if (uartHandle->Instance == USART3) {
		/* USER CODE BEGIN USART3_MspInit 0 */

		/* USER CODE END USART3_MspInit 0 */
		/* USART3 clock enable */
		__HAL_RCC_USART3_CLK_ENABLE();

		__HAL_RCC_GPIOD_CLK_ENABLE();
		/**USART3 GPIO Configuration
		 PD8     ------> USART3_TX
		 PD9     ------> USART3_RX
		 */
		GPIO_InitStruct.Pin = STLK_RX_Pin | STLK_TX_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		/* USART3 interrupt Init */
		HAL_NVIC_SetPriority(USART3_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(USART3_IRQn);
		/* USER CODE BEGIN USART3_MspInit 1 */

		/* USER CODE END USART3_MspInit 1 */
	}
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *uartHandle) {

	if (uartHandle->Instance == USART3) {
		/* USER CODE BEGIN USART3_MspDeInit 0 */

		/* USER CODE END USART3_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_USART3_CLK_DISABLE();

		/**USART3 GPIO Configuration
		 PD8     ------> USART3_TX
		 PD9     ------> USART3_RX
		 */
		HAL_GPIO_DeInit(GPIOD, STLK_RX_Pin | STLK_TX_Pin);

		/* USART3 interrupt Deinit */
		HAL_NVIC_DisableIRQ(USART3_IRQn);
		/* USER CODE BEGIN USART3_MspDeInit 1 */

		/* USER CODE END USART3_MspDeInit 1 */
	}
}

/* USER CODE BEGIN 1 */
/*******************************************************************************
 * Name: SCI6_SendChar                                                         *
 * Desc: Send Data SCI6 Module                                                 *
 * Parameter: val                                                              *
 * Return: None                                                                *
 *******************************************************************************/
void USART3_UART_SendChar(uint8_t *val) {
	HAL_UART_Transmit_IT(&huart3, val, 1); // activate the hardware transmision by interruption
}

/*******************************************************************************
 * Name: SCI1_SendLoad                                                         *
 * Desc: Send Load SCI1 Module                                                 *
 * Parameter: *load, len                                                       *
 * Return: None                                                                *
 *******************************************************************************/
void USART3_UART_SendLoad(char *load, int len) {
	HAL_UART_Transmit(&huart3, load, len, HAL_MAX_DELAY); // activate the hardware transmision by interruption
}

/*******************************************************************************
 * Name: _U3InterruptHandler                                                   *
 * Desc: Interrupt SCI3 Module                                                 *
 * Parameter: None                                                             *
 * Return: None                                                                *
 *******************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	// call the function to process an interruption
	USART3_UART_RX_ISR();
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	// call the function to process an interruption
	USART3_UART_TX_ISR();
}

/*******************************************************************************
 * Name: USART3_UART_RX_ISR                                                    *
 * Desc: Interrupt SCI3 Module                                                 *
 * Parameter: None                                                             *
 * Return: None                                                                *
 *******************************************************************************/
void USART3_UART_RX_ISR(void) {
	// Programming space

#if USE_FIFO_USART3
	volatile uint8_t dataUART3;

	dataUART3 = U3RXBUFF[0];
	if (dataUART3 == CHAR_NULL) {
		__NOP();
	} else if (dataUART3 == CR) { // nothing to do, omit CR character
		__NOP();
	} else if (dataUART3 == _CTR_CHAR_USART3) { // control character arrived to USART3
		// verify if it is necessary to add this data to the queue
		// Fifo_Rx3_Put(dataUART3);
		fl_usart3_rx = TRUE; // there is an serial interrupt to be attended
	} else { // if ((datoSCI >= 0x65 && datoSCI <= 0x69) || (datoSCI >= 0x30 && datoSCI <= 0x39)) { // valid characters to the payload

		if (!Fifo_Rx3_Put(dataUART3)) {
			Fifo_Rx3_Init();
		}
	}
	HAL_UART_Receive_IT(&huart3, U3RXBUFF, 1);

#else
	// programming without fifos

#endif
}

/*******************************************************************************
 * Name: USART3_UART_TX_ISR                                                    *
 * Desc: Interrupt SCI3 Module                                                 *
 * Parameter: None                                                             *
 * Return: None                                                                *
 *******************************************************************************/
void USART3_UART_TX_ISR(void) {
	// Programming space

#if USE_FIFO_USART3
	// volatile uint8_t dataUART3;

	// try to obtain data from FIFO to write in UART3_TX
	if (Fifo_Tx3_Get(U3TXBUFF) == 1) {
		// send the data through USART3_TX
		HAL_UART_Transmit_IT(&huart3, U3TXBUFF, 1);
	} else {
		__NOP();
	}
#endif
}

/*******************************************************************************
 * Name: USART3_UART_TX_ISR                                                    *
 * Desc: Interrupt SCI3 Module                                                 *
 * Parameter: None                                                             *
 * Return: None                                                                *
 *******************************************************************************/
void USART3_Interrupt_Init(void) {
	HAL_UART_Receive_IT(&huart3, U3RXBUFF, 1);
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

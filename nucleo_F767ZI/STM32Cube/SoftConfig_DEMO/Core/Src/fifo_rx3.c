/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : fifo_rx3.c
 * @brief          : Fifo RX USART3 source file
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

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fifo_rx3.h"

/* USER CODE END Includes */

/* USER CODE BEGIN 0 */
// Variables definitions
volatile static unsigned char Fifo[FIFO_SIZE];
volatile static unsigned char *GetPtr;
volatile static unsigned char *PutPtr;

/* USER CODE END 0 */

/* USER CODE BEGIN 1 */
/*******************************************************************************
 * Name: Fifo_Rx1_Init                                                         *
 * Desc: Initialize RX3 Fifo                                                   *
 * Parameter: None                                                             *
 * Return: None                                                                *
 *******************************************************************************/
void Fifo_Rx3_Init(void) {

	GetPtr = &Fifo[0];
	PutPtr = &Fifo[0];
}

/*******************************************************************************
 * Name: Fifo_Rx3_Put                                                          *
 * Desc: Put Data in RX3 Fifo                                                  *
 * Parameter: volatile unsigned int c                                          *
 * Return: volatile unsigned int                                               *
 *******************************************************************************/
volatile unsigned char Fifo_Rx3_Put(volatile unsigned char c) {

	// Verify if PUT doesn't reach GET and if FIFO is totally full
	if (((PutPtr + 1) == GetPtr) || ((PutPtr - GetPtr) == (FIFO_SIZE - 1))) {
		return (0);
	} else {
		*PutPtr = c; // save the data in queue
		// update the pointer, watch if the pointer must go to the beginning of queue
		if (PutPtr == &Fifo[FIFO_SIZE - 1]) {
			PutPtr = &Fifo[0];
		} else {
			PutPtr++;
		}
		return (1);
	}
}

/*******************************************************************************
 * Name: Fifo_Rx3_Get                                                          *
 * Desc: Get Data from RX2 Fifo                                                *
 * Parameter: volatile unsigned int* DataPtr                                   *
 * Return: volatile unsigned int                                               *
 *******************************************************************************/
volatile unsigned char Fifo_Rx3_Get(volatile unsigned char *DataPtr) {
	if (PutPtr == GetPtr) { // Verify if queue is empty
		return (0);
	} else {
		*DataPtr = *GetPtr;
		// update the pointer
		if (GetPtr == &Fifo[FIFO_SIZE - 1]) {
			GetPtr = &Fifo[0];
		} else {
			GetPtr++;
		}
		return (1);
	}
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


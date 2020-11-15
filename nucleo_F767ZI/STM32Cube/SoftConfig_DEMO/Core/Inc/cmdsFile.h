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

#ifndef INC_CMDSFILE_H_
#define INC_CMDSFILE_H_

// command list
const uint8_t gver[] = "GVER";
const uint8_t blkl[] = "BLKL";
const uint8_t adcn[] = "ADCR";

// response list
const uint8_t verResp[] =
		"DUNE-DAHPNE UDEA - Version software 1.0 \n software write in part by University of Antioquia\n\n";
const uint8_t blkResp[] = "Blink command accepted\n\n";
const uint8_t adcResp[] = "ADC data ready to send \nValue in ADC = \n\n";
const uint8_t failMsg[] = "Command is not recognized\n\n";

#endif /* INC_CMDSFILE_H_ */

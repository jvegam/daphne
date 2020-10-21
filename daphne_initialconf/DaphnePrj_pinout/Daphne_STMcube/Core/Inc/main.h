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
#include "stm32h7xx_hal.h"

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
#define CM_SCLK_DAC_SCLK_AFE0_SCLK_Pin GPIO_PIN_2
#define CM_SCLK_DAC_SCLK_AFE0_SCLK_GPIO_Port GPIOE
#define CM_ADC_RESETn_Pin GPIO_PIN_3
#define CM_ADC_RESETn_GPIO_Port GPIOE
#define CM_ADC_START_Pin GPIO_PIN_4
#define CM_ADC_START_GPIO_Port GPIOE
#define CM_SDO_AFE0_SDOUT_Pin GPIO_PIN_5
#define CM_SDO_AFE0_SDOUT_GPIO_Port GPIOE
#define CM_SDI_DAC_DIN_AFE0_SDATA_Pin GPIO_PIN_6
#define CM_SDI_DAC_DIN_AFE0_SDATA_GPIO_Port GPIOE
#define CM_ADC_DRDYn_Pin GPIO_PIN_8
#define CM_ADC_DRDYn_GPIO_Port GPIOI
#define SDA1_Pin GPIO_PIN_0
#define SDA1_GPIO_Port GPIOF
#define SCL1_Pin GPIO_PIN_1
#define SCL1_GPIO_Port GPIOF
#define BiasMon0_Pin GPIO_PIN_3
#define BiasMon0_GPIO_Port GPIOF
#define BiasMon1_Pin GPIO_PIN_4
#define BiasMon1_GPIO_Port GPIOF
#define BiasMon2_Pin GPIO_PIN_5
#define BiasMon2_GPIO_Port GPIOF
#define BiasMon3_Pin GPIO_PIN_7
#define BiasMon3_GPIO_Port GPIOF
#define BiasMon4_Pin GPIO_PIN_8
#define BiasMon4_GPIO_Port GPIOF
#define __CEVMon_Pin GPIO_PIN_9
#define __CEVMon_GPIO_Port GPIOF
#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_MDC_GPIO_Port GPIOC
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_REF_CLK_GPIO_Port GPIOA
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_MDIO_GPIO_Port GPIOA
#define __2_5VMon_Pin GPIO_PIN_4
#define __2_5VMon_GPIO_Port GPIOH
#define __5_0VMon_Pin GPIO_PIN_5
#define __5_0VMon_GPIO_Port GPIOH
#define SS_CCLK_Pin GPIO_PIN_5
#define SS_CCLK_GPIO_Port GPIOA
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_CRS_DV_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define ETH_SFP_LOS_Pin GPIO_PIN_0
#define ETH_SFP_LOS_GPIO_Port GPIOB
#define ETH_SFP_ABS_Pin GPIO_PIN_1
#define ETH_SFP_ABS_GPIO_Port GPIOB
#define DAC_LDACn_Pin GPIO_PIN_2
#define DAC_LDACn_GPIO_Port GPIOB
#define AFE1_SDATA_AFE2_SDATA_Pin GPIO_PIN_11
#define AFE1_SDATA_AFE2_SDATA_GPIO_Port GPIOF
#define LED0_Pin GPIO_PIN_15
#define LED0_GPIO_Port GPIOF
#define VBIAS_EN_Pin GPIO_PIN_0
#define VBIAS_EN_GPIO_Port GPIOG
#define MUXEN0_Pin GPIO_PIN_1
#define MUXEN0_GPIO_Port GPIOG
#define MUXEN1_Pin GPIO_PIN_7
#define MUXEN1_GPIO_Port GPIOE
#define MUXEN2_Pin GPIO_PIN_8
#define MUXEN2_GPIO_Port GPIOE
#define MUXEN3_Pin GPIO_PIN_9
#define MUXEN3_GPIO_Port GPIOE
#define MUXEN4_Pin GPIO_PIN_10
#define MUXEN4_GPIO_Port GPIOE
#define MUXEN5_Pin GPIO_PIN_11
#define MUXEN5_GPIO_Port GPIOE
#define MUXEN6_Pin GPIO_PIN_12
#define MUXEN6_GPIO_Port GPIOE
#define MUXEN7_Pin GPIO_PIN_13
#define MUXEN7_GPIO_Port GPIOE
#define MUXEN8_Pin GPIO_PIN_14
#define MUXEN8_GPIO_Port GPIOE
#define MUXEN9_Pin GPIO_PIN_15
#define MUXEN9_GPIO_Port GPIOE
#define SCLK_Pin GPIO_PIN_10
#define SCLK_GPIO_Port GPIOB
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TX_EN_GPIO_Port GPIOB
#define AFE1_SCLK_AFE2_SCLK_Pin GPIO_PIN_6
#define AFE1_SCLK_AFE2_SCLK_GPIO_Port GPIOH
#define AFE1_SDOUT_AFE2_SDOUT_Pin GPIO_PIN_7
#define AFE1_SDOUT_AFE2_SDOUT_GPIO_Port GPIOH
#define MUXA0_Pin GPIO_PIN_9
#define MUXA0_GPIO_Port GPIOH
#define MUXA1_Pin GPIO_PIN_10
#define MUXA1_GPIO_Port GPIOH
#define AFE4_AFE_SEn_Pin GPIO_PIN_11
#define AFE4_AFE_SEn_GPIO_Port GPIOH
#define AFE3_AFE_SEn_Pin GPIO_PIN_12
#define AFE3_AFE_SEn_GPIO_Port GPIOH
#define RMII_TXD0_Pin GPIO_PIN_12
#define RMII_TXD0_GPIO_Port GPIOB
#define RMII_TXD1_Pin GPIO_PIN_13
#define RMII_TXD1_GPIO_Port GPIOB
#define MISO_Pin GPIO_PIN_14
#define MISO_GPIO_Port GPIOB
#define MOSI_Pin GPIO_PIN_15
#define MOSI_GPIO_Port GPIOB
#define CSn_Pin GPIO_PIN_8
#define CSn_GPIO_Port GPIOD
#define RESETn_Pin GPIO_PIN_9
#define RESETn_GPIO_Port GPIOD
#define FPGA_to_uC_IRQ_Pin GPIO_PIN_10
#define FPGA_to_uC_IRQ_GPIO_Port GPIOD
#define AFE3_TRM_SYNCn_Pin GPIO_PIN_11
#define AFE3_TRM_SYNCn_GPIO_Port GPIOD
#define AFE3_TRM_LDACn_Pin GPIO_PIN_12
#define AFE3_TRM_LDACn_GPIO_Port GPIOD
#define AFE3_OFF_SYNCn_Pin GPIO_PIN_13
#define AFE3_OFF_SYNCn_GPIO_Port GPIOD
#define AFE3_OFF_LDACn_Pin GPIO_PIN_14
#define AFE3_OFF_LDACn_GPIO_Port GPIOD
#define AFE2_TRM_SYNCn_Pin GPIO_PIN_15
#define AFE2_TRM_SYNCn_GPIO_Port GPIOD
#define AFE2_TRM_LDACn_Pin GPIO_PIN_2
#define AFE2_TRM_LDACn_GPIO_Port GPIOG
#define AFE2_OFF_SYNCn_Pin GPIO_PIN_3
#define AFE2_OFF_SYNCn_GPIO_Port GPIOG
#define AFE2_OFF_LDACn_Pin GPIO_PIN_4
#define AFE2_OFF_LDACn_GPIO_Port GPIOG
#define AFE1_TRM_SYNCn_Pin GPIO_PIN_5
#define AFE1_TRM_SYNCn_GPIO_Port GPIOG
#define AFE1_TRM_LDACn_Pin GPIO_PIN_6
#define AFE1_TRM_LDACn_GPIO_Port GPIOG
#define AFE1_OFF_SYNCn_Pin GPIO_PIN_7
#define AFE1_OFF_SYNCn_GPIO_Port GPIOG
#define AFE1_OFF_LDACn_Pin GPIO_PIN_8
#define AFE1_OFF_LDACn_GPIO_Port GPIOG
#define FAN_TACH_Pin GPIO_PIN_6
#define FAN_TACH_GPIO_Port GPIOC
#define AFE_RST_Pin GPIO_PIN_8
#define AFE_RST_GPIO_Port GPIOC
#define AFE_PDN_Pin GPIO_PIN_9
#define AFE_PDN_GPIO_Port GPIOC
#define TX_Pin GPIO_PIN_9
#define TX_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_10
#define RX_GPIO_Port GPIOA
#define CTS_Pin GPIO_PIN_11
#define CTS_GPIO_Port GPIOA
#define RTS_Pin GPIO_PIN_12
#define RTS_GPIO_Port GPIOA
#define uC_TMS_Pin GPIO_PIN_13
#define uC_TMS_GPIO_Port GPIOA
#define AFE2_AFE_SEn_Pin GPIO_PIN_13
#define AFE2_AFE_SEn_GPIO_Port GPIOH
#define AFE1_AFE_SEn_Pin GPIO_PIN_14
#define AFE1_AFE_SEn_GPIO_Port GPIOH
#define AFE0_AFE_SEn_Pin GPIO_PIN_15
#define AFE0_AFE_SEn_GPIO_Port GPIOH
#define AFE0_TRM_LDACn_Pin GPIO_PIN_0
#define AFE0_TRM_LDACn_GPIO_Port GPIOI
#define AFE0_TRM_SYNCn_Pin GPIO_PIN_1
#define AFE0_TRM_SYNCn_GPIO_Port GPIOI
#define AFE0_OFF_LDACn_Pin GPIO_PIN_2
#define AFE0_OFF_LDACn_GPIO_Port GPIOI
#define AFE0_OFF_SYNCn_Pin GPIO_PIN_3
#define AFE0_OFF_SYNCn_GPIO_Port GPIOI
#define uC_TCK_Pin GPIO_PIN_14
#define uC_TCK_GPIO_Port GPIOA
#define uC_TDI_Pin GPIO_PIN_15
#define uC_TDI_GPIO_Port GPIOA
#define SPIRamClk_Pin GPIO_PIN_10
#define SPIRamClk_GPIO_Port GPIOC
#define SPIRamDO_Pin GPIO_PIN_11
#define SPIRamDO_GPIO_Port GPIOC
#define SPIRamDI_Pin GPIO_PIN_12
#define SPIRamDI_GPIO_Port GPIOC
#define SPIRamCS_Pin GPIO_PIN_0
#define SPIRamCS_GPIO_Port GPIOD
#define SPIFlshCS_Pin GPIO_PIN_1
#define SPIFlshCS_GPIO_Port GPIOD
#define SPIRamHld_Pin GPIO_PIN_2
#define SPIRamHld_GPIO_Port GPIOD
#define AFE4_OFF_LDACn_Pin GPIO_PIN_3
#define AFE4_OFF_LDACn_GPIO_Port GPIOD
#define AFE4_OFF_SYNCn_Pin GPIO_PIN_4
#define AFE4_OFF_SYNCn_GPIO_Port GPIOD
#define AFE4_TRM_LDACn_Pin GPIO_PIN_5
#define AFE4_TRM_LDACn_GPIO_Port GPIOD
#define AFE4_TRM_SYNCn_Pin GPIO_PIN_6
#define AFE4_TRM_SYNCn_GPIO_Port GPIOD
#define SS_DIN_Pin GPIO_PIN_7
#define SS_DIN_GPIO_Port GPIOD
#define SS_PROG_B_Pin GPIO_PIN_9
#define SS_PROG_B_GPIO_Port GPIOG
#define SS_INIT_B_Pin GPIO_PIN_10
#define SS_INIT_B_GPIO_Port GPIOG
#define SS_DONE_Pin GPIO_PIN_11
#define SS_DONE_GPIO_Port GPIOG
#define AFE3_SDOUT_AFE4_SDOUT_Pin GPIO_PIN_12
#define AFE3_SDOUT_AFE4_SDOUT_GPIO_Port GPIOG
#define AFE3_SCLK_AFE4_SCLK_Pin GPIO_PIN_13
#define AFE3_SCLK_AFE4_SCLK_GPIO_Port GPIOG
#define AFE3_SDATA_AFE4_SDATA_Pin GPIO_PIN_14
#define AFE3_SDATA_AFE4_SDATA_GPIO_Port GPIOG
#define uC_TDO_Pin GPIO_PIN_3
#define uC_TDO_GPIO_Port GPIOB
#define uC_nRST_Pin GPIO_PIN_4
#define uC_nRST_GPIO_Port GPIOB
#define SCL0_Pin GPIO_PIN_6
#define SCL0_GPIO_Port GPIOB
#define SDA0_Pin GPIO_PIN_7
#define SDA0_GPIO_Port GPIOB
#define CM_A0_Pin GPIO_PIN_0
#define CM_A0_GPIO_Port GPIOE
#define CM_A1_Pin GPIO_PIN_1
#define CM_A1_GPIO_Port GPIOE
#define DAC_SYNCn_Pin GPIO_PIN_4
#define DAC_SYNCn_GPIO_Port GPIOI
#define DAC_LDACnI5_Pin GPIO_PIN_5
#define DAC_LDACnI5_GPIO_Port GPIOI
#define CM_PGA_CSn_Pin GPIO_PIN_6
#define CM_PGA_CSn_GPIO_Port GPIOI
#define CM_ADC_CSn_Pin GPIO_PIN_7
#define CM_ADC_CSn_GPIO_Port GPIOI
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

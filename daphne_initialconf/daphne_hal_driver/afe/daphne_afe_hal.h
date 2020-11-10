/**
  ******************************************************************************
  * @file    DAPHNE_AFE_HAL.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DAPHNE_AFE_HAL_H
#define DAPHNE_AFE_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_ll_spi.h"
#include "afe_ctrl.h"


typedef enum
{
  HAL_AFE_STATE_RESET     = 0x00U,  /*!< AFE not yet initialized or disabled           */
  HAL_AFE_STATE_READY     = 0x01U,  /*!< AFE initialized and ready for use             */
  HAL_AFE_STATE_BUSY      = 0x02U,  /*!< AFE internal process is ongoing               */
  HAL_AFE_STATE_ERROR     = 0x03U   /*!< AFE error state                               */
} HAL_StatusTypeDef;

typedef enum
{
  AFE     = 0x00U,  /*!< AFE REGs device select             */
  TRIM    = 0x01U,  /*!< AFE TRIM REGs device selected      */
  OFFSET  = 0x02U,  /*!< AFE OFFSET REGs selected           */
  ALL     = 0x03U   /*!< Updated all REGs devices selected  */
} HAL_DeviceSelectTypeDef;



typedef struct 
{ 
  SPI_HandleTypeDef *instance;
  AFE_TypeDef *AFE;
  TRIM_TypeDef *TRIM;
  OFFSET_TypeDef *OFFSET;
  CTRL_TypeDef *CTRL;
  HAL_SRAM_StateTypeDef State;      /*!< AFE device access state                     */
}AFE_HandleTypeDef;


//static
void AFE_init (AFE_HandleTypeDef *hAFE);
HAL_StatusTypeDef AFE_Write_16b   (AFE_HandleTypeDef *hAFE, uint16_t pAddress);
HAL_StatusTypeDef AFE_Read_16b    (AFE_HandleTypeDef *hAFE, uint16_t pAddress);
HAL_StatusTypeDef TRIM_Write_32b  (AFE_HandleTypeDef *hAFE, uint32_t pAddress);
HAL_StatusTypeDef OFFSET_Write_32b(AFE_HandleTypeDef *hAFE, uint32_t pAddress);

#endif /* DAPHNE_AFE_HAL_H */

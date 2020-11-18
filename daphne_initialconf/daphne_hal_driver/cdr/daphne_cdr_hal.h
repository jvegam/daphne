/**
  ******************************************************************************
  * @file    DAPHNE_CDR_HAL.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of CDR HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DAPHNE_CDR_HAL_H
#define DAPHNE_CDR_HAL_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_ll_i2c.h"

#define SADDR5_HIGH
#include "ADN2814A.h"


typedef enum
{
  HAL_CDR_STATE_RESET     = 0x00U,  /*!< CDR not yet initialized or disabled           */
  HAL_CDR_STATE_READY     = 0x01U,  /*!< CDR initialized and ready for use             */
  HAL_CDR_STATE_BUSY      = 0x02U,  /*!< CDR internal process is ongoing               */
  HAL_CDR_STATE_ERROR     = 0x03U,  /*!< CDR error state                               */
  HAL_CDR_OK			  = 0x04U	/*!< CDR OK state                                  */
} HAL_StatusTypeDef;


typedef struct 
{ 
  I2C_HandleTypeDef *instance;
  CDRREGS_TypeDef *CDR;
  HAL_StatusTypeDef State;      /*!< CDR device access state                     */
}CDR_HandleTypeDef;

HAL_StatusTypeDef CDR_Write_8b   (CDR_HandleTypeDef *hCDR, uint8_t *pAddress, uint8_t size);
HAL_StatusTypeDef CDR_Read_8b    (CDR_HandleTypeDef *hCDR, uint8_t *pAddress, uint8_t size);


void CDR_init (CDR_HandleTypeDef *hCDR);
void CDR_Read_Reg    (CDR_HandleTypeDef *hCDR, uint8_t *pAddress);
void CDR_Write_Reg    (CDR_HandleTypeDef *hCDR, uint8_t *pAddress);
void CDR_Read_Regs    (CDR_HandleTypeDef *hCDR);
void CDR_Write_Regs    (CDR_HandleTypeDef *hCDR);



#endif /* DAPHNE_CDR_HAL_H */
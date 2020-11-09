AFE5808A_H

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DAPHNE_DAC_HAL_H
#define DAPHNE_DAC_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_ll_spi.h"
#include "dac_ctrl.h"


typedef enum
{
  HAL_DAC_STATE_RESET     = 0x00U,  /*!< AFE not yet initialized or disabled           */
  HAL_DAC_STATE_READY     = 0x01U,  /*!< AFE initialized and ready for use             */
  HAL_DAC_STATE_BUSY      = 0x02U,  /*!< AFE internal process is ongoing               */
  HAL_DAC_STATE_ERROR     = 0x03U   /*!< AFE error state                               */
} HAL_StatusTypeDef;


typedef struct 
{ 
  SPI_HandleTypeDef *instance;
  AD5317_REGS_TypeDef *instance1;
  AD5317_REGS_TypeDef *instance2;
  AD5317_REGS_TypeDef *instance3;
  AD5317_CommonCTRL_TypeDef *Ctrl;
}DAC_Handle_TypeDef;

void DAC_init (DAC_Handle_TypeDef *hspi);
HAL_StatusTypeDef DAC_Write_48b   (DAC_Handle_TypeDef *hDAC, uint16_t pAddress);


#endif /* DAPHNE_DAC_HAL_H */


/**
  ******************************************************************************
  * @file    stm32h7xx_hal_afe.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE HAL module.
  ******************************************************************************
  */

/**
  ******************************************************************************
  * @file    DAC_CTRL.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of DAC HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DAC_CTRL_H
#define DAC_CTRL_H

#include <stdint.h>

#include "AD5317.h"


typedef struct 
{ 
  SPI_HandleTypeDef *instance;
  AD5317_REGS_TypeDef *instance1;
  AD5317_REGS_TypeDef *instance2;
  AD5317_REGS_TypeDef *instance3;
  AD5317_CommonCTRL_TypeDef *Ctrl;
}DAC_Ctrl_TypeDef;


#endif /* DAC_CTRL_H */

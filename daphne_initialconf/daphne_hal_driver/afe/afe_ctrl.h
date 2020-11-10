/**
  ******************************************************************************
  * @file    AFE_CTRL.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef AFE_CTRL_H
#define AFE_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal_def.h"

/* Include low level driver */
#include "stm32h7xx_ll_spi.h"

/**/
#include "AFE5808A.h"
/* Daphne struct ctrl pins 
 * 
*/

  
typedef struct 
{ 
  AFEREGS_TypeDef reg;
  bool Enable;
  uint16_t Gain;     
  uint16_t Bias_set;
  uint16_t Bias_mon;
  bool Powerdown;
  bool Reset;
}AFE_TypeDef;

typedef struct 
{   
  AD5317_REGS_TypeDef *instance;
  AD5317_REGS_TypeDef *instance1;   
}TRIM_TypeDef;

typedef struct 
{   
  AD5317_REGS_TypeDef *instance;
  AD5317_REGS_TypeDef *instance1;   
}OFFSET_TypeDef;

typedef struct 
{   
  AD5317_CommonCTRL_TypeDef *Ctrl;     
}CTRL_TypeDef;



#endif /* AFE_CTRL_H */

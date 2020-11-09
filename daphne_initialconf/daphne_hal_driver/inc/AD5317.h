/**
  ******************************************************************************
  * @file    AD5317.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AD5317 module.
  ******************************************************************************
  */
#include <stdint.h>

#ifndef AD5317_H
#define AD5317_H

#define AD5317_REG_TypeDef AD5317_REG_TypeDef
typedef struct 
 {
  union {
    struct {
      uint16_t DATA:12;
      uint16_t BUF:1;
      uint16_t GAIN:1;
      uint16_t ADDRESS:2;
    };
      struct {
      uint16_t :14; 
      uint16_t ADDRESS0:1;
      uint16_t ADDRESS1:1;        
    };
  };
} AD5317_REG_TypeDef;
 
#define AD5317_CommonCTRL_TypeDef AD5317_CommonCTRL_TypeDef
typedef struct
{ uint16_t SYNC;
  uint16_t LDACn;    
}AD5317_CommonCTRL_TypeDef;

typedef struct 
{ 
  AD5317_REG_TypeDef REGA;
  AD5317_REG_TypeDef REGB;  
  AD5317_REG_TypeDef REGC;
  AD5317_REG_TypeDef REGD;   
}AD5317_REGS_TypeDef;

/* AD5317 Type definition one DAC
 *
 */
typedef struct 
{ 
  AD5317_REGS_TypeDef *REGS;
  AD5317_CommonCTRL_TypeDef *CommonCTRL;
}AD5317_TypeDef;


#define UNBUFFERED_REF (0<<12) 
#define BUFFERED_REF   (1<<12)

#define GAIN_1 (0<<13) 
#define GAIN_2 (1<<13)

#define DAC_A (0<<14)
#define DAC_B (1<<14)
#define DAC_C (2<<14)
#define DAC_D (3<<14)


#endif
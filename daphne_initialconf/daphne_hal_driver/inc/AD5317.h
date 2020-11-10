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

/*****************  Bit definition for AD5317_REG register  ******************/
#define AD5317_REG_BUFFERED_REF_Pos               (12U)
#define AD5317_REG_BUFFERED_REF_Msk               (0x1UL << AD5317_REG_BUFFERED_REF_Pos) /*!< 0x00000001 */
#define AD5317_REG_BUFFERED_REF                   AD5317_REG_BUFFERED_REF_Msk

#define AD5317_REG_GAIN_Pos                       (13U)
#define AD5317_REG_GAIN_Msk                       (0x1UL << AD5317_REG_GAIN_Pos)         /*!< 0x00000000 */
#define AD5317_REG_GAIN                           AD5317_REG_GAIN_Msk
#define AD5317_REG_GAIN_1                         (0x0UL << AD5317_REG_GAIN_Pos)         /*!< 0x00000000 */
#define AD5317_REG_GAIN_2                         (0x1UL << AD5317_REG_GAIN_Pos)         /*!< 0x00000000 */

#define AD5317_REG_DAC_SELECT_Pos                 (14U)
#define AD5317_REG_DAC_SELECT_Msk                 (0x3UL << AD5317_REG_DAC_SELECT_Pos)         /*!< 0x00000000 */
#define AD5317_REG_DAC_SELECT                     AD5317_REG_DAC_SELECT_Msk
#define AD5317_REG_DAC_SELECT_CHA                 (0x0UL << AD5317_REG_DAC_SELECT_Pos)         /*!< 0x00000000 */
#define AD5317_REG_DAC_SELECT_CHB                 (0x1UL << AD5317_REG_DAC_SELECT_Pos)         /*!< 0x00000000 */
#define AD5317_REG_DAC_SELECT_CHC                 (0x2UL << AD5317_REG_DAC_SELECT_Pos)         /*!< 0x00000000 */
#define AD5317_REG_DAC_SELECT_CHD                 (0x3UL << AD5317_REG_DAC_SELECT_Pos)         /*!< 0x00000000 */

#endif
/**
  ******************************************************************************
  * @file    AFE5808A.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE HAL module.
  ******************************************************************************
  */

#include <stdint.h>

#ifndef ADN2814_H
#define ADN2814_H

typedef struct
{ 
  uint8_t FREQ0;
  uint8_t FREQ1;
  uint8_t FREQ2;
  uint8_t RATE;
  uint8_t MISC;
  uint8_t CTRLA;
  uint8_t CTRLB;
  uint8_t CTRLC;
}CDRREGS_TypeDef;

#ifdef SADDR5_HIGH
  #define CDR_SLAVEADDR (0xC0)
#else
  #define CDR_SLAVEADDR (0x80)
#endif

#define CDR_SLAVEADDR_WRITE (CDR_SLAVEADDR)
#define CDR_SLAVEADDR_READ  (CDR_SLAVEADDR | 1 )

#define ADDR_FREQ0 (0U)
#define ADDR_FREQ1 (1U)
#define ADDR_FREQ2 (2U)
#define ADDR_RATE  (3U)
#define ADDR_MISC  (4U)
#define ADDR_CTRLA (8U)
#define ADDR_CTRLB (9U)
#define ADDR_CTRLC (11U)

#endif
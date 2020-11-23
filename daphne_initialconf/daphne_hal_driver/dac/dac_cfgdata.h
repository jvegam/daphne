/**
  ******************************************************************************
  * @file    DAC_CFGDATA.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE CONFIG DATA HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DAC_CFGDATA_H
#define DAC_CFGDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_REGS_DAC 12

typedef struct Reg_Data{
   unsigned char Channel;	
   unsigned int  Reg_Val; 
} Reg_DACData;

#define CHA 0
#define CHB 1
#define CHC 2
#define CHD 3

Reg_Data const code Reg_Store[NUM_REGS_DAC] = {
//Daisy Chain 48 bits Register Map

//DAC VOUTA 48 bits
{ CHA, 0x0000}, 
{ CHA, 0x0000}, 
{ CHA, 0x0000}, 

//DAC VOUTB 48 bits
{ CHB, 0x4000}, 
{ CHB, 0x4000}, 
{ CHB, 0x4000},

//DAC VOUTC 48 bits
{ CHC, 0x8000}, 
{ CHC, 0x8000}, 
{ CHC, 0x8000},

//DAC VOUTD 48 bits
{ CHD, 0xC000},
{ CHD, 0xC000},
{ CHD, 0xC000}

 }; // set page bit to 0


#endif /* DAC_CFGDATA_H */

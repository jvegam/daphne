/**
  ******************************************************************************
  * @file    AFE_CFGDATA.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE CONFIG DATA HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef AFE_CDRDATA_H
#define AFE_CDrDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_REGS_MAX 3

typedef struct Reg_Data{
   unsigned char Reg_Addr; 
   unsigned char Reg_Val; 
} Reg_CDRData;

Reg_Data const code Reg_Store[NUM_REGS_MAX] = {
//CDR Register Map
{  0x8,0x83}, // bit 7   6   5   4   3   2   1   0
			  //     1   0   0   0   0   0   1   1
			  //    (62.5M)  (   DIV_1   )  (ON) (CLOCK REF OFF)
{  0x9,0x00}, // LOL normal operation
			  // Reset MISC, system Reset Write a '1' followed by
			  // '0' to reset 
{  0x11,0x00} // LOL active HIGH, SQUELCH CLK and DATA, Default output swing 

 }; // set page bit to 0


#endif /* AFE_CDRDATA_H */

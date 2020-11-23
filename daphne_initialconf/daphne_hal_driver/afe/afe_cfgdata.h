/**
  ******************************************************************************
  * @file    AFE_CFGDATA.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE CONFIG DATA HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef AFE_CFGDATA_H
#define AFE_CFGDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_REGS_MAX 27

typedef struct Reg_Data{
   unsigned char Reg_Addr; //decimal value
   unsigned int Reg_Val; 
} Reg_AFEData;

Reg_Data const code Reg_Store[NUM_REGS_MAX] = {
//ADC Register Map
{  0,0x0000},
{  1,0x0000},
{  2,0x0000},
{  3,0x0000},
{  4,0x0000},
{  5,0x0000},
{  10,0x0000},
{  13,0x0000},
{  15,0x0000},
{  17,0x0000},
{  19,0x0000},
{  21,0x0000},
{  25,0x0000},
{  27,0x0000},
{  29,0x0000},
{  31,0x0000},
{  33,0x0000},
{  66,0x0000},
//VCA register Map
{  50,0x0000},
{  51,0x0000},
{  52,0x1000}, //DC offset correction = OFF (BIT 12)
{  53,0x0000},
{  54,0x0000},
{  55,0x0000},
{  56,0x0000},
{  57,0x0000},
{  59,0x0000}

 }; // set page bit to 0


#endif /* AFE_CFGDATA_H */

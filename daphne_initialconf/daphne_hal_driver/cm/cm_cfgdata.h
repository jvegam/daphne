/**
  ******************************************************************************
  * @file    CM_CFGDATA.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE CONFIG DATA HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CM_CFGDATA_H
#define CM_CFGDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_REGS_PGA 12
#define  9
#define NUM_REGS_MAX (NUM_REGS_PGA+NUM_REGS_ADC)  

typedef struct Reg_Data{
   unsigned char Reg_Addr; 
   unsigned char Reg_Val; 
} Reg_CMData;

Reg_Data const code Reg_Store[NUM_REGS_MAX] = {
//PGA Register Map
{  0,0x00}, 
{  1,0x00},  
{  2,0x00}, 
{  3,0x00},
{  4,0x00}, 
{  5,0x00},  
{  6,0x00}, 
{  7,0x00},
{  8,0x00}, 
{  9,0x00},  
{  10,0x00}, 
{  11,0x00},
// ADC - 24bits Register Map
{ 0, 0x00},
{ 1, 0x00},
{ 2, 0x00},
{ 3, 0x00},
{ 4, 0x00},
{ 5, 0x00},
{ 6, 0x00},
{ 7, 0x00},
{ 8, 0x00}

 }; // set page bit to 0


#endif /* CM_CFGDATA_H */

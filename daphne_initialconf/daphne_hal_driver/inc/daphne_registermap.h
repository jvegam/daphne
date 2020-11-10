/**
  ******************************************************************************
  * @file    Registermap.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of Register Map HAL module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DAPHNE_REGISTERMAP_H
#define DAPHNE_REGISTERMAP_H

/* Includes ------------------------------------------------------------------*/


/* Include low level driver */
#define Registermap RegisterMap;
//Reserve memory with malloc
typedef enum
{
/*****************  Memory Map Address Register ***************************/
  ControlREG         = 0,    /*!<                                       */
  StatusREG          = 1,    /*!<                               */
  /***** Bias Trim DAC voltage ******/
  AFE0Trim_CH0		= 	,
  AFE0Trim_CH1		= 	,
  AFE0Trim_CH2		=   ,
  AFE0Trim_CH3		=   ,
  AFE0Trim_CH4		=   ,
  AFE0Trim_CH5		=   ,
  AFE0Trim_CH6		=   ,
  AFE0Trim_CH7		=   ,

  AFE1Trim_CH0		= 	,
  AFE1Trim_CH1		= 	,
  AFE1Trim_CH2		=   ,
  AFE1Trim_CH3		=   ,
  AFE1Trim_CH4		=   ,
  AFE1Trim_CH5		=   ,
  AFE1Trim_CH6		=   ,
  AFE1Trim_CH7		=   ,

  AFE2Trim_CH0		= 	,
  AFE2Trim_CH1		= 	,
  AFE2Trim_CH2		=   ,
  AFE2Trim_CH3		=   ,
  AFE2Trim_CH4		=   ,
  AFE2Trim_CH5		=   ,
  AFE2Trim_CH6		=   ,
  AFE2Trim_CH7		=   ,

  AFE3Trim_CH0		= 	,
  AFE3Trim_CH1		= 	,
  AFE3Trim_CH2		=   ,
  AFE3Trim_CH3		=   ,
  AFE3Trim_CH4		=   ,
  AFE3Trim_CH5		=   ,
  AFE3Trim_CH6		=   ,
  AFE3Trim_CH7		=   ,

  AFE4Trim_CH0		= 	,
  AFE4Trim_CH1		= 	,
  AFE4Trim_CH2		=   ,
  AFE4Trim_CH3		=   ,
  AFE4Trim_CH4		=   ,
  AFE4Trim_CH5		=   ,
  AFE4Trim_CH6		=   ,
  AFE4Trim_CH7		=   ,
  /***** Bias Offset DAC voltage ******/
  AFE0Offset_CH0	= 	,
  AFE0Offset_CH1	= 	,
  AFE0Offset_CH2		=   ,
  AFE0Offset_CH3		=   ,
  AFE0Offset_CH4		=   ,
  AFE0Offset_CH5		=   ,
  AFE0Offset_CH6		=   ,
  AFE0Offset_CH7		=   ,

  AFE1Offset_CH0		= 	,
  AFE1Offset_CH1		= 	,
  AFE1Offset_CH2		=   ,
  AFE1Offset_CH3		=   ,
  AFE1Offset_CH4		=   ,
  AFE1Offset_CH5		=   ,
  AFE1Offset_CH6		=   ,
  AFE1Offset_CH7		=   ,

  AFE2Offset_CH0		= 	,
  AFE2Offset_CH1		= 	,
  AFE2Offset_CH2		=   ,
  AFE2Offset_CH3		=   ,
  AFE2Offset_CH4		=   ,
  AFE2Offset_CH5		=   ,
  AFE2Offset_CH6		=   ,
  AFE2Offset_CH7		=   ,

  AFE3Offset_CH0		= 	,
  AFE3Offset_CH1		= 	,
  AFE3Offset_CH2		=   ,
  AFE3Offset_CH3		=   ,
  AFE3Offset_CH4		=   ,
  AFE3Offset_CH5		=   ,
  AFE3Offset_CH6		=   ,
  AFE3Offset_CH7		=   ,

  AFE4Offset_CH0		= 	,
  AFE4Offset_CH1		= 	,
  AFE4Offset_CH2		=   ,
  AFE4Offset_CH3		=   ,
  AFE4Offset_CH4		=   ,
  AFE4Offset_CH5		=   ,
  AFE4Offset_CH6		=   ,
  AFE4Offset_CH7		=   ,

} RegMapAddr_TypeDef;


typedef struct MM_Reg_t{
   RegMapAddr_TypeDef Reg_Addr;
   uint16_t Reg_Val;
} MM_Reg_t;

typedef struct MM_AFEReg_t{
   uint16_t AFECtrlReg;
   uint16_t AFEStatusReg;
   uint16_t TRIM[8];
   uint16_t OFFSET[8];
   uint16_t BIAS_SET;
   uint16_t BIAS_MON
} MM_AFEReg_t;

typedef struct
{ 
      uint16_t CommandReg;
      uint16_t ControlReg;   
	  uint16_t StatusReg;

	  MM_AFEReg_t AFE0;
	  MM_AFEReg_t AFE1;
	  MM_AFEReg_t AFE2;
	  MM_AFEReg_t AFE3;
	  MM_AFEReg_t AFE4;

	  uint16_t VM_CtrlReg;
	  uint16_t VM_DataReg[8];         // Read Voltages
      uint16_t CM_ControlReg;
      uint16_t CM_DataReg[8];   

}RegisterMap_TypeDef;





/*****************  Bit definition for Control Register   ******************/
#define RegisterMap_ControlREG_pos					  (0U)
#define AFEREGS_REG0_SOFTWARE_RESET_Msk               (0x1UL << AFEREGS_REG0_SOFTWARE_RESET_Pos)         /*!< 0x00000001 */
#define AFEREGS_REG0_SOFTWARE_RESET                   AFEREGS_REG0_SOFTWARE_RESET_Msk
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE_Pos      (1U)
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE_Msk      (0x1UL << AFEREGS_REG0_REGISTER_READOUT_ENABLE_Pos)     /*!< 0x00000002 */
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE          AFEREGS_REG0_REGISTER_READOUT_ENABLE_Msk 



#endif /* DAPHNE_REGISTERMAP_H */


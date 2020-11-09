/**
  ******************************************************************************
  * @file    AFE5808A.h
  * @author  Daphne Microcontroller Team
  *          Juan Vega Martinez
  * @brief   Header file of AFE HAL module.
  ******************************************************************************
  */

#include <stdint.h>

#ifndef AFE5808A_H
#define AFE5808A_H

 #define SPI2                  ((SPI_TypeDef *) SPI2_BASE)
 #define SPI2_BASE             (MEMORYMAP_BASE + 0x3800UL)

typedef struct
{ 
  volatile uint16_t REG0;
  volatile uint16_t REG1;

}AFEREGS_TypeDef;

/*****************  Bit definition for AFEREGS_REG0 register  ******************/
#define AFEREGS_REG0_SOFTWARE_RESET_Pos               (0U)
#define AFEREGS_REG0_SOFTWARE_RESET_Msk               (0x1UL << AFEREGS_REG0_SOFTWARE_RESET_Pos)         /*!< 0x00000001 */
#define AFEREGS_REG0_SOFTWARE_RESET                   AFEREGS_REG0_SOFTWARE_RESET_Msk
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE_Pos      (1U)
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE_Msk      (0x1UL << AFEREGS_REG0_REGISTER_READOUT_ENABLE_Pos)     /*!< 0x00000002 */
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE          AFEREGS_REG0_REGISTER_READOUT_ENABLE_Msk 


#define AFEREGS_REG1_ADC_COMPLETE_PDN_Pos             (0U)
#define AFEREGS_REG1_ADC_COMPLETE_PDN_Msk             (0x1UL << AFEREGS_REG1_ADC_COMPLETE_PDN_Pos)            /*!< 0x00000001 */
#define AFEREGS_REG1_ADC_COMPLETE_PDN                 AFEREGS_REG1_ADC_COMPLETE_PDN_Msk

#define AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Pos          (1U)
#define AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Msk          (0x1UL << AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG1_LVDS_OUTPUT_DISABLE              AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Msk

#define AFEREGS_REG1_ADC_PDN_CH_Pos                   (2U)
#define AFEREGS_REG1_ADC_PDN_CH_Msk                   (0xFUL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x00000002 */
#define AFEREGS_REG1_ADC_PDN_CH                       AFEREGS_REG1_ADC_PDN_CH_Msk
#define AFEREGS_REG1_ADC_PDN_CH1                      (0x1UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH2                      (0x2UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH3                      (0x4UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH4                      (0x8UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH5                      (0x16UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                 /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH6                      (0x32UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                 /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH7                      (0x64UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                 /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH8                      (0x128UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                /*!< 0x01000000 */

#define AFEREGS_REG1_PARTIAL_PDN_Pos                  (10U)
#define AFEREGS_REG1_PARTIAL_PDN_Msk                  (0x1UL << AFEREGS_REG1_PARTIAL_PDN_Pos)                 /*!< 0x00000002 */
#define AFEREGS_REG1_PARTIAL_PDN                      AFEREGS_REG1_PARTIAL_PDN_Msk

#define AFEREGS_REG1_LOW_FREQ_NOISE_Pos               (11U)
#define AFEREGS_REG1_LOW_FREQ_NOISE_Msk               (0x1UL << AFEREGS_REG1_LOW_FREQ_NOISE_Pos)              /*!< 0x00000002 */
#define AFEREGS_REG1_LOW_FREQ_NOISE                   AFEREGS_REG1_LOW_FREQ_NOISE_Msk

#define AFEREGS_REG1_EXT_REF_Pos                      (13U)
#define AFEREGS_REG1_EXT_REF_Msk                      (0x1UL << AFEREGS_REG1_EXT_REF_Pos)                     /*!< 0x00000002 */
#define AFEREGS_REG1_EXT_REF                          AFEREGS_REG1_EXT_REF_Msk

#define AFEREGS_REG1_LVDS_OUTPUT_RATE_2X_Pos          (14U)
#define AFEREGS_REG1_LVDS_OUTPUT_RATE_2X_Msk          (0x1UL << AFEREGS_REG1_LVDS_OUTPUT_RATE_2X_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG1_LVDS_OUTPUT_RATE_2X              AFEREGS_REG1_LVDS_OUTPUT_RATE_2X_Msk

#define AFEREGS_REG1_SINGLE_ENDED_CLK_MODE_Pos        (15U)
#define AFEREGS_REG1_SINGLE_ENDED_CLK_MODE_Msk        (0x1UL << AFEREGS_REG1_SINGLE_ENDED_CLK_MODE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG1_SINGLE_ENDED_CLK_MODE            AFEREGS_REG1_SINGLE_ENDED_CLK_MODE_Msk







extern volatile uint16_t  REG2;
__extension__ typedef struct tagREG2BITS {
  union {
    struct {
      uint16_t :3;
      uint16_t POWER_DOWN_LVDS:8;
      uint16_t AVERAGING_ENABLE:1;
      uint16_t LOW_LATENCY:1;
      uint16_t TEST_PATTERN_MODES:3;
    };
    struct {
      uint16_t :3;
      uint16_t POWER_DOWN_LVDS_CH1:1;
      uint16_t POWER_DOWN_LVDS_CH2:1;
      uint16_t POWER_DOWN_LVDS_CH3:1;
      uint16_t POWER_DOWN_LVDS_CH4:1;
      uint16_t POWER_DOWN_LVDS_CH5:1;
      uint16_t POWER_DOWN_LVDS_CH6:1;
      uint16_t POWER_DOWN_LVDS_CH7:1;
      uint16_t POWER_DOWN_LVDS_CH8:1;
      uint16_t :5;      
    };
  };
} REG2BITS;
extern volatile REG2BITS REG2bits;

extern volatile uint16_t  REG3;
__extension__ typedef struct tagREG3BITS {
  union {
    struct {
      uint16_t INVERT_CHANNELS:8;
      uint16_t CHANNEL_OFFSET_SUBSTRACTION_ENABLE:1;
      uint16_t :3;
      uint16_t DIGITAL_GAIN_ENABLE:1;
      uint16_t SERIALIZED_DATA_RATE:2;
      uint16_t ENABLE_EXTERNAL_REFERENCE_MODE:1;
    };
    struct {
      uint16_t INVERT_CHANNELS_CH1:1;
      uint16_t INVERT_CHANNELS_CH2:1;
      uint16_t INVERT_CHANNELS_CH3:1;
      uint16_t INVERT_CHANNELS_CH4:1;
      uint16_t INVERT_CHANNELS_CH5:1;
      uint16_t INVERT_CHANNELS_CH6:1;
      uint16_t INVERT_CHANNELS_CH7:1;
      uint16_t INVERT_CHANNELS_CH8:1;
      uint16_t :8; 
    };
  };
} REG3BITS;
extern volatile REG3BITS REG3bits;

extern volatile uint16_t  REG4;
__extension__ typedef struct tagREG4BITS {
  union {
    struct {
      uint16_t ADC_RESOLUTION_SELECT:1;
      uint16_t ADC_OUTPUT_FORMAT:1;
      uint16_t LSB_MSB_FIRST:1;
      uint16_t :13; 
    };
    struct {
      uint16_t :16;       
    };
  };
} REG4BITS;
extern volatile REG4BITS REG4bits;

extern volatile uint16_t  REG5;
__extension__ typedef struct tagREG5BITS {
  union {
    struct {
      uint16_t CUSTOM_PATTERN:14;
      uint16_t :2;
    };
    struct {     
      uint16_t :16; 
    };
  };
} REG5BITS;
extern volatile REG5BITS REG5bits;

extern volatile uint16_t  REG10;
__extension__ typedef struct tagREG10BITS {
  union {
    struct {
      uint16_t SYNC_PATTERN:1;
      uint16_t :15;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG10BITS;
extern volatile REG10BITS REG10bits;

extern volatile uint16_t  REG13;
__extension__ typedef struct tagREG13BITS {
  union {
    struct {
      uint16_t OFFSET_CH1:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH1:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG13BITS;
extern volatile REG13BITS REG13bits;

extern volatile uint16_t  REG15;
__extension__ typedef struct tagREG15BITS {
  union {
    struct {
      uint16_t OFFSET_CH2:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH2:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG15BITS;
extern volatile REG15BITS REG15bits;

extern volatile uint16_t  REG17;
__extension__ typedef struct tagREG17BITS {
  union {
    struct {
      uint16_t OFFSET_CH3:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH3:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG17BITS;
extern volatile REG17BITS REG17bits;

extern volatile uint16_t  REG19;
__extension__ typedef struct tagREG19BITS {
  union {
    struct {
      uint16_t OFFSET_CH4:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH4:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG19BITS;
extern volatile REG19BITS REG19bits;


extern volatile uint16_t  REG21;
__extension__ typedef struct tagREG21BITS {
  union {
    struct {
      uint16_t DIGITAL_HPF_FILTER_ENABLE_CH1to4:1;
      uint16_t DIGITAL_HPF_FILTER_K_CH1to4:4;
      uint16_t :11;
      
    };
    struct {
      uint16_t :16;      
    };
  };
} REG21BITS;
extern volatile REG21BITS REG21bits;

extern volatile uint16_t  REG25;
__extension__ typedef struct tagREG25BITS {
  union {
    struct {
      uint16_t OFFSET_CH8:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH8:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG25BITS;
extern volatile REG25BITS REG25bits;

extern volatile uint16_t  REG27;
__extension__ typedef struct tagREG27BITS {
  union {
    struct {
      uint16_t OFFSET_CH7:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH7:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG27BITS;
extern volatile REG27BITS REG27bits;

extern volatile uint16_t  REG29;
__extension__ typedef struct tagREG29BITS {
  union {
    struct {
      uint16_t OFFSET_CH6:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH6:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG29BITS;
extern volatile REG29BITS REG29bits;

extern volatile uint16_t  REG31;
__extension__ typedef struct tagREG31BITS {
  union {
    struct {
      uint16_t OFFSET_CH5:10;
      uint16_t :1;
      uint16_t DIGITAL_GAIN_CH5:5;
    };
    struct {
      uint16_t :16;      
    };
  };
} REG31BITS;
extern volatile REG31BITS REG31bits;

extern volatile uint16_t  REG33;
__extension__ typedef struct tagREG33BITS {
  union {
    struct {
      uint16_t DIGITAL_HPF_FILTER_ENABLE_CH5to8:1;
      uint16_t DIGITAL_HPF_FILTER_K_CH5to8:4;
      uint16_t :11;      
    };
    struct {
      uint16_t :16;      
    };
  };
} REG33BITS;
extern volatile REG33BITS REG33bits;

extern volatile uint16_t  REG66;
__extension__ typedef struct tagREG66BITS {
  union {
    struct {
      uint16_t :15;   
      uint16_t DITHER:1;
         
    };
    struct {
      uint16_t :16;      
    };
  };
} REG66BITS;
extern volatile REG66BITS REG66bits;


#endif
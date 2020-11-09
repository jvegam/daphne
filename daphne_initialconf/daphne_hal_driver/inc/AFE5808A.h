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

 

extern volatile uint16_t  REG0;
__extension__ typedef struct tagREG0BITS {
  union {
    struct {
      uint16_t SOFTWARE_RESET:1;
      uint16_t REGISTER_READOUT_ENABLE:1;
      uint16_t :14;
    };
    struct {
      uint16_t :16;       
    };
  };
} REG0BITS;
extern volatile REG0BITS REG0bits;

extern volatile uint16_t  REG1;
__extension__ typedef struct tagREG1BITS {
  union {
    struct {
      uint16_t ADC_COMPLETE_PDN:1;
      uint16_t LVDS_OUTPUT_DISABLE:1;
      uint16_t ADC_PDN_CH:8;
      uint16_t PARTIAL_PDN:1;
      uint16_t LOW_FREQUENCY_NOISE_SUPPRESSION:1;
      uint16_t :1;
      uint16_t EXT_REF:1;
      uint16_t LVDS_OUTPUT_RATE_2X:1;
      uint16_t SINGLE_ENDED_CLK_MODE:1;
    };
    struct {
      uint16_t :2;
      uint16_t ADC_PDN_CH1:1;
      uint16_t ADC_PDN_CH2:1;
      uint16_t ADC_PDN_CH3:1;
      uint16_t ADC_PDN_CH4:1;
      uint16_t ADC_PDN_CH5:1;
      uint16_t ADC_PDN_CH6:1;
      uint16_t ADC_PDN_CH7:1;
      uint16_t ADC_PDN_CH8:1;
      uint16_t :6;      
    };
  };
} REG1BITS;
extern volatile REG1BITS REG1bits;

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
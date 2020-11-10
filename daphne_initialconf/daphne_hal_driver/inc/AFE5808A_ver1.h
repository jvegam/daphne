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
  uint16_t REG0;
  uint16_t REG1;
  uint16_t REG2;
  uint16_t REG3;
  uint16_t REG4;
  uint16_t REG5;
  uint16_t REG10;
  uint16_t REG13;
  uint16_t REG15;
  uint16_t REG17;
  uint16_t REG19;
  uint16_t REG21;
  uint16_t REG25;
  uint16_t REG27;
  uint16_t REG29;
  uint16_t REG31;
  uint16_t REG33;
  uint16_t REG66;
}AFEREGS_TypeDef;

/*****************  Bit definition for AFEREGS_REG0 register  ******************/
#define AFEREGS_REG0_SOFTWARE_RESET_Pos               (0U)
#define AFEREGS_REG0_SOFTWARE_RESET_Msk               (0x1UL << AFEREGS_REG0_SOFTWARE_RESET_Pos)         /*!< 0x00000001 */
#define AFEREGS_REG0_SOFTWARE_RESET                   AFEREGS_REG0_SOFTWARE_RESET_Msk
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE_Pos      (1U)
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE_Msk      (0x1UL << AFEREGS_REG0_REGISTER_READOUT_ENABLE_Pos)     /*!< 0x00000002 */
#define AFEREGS_REG0_REGISTER_READOUT_ENABLE          AFEREGS_REG0_REGISTER_READOUT_ENABLE_Msk 

/*****************  Bit definition for AFEREGS_REG1 register  ******************/
#define AFEREGS_REG1_ADC_COMPLETE_PDN_Pos             (0U)
#define AFEREGS_REG1_ADC_COMPLETE_PDN_Msk             (0x1UL << AFEREGS_REG1_ADC_COMPLETE_PDN_Pos)            /*!< 0x00000001 */
#define AFEREGS_REG1_ADC_COMPLETE_PDN                 AFEREGS_REG1_ADC_COMPLETE_PDN_Msk

#define AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Pos          (1U)
#define AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Msk          (0x1UL << AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG1_LVDS_OUTPUT_DISABLE              AFEREGS_REG1_LVDS_OUTPUT_DISABLE_Msk

#define AFEREGS_REG1_ADC_PDN_CH_Pos                   (2U)
#define AFEREGS_REG1_ADC_PDN_CH_Msk                   (0xFFUL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x00000002 */
#define AFEREGS_REG1_ADC_PDN_CH                       AFEREGS_REG1_ADC_PDN_CH_Msk
#define AFEREGS_REG1_ADC_PDN_CH1                      (0x1UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH2                      (0x2UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH3                      (0x4UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH4                      (0x8UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                  /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH5                      (0x16UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                 /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH6                      (0x32UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                 /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH7                      (0x64UL << AFEREGS_REG1_ADC_PDN_CH_Pos)                 /*!< 0x01000000 */
#define AFEREGS_REG1_ADC_PDN_CH8                      (0x128UL << AFEREGS_REG1_ADC_PDN_CH_Pos)             /*!< 0x01000000 */

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

/*****************  Bit definition for AFEREGS_REG2 register  ******************/

#define AFEREGS_REG2_POWER_DOWN_LVDS_Pos              (3U)
#define AFEREGS_REG2_POWER_DOWN_LVDS_Msk              (0xFFUL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG2_POWER_DOWN_LVDS                  AFEREGS_REG2_POWER_DOWN_LVDS_Msk
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH1              (0x1UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH2              (0x2UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH3              (0x4UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH4              (0x8UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH5              (0x16UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH6              (0x32UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH7              (0x64UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)
#define AFEREGS_REG2_POWER_DOWN_LVDS_CH8              (0x128UL << AFEREGS_REG2_POWER_DOWN_LVDS_Pos)

#define AFEREGS_REG2_AVERAGING_ENABLE_Pos             (11U)
#define AFEREGS_REG2_AVERAGING_ENABLE_Msk             (0x1UL << AFEREGS_REG2_AVERAGING_ENABLE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG2_AVERAGING_ENABLE                 AFEREGS_REG2_AVERAGING_ENABLE_Msk

#define AFEREGS_REG2_AVERAGING_ENABLE_Pos             (11U)
#define AFEREGS_REG2_AVERAGING_ENABLE_Msk             (0x1UL << AFEREGS_REG2_AVERAGING_ENABLE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG2_AVERAGING_ENABLE                 AFEREGS_REG2_AVERAGING_ENABLE_Msk

#define AFEREGS_REG2_LOW_LATENCY_Pos                  (12U)
#define AFEREGS_REG2_LOW_LATENCY_Msk                  (0x1UL << AFEREGS_REG2_LOW_LATENCY_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG2_LOW_LATENCY                      AFEREGS_REG2_LOW_LATENCY_Msk

#define AFEREGS_REG2_TEST_PATTERN_MODES_Pos           (13U)
#define AFEREGS_REG2_TEST_PATTERN_MODES_Msk           (0x7UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG2_TEST_PATTERN_MODES               AFEREGS_REG2_TEST_PATTERN_MODES_Msk
#define AFEREGS_REG2_TEST_PATTERN_MODES_NORMAL        (0x0UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)
#define AFEREGS_REG2_TEST_PATTERN_MODES_SYNC          (0x1UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)
#define AFEREGS_REG2_TEST_PATTERN_MODES_DESKEW        (0x2UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)
#define AFEREGS_REG2_TEST_PATTERN_MODES_CUSTOM        (0x3UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)
#define AFEREGS_REG2_TEST_PATTERN_MODES_ALLONES       (0x4UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)
#define AFEREGS_REG2_TEST_PATTERN_MODES_TOGGLE        (0x5UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)
#define AFEREGS_REG2_TEST_PATTERN_MODES_ALLZEROS      (0x6UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)
#define AFEREGS_REG2_TEST_PATTERN_MODES_RAMP          (0x7UL << AFEREGS_REG2_TEST_PATTERN_MODES_Pos)

/*****************  Bit definition for AFEREGS_REG3 register  ******************/
#define AFEREGS_REG3_INVERT_CHANNELS_Pos           (0U)
#define AFEREGS_REG3_INVERT_CHANNELS_Msk           (0xFFUL << AFEREGS_REG3_INVERT_CHANNELS_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG3_INVERT_CHANNELS               AFEREGS_REG3_INVERT_CHANNELS_Msk
#define AFEREGS_REG3_INVERT_CHANNELS_CH1           (0x1UL << AFEREGS_REG3_INVERT_CHANNELS_Pos)  
#define AFEREGS_REG3_INVERT_CHANNELS_CH2           (0x2UL << AFEREGS_REG3_INVERT_CHANNELS_Pos) 
#define AFEREGS_REG3_INVERT_CHANNELS_CH3           (0x4UL << AFEREGS_REG3_INVERT_CHANNELS_Pos) 
#define AFEREGS_REG3_INVERT_CHANNELS_CH4           (0x8UL << AFEREGS_REG3_INVERT_CHANNELS_Pos) 
#define AFEREGS_REG3_INVERT_CHANNELS_CH5           (0x16UL << AFEREGS_REG3_INVERT_CHANNELS_Pos) 
#define AFEREGS_REG3_INVERT_CHANNELS_CH6           (0x32UL << AFEREGS_REG3_INVERT_CHANNELS_Pos) 
#define AFEREGS_REG3_INVERT_CHANNELS_CH7           (0x64UL << AFEREGS_REG3_INVERT_CHANNELS_Pos) 
#define AFEREGS_REG3_INVERT_CHANNELS_CH8           (0x128UL << AFEREGS_REG3_INVERT_CHANNELS_Pos) 

#define AFEREGS_REG3_CHANNEL_OFFSET_SUBSTRACTION_ENABLE_Pos           (8U)
#define AFEREGS_REG3_CHANNEL_OFFSET_SUBSTRACTION_ENABLE_Msk           (0x1UL << AFEREGS_REG3_CHANNEL_OFFSET_SUBSTRACTION_ENABLE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG3_CHANNEL_OFFSET_SUBSTRACTION_ENABLE               AFEREGS_REG3_CHANNEL_OFFSET_SUBSTRACTION_ENABLE_Msk

#define AFEREGS_REG3_DIGITAL_GAIN_ENABLE_Pos            (12U)
#define AFEREGS_REG3_DIGITAL_GAIN_ENABLE_Msk            (0x1UL << AFEREGS_REG3_DIGITAL_GAIN_ENABLE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG3_DIGITAL_GAIN_ENABLE                AFEREGS_REG3_DIGITAL_GAIN_ENABLE_Msk

#define AFEREGS_REG3_SERIALIZED_DATA_RATE_Pos           (13U)
#define AFEREGS_REG3_SERIALIZED_DATA_RATE_Msk           (0x3UL << AFEREGS_REG3_SERIALIZED_DATA_RATE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG3_SERIALIZED_DATA_RATE               AFEREGS_REG3_SERIALIZED_DATA_RATE_Msk
#define AFEREGS_REG3_SERIALIZED_DATA_RATE_14X           (0x0UL << AFEREGS_REG3_SERIALIZED_DATA_RATE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG3_SERIALIZED_DATA_RATE_16X           (0x1UL << AFEREGS_REG3_SERIALIZED_DATA_RATE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG3_SERIALIZED_DATA_RATE_12X           (0x3UL << AFEREGS_REG3_SERIALIZED_DATA_RATE_Pos)         /*!< 0x00000002 */

#define AFEREGS_REG3_ENABLE_EXTERNAL_REFERENCE_MODE_Pos (15U)
#define AFEREGS_REG3_ENABLE_EXTERNAL_REFERENCE_MODE_Msk (0x1UL << AFEREGS_REG3_ENABLE_EXTERNAL_REFERENCE_MODE_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG3_ENABLE_EXTERNAL_REFERENCE_MODE     AFEREGS_REG3_ENABLE_EXTERNAL_REFERENCE_MODE_Msk
/*****************  Bit definition for AFEREGS_REG4 register  ******************/
#define AFEREGS_REG4_ADC_RESOLUTION_SELECT_Pos          (1U)
#define AFEREGS_REG4_ADC_RESOLUTION_SELECT_Msk          (0x1UL << AFEREGS_REG4_ADC_RESOLUTION_SELECT_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG4_ADC_RESOLUTION_SELECT              AFEREGS_REG4_ADC_RESOLUTION_SELECT_Msk
#define AFEREGS_REG4_ADC_RESOLUTION_SELECT_14b          (0x0UL << AFEREGS_REG4_ADC_RESOLUTION_SELECT_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG4_ADC_RESOLUTION_SELECT_12b          (0x1UL << AFEREGS_REG4_ADC_RESOLUTION_SELECT_Pos)         /*!< 0x00000002 */

#define AFEREGS_REG4_ADC_OUTPUT_FORMAT_Pos              (3U)
#define AFEREGS_REG4_ADC_OUTPUT_FORMAT_Msk              (0x1UL << AFEREGS_REG4_ADC_OUTPUT_FORMAT_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG4_ADC_OUTPUT_FORMAT                  AFEREGS_REG4_ADC_OUTPUT_FORMAT_Msk
#define AFEREGS_REG4_ADC_OUTPUT_FORMAT_TWOCOMP          (0x0UL << AFEREGS_REG4_ADC_OUTPUT_FORMAT_Pos)
#define AFEREGS_REG4_ADC_OUTPUT_FORMAT_OFFBINARY        (0x1UL << AFEREGS_REG4_ADC_OUTPUT_FORMAT_Pos)

#define AFEREGS_REG4_LSB_MSB_FIRST_Pos                  (4U)
#define AFEREGS_REG4_LSB_MSB_FIRST_Msk                  (0x1UL << AFEREGS_REG4_LSB_MSB_FIRST_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG4_LSB_MSB_FIRST                      AFEREGS_REG4_LSB_MSB_FIRST_Msk
#define AFEREGS_REG4_LSB_FIRST                          (0x0UL << AFEREGS_REG4_LSB_MSB_FIRST_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG4_MSB_FIRST                          (0x1UL << AFEREGS_REG4_LSB_MSB_FIRST_Pos)         /*!< 0x00000002 */

/*****************  Bit definition for AFEREGS_REG5 register  ******************/

#define AFEREGS_REG5_CUSTOM_PATTERN_Pos                 (0U)
#define AFEREGS_REG5_CUSTOM_PATTERN_Msk                 (0x2FFFUL << AFEREGS_REG5_CUSTOM_PATTERN_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG5_CUSTOM_PATTERN                     AFEREGS_REG5_CUSTOM_PATTERN_Msk

/*****************  Bit definition for AFEREGS_REG10 register  ******************/
#define AFEREGS_REG10_SYNC_PATTERN_Pos                  (8U)
#define AFEREGS_REG10_SYNC_PATTERN_Msk                  (0x1UL << AFEREGS_REG10_SYNC_PATTERN_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG10_SYNC_PATTERN                      AFEREGS_REG10_SYNC_PATTERN_Msk

/*****************  Bit definition for AFEREGS_REG13 register  ******************/
#define AFEREGS_REG13_OFFSET_CH1_Pos                    (0U)
#define AFEREGS_REG13_OFFSET_CH1_Msk                    (0x3FFUL << AFEREGS_REG13_OFFSET_CH1_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG13_OFFSET_CH1                        AFEREGS_REG13_OFFSET_CH1_Msk

#define AFEREGS_REG13_DIGITAL_GAIN_CH1_Pos              (11U)
#define AFEREGS_REG13_DIGITAL_GAIN_CH1_Msk              (0x1FUL << AFEREGS_REG13_DIGITAL_GAIN_CH1_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG13_DIGITAL_GAIN_CH1                  AFEREGS_REG13_DIGITAL_GAIN_CH1_Msk

/*****************  Bit definition for AFEREGS_REG15 register  ******************/
#define AFEREGS_REG15_OFFSET_CH2_Pos                    (0U)
#define AFEREGS_REG15_OFFSET_CH2_Msk                    (0x3FFUL << AFEREGS_REG15_OFFSET_CH2_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG15_OFFSET_CH2                        AFEREGS_REG15_OFFSET_CH2_Msk

#define AFEREGS_REG15_DIGITAL_GAIN_CH2_Pos              (11U)
#define AFEREGS_REG15_DIGITAL_GAIN_CH2_Msk              (0x1FUL << AFEREGS_REG15_DIGITAL_GAIN_CH2_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG15_DIGITAL_GAIN_CH2                  AFEREGS_REG15_DIGITAL_GAIN_CH2_Msk

/*****************  Bit definition for AFEREGS_REG17 register  ******************/
#define AFEREGS_REG17_OFFSET_CH3_Pos                    (0U)
#define AFEREGS_REG17_OFFSET_CH3_Msk                    (0x3FFUL << AFEREGS_REG17_OFFSET_CH3_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG17_OFFSET_CH3                        AFEREGS_REG17_OFFSET_CH3_Msk

#define AFEREGS_REG17_DIGITAL_GAIN_CH3_Pos              (11U)
#define AFEREGS_REG17_DIGITAL_GAIN_CH3_Msk              (0x1FUL << AFEREGS_REG17_DIGITAL_GAIN_CH3_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG17_DIGITAL_GAIN_CH3                  AFEREGS_REG17_DIGITAL_GAIN_CH3_Msk

/*****************  Bit definition for AFEREGS_REG19 register  ******************/
#define AFEREGS_REG19_OFFSET_CH4_Pos                    (0U)
#define AFEREGS_REG19_OFFSET_CH4_Msk                    (0x3FFUL << AFEREGS_REG19_OFFSET_CH4_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG19_OFFSET_CH4                        AFEREGS_REG19_OFFSET_CH4_Msk

#define AFEREGS_REG19_DIGITAL_GAIN_CH4_Pos              (11U)
#define AFEREGS_REG19_DIGITAL_GAIN_CH4_Msk              (0x1FUL << AFEREGS_REG19_DIGITAL_GAIN_CH4_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG19_DIGITAL_GAIN_CH4                  AFEREGS_REG19_DIGITAL_GAIN_CH4_Msk

/*****************  Bit definition for AFEREGS_REG21 register  ******************/
#define AFEREGS_REG21_DIGITAL_HPF_FILTER_ENABLE_CH1to4_Pos           (0U)
#define AFEREGS_REG21_DIGITAL_HPF_FILTER_ENABLE_CH1to4_Msk           (0x1UL << AFEREGS_REG21_DIGITAL_HPF_FILTER_ENABLE_CH1to4_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG21_DIGITAL_HPF_FILTER_ENABLE_CH1to4               AFEREGS_REG21_DIGITAL_HPF_FILTER_ENABLE_CH1to4_Msk

#define AFEREGS_REG21_DIGITAL_HPF_FILTER_K_CH1to4_Pos               (1U)
#define AFEREGS_REG21_DIGITAL_HPF_FILTER_K_CH1to4_Msk               (0xFUL << AFEREGS_REG21_DIGITAL_HPF_FILTER_K_CH1to4_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG21_DIGITAL_HPF_FILTER_K_CH1to4                   AFEREGS_REG21_DIGITAL_HPF_FILTER_K_CH1to4_Msk


/*****************  Bit definition for AFEREGS_REG25 register  ******************/
#define AFEREGS_REG25_OFFSET_CH8_Pos           (0U)
#define AFEREGS_REG25_OFFSET_CH8_Msk           (0x3FFUL << AFEREGS_REG25_OFFSET_CH8_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG25_OFFSET_CH8               AFEREGS_REG25_OFFSET_CH8_Msk

#define AFEREGS_REG25_DIGITAL_GAIN_CH8_Pos     (11U)
#define AFEREGS_REG25_DIGITAL_GAIN_CH8_Msk     (0x1FUL << AFEREGS_REG25_DIGITAL_GAIN_CH8_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG25_DIGITAL_GAIN_CH8         AFEREGS_REG25_DIGITAL_GAIN_CH8_Msk

/*****************  Bit definition for AFEREGS_REG27 register  ******************/
#define AFEREGS_REG27_OFFSET_CH7_Pos           (0U)
#define AFEREGS_REG27_OFFSET_CH7_Msk           (0x3FFUL << AFEREGS_REG27_OFFSET_CH7_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG27_OFFSET_CH7               AFEREGS_REG27_OFFSET_CH7_Msk

#define AFEREGS_REG27_DIGITAL_GAIN_CH7_Pos     (11U)
#define AFEREGS_REG27_DIGITAL_GAIN_CH7_Msk     (0x1FUL << AFEREGS_REG27_DIGITAL_GAIN_CH7_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG27_DIGITAL_GAIN_CH7         AFEREGS_REG27_DIGITAL_GAIN_CH7_Msk

/*****************  Bit definition for AFEREGS_REG29 register  ******************/
#define AFEREGS_REG29_OFFSET_CH6_Pos           (0U)
#define AFEREGS_REG29_OFFSET_CH3_Msk           (0x3FFUL << AFEREGS_REG29_OFFSET_CH6_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG29_OFFSET_CH3               AFEREGS_REG29_OFFSET_CH3_Msk

#define AFEREGS_REG29_DIGITAL_GAIN_CH6_Pos     (11U)
#define AFEREGS_REG29_DIGITAL_GAIN_CH6_Msk     (0x1FUL << AFEREGS_REG29_DIGITAL_GAIN_CH6_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG29_DIGITAL_GAIN_CH6         AFEREGS_REG29_DIGITAL_GAIN_CH6_Msk

/*****************  Bit definition for AFEREGS_REG31 register  ******************/
#define AFEREGS_REG31_OFFSET_CH5_Pos           (0U)
#define AFEREGS_REG31_OFFSET_CH5_Msk           (0x3FFUL << AFEREGS_REG31_OFFSET_CH5_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG31_OFFSET_CH5               AFEREGS_REG31_OFFSET_CH5_Msk

#define AFEREGS_REG31_DIGITAL_GAIN_CH5_Pos     (11U)
#define AFEREGS_REG31_DIGITAL_GAIN_CH5_Msk     (0x1FUL << AFEREGS_REG31_DIGITAL_GAIN_CH5_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG31_DIGITAL_GAIN_CH5         AFEREGS_REG31_DIGITAL_GAIN_CH5_Msk

/*****************  Bit definition for AFEREGS_REG33 register  ******************/
#define AFEREGS_REG33_DIGITAL_HPF_FILTER_ENABLE_CH5to8_Pos        (0U)
#define AFEREGS_REG33_DIGITAL_HPF_FILTER_ENABLE_CH5to8_Msk        (0x1UL << AFEREGS_REG33_DIGITAL_HPF_FILTER_ENABLE_CH5to8_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG33_DIGITAL_HPF_FILTER_ENABLE_CH5to8            AFEREGS_REG33_DIGITAL_HPF_FILTER_ENABLE_CH5to8_Msk

#define AFEREGS_REG33_DIGITAL_HPF_FILTER_K_CH5to8_Pos             (1U)
#define AFEREGS_REG33_DIGITAL_HPF_FILTER_K_CH5to8_Msk             (0xFUL << AFEREGS_REG33_DIGITAL_HPF_FILTER_K_CH5to8_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG33_DIGITAL_HPF_FILTER_K_CH5to8                 AFEREGS_REG33_DIGITAL_HPF_FILTER_K_CH5to8_Msk

/*****************  Bit definition for AFEREGS_REG66 register  ******************/
#define AFEREGS_REG33_DITHER_Pos           (15U)
#define AFEREGS_REG33_DITHER_Msk           (0x1UL << AFEREGS_REG33_DITHER_Pos)         /*!< 0x00000002 */
#define AFEREGS_REG33_DITHER               AFEREGS_REG33_DITHER_Msk




#endif
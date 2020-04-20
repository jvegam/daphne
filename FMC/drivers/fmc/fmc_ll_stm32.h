/*
 * Copyright (c) 2016 BayLibre, SAS
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_FMC_SPI_LL_STM32_H_
#define ZEPHYR_DRIVERS_FMC_SPI_LL_STM32_H_

#include "fmc_context.h"

typedef void (*irq_config_func_t)(struct device *port);

struct fmc_enable{
	u8_t enable1;
	u8_t enable2;
	u8_t enable3;
	u8_t enable4;
};

struct fmc_cfgdata {
	struct fmc_enable *sramhandleen;
	u8_t datawidth;
	u8_t addresswidth;
	struct fmc_enable *asyncwaiten;

};

struct fmc_stm32_config {
	struct SRAM_HandleTypeDef *sramfmc;
	struct stm32_pclken pclken;	

};

struct fmc_stm32_data {
    struct device *clock;
	struct fmc_cfgdata *data;
	
	struct SRAM_HandleTypeDef *sramfmc1;
	struct SRAM_HandleTypeDef *sramfmc2;
	struct SRAM_HandleTypeDef *sramfmc3;
	struct SRAM_HandleTypeDef *sramfmc4;
	FMC_NORSRAM_TimingTypeDef *Timing;
	FMC_NORSRAM_TimingTypeDef *ExtTiming;

};






#endif	/* ZEPHYR_DRIVERS_FMC_LL_STM32_H_ */

/*
 * Copyright (c) 2015 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Public API for FMC drivers and applications
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_FMC_H_
#define ZEPHYR_INCLUDE_DRIVERS_FMC_H_

/**
 * @brief FMC Interface
 * @defgroup fmc_interface FMC Interface
 * @ingroup io_interfaces
 * @{
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief FMC SRAM Address 
 */
#define FMC_SRAM_BANK1_ADDR1 ((uint32_t)0x60000000)
#define FMC_SRAM_BANK1_ADDR2 ((uint32_t)0x64000000)
#define FMC_SRAM_BANK1_ADDR3 ((uint32_t)0x68000000)
#define FMC_SRAM_BANK1_ADDR4 ((uint32_t)0x6C000000)


/** @brief FMC devices mode, only NORSRAM is supported */
enum fmc_config_device {
	NORSRAM_DEVICE,
	NAND_DEVICE, 
	SDRAM_DEVICE
};

/** @brief FMC bank select */
#
enum fmc_config_bank {
	BANK1,
	BANK2,
	BANK3,
	BANK4
};

/** @brief FMC config memory type only SRAM is supported*/
enum fmc_config_type {
	SRAM
};

struct fmc_config_data {
 	u32_t BankAddress,
	u32_t Offset,
	u32_t bufferSize
};

struct fmc_config {
	u32_t 	cfgdev;
	fmc_config_bank Bank;
	u32_t 	AddrWidth;
	u32_t 	DatWidth;
	u32_t 	WriteOperationEnable;	
	const struct fmc_config_wait *WaitSignal;
	const struct fmc_config_timing *timing;
	u32_t 	ExtendedMode;
	const struct fmc_config_timing *ExtTiming;
};

 struct fmc_config_wait {
 	u32_t 	Enable;
 	u32_t 	Polarity;
 	u32_t 	Active;
 }

struct fmc_config_timing {
	u32_t 	AddressSetup;
	u32_t 	AddressHold;
	u32_t 	DataSetup;
	u32_t 	BusTurnAroundDuration;
	u32_t 	ClkDivision;
	u32_t 	DataLatency;
	u32_t 	AccessMode;
};


__syscall int fmc_sram_read16(struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t *BufferRx);

static inline int z_impl_fmc_sram_read16(struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t *BufferRx);				
{
	const struct fmc_driver_api *api =
		(const struct fmc_driver_api *)dev->driver_api;

	return api->sram_read16(dev, bank, offset, size, BufferRx);
}

__syscall int fmc_sram_write16(struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t *BufferTx);

static inline int z_impl_fmc_sram_write16(struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t *BufferTx);				
{
	const struct fmc_driver_api *api =
		(const struct fmc_driver_api *)dev->driver_api;

	return api->sram_write16(dev, bank, offset, size, BufferTx);
}

__syscall int fmc_sram_configure(struct device *dev,
				 struct fmc_config *cfgdata);

static inline int z_impl_fmc_sram_configure(struct device *dev,
				 struct fmc_config_data *cfgdata)				
{
	const struct fmc_driver_api *api =
		(const struct fmc_driver_api *)dev->driver_api;

	return api->sram_configure(dev, cfgdata);
}



/**
 * @brief FMC driver API
 * This is the mandatory API any SPI driver needs to expose.
 */
__subsystem struct spi_driver_api {
	int (*sram_write16) (struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t BufferTx);

	int (*sram_read16) (struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t *BufferRx);

	int (*sram_configure) (struct device *dev,
				 struct fmc_config *cfg);
};

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#include <syscalls/fmc.h>

#endif /* ZEPHYR_INCLUDE_DRIVERS_FMC_H_ */

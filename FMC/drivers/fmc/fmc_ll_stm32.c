/*
 * Copyright (c) 2020 Juan Vega <juan.vega25@gmailcom>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT st_stm32_fmc

#define LOG_LEVEL CONFIG_FMC_LOG_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(fmc_ll_stm32);

#include <sys/util.h>
#include <kernel.h>
#include <soc.h>
#include <errno.h>
#include <drivers/fmc.h>
#include <toolchain.h>

#include <drivers/clock_control/stm32_clock_control.h>
#include <drivers/clock_control.h>

#include "fmc_ll_stm32.h"


#define DEV_CFG(dev)						\
(const struct fmc_stm32_config * const)(dev->config->config_info)

#define DEV_DATA(dev)					\
(struct fmc_stm32_data * const)(dev->driver_data)


static const struct fmc_driver_api fmc_stm32_driver_api = {
	.configure = fmc_stm32_configure,
	.sram_read16 = fmc_stm32_read,
	.sram_write16 = fmc_stm32_write	
};	


static int sram_write16 (struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t *BufferTx);
{
	const struct spi_stm32_config *cfg = DEV_CFG(dev);
	struct spi_stm32_data *data = DEV_DATA(dev);
    
    struct SRAM_HandleTypeDef *phsram1 = &data->sramfmc1;
    struct SRAM_HandleTypeDef *phsram2 = &data->sramfmc2;
    struct SRAM_HandleTypeDef *phsram3 = &data->sramfmc3;
    struct SRAM_HandleTypeDef *phsram4 = &data->sramfmc4;
    
    struct SRAM_HandleTypeDef *phsramhandle;
	int ret;

    u32_t SRAMBank_Address;

    switch(bank){
    	case BANK1: SRAMBank_Address=(uint32_t)(0x60000000); phsramhandle = &phsram1; break;
    	case BANK2: SRAMBank_Address=(uint32_t)(0x64000000); phsramhandle = &phsram2; break;
    	case BANK3: SRAMBank_Address=(uint32_t)(0x68000000); phsramhandle = &phsram3; break;
    	case BANK4: SRAMBank_Address=(uint32_t)(0x6c000000); phsramhandle = &phsram4; break;
    	default: SRAMBank_Address=(uint32_t)(0x60000000); phsramhandle = &phsram1; break;
    };
    
    SRAMBank_Address+=offset;

    HAL_SRAM_Write_16b(&phsram,(uint32_t *)(SRAMBank_Address),&BufferTx, size);
}

static int sram_read16 (struct device *dev,
				 enum fmc_config_bank bank, 
				 u32_t offset,
				 u32_t size,
				 u16_t *BufferRx);
{
	const struct spi_stm32_config *cfg = DEV_CFG(dev);
	struct spi_stm32_data *data = DEV_DATA(dev);
    
    struct SRAM_HandleTypeDef *phsram1 = &data->sramfmc1;
    struct SRAM_HandleTypeDef *phsram2 = &data->sramfmc2;
    struct SRAM_HandleTypeDef *phsram3 = &data->sramfmc3;
    struct SRAM_HandleTypeDef *phsram4 = &data->sramfmc4;
    
    struct SRAM_HandleTypeDef *phsramhandle;
	int ret;

    u32_t SRAMBank_Address;

    switch(bank){
    	case BANK1: SRAMBank_Address=(uint32_t)(0x60000000); phsramhandle = &phsram1; break;
    	case BANK2: SRAMBank_Address=(uint32_t)(0x64000000); phsramhandle = &phsram2; break;
    	case BANK3: SRAMBank_Address=(uint32_t)(0x68000000); phsramhandle = &phsram3; break;
    	case BANK4: SRAMBank_Address=(uint32_t)(0x6c000000); phsramhandle = &phsram4; break;
    	default: SRAMBank_Address=(uint32_t)(0x60000000); phsramhandle = &phsram1; break;
    };
    
    SRAMBank_Address+=offset;

    HAL_SRAM_Read_16b(&phsramhandle,(uint32_t *)(SRAMBank_Address),&BufferRx, size);

}

static inline void __fmc_stm32_get_clock(struct device *dev)
{
	struct fmc_stm32_data *data = DEV_DATA(dev);
	struct device *clk =
		device_get_binding(STM32_CLOCK_CONTROL_NAME);

	__ASSERT_NO_MSG(clk);

	data->clock = clk;
}


static int fmc_stm32_init(struct device *dev)
{
	const struct fmc_stm32_config *cfg = DEV_CFG(dev);
	struct fmc_stm32_data *data = DEV_DATA(dev);


	FMC_NORSRAM_TimingTypeDef *Tim 	   = &data->Timing;
	FMC_NORSRAM_TimingTypeDef *ExtTim  = &data->ExtTiming;
    struct SRAM_HandleTypeDef *phsram1 = &data->sramfmc1;
    struct SRAM_HandleTypeDef *phsram2 = &data->sramfmc2;
    struct SRAM_HandleTypeDef *phsram3 = &data->sramfmc3;
    struct SRAM_HandleTypeDef *phsram4 = &data->sramfmc4;

    __fmc_stm32_get_clock(dev);
	/* enable clock */
	if (clock_control_on(data->clock,
			(clock_control_subsys_t *)&config->pclken) != 0) {
		return -EIO;
	}

	  /* Timing */
	Tim->AddressSetupTime = 15;
	Tim->AddressHoldTime = 15;
	Tim->DataSetupTime = 255;
	Tim->BusTurnAroundDuration = 15;
	Tim->CLKDivision = 16;
	Tim->DataLatency = 17;
	Tim->AccessMode = FMC_ACCESS_MODE_A;
	  /* ExtTiming */
	ExtTim->AddressSetupTime = 15;
	ExtTim->AddressHoldTime = 15;
	ExtTim->DataSetupTime = 255;
	ExtTim->BusTurnAroundDuration = 15;
	ExtTim->CLKDivision = 16;
	ExtTim->DataLatency = 17;
	ExtTim->AccessMode = FMC_ACCESS_MODE_A;


    phsram1->Instance = FMC_NORSRAM_DEVICE; // (FMC_NORSRAM_TypeDef *) DT_INST_REG_ADDR_BY_IDX(id,0),
	phsram1->Extended = FMC_NORSRAM_EXTENDED_DEVICE; //(FMC_NORSRAM_EXTENDED_TypeDef *) DT_INST_REG_ADDR_BY_IDX(id,1)
	  /* &phsram->Init */
	phsram1->Init->NSBank = FMC_NORSRAM_BANK1; //--
	phsram1->Init->DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
	phsram1->Init->MemoryType = FMC_MEMORY_TYPE_SRAM;
	phsram1->Init->MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16; //--
	phsram1->Init->BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
	phsram1->Init->WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_HIGH; //--
	phsram1->Init->WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
	phsram1->Init->WriteOperation = FMC_WRITE_OPERATION_ENABLE;
	phsram1->Init->WaitSignal = FMC_WAIT_SIGNAL_DISABLE; //--
	phsram1->Init->ExtendedMode = FMC_EXTENDED_MODE_ENABLE;
	phsram1->Init->AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_ENABLE;
	phsram1->Init->WriteBurst = FMC_WRITE_BURST_DISABLE;
	phsram1->Init->ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
	phsram1->Init->WriteFifo = FMC_WRITE_FIFO_ENABLE;
	phsram1->Init->PageSize = FMC_PAGE_SIZE_NONE;

    
	phsram2->Instance = FMC_NORSRAM_DEVICE;
	phsram2->Extended = FMC_NORSRAM_EXTENDED_DEVICE;
	  /* &phsram->Init */
	phsram2->Init->NSBank = FMC_NORSRAM_BANK2; //--
	phsram2->Init->DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
	phsram2->Init->MemoryType = FMC_MEMORY_TYPE_SRAM;
	phsram2->Init->MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16; //--
	phsram2->Init->BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
	phsram2->Init->WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_HIGH; //--
	phsram2->Init->WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
	phsram2->Init->WriteOperation = FMC_WRITE_OPERATION_ENABLE;
	phsram2->Init->WaitSignal = FMC_WAIT_SIGNAL_DISABLE; //--
	phsram2->Init->ExtendedMode = FMC_EXTENDED_MODE_ENABLE;
	phsram2->Init->AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
	phsram2->Init->WriteBurst = FMC_WRITE_BURST_DISABLE;
	phsram2->Init->ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
	phsram2->Init->WriteFifo = FMC_WRITE_FIFO_ENABLE;
	phsram2->Init->PageSize = FMC_PAGE_SIZE_NONE;


    
    if (HAL_SRAM_Init(&phsram1, &Tim, &ExtTim) != HAL_OK)
    {
  		LOG_ERR("FMC SRAM 1 UNINITIALIZED");
     	return -EIO
    }

     if (HAL_SRAM_Init(&phsram2, &Tim, &ExtTim) != HAL_OK)
    {
  		LOG_ERR("FMC SRAM 2 UNINITIALIZED");
     	return -EIO
    }

    return 0;
	
};
//Funcion para inicializar desde el programa de usuario
static int fmc_stm32_configure(struct device *dev,
				 struct fmc_config *cfgdata);
{
	const struct fmc_stm32_config *cfg = DEV_CFG(dev);
	struct fmc_stm32_data *data = DEV_DATA(dev);


	return 0;
}






#define STM32_FMC_INIT(id)													\
																			\
static const struct fmc_stm32_config fmc_stm32_cfg_##id = {					\
	.sramfmc = {															\
		.Instance = (FMC_NORSRAM_TypeDef *) DT_INST_REG_ADDR_BY_IDX(id,0),	\
		.Extended = (FMC_NORSRAM_EXTENDED_TypeDef *) DT_INST_REG_ADDR_BY_IDX(id,2),\
	},																		\
	.pclken = {																\
		.enr = DT_INST_CLOCKS_CELL(id, bits),								\
		.bus = DT_INST_CLOCKS_CELL(id, bus),								\
	},																\
};																	\
																	\
static struct fmc_stm32_data fmc_stm32_dev_data_##id = {			\
	.sramhandleen ={											\
		.Enable1 = DT_INST_PROP_BY_IDX(id, sram_handle_enable, 0), 		\
		.Enable2 = DT_INST_PROP_BY_IDX(id, sram_handle_enable, 1), 		\
		.Enable3 = DT_INST_PROP_BY_IDX(id, sram_handle_enable, 2),		\
		.Enable4 = DT_INST_PROP_BY_IDX(id, sram_handle_enable, 3),		\
	},																\
	.datawidth = DT_INST_PROP(id, data_width),				\
	.addresswidth = DT_INST_PROP(id, address_width),			\
	.asyncwaiten ={								\
		.Enable1 = DT_INST_PROP_BY_IDX(id, async_wait_enable, 0), 	\
		.Enable2 = DT_INST_PROP_BY_IDX(id, async_wait_enable, 1), 	\
		.Enable3 = DT_INST_PROP_BY_IDX(id, async_wait_enable, 2),	\
		.Enable4 = DT_INST_PROP_BY_IDX(id, async_wait_enable, 3),	\
	}, 																\
}; 																	\
																	\
DEVICE_AND_API_INIT(fmc_stm32_##id, DT_INST_LABEL(id),				\
		    &fmc_stm32_init,										\
		    &fmc_stm32_dev_data_##id, &fmc_stm32_cfg_##id,			\
		    POST_KERNEL, CONFIG_FMC_INIT_PRIORITY,					\
		    &fmc_stm32_driver_api);											\
																	\

#if CONFIG_FMC_0
STM32_FMC_INIT(0)
#endif /* CONFIG_FMC(0) */


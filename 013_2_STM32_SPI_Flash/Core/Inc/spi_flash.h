#ifndef _SPI_FLASH_H_
#define _SPI_FLASH_H_

#include "stm32f4xx_hal.h"

//
#define ON	1
#define OFF	0
#define USE_GETCHIPID			ON
#define USE_READ_STATUSREG		ON
#define USE_WRITE_STATUSREG		OFF
#define USE_WRITE_ENABLE		ON
#define USE_WRITE_DISABLE		OFF
#define USE_ERASE_CHIP			ON
#define USE_ERASE_SECTOR		ON
#define USE_ERASE_BLOCK			ON
#define USE_WAIT_BUSY			ON
#define USE_POWERDOWN			OFF
#define USE_RELEASEPOWERDOWN	OFF
#define USE_READ_BYTES			ON
#define USE_WRITE_BYTES			OFF
#define USE_READ_SECTOR			ON
#define USE_WRITE_SECTOR		ON


//Flash
#define FLASH_PAGE_SIZE			256
#define FLASH_SECTOR_SIZE		4096
#define FLASH_SECTOR_COUNT		512
#define FLASH_BLOCK_SIZE		65536
#define FLASH_PAGES_PER_SECTOR	FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE

/****************************************
	W25X16
****************************************/
#define W25X16_CHIPID				0xEF4015

#define W25X_WriteEnable			0x06
#define W25X_WriteDisable			0x04
#define W25X_ReadStatusReg			0x05
#define W25X_WriteStatusReg			0x01
#define W25X_ReadData				0x03
#define W25X_FastReadData			0x0B
#define W25X_FastReadDual			0x3B
#define W25X_PageProgram			0x02
#define W25X_BlockErase				0xD8
#define W25X_SectorErase			0x20
#define W25X_ChipErase				0xC7
#define W25X_SetPowerDown			0xB9
#define W25X_SetReleasePowerDown	0xAB
#define W25X_DeviceID				0xAB
#define W25X_ManufactDeviceID		0x90
#define W25X_JedecDeviceID			0x9F

//CS
#define FLASH_CS_0()			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
#define FLASH_CS_1()			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

//
#define W25X_Check()			((W25X_GetChipID() == W25X32_CHIPID) ? 1 : 0)

int32_t SPIFLASH_disk_initialize(void);
void	SPI1_Init(void);
uint8_t SPI_Read_Byte(void);
uint8_t SPI_Write_Byte(uint8_t data);

#if USE_GETCHIPID
	int	W25X_GetChipID(void);
#endif

#if USE_READ_STATUSREG
char		W25X_Read_StatusReg(void);
#endif

#if USE_WRITE_STATUSREG
void	W25X_Write_StatusReg(u8 reg);
#endif

#if USE_WRITE_ENABLE
void	W25X_Write_Enable(void);
#endif

#if USE_WRITE_DISABLE
void	W25X_Write_Disable(void);
#endif

#if USE_ERASE_CHIP
void	W25X_Erase_Chip(void);
#endif

#if USE_ERASE_SECTOR
void	W25X_Erase_Sector(uint32_t nDest);
#endif

#if USE_ERASE_BLOCK
void	W25X_Erase_Block(uint32_t nDest);
#endif

#if USE_WAIT_BUSY
void	W25X_Wait_Busy(void);
#endif

#if USE_POWERDOWN
void	W25X_PowerDown(void);
#endif

#if USE_RELEASEPOWERDOWN
void	W25X_ReleasePowerDown(void);
#endif

#if USE_READ_BYTES
void	W25X_Read_Bytes(uint32_t nDest, char* pBuffer, char nBytes);
#endif

#if USE_WRITE_BYTES
void	W25X_Write_Bytes(uint32_t nDest,char* pBuffer, u8 nBytes);
#endif

#if USE_READ_SECTOR
void	W25X_Read_Sector(uint32_t nSector, char* pBuffer);
#endif

#if USE_WRITE_SECTOR
void	W25X_Write_Sector(uint32_t nSector, char* pBuffer);
#endif

#endif


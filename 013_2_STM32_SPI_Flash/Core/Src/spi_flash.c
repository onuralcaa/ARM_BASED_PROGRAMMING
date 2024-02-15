#include "stm32f4xx_hal.h"
#include "spi_flash.h"

extern SPI_HandleTypeDef hspi1;

int32_t SPIFLASH_disk_initialize(void)
{
	int ret;

	ret = W25X_GetChipID();
	if(ret!=W25X16_CHIPID)
		return 1;

	return 0;
}

uint8_t SPI_Read_Byte(void)
{
	return (SPI_Write_Byte(0xFF));
}

uint8_t SPI_Write_Byte(uint8_t data)
{
	char read_data;

	HAL_SPI_TransmitReceive(&hspi1, &data, &read_data, 1, 1);
	return read_data;
}

#if USE_GETCHIPID
int W25X_GetChipID(void)
{
	int nID = 0;
	
	FLASH_CS_0();

	SPI_Write_Byte(W25X_JedecDeviceID);
	nID = SPI_Read_Byte();
	nID <<= 8;
	nID |= SPI_Read_Byte();
	nID <<= 8;
	nID |= SPI_Read_Byte();
	
	FLASH_CS_1();

	return nID;
}
#endif

#if USE_READ_STATUSREG
char W25X_Read_StatusReg(void)
{	char u8 = 0;
	FLASH_CS_0();
	SPI_Write_Byte(W25X_ReadStatusReg);
	u8 = SPI_Read_Byte();
	FLASH_CS_1();	
	return u8;
}
#endif

#if USE_WRITE_STATUSREG
void W25X_Write_StatusReg(u8 reg)
{	FLASH_CS_0();
	SPI_Write_Byte(W25X_WriteStatusReg);
	SPI_Write_Byte(reg);
	FLASH_CS_1();
}
#endif

#if USE_WRITE_ENABLE
void W25X_Write_Enable(void)
{	FLASH_CS_0();
	SPI_Write_Byte(W25X_WriteEnable);
	FLASH_CS_1();
}
#endif

#if USE_WRITE_DISABLE
void W25X_Write_Disable(void)
{	FLASH_CS_0();
	SPI_Write_Byte(W25X_WriteDisable);
	FLASH_CS_1();
}
#endif

#if USE_WAIT_BUSY
void W25X_Wait_Busy(void)
{	while(W25X_Read_StatusReg() == 0x03)
		W25X_Read_StatusReg();
}
#endif

#if USE_ERASE_SECTOR
void W25X_Erase_Sector(uint32_t nDest)
{
	nDest *= FLASH_SECTOR_SIZE;
	
	FLASH_CS_0();			
	W25X_Write_Enable();
	FLASH_CS_0();
	SPI_Write_Byte(W25X_SectorErase);
	SPI_Write_Byte((char)((nDest & 0xFFFFFF) >> 16));
	SPI_Write_Byte((char)((nDest & 0xFFFF) >> 8));
	SPI_Write_Byte((char)nDest & 0xFF);
	FLASH_CS_1();
	W25X_Wait_Busy();
}
#endif

#if USE_ERASE_BLOCK
void W25X_Erase_Block(uint32_t nDest)
{
	nDest *= FLASH_BLOCK_SIZE;
	
	FLASH_CS_0();			
	W25X_Write_Enable();
	FLASH_CS_0();
	SPI_Write_Byte(W25X_SectorErase);
	SPI_Write_Byte((char)((nDest & 0xFFFFFF) >> 16));
	SPI_Write_Byte((char)((nDest & 0xFFFF) >> 8));
	SPI_Write_Byte((char)nDest & 0xFF);
	FLASH_CS_1();
	W25X_Wait_Busy();
}
#endif

#if USE_ERASE_CHIP
void W25X_Erase_Chip(void)
{
	FLASH_CS_0();
	W25X_Write_Enable();
	FLASH_CS_0();
	W25X_Wait_Busy();
	FLASH_CS_0();
	SPI_Write_Byte(W25X_ChipErase);
	FLASH_CS_1();
	W25X_Wait_Busy();
}
#endif

#if USE_READ_BYTES
void W25X_Read_Bytes(uint32_t nDest, char* pBuffer, char nBytes)
{	uint16_t i;
	
	FLASH_CS_0();
	SPI_Write_Byte(W25X_ReadData);
	SPI_Write_Byte((char)(nDest >> 16));
	SPI_Write_Byte((char)(nDest >> 8));
	SPI_Write_Byte((char)nDest);
	for(i=0;i<nBytes;i++)
	{	pBuffer[i] = SPI_Read_Byte();
	}
	
	FLASH_CS_1();
	W25X_Wait_Busy();
}
#endif

#if USE_READ_SECTOR
void W25X_Read_Sector(uint32_t nSector, char* pBuffer)
{	uint16_t i;

	nSector *= FLASH_SECTOR_SIZE;
	
	FLASH_CS_0();
	SPI_Write_Byte(W25X_ReadData);
	SPI_Write_Byte((char)(nSector >> 16));
	SPI_Write_Byte((char)(nSector>> 8));
	SPI_Write_Byte((char) nSector);
	
	for(i=0;i<FLASH_SECTOR_SIZE;i++)
	{	pBuffer[i] = SPI_Read_Byte();
	}
	FLASH_CS_1();
	W25X_Wait_Busy();
}
#endif

#if USE_WRITE_BYTES
void W25X_Write_Bytes(uint32_t nSector,char* pBuffer, u8 nBytes)
{
	int i;
	
	FLASH_CS_0();
	W25X_Write_Enable();
	FLASH_CS_0();
				
	SPI_Write_Byte(W25X_PageProgram);
	SPI_Write_Byte((u8)(nSector >> 16));
	SPI_Write_Byte((u8)(nSector >> 8));
	SPI_Write_Byte((u8) nSector);
	for(i=0;i<nBytes;i++)
	{	SPI_Write_Byte(pBuffer[i]);
	}
	FLASH_CS_1();
	W25X_Wait_Busy();
}
#endif

#if USE_WRITE_SECTOR
void W25X_Write_Sector(uint32_t nSector, char* pBuffer)
{	
	int i,j;

	nSector *= FLASH_SECTOR_SIZE;
	
	for(j=0;j<FLASH_PAGES_PER_SECTOR;j++)
	{
		FLASH_CS_0();
		W25X_Write_Enable();
		FLASH_CS_0();
		
		SPI_Write_Byte(W25X_PageProgram);
		SPI_Write_Byte((char)(nSector >> 16));
		SPI_Write_Byte((char)(nSector >> 8));
		SPI_Write_Byte((char) nSector);
		
		for(i=0;i<FLASH_PAGE_SIZE;i++)								
			SPI_Write_Byte(pBuffer[i]);
		
		pBuffer += FLASH_PAGE_SIZE;
		nSector += FLASH_PAGE_SIZE;

		FLASH_CS_1();
		W25X_Wait_Busy();
	}
}
#endif

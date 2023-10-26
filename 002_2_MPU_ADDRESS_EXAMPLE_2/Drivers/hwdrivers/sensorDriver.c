/*
 * sensorDriver.c
 *
 *  Created on: 26 Eki 2023
 *      Author: onura
 */

#include "stm32f4xx_hal.h"
#include "sensorDriver.h"

extern I2C_HandleTypeDef hi2c1;


sensor_status_e sensor_test_device(uint8_t chipAdd )
{
	HAL_StatusTypeDef status;

	status = HAL_I2C_IsDeviceReady(&hi2c1, chipAdd, 4, 100);

	if(HAL_OK == status)
	{
		return SENSOR_OK;
	}
	else
	{
		return SENSOR_ERROR;
	}

}


uint8_t sensor_read_register8(uint8_t chipAdd, uint8_t regAdd)
{
	uint8_t data;
	HAL_StatusTypeDef status;
	status = HAL_I2C_Mem_Read(&hi2c1, chipAdd, regAdd, 1, &data, 1, 100);

	if(HAL_OK != status)
	{
			return 0;
	}
	else
	{
		return data;
	}

}


uint16_t sensor_read_register16(uint8_t chipAdd, uint8_t regAdd)
{
	uint8_t data[2];
	uint16_t retVal;
	HAL_StatusTypeDef status;

		status = HAL_I2C_Mem_Read(&hi2c1, chipAdd, regAdd, 1, data, 2, 100);

		if(HAL_OK != status)
		{
				return 0;
		}
		else
		{
			retVal = (data[1]<<8) | data[0];
			return retVal;
		}

}


sensor_status_e sensor_write_register8(uint8_t chipAdd, uint8_t regAdd, uint8_t value)
{
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Write(&hi2c1, chipAdd, regAdd, 1, &value, 1, 100);

	if(HAL_OK != status)
		{
			return HAL_ERROR;
		}
		else
		{
			return HAL_OK;
		}


}


sensor_status_e sensor_write_register16(uint8_t chipAdd, uint8_t regAdd, uint16_t value)
{
	uint8_t data[2];
	data[0] = (uint8_t)(value | 0xFF);
	data[1] = (uint8_t)((value >> 8) | 0xFF);
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Write(&hi2c1, chipAdd, regAdd, 1, data, 1, 100);

	if(HAL_OK != status)
			{
				return HAL_ERROR;
			}
			else
			{
				return HAL_OK;
			}

}

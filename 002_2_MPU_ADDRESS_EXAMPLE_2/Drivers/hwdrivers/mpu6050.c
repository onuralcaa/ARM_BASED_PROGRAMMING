/*
 * MPU6050.c
 *
 *  Created on: 26 Eki 2023
 *      Author: onura
 */

#include "mpu6050.h"
#include "sensorDriver.h"

sensor_status_e MPU_6050_TestSensor()
{
	sensor_status_e retVal;

	retVal = sensor_test_device(MPU_6050_I2C_ADDRESS_AD1);

	return retVal;

}

uint8_t MPU6050_ReadID()
{
	uint8_t id = 0;

	id = sensor_read_register8(MPU_6050_I2C_ADDRESS_AD1, MPU_REG_WHO_AM_I);

	return id;




}







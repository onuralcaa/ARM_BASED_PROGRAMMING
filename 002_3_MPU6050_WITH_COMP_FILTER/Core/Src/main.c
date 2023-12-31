/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MPU6050_ADDR 0x68<<1
#define PWR_MGMT_1_REG 0x6B
#define SMPLRT_DIV_REG 0x19
#define GYRO_CNFG_REG 0x1B
#define ACC_CNFG_REG 0x1C
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */
uint8_t data;
uint8_t Temp_buffer[2], Acc_buffer[6], Gyro_buffer[6]; //raw data list
int16_t gyro_raw[3], acc_raw[3]; // processed data list
float gyro_cal[3]; // calibration offsets
int16_t acc_total_vector;
float angle_pitch_gyro, angle_roll_gyro;
float angle_pitch_acc, angle_roll_acc;
float angle_pitch, angle_roll;
int16_t raw_temp;
float temp;
int i;
float pTime, pTime1, time1, elapsedtime1, pTime2, time2, elapsedtime2;
HAL_StatusTypeDef setgyro;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  data = 0x00;
  HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &data, 1, HAL_MAX_DELAY);

  //GYRO_CONFIG => +-500 DERECE/SANIYE -----> 08
  data = 0x08;
  HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, GYRO_CNFG_REG, 1, &data, 1, HAL_MAX_DELAY);


  //ACC_CONFIG => +-8G ------> 10
  data = 0x10;
  HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, ACC_CNFG_REG, 1, &data, 1, HAL_MAX_DELAY);

  for(i=0 ; i<2000 ; i++)
  {
	  pTime2 = time2;
	  time2 = HAL_GetTick();
	  elapsedtime2 = (time2 - pTime2) * 1000;

	  Gyro_buffer[0] = 0x43;
	  HAL_I2C_Master_Transmit(&hi2c1, MPU6050_ADDR, Gyro_buffer, 1, HAL_MAX_DELAY);
	  HAL_I2C_Master_Receive(&hi2c1, MPU6050_ADDR, Gyro_buffer, 6, HAL_MAX_DELAY);

	  gyro_raw[0] = (Gyro_buffer[0] << 8 | Gyro_buffer[1]); //X ekseni
	  gyro_raw[1] = (Gyro_buffer[2] << 8 | Gyro_buffer[3]); //Y ekseni
	  gyro_raw[2] = (Gyro_buffer[4] << 8 | Gyro_buffer[5]); //Z ekseni

	  gyro_cal[0] += gyro_raw[0];
	  gyro_cal[1] += gyro_raw[1];
	  gyro_cal[2] += gyro_raw[2];

	  HAL_Delay(3); // 4 ms
  }

  gyro_cal[0] /= 2000;
  gyro_cal[1] /= 2000;
  gyro_cal[2] /= 2000;

  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
  HAL_Delay(1000);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  pTime1 = time1;
	  time1 = HAL_GetTick();
	  elapsedtime1 = (time1 - pTime1)*1000;

	  Acc_buffer[0] = 0x3B;
	  HAL_I2C_Master_Transmit(&hi2c1, MPU6050_ADDR, Acc_buffer, 1, HAL_MAX_DELAY);
	  HAL_I2C_Master_Receive(&hi2c1, MPU6050_ADDR, Acc_buffer, 6, HAL_MAX_DELAY);

	  //Acc raw values
	  acc_raw[0] = (Acc_buffer[0] << 8 | Acc_buffer[1]);
	  acc_raw[1] = (Acc_buffer[2] << 8 | Acc_buffer[3]);
	  acc_raw[2] = (Acc_buffer[4] << 8 | Acc_buffer[5]);

	  Temp_buffer[0] = 0x41;
	  HAL_I2C_Master_Transmit(&hi2c1, MPU6050_ADDR, Temp_buffer, 1, HAL_MAX_DELAY);
	  HAL_I2C_Master_Receive(&hi2c1, MPU6050_ADDR, Temp_buffer, 2, HAL_MAX_DELAY);

	  raw_temp = (Temp_buffer[0] << 8 | Temp_buffer[1]);
	  temp = (temp / 340.0) + 36.53;

	  Gyro_buffer[0] = 0x43;
	  HAL_I2C_Master_Transmit(&hi2c1, MPU6050_ADDR, Gyro_buffer, 1, HAL_MAX_DELAY);
	  HAL_I2C_Master_Receive(&hi2c1, MPU6050_ADDR, Gyro_buffer, 6, HAL_MAX_DELAY);

	  //Gyro raw values
	  gyro_raw[0] = (Gyro_buffer[0] << 8 | Gyro_buffer[1]);
	  gyro_raw[1] = (Gyro_buffer[2] << 8 | Gyro_buffer[3]);
	  gyro_raw[2] = (Gyro_buffer[4] << 8 | Gyro_buffer[5]);

	  gyro_raw[0] -= gyro_cal[0];
	  gyro_raw[1] -= gyro_cal[1];
	  gyro_raw[2] -= gyro_cal[2];

	  angle_pitch_gyro += gyro_raw[0] * 0.0000611;
	  angle_roll_gyro += gyro_raw[1] * 0.0000611;

	  angle_pitch_gyro += angle_roll_gyro * sin(gyro_raw[2] * 0.000001066);
	  angle_roll_gyro -= angle_pitch_gyro * sin(gyro_raw[2] * 0.000001066);

	  acc_total_vector = sqrt((acc_raw[0]*acc_raw[0]) + (acc_raw[1]*acc_raw[1]) + (acc_raw[2]*acc_raw[2]));

	  //57.296 = 1 / (3.142 / 180) //derece/saniye hesabi
	  angle_pitch_acc = asin((float)acc_raw[1]/acc_total_vector) * 57.296;
	  angle_roll_acc = asin((float)acc_raw[0]/acc_total_vector) * -57.296;

	  //calibration offsets
	  angle_pitch_acc -= 0.00;
	  angle_roll_acc -= 0.00;


	  if(setgyro)
	  {
		  angle_pitch = angle_pitch_gyro * 0.9996 + angle_pitch_acc * 0.0004;
		  angle_roll = angle_roll_gyro * 0.9996 + angle_roll_acc * 0.0004;
	  }
	  else
	  {
		  angle_pitch = angle_pitch_acc;
		  setgyro = true;
	  }

	  while((HAL_GetTick() - pTime) * 1000 < 4000);
	  pTime = HAL_GetTick();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin : PD12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

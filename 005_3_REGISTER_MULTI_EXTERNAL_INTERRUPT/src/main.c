#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

CLK_Config()
{
		//KONTROL REGISTER AYARLARI(CR - CONTROL REGISTER)
		RCC->CR |= 0x00030000;            // HSEON and HSEONRDY enable
		while(!(RCC->CR & 0x00020000));   // HSEOAN Ready Flag wait
	    RCC->CR |= 0x00080000;            //CSS enable

	    //PLL AYARLARI(PLL CONFIGURATION)
	    RCC->PLLCFGR |= 0x00400000;       //PLL E HSE secildi
	    RCC->PLLCFGR |= 0x00000004;       //PLL_M = 4
	    RCC->PLLCFGR |= 0x00005A00;       //PLL_N = 168
	    RCC->PLLCFGR |= 0x00000000;       //PLL_P = 2


	    RCC->CFGR |= 0x00000000;          //AHB PRESCALER = 1
	    RCC->CFGR |= 0x00080000;          //APB2 PRESCALER = 2
	    RCC->CFGR |= 0x00001400;          //APB1 PRESCALER = 4


	    RCC->CIR  |= 0x00080000;          //HSERDY FLAG CLEAR/RESET
	    RCC->CIR  |= 0x08000000;          //CSS FLAG CLEAR/RESET
}

GPIO_Config()
{
	RCC->AHB1ENR = 0x00000009; //GPIOA AND GPIOD ACTÝVE

	GPIOD->MODER = 0x55000000;
	GPIOD->OTYPER = 0x00000000;
	GPIOD->OSPEEDR = 0xFF000000;
	GPIOD->PUPDR = 0x00000000;
}

EXTI_Config()
{
	RCC->APB2ENR = 0x00004000; //SYSCFG AKTÝVE
	SYSCFG->EXTICR[0] = 0x00000000;//A PART ACTIVE

	NVIC_EnableIRQ(EXTI0_IRQn); // INTERRUPT ACTIVE FOR EXTI0
	NVIC_EnableIRQ(EXTI1_IRQn); // INTERRUPT ACTÝVE FOR EXTI1
	NVIC_EnableIRQ(EXTI2_IRQn); // INTERRUPT AVTÝVE FOR EXTI2

	NVIC_SetPriority(EXTI0_IRQn, 0);//master button
	NVIC_SetPriority(EXTI1_IRQn, 1);//medium button
	NVIC_SetPriority(EXTI2_IRQn, 2);//most small efficiency



	EXTI->IMR = 0x00000007;//INTERRUPT SELECTED // EVENT NOT SELECTED
	EXTI->RTSR = 0x00000007;//RISING SELECTED //FALLING NOT SELECTED
}

void delay(uint32_t time)
{
	while(time--);
}

void EXTI0_IRQHandler()
{
	if(EXTI->PR & 0x00000001)
	{
		GPIOD->ODR = 0x00001000;
		delay(33600000);

		EXTI->PR = 0x00000001;
	}
}
void EXTI1_IRQHandler()
{
	if(EXTI->PR & 0x00000002)
	{
		GPIOD->ODR = 0x00002000;
		delay(33600000);

		EXTI->PR = 0x00000002;
	}
}
void EXTI2_IRQHandler()
{
	if(EXTI->PR & 0x00000004)
	{
		GPIOD->ODR = 0x00004000;
		delay(33600000);

		EXTI->PR = 0x00000004;
	}
}

int main()
{
	CLK_Config();
	GPIO_Config();
	EXTI_Config();

  while (1)
  {
	GPIOD->ODR = 0x0000F000;
  }
}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}

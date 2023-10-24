#include "stm32f0xx.h"

GPIO_Config(){

	RCC->CR |= 0x01010000;
	while(!(RCC->CR & 0x00020000));   // HSEON Ready Flag wait
	RCC->CR |= 0x00080000;   //CSS enable


	RCC->CFGR |= 0x06000000;       //PLL icin HSE seçildi.
	RCC->CFGR |= 0x00040000;       //PLL_N = 4
	RCC->CFGR |= 0x10000000;       //PLL_M = 168
	RCC->CFGR |= 0x0000000A;       //PLL seçildi.

	RCC->AHBENR |= 0x00020000;
	GPIOA->MODER |= 0x00000100;
	GPIOA->OTYPER |= 0x00000000;
	GPIOA->OSPEEDR |= 0x00000300;
	GPIOA->PUPDR |= 0x00000100;
}

void delay(uint32_t time)
 {
	 while(time--);
 }

int main(void)
{
	GPIO_Config();


  while (1)
  {
	  GPIOA->ODR = 0x00000000;
	  //delay(48000000);
	  //GPIOA->ODR = 0x00000000;
	  //delay(48000000);



  }
}

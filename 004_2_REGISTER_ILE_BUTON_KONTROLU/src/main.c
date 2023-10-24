#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int count=0;

void GPIO_Config()
{
	//KONTROL REGISTER AYARLARI(CR - CONTROL REGISTER)
		RCC->CR |= 0x00030000;            // HSEON and HSEONRDY enable
		while(!(RCC->CR & 0x00020000));   // HSEOAN Ready Flag wait
	    RCC->CR |= 0x00080000;            //CSS enable

	    //PLL AYARLARI(PLL CONFIGURATION)
	    RCC->PLLCFGR |= 0x00400000;       //PLL E HSE seçildi.
	    RCC->PLLCFGR |= 0x00000004;       //PLL_M = 4
	    RCC->PLLCFGR |= 0x00005A00;       //PLL_N = 168
	    RCC->PLLCFGR |= 0x00000000;       //PLL_P = 2


	    RCC->CFGR |= 0x00000000;          //AHB PRESCALER = 1
	    RCC->CFGR |= 0x00080000;          //APB2 PRESCALER = 2
	    RCC->CFGR |= 0x00001400;          //APB1 PRESCALER = 4


	    RCC->CIR  |= 0x00080000;          //HSERDY FLAG CLEAR/RESET
	    RCC->CIR  |= 0x08000000;          //CSS FLAG CLEAR/RESET


	    RCC->AHB1ENR = 0x00000009;//GPIOA VE GPIOD PORTUNU AKTÝF ETME

	    GPIOD->MODER = 0x55000000;//12,13,14,15 PÝNS DÝGÝTAL OUTPUT
	    GPIOD->OTYPER = 0x00000000;//12,13,14,15 PÝNS PUSH PULL
	    GPIOD->OSPEEDR = 0xFF000000;//12,13,14,15 PÝNS 100MHZ
	    GPIOD->PUPDR = 0x000000000;//12,13,14,15 PÝNS NO PULL

	    //GPIO PORTU DEFAULT OLARAK INPUT MODUNDADIR. MODER REGISTERI DEGERLERINI ALIYOR KI
	    //00:INPUT MODUDUR.


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
	  if(GPIOA->IDR & 0x00000001)
	  {
		  while(GPIOA->IDR & 0x00000001);
		  delay(168000);

		  count++;
	  }

	  if(count%2==0)
	  {
		  GPIOD->ODR = 0x00000000;
	  }
	  else
	  {
		GPIOD->ODR = 0x0000F000;
	  }
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

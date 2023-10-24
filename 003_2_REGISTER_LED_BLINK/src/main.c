#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_ayar()
{
	RCC->AHB1ENR = 0x00000008;//Clock hattý aktif edildi.

	GPIOD->MODER = 0x55000000;
	GPIOD->OTYPER = 0x00000000;
	GPIOD->OSPEEDR = 0xFF000000;
	GPIOD->PUPDR = 0x00000000;
}
void delay(uint32_t time)
 {
	 while(time--);
 }
int main(void)
{
	GPIO_ayar();

  while (1)
  {
	  GPIOD->ODR = 0x00001000;
	  delay(1500000);
	  GPIOD->ODR = 0x00002000;
	  delay(1500000);
	  GPIOD->ODR = 0x00004000;
	  delay(1500000);
	  GPIOD->ODR = 0x00008000;
	  delay(1500000);

  }
}
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){

  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){

  return -1;
}

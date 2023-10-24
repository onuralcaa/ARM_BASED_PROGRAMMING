#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int i=0;


void delay(uint32_t time)
{
	while(time--);
}

void RCC_Config()
{
		//KONTROL REGISTER AYARLARI(CR - CONTROL REGISTER)
		RCC->CR |= 0x00010000;            // HSEON enable
		while(!(RCC->CR & 0x00020000));   // HSEON Ready Flag wait
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
}

void DAC1_Config()
{
	RCC->APB1ENR |=0x00000001;
	RCC->APB1ENR |= 0x20000000; // APB1 port active
	DAC->CR |= 0x00000001; // DAC channel 1 active
	DAC->SWTRIGR |= 0x00000000;// DAC channel 1 software trigger disable
	DAC->DHR12R1 |= 0x00000000;// DAC cahnnel 1 12-bit right aligned data

}
/*
 * DAC1 PA4 pinine baðlý, DAC2 PA5 pinine baðlýdýr.Bu projede PA4 pinine led baðlanýp
 * DAC output u led yardýmýyla gözlemlenmiþtir.
 */
int main(void)
{
	RCC_Config();
	DAC_Config();

  while (1)
  {
	  for(i=0  ; i < 4096 ; i++ )
	  {
		  DAC->DHR12R1 = i;
		  delay(16800);
	  }


	  i=0;
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

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

uint8_t adc_value;

void RCC_CLK_Config()
{
	//KONTROL REGISTER AYARLARI(CR - CONTROL REGISTER)
	RCC->CR |= 0x00030000;            // HSEON and HSEONRDY enable
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

void GPIO_Config()
{
	//A portuna baðlý olan diðer baðlantýlara zarar vermemek için" YA DA EÞÝTTÝR "kullanýlacaktýr.
	RCC->AHB1ENR |= 0x00000001;//GPIOA Clock enable

	GPIOA->MODER |= 0x00000003;//Analog mode selected
	GPIOA->OTYPER |= 0x00000000;
	GPIOA->PUPDR |= 0x00000000;
	GPIOA->OSPEEDR |= 0x00000003;//PÝN0 100 MHz
}

ADC_Config()
{
	RCC->APB2ENR |= 0x00000100; //ADC Clock enable

	ADC1->CR1 |= 0x02000000;//Resolution 8 bit
	ADC1->CR2 |= 0x00000001;//ADC enable
	ADC1->SMPR2 |= 0x00000003;//56 cycle
	ADC->CCR |= 0x00010000;//Dive 4 selected
}

uint8_t Read_ADC()
{
	uint8_t value;

	ADC1->CR2 |= 0x40000000;

	while(!(ADC1->SR & 0x00000002));

	value = ADC1->DR;

	return value;
}

int main(void)
{
	RCC_CLK_Config();
	GPIO_Config();
	ADC_Config();

  while (1)
  {
	  adc_value = Read_ADC();
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

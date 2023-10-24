#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;
EXTI_InitTypeDef EXTI_InitStruct;
NVIC_InitTypeDef NVIC_InitStruct;

void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);//Veriler D portuna aktarýldý.

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA, &GPIO_InitStruct);//Veriler A portuna aktarýldý.

}

void delay(uint32_t time)
{
	while(time--);

}


void EXTI_Config()
{		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
		//NVIC iþlemciye dahil olduðu için Clock hatlarýna baðlý deðil.

		SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, GPIO_PinSource0);

		EXTI_InitStruct.EXTI_Line = EXTI_Line0;
		EXTI_InitStruct.EXTI_LineCmd = ENABLE;
		EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
		EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;

		EXTI_Init(&EXTI_InitStruct);//Interrupt ayarlarý aktarýldý.


		NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
		NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0xFF;
		NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0X00;

		NVIC_Init(&NVIC_InitStruct);//NVIC ayarlarý aktarýldý.
}
void EXTI_IRQHandler()
{
	if((EXTI_GetITStatus(EXTI_Line0)) != RESET)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_All);
		delay(1680000);

		EXTI_ClearITPendingBit(EXTI_Line0);
	}

}

int main(void)
{
	//BU KOD ISTENILEN SEKILDE KESME(INTERRUPT) ISLEMI YAPMADI.

  GPIO_Config();
  EXTI_Config();

  while (1)
  {

	  GPIO_SetBits(GPIOD, GPIO_Pin_All);
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

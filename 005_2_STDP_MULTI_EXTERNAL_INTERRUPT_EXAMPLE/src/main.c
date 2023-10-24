#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void delay(uint32_t time)
{
	while(time--);//Interrupt içeren çalýþmalarda delay fonksiyonu kullanýmý genelde tavsiye edilmez.
}

GPIO_InitTypeDef GPIO_InitStruct;
EXTI_InitTypeDef EXTI_InitStruct;
NVIC_InitTypeDef NVIC_InitStruct;

void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//A portu aktif edildi.
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//D portu aktif edildi.
	//--------------------------------------------------------------------------------------
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);//Ayarlar D portuna atandý.
	//--------------------------------------------------------------------------------------

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA, &GPIO_InitStruct);//Ayarlar A portuna atandý.
	//--------------------------------------------------------------------------------------
}

void EXTI_Config()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line1;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;

	EXTI_Init(&EXTI_InitStruct);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//Cortex iþlemcilerde multi interrupt iþlemi için
							   //ayrýlan 4 bitin nasýl kullanýlacaðýný belirleyen fonksiyon.
	//Birden fazla öncelik tanýmlamasý yapacaðýmýz zaman kullanýlýr.


	NVIC_InitStruct.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;

	NVIC_Init(&NVIC_InitStruct);


	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;

	NVIC_Init(&NVIC_InitStruct);

}

void EXTI_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_All);
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		delay(16800000);
		GPIO_SetBits(GPIOD, GPIO_Pin_13);
		delay(16800000);
		GPIO_SetBits(GPIOD, GPIO_Pin_14);
		delay(16800000);
		GPIO_SetBits(GPIOD, GPIO_Pin_15);
		delay(16800000);

		EXTI_ClearITPendingBit(EXTI_Line0);

	}
}

void EXTI2_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line1) != RESET)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_All);
			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			delay(16800000);
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			delay(16800000);
			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			delay(16800000);
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			delay(16800000);

			EXTI_ClearITPendingBit(EXTI_Line1);

		}
}

int main(void)
{
	GPIO_Config();
	EXTI_Config();

  while (1)
  {
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
  }
}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef  GPIO_InitStruct;

void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//GPIOA portunu aktif etme
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//GPIOD portunu aktif etme
	GPIO_InitStruct.GPIO_Mode = 0x00;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_OType = 0x00;
	GPIO_InitStruct.GPIO_PuPd = 0x02;
	GPIO_InitStruct.GPIO_Speed = 0x03;

	GPIO_Init(GPIOA, &GPIO_InitStruct);//Ayarlarýn A portuna yüklenmesini saðlar.

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);//Ayarlarýn D portuna yüklenmesini saðlar.

}

void delay(uint32_t time)//delay fonksiyonu.
{
	while(time--);
}

int main(void)
{
  GPIO_Config();
  int sayac=0;
  while (1)
  {
	 if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))//A portuna baðlý butondan veri okundu.
	 {
		 while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));
		 delay(1680000);//Arklara karþý bekleme önlemi alýnabilir.
		 sayac++;
		 switch(sayac)
		 {
		 case 1:
			 GPIO_SetBits(GPIOD, GPIO_Pin_12);
			 GPIO_ResetBits(GPIOD , GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

			 break;

		 case 2:
			 GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13);
			 GPIO_ResetBits(GPIOD , GPIO_Pin_14 | GPIO_Pin_15);
			 break;

		 case 3:
			 GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
			 GPIO_ResetBits(GPIOD, GPIO_Pin_15);
			 break;

		 case 4:
			 GPIO_SetBits(GPIOD , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			 break;

		 case 5:
			 GPIO_ResetBits(GPIOD , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			 break;

		 case 6:
				 GPIO_SetBits(GPIOD , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
				 delay(1680000);
				 GPIO_ResetBits(GPIOD , GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
				 delay(1680000);
			 break;
		 default:
			 sayac=0;
			 break;

		 }


		 //GPIO_ToggleBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
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

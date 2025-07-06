#include "stm32f10x.h"                  // Device header
#include "Servo.h"
#include "Delay.h"


void Sensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}

uint8_t GetLeftflag()
{
	uint8_t leftdata = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
	{
		Delay_ms(20);
		leftdata = !GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14);
	}
	return leftdata;
}

uint8_t GetRightflag()
{
	uint8_t rightdata = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
	{
		Delay_ms(20);
		rightdata = !GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15);
	}
	return rightdata;
}

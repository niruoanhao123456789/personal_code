#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"
#include "HCSR04.h"
#include "Timer.h"
#include "Sensor.h"
#include "PWM_LED.h"

uint8_t KeyNum;
uint16_t time;
uint16_t T;
uint8_t flag;
uint8_t lightflag = 1;
uint8_t sflag;
uint8_t turnflag;
uint8_t leftflag = 0;
uint8_t rightflag = 0;

int main(void)
{
	Sensor_Init();
//	OLED_Init();
	Key_Init();
	Servo_Init();
	HCSR04_Init();
	PWM_LED_Init();
	
//	OLED_ShowString(1, 1, "distance:");
//	OLED_ShowString(1, 13, "cm");
//	OLED_ShowString(1, 1, "leftflag:");
	
	while (1)
	{
		if(lightflag == 1)
		{
			LED_ON();
		}
		if(lightflag == 0)
		{
			LED_OFF();
		}
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			LED_OFF();
			Standup();
			flag = 1;
			sflag = 0;
			lightflag = 0;
		}
		KeyNum = Key_GetNum();
		if(KeyNum == 2)
		{
			sflag = 1;
		}
		KeyNum = Key_GetNum();
		if(KeyNum == 3)
		{
			LED_ON();
			Putdown();
			flag = 0;
			sflag = 0;
			lightflag = 1;
		}
		while(flag == 1 && sflag == 1)
		{
			KeyNum = Key_GetNum();
			if(KeyNum == 3)
			{
				LED_ON();
				Putdown();
				flag = 0;
				sflag = 0;
				lightflag = 1;
				break;
			}
			turnflag = 1;
			T = HCSR04_GetValue();
			Delay_ms(10);
			PWM_LED_SetCompare(100 - T);
			Delay_ms(10);
			if(T>25 && leftflag!=1 && rightflag!=1)
			{
				LED_OFF();
				Straight();
			}
			if(T<=25 && T>5)
			{
				Sitdown();
				turnflag = 0;
			}
			if(T<=5 && leftflag!=1 && rightflag!=1)
			{
				LED_ON();
				Backward();
			}
			if(turnflag == 1)
			{
				leftflag = GetLeftflag();
				if(leftflag==1)
				{
					Turnright();
				}
				rightflag = GetRightflag();
				if(rightflag==1)
				{
					Turnleft();
				}
			}
		}
	}
}

#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"

float Angle1;
float Angle2;
float Angle3;
float Angle4;

void Servo_Init(void)
{
	PWM_Init();									
}

void Servo_SetAngle2(float Angle)
{
	PWM_SetCompare2(Angle / 180 * 2000 + 500);
}

void Servo_SetAngle1(float Angle)
{
	PWM_SetCompare1(Angle / 180 * 2000 + 500);
}

void Servo_SetAngle3(float Angle)
{
	PWM_SetCompare3(Angle / 180 * 2000 + 500);
}

void Servo_SetAngle4(float Angle)
{
	PWM_SetCompare4(Angle / 180 * 2000 + 500);
}

void Servo_SetAngle(float Angle1,float Angle2,float Angle3,float Angle4)
{
	Servo_SetAngle1(Angle1);
	Servo_SetAngle2(Angle2);
	Servo_SetAngle3(Angle3);
	Servo_SetAngle4(Angle4);
	Delay_ms(150);
}

void Straight(void)
{
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 130;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 130;
	Angle2 = 50;
	Angle3 = 130;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 50;
	Angle3 = 130;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 130;
	Angle3 = 50;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 50;
	Angle2 = 130;
	Angle3 = 50;
	Angle4 = 130;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 50;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 130;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
}

void Backward(void)
{
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 50;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 130;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 50;
	Angle2 = 130;
	Angle3 = 50;
	Angle4 = 130;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 130;
	Angle3 = 50;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 50;
	Angle3 = 130;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 130;
	Angle2 = 50;
	Angle3 = 130;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 130;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
}

void Standup(void)
{
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
}

void Sitdown(void)
{
	Angle1 = 90;
	Angle2 = 150;
	Angle3 = 90;
	Angle4 = 30;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
}

void Putdown(void)
{
	Angle1 = 130;
	Angle2 = 50;
	Angle3 = 50;
	Angle4 = 130;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
}

void Turnright(void)
{
	Angle1 = 50;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 50;
	Angle2 = 130;
	Angle3 = 130;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 130;
	Angle3 = 130;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
}

void Turnleft(void)
{
	Angle1 = 90;
	Angle2 = 130;
	Angle3 = 130;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 50;
	Angle2 = 130;
	Angle3 = 130;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 50;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 50;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	
	Angle1 = 90;
	Angle2 = 90;
	Angle3 = 90;
	Angle4 = 90;
	Servo_SetAngle(Angle1,Angle2,Angle3,Angle4);
	

}

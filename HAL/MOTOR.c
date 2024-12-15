/*
 * MOTOR.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Egypt_Laptop
 */

#include"MOTOR.h"
#include"../MCAL/DIO.h"
#include"../StdTypes.h"
#include"../Utils.h"

void MOTOR_CW(void)
{
	DIO_WritePin(IN1_M1,HIGH);
	DIO_WritePin(IN2_M1,LOW);
	_delay_ms(300);
	DIO_WritePin(IN1_M2,HIGH);
		DIO_WritePin(IN2_M2,LOW);
		_delay_ms(300);

}
void MOTOR_CCW(void)
{
	DIO_WritePin(IN1_M1,LOW);
    DIO_WritePin(IN2_M1,HIGH);
		_delay_ms(300);
		DIO_WritePin(IN1_M2,LOW);
		    DIO_WritePin(IN2_M2,HIGH);
				_delay_ms(300);

}
void MOTOR_STOP(void)
{
	DIO_WritePin(IN1_M1,LOW);
		DIO_WritePin(IN2_M1,LOW);
		_delay_ms(300);
		DIO_WritePin(IN1_M2,LOW);
		DIO_WritePin(IN2_M2,LOW);
		_delay_ms(300);

}

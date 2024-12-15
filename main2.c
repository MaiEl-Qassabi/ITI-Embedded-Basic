/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Egypt_Laptop
 */
#include "avr/io.h"
#include<util/delay.h>
#include <stdio.h>
/*#include <stdlib.h>*/
//#include "Sty_Type.h"
#include"Utils.h"
#include "MCAL/DIO.h"
#include "HAL/LCD.h"
#include"HAL/Keypad.h"
#include"HAL/MOTOR.h"
#include"HAL/Stepper.h"
#include "avr/interrupt.h"
#include "MCAL/ADC.h"
#include "MCAL/WDT.h"
#include "MCAL/UART.h"
#include "MCAL/sensor.h"
void RUN (void);
void STOP (void);

void main ()
{
	DIO_Init();
	LCD_Init();
	UART_Init();

	//ADC_Init(VREF_VCC,ADC_SCALER_64);
	//sei();
	u8 temp=0,pastvalue=0;
	while (1)
	{
        temp=UART_Receive();

		if (temp !=pastvalue)
		{
		if (temp<60)
		{
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("TEMP value: ");
			LCD_SetCursor(0,13);
			LCD_WriteNumber(temp);
			LCD_SetCursor(1,1);
			LCD_WriteString("Normal Mode ");
			STOP();
		}
		else if (temp>=60 && temp<100)
		{
			LCD_Clear();
			LCD_WriteString("TEMP value: ");
			LCD_SetCursor(0,13);
			LCD_WriteNumber(temp);
		    LCD_SetCursor(1,1);
			LCD_WriteString("Fan on ");
			DIO_WritePin(PINB00,HIGH);
			DIO_WritePin(PINB01,LOW);

		}
		else if (temp>=100)
		{
			LCD_Clear();
			LCD_WriteString("TEMP value: ");
			LCD_SetCursor(0,13);
			LCD_WriteNumber(temp);
		 LCD_SetCursor(1,1);
			LCD_WriteString("7are2aaaaa ");
				RUN();
		}
	}

		pastvalue=temp;
	}



}

void RUN (void){
	DIO_WritePin(PINB00,HIGH);
	DIO_WritePin(PINB01,HIGH);
}
void STOP (void){
	DIO_WritePin(PINB00,LOW);
		DIO_WritePin(PINB01,LOW);
}

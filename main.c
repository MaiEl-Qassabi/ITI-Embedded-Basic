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
//void conver();
void flashing_leds();
void main ()
{
	DIO_Init();
	LCD_Init();
	UART_Init();

	ADC_Init(VREF_VCC,ADC_SCALER_64);
	//sei();
	u8 temp=0,pastvalue=0;
	while (1)
	{

		temp = Temp1_Read();

		UART_Send(temp);

		if (temp !=pastvalue)
		{
		if (temp<60)
		{
	 flashing_leds();
			 MOTOR_STOP();
		}
		else if (temp>=60 && temp<100)
		{
			DIO_WritePin(IN1_M1,HIGH);
				DIO_WritePin(IN2_M1,LOW);
				_delay_ms(300);
				DIO_WritePin(IN1_M2,LOW);
						DIO_WritePin(IN2_M2,LOW);
						_delay_ms(300);
		}
		else if (temp>=100)
		{
			MOTOR_CW();
		}
	}

		pastvalue=temp;
	}



}
void flashing_leds()
{
	PORTC=0xff;
	_delay_ms(100);
	PORTC=0x00;
	_delay_ms(100);
}
/*{
	DIO_Init();
	UART_Init();




	 while(1)
	 {
		 u8 receivedData = UART_Receive();
		     if (receivedData == '1') {
		     	DIO_TogglePin(PINB00);
		     } else if (receivedData == '2') {
		     	DIO_TogglePin(PINB01);
		     }

	 }


}*/

/*ISR(UART_RX_vect) {

    u8 receivedData = UDR;
    if (receivedData == '1') {
    	DIO_TogglePin(PINB00);
    } else if (receivedData == '2') {
    	DIO_TogglePin(PINB01);
    }
}*/

/*
ISR(WDT_vect) {

    if (!(READ_BIT(PORTD,4))) {

    	DIO_WritePin(PIND04 , HIGH) ;


    }
    while (1) {

       }
   }*/






/*
ISR(TIMR0_OVF_vect)
{
	static u16 c=0;
	c++;
	if (c=3906) // ovftime=((2^8)*8)/8MHZ=0.256ms >> COV =1000/0.256=3906.25
	{
		 DIO_TogglePin(PIND03);
		 c=0;
	}
}*/



	/*DIO_Init();
	LCD_Init();
	Keypad_Init();
  ADC_Init(VREF_VCC,ADC_SCALER_64);

	//LCD_Clear();
	LCD_SetCursor(0,0);
	LCD_WriteString("Voltage value");
	u16 num=0;*/

	//LCD_WriteNumber(-547);
	//char arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	/*sei();
	MCUCR=0x0B;
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);*/

/*
	    while (1) {
	    	num= ADC_ReadVolt(CH_0);

               _delay_ms(100); //1000
	    		LCD_SetCursor(1,0);
	    		LCD_WriteNumber(num);


}
}*/




	      /*	if (DIO_ReadPin (PIND02)==0)
	    	{
	    		//LCD_Clear();
	    		LCD_SetCursor(1,0);
	    		LCD_WriteString("CLOCKWISE.");
	    		 MOTOR_CW();
	    	}
	    	else if (DIO_ReadPin (PIND03)==0)
	    	{
	    		LCD_SetCursor(1,0);
	    		LCD_WriteString("CounterCW.");
	    			 MOTOR_CCW();
	    	}*/

/*ISR(INT0_vect)
{
   conver();
}
ISR(INT1_vect)
{
	DIO_TogglePin(PINC01);
}
void conver()
{
	int a=0b00100000;
		int b=0b00000001;
		for (int i=0;i<3;i++)
		{
			PORTC=a+b;
			_delay_ms(100);
			a=a>>1;
			b=b<<1;
		}
}*/



            /* u8 x=Keypad_Getkey();
	    	if (x !='A')
	    	{
	    		//LCD_WriteChar(x);
	    		//_delay_ms(500);

	    }*/

/*void step_motor(u16 steps, u8 direction, u16 delay_ms) {
    // Generate step pulses to move the stepper motor
    for (u16 i = 0; i < steps; i++) {
    	DIO_WritePin(DIO_Pin_type[i],HIGH); // Set step pin high
        _delay_ms(delay_ms);       // Delay for step pulse duration
        DIO_WritePin(DIO_Pin_type[i],LOW); // Set step pin low
        _delay_ms(delay_ms);       // Delay between steps
    }
}*/

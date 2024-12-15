/*
 * Stepper.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Egypt_Laptop
 */
#include "Stepper.h"
#include"../MCAL/DIO.h"
#include"../StdTypes.h"
#include"../Utils.h"
#include<util/delay.h>
#define DELAY 1000

u8 arr[4]={COIL1A,COIL2A,COIL1B,COIL2B};


void STEPPER_Bipolar_CW(void)
{
	/*for (u16 i = 0; i < 4; i++) {

	    	DIO_WritePin(arr[i],HIGH); // Set step pin high
	        _delay_ms(DELAY);       // Delay for step pulse duration
	        DIO_WritePin(arr[i],LOW); // Set step pin low
	        _delay_ms(DELAY);
	}*/
	DIO_WritePin(PINA00,HIGH);
		DIO_WritePin(PINA01,LOW);
		DIO_WritePin(PINA02,LOW);
		DIO_WritePin(PINA03,LOW);
		_delay_ms(DELAY);
		DIO_WritePin(PINA00,LOW);
		DIO_WritePin(PINA01,LOW);
		DIO_WritePin(PINA02,HIGH);
		DIO_WritePin(PINA03,LOW);
		_delay_ms(DELAY);
		DIO_WritePin(PINA00,LOW);
		DIO_WritePin(PINA01,HIGH);
		DIO_WritePin(PINA02,LOW);
		DIO_WritePin(PINA03,LOW);
		_delay_ms(DELAY);
		DIO_WritePin(PINA00,LOW);
		DIO_WritePin(PINA01,LOW);
		DIO_WritePin(PINA02,LOW);
		DIO_WritePin(PINA03,HIGH);
		_delay_ms(DELAY);
}
void STEPPER_Bipolar_CCW(void)
{
	/*for (u16 i = 3; i >= 0; i--) {
		    	DIO_WritePin(arr[i],HIGH); // Set step pin high
		        _delay_ms(delay_ms);       // Delay for step pulse duration
		        DIO_WritePin(arr[i],LOW); // Set step pin low
		        _delay_ms(delay_ms);}*/
	DIO_WritePin(COIL1A,HIGH);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2A,LOW);
		DIO_WritePin(COIL2B,LOW);
		_delay_ms(DELAY);
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2A,LOW);
		DIO_WritePin(COIL2B,HIGH);
		_delay_ms(DELAY);
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,HIGH);
		DIO_WritePin(COIL2A,LOW);
		DIO_WritePin(COIL2B,LOW);
		_delay_ms(DELAY);
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2A,HIGH);
		DIO_WritePin(COIL2B,LOW);
		_delay_ms(DELAY);

}
void STEPPER_UniPolar_CW(void)
{
	DIO_WritePin(PINA00,HIGH);
			DIO_WritePin(PIND01,HIGH);
			DIO_WritePin(PIND02,LOW);
			DIO_WritePin(PIND03,LOW);
			DIO_WritePin(PIND03,HIGH);
			_delay_ms(DELAY);
			DIO_WritePin(PIND00,LOW);
			DIO_WritePin(PIND01,LOW);
			DIO_WritePin(PIND02,HIGH);
			DIO_WritePin(PIND03,HIGH);
			_delay_ms(DELAY);
			DIO_WritePin(PIND00,LOW);
			DIO_WritePin(PIND01,HIGH);
			DIO_WritePin(PIND02,HIGH);
			DIO_WritePin(PIND03,LOW);
			_delay_ms(DELAY);
			DIO_WritePin(PIND00,HIGH);
			DIO_WritePin(PIND01,HIGH);
			DIO_WritePin(PIND02,LOW);
			DIO_WritePin(PIND03,LOW);
			_delay_ms(DELAY);

}
void STEPPER_UniPolar_CCW(void);

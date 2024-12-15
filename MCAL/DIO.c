/*
 * DIO.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Egypt_Laptop
 */

/*#include "avr/io.h"
#include<util/delay.h>
#include <stdio.h>
#include "../Sty_Typ.h"
#include"../Utils.h"*/
/*
 * DIO.c
 *
 *  Created on: Aug 8, 2023
 *      Author: NEW LAP
 */

#include <avr/io.h>
#include"../StdTypes.h"
#include"../Utils.h"
#include"DIO.h"

DIO_PinStatus_Type PinsStatusArray[TOTAL_PINS]={
	INFREE,    /* port A pin 0 */
	OUTPUT,    /* port A pin 1 */
	OUTPUT,    /* port A pin 2 */
	OUTPUT,    /* port A pin 3 */
	OUTPUT,    /* port A pin 4 */
	OUTPUT,    /* port A pin 5 */
	OUTPUT,    /* port A pin 6 */
	OUTPUT,    /* port A pin 7 */
	OUTPUT,    /* port B pin 0 */
	OUTPUT,    /* port B pin 1 */
	OUTPUT,    /* port B pin 2 */
	OUTPUT,    /* port B pin 3 */
	OUTPUT,    /* port B pin 4 */
	OUTPUT,    /* port B pin 5 */
	OUTPUT,    /* port B pin 6 */
	OUTPUT,    /* port B pin 7 */
	OUTPUT,    /* port C pin 0 */
	OUTPUT,    /* port C pin 1 */
	OUTPUT,    /* port C pin 2 */
	OUTPUT,    /* port C pin 3 */
	OUTPUT,    /* port C pin 4 */
	OUTPUT,    /* port C pin 5 */
	OUTPUT,    /* port C pin 6 */
	OUTPUT,    /* port C pin 7 */
	OUTPUT,    /* port D pin 0 */
	OUTPUT,    /* port D pin 1 */
	OUTPUT,    /* port D pin 2 */
	OUTPUT,    /* port D pin 3 */
	OUTPUT,    /* port D pin 4 */
	OUTPUT,    /* port D pin 5 */
	OUTPUT,    /* port D pin 6 */
	OUTPUT    /* port D pin 7 */

};

/*void DIO_PIN_Init(DIO_Port_Type port ,u8 pin_num ,DIO_PinStatus_Type status )
{

		switch(status)
		{
			case OUTPUT:

			switch(port)
			{
				case PA:
				SET_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;

				case PB:
				SET_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;

				case PC:
				SET_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;

				case PD:
				SET_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;

			case INFREE:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;

				case PB:
				CLR_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;

				case PC:
				CLR_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;

				case PD:
				CLR_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;

			case INPULL:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;

				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;

				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;

				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
			}
			break;
		}
}*/

void DIO_PIN_Init(DIO_Pin_type pin ,DIO_PinStatus_Type status)
{
	   DIO_Port_Type port=pin/8;
		u8 pin_num=pin%8;

		switch(status)
		{
			case OUTPUT:

			switch(port)
			{
				case PA:
				SET_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;

				case PB:
				SET_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;

				case PC:
				SET_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;

				case PD:
				SET_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;

			case INFREE:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;

				case PB:
				CLR_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;

				case PC:
				CLR_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;

				case PD:
				CLR_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;

			case INPULL:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;

				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;

				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;

				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
			}
			break;
		}
}




void DIO_WritePin(DIO_Pin_type pin  ,DIO_PinVoltage_Type volt  )
{
	    DIO_Port_Type port=pin/8;
		u8 pin_num=pin%8;
	if(volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}

	}
	if(volt==LOW)
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
		}

	}

}

DIO_PinVoltage_Type DIO_ReadPin(DIO_Pin_type pin )
{

	  DIO_Port_Type port=pin/8;
	  u8 pin_num=pin%8;
	  DIO_PinVoltage_Type volt=LOW;

		switch(port)
		{
			case PA:
			volt=(DIO_PinVoltage_Type)READ_BIT(PINA,pin_num);
			break;
			case PB:
			volt=(DIO_PinVoltage_Type)READ_BIT(PINB,pin_num);
			break;
			case PC:
			volt=(DIO_PinVoltage_Type)READ_BIT(PINC,pin_num);
			break;
			case PD:
			volt=(DIO_PinVoltage_Type)READ_BIT(PIND,pin_num);
			break;
		}

		return volt;
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port_Type port=pin/8;
	u8 pin_num=pin%8;

	switch(port)
	{
		case PA:
		TGL_BIT(PORTA,pin_num);
		break;
		case PB:
		TGL_BIT(PORTB,pin_num);
		break;
		case PC:
		TGL_BIT(PORTC,pin_num);
		break;
		case PD:
		TGL_BIT(PORTD,pin_num);
		break;
	}
}

void DIO_Init(void)
{

	DIO_Pin_type i;
	for(i=0;i<TOTAL_PINS;i++)
	{
		DIO_PIN_Init(i,PinsStatusArray[i]);
	}

}


void DIO_WritePort(DIO_Port_Type port,u8 data)
{
	switch(port)
	{
		case PA:
		PORTA=data;
		break;
		case PB:
		PORTB=data;
		break;
		case PC:
		PORTC=data;
		break;
		case PD:
		PORTD=data;
		break;
	}

}

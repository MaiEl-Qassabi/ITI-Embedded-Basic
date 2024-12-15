/*
 * DIO.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Egypt_Laptop
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

/*
 * DIO.h
 *
 *  Created on: Aug 8, 2023
 *      Author: NEW LAP
 */
#include "avr/io.h"
#include<util/delay.h>
#include <stdio.h>
#include"../StdTypes.h"
#include"../Utils.h"

typedef enum{

	PA,
	PB,
	PC,
	PD
}DIO_Port_Type;

typedef enum{

	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_Type;

typedef enum {

	LOW,
	HIGH
}DIO_PinVoltage_Type;


typedef enum {
	PINA00,
	PINA01,
	PINA02,
	PINA03,
	PINA04,
	PINA05,
	PINA06,
	PINA07,
	PINB00,
	PINB01,
	PINB02,
	PINB03,
	PINB04,
	PINB05,
	PINB06,
	PINB07,
	PINC00,
	PINC01,
	PINC02,
	PINC03,
	PINC04,
	PINC05,
	PINC06,
	PINC07,
	PIND00,
	PIND01,
	PIND02,
	PIND03,
	PIND04,
	PIND05,
	PIND06,
	PIND07,
	TOTAL_PINS
}DIO_Pin_type;





//void DIO_PIN_Init(DIO_Port_Type port ,u8 pin_num ,DIO_PinStatus_Type status );
void DIO_PIN_Init(DIO_Pin_type pin ,DIO_PinStatus_Type status );

//void DIO_WritePin(DIO_Port_Type port ,u8 pin_num ,DIO_PinVoltage_Type volt );
void DIO_WritePin(DIO_Pin_type pin  ,DIO_PinVoltage_Type volt );

//DIO_PinVoltage_Type DIO_ReadPin(DIO_Port_Type port ,u8 pin_num );
DIO_PinVoltage_Type DIO_ReadPin(DIO_Pin_type pin);

void DIO_TogglePin(DIO_Pin_type pin);

void DIO_Init(void);

//void DIO_WritePort(DIO_Port_Type port,u8 data);

#endif /* MCAL_DIO_H_ */



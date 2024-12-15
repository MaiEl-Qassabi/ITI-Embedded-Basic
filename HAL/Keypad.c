/*
 * Keypad.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Egypt_Laptop
 */

#define KEYPAD_PROG

#include"../StdTypes.h"
#include"../MCAL/DIO.h"
#include"Keypad.h"

void Keypad_Init(void)
{
	DIO_WritePin(FRIST_OUTPUT,HIGH);
	DIO_WritePin(FRIST_OUTPUT+1,HIGH);
	DIO_WritePin(FRIST_OUTPUT+2,HIGH);
	DIO_WritePin(FRIST_OUTPUT+3,HIGH);
}



u8 Keypad_Getkey(void)
{
	u8 r,c,key=NO_KEY;
   for(r=0;r<ROW;r++)
   {
	   DIO_WritePin(FRIST_OUTPUT+r,LOW);

	   for(c=0;c<COL;c++)
	   {
		   if(DIO_ReadPin(FRIST_INPUT+c)==LOW)
		   {
			   key=KeysArray[r][c];
			   while(DIO_ReadPin(FRIST_INPUT+c)==LOW);
		   }
	   }
	   DIO_WritePin(FRIST_OUTPUT+r,HIGH);
   }

   return key;

}

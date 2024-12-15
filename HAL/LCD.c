/*
 * LCD.c

 *
 *  Created on: Aug 13, 2023
 *      Author: NEW LAP
 */

#include"avr/io.h"
#include"avr/delay.h"
#include"../StdTypes.h"
#include"../Utils.h"
#include"../MCAL/DIO.h"
#include"LCD.h"

static void WriteInstruction(u8 ins)
{

	    DIO_WritePin(RS,LOW);
		DIO_WritePort(LCD_PORT,ins);
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);

}

static void WriteData(u8 data)
{
	    DIO_WritePin(RS,HIGH);
		DIO_WritePort(LCD_PORT,data);
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);
}

void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteInstruction(0x38);    //8bit mode 2line
	WriteInstruction(0x0e);    //cursor off >>0x0e 0x0f
	WriteInstruction(0x01);    //Display Clear
	_delay_ms(1);
	WriteInstruction(0x06);   //increase no shift

}

void LCD_WriteNumber(s32 num) //24578
{
	u8 str[16];
	u8 i=0;
	s8 j;
	if (num == 0) {
	        LCD_WriteChar('0');
	        return;
	    }

	    if (num < 0) {
	    	LCD_WriteChar('-');
	        num = -num;  // Convert to positive
	    }

	while(num>0)
	{
		str[i]=num%10+'0';   //8 7 5 4 2
		num=num/10;
		i++;               //i size str
	}

	for(j=i-1;j>=0;j--)   //0:255
	{
		LCD_WriteChar(str[j]);
	}
}

void LCD_Clear(void)
{
	WriteInstruction(0x01);
	_delay_ms(1);
}

void LCD_SetCursor(u8 line,u8 cell)
{
	if(line==0)
	{
		WriteInstruction(0x80+cell);
	}
	else if(line==1)
	{
		WriteInstruction(0x80+0x40+cell);
	}

}
void LCD_WriteString(u8 *text)
{
	//u8 text[16];
	for (int i = 0; text[i] != '\0'; i++) {
		LCD_WriteChar(text[i]);
	    }
}
void LCD_shift_text(u8 *ptr, u8 r, u8 c) {
    u8 address = 0;

    if (r == 0) {
        address = 0x00 + c;
    } else if (r == 1) {
        address = 0x40 + c;
    }

    WriteInstruction(0x80 | address);

    for (u8 i = 0; i < strlen(ptr); i++) {
    	LCD_WriteChar(ptr[i]);
    }
}


/*
 * UART.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Egypt_Laptop
 */

#include <avr/io.h>
#include"../StdTypes.h"
#include"../Utils.h"
#include"UART.h"

void UART_Init(void)
{
	// baud rate
	UBRRL=51;

	// NORMAL SPEED
	CLR_BIT(UCSRA,U2X);
	// frame data bit , parity , stop
	// 8 DATA , NO PARITY 1 STOP


	//enable
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);

}

void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}

u8 UART_Recieve(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}





u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

u8 UART_ReceivePerodic(u8*pdata)
{
	if (READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1 ;
	}
	return 0;

}

/* synch function */
void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);

	}
}

void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]=UART_Receive();
	for (;str[i]!=0x0d;)
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0;

}


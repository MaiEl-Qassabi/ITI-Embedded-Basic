/*
 * SPI.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Egypt_Laptop
 */
#include <avr/io.h>
#include"../StdTypes.h"
#include"../Utils.h"
#include"SPI.h"
void SPI_Init()
{
	// Set MOSI, SCK, and SS as output
	if (SPI_MODE == 'MASTER')
	{
		SET_BIT(SPCR , MSTR );
		SET_BIT(SPCR , SPR0);
	  CLR_BIT(SPCR , SPR1);
	CLR_BIT(SPSR , SPI2X);


	}
	else if (SPI_MODE == 'Slave')
	{
		CLR_BIT(SPCR , MSTR );
	}

		/* SPI Enable*/
		SET_BIT(SPCR , SPE);
}


u8 SendRecieved(u8 data){
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}
u8 SendRecievPerodic(u8 *pdata)
{
	if (!READ_BIT(SPSR,SPIF))
	{
		*pdata= SPDR;
		return 1;
	}
	return 0;
}
void SPI_InterruptEnable()
{
	SET_BIT(SPCR,SPIE);
}

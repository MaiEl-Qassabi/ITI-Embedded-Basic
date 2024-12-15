/*
 * SPI.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Egypt_Laptop
 */

#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_


#define MASTER 0
#define SLAVE 1

#define SPI_MODE MASTER

void SPI_Init(void);

u8 SendRecieved(u8 data);
u8 SendRecievPerodic(u8 *pdata);
void SPI_InterruptEnable(void);


#endif /* MCAL_SPI_H_ */

/*
 * ADC.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Egypt_Laptop
 */


/*
 * ADC.c
 *
 *  Created on: Aug 17, 2023
 *      Author: NEW LAP
 */

#include <avr/io.h>
#include"../StdTypes.h"
#include"../Utils.h"
#include"ADC.h"


static u8 ADC_flag=0;
void ADC_Init(ADC_VoltRef_type ref,ADC_Prescaler_type scaler)
{
	// prescaler

	ADCSRA=ADCSRA&0xF8;// 11111000
	scaler=scaler&0x07;// 00000111
	ADCSRA=ADCSRA|scaler;

	//READ ADJUSTED
	CLR_BIT(ADMUX,ADLAR);

	// vref

	switch(ref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		break;
		case VREF_VCC:
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	}

	/*ADC ENABLE*/
	SET_BIT(ADCSRA,ADEN);
}




u16 ADC_Read(ADC_Channel_type ch)
{
	u16 adc;
	/* select mux */
	 ADMUX=ADMUX&0xE0;  //11100000
	 ADMUX=ADMUX|ch;


	/* start conversion*/
	SET_BIT(ADCSRA,ADSC);

	/* wait to end */
	while(READ_BIT(ADCSRA,ADSC)); //Busy Wait
	/* get read */
	//adc=((u16)ADCH<<8|(u16)ADCL);
	//adc=ADCH<<2;
	adc=ADC;
	return adc;
}

void ADC_StartConversion(ADC_Channel_type ch)
{
	if(ADC_flag==0)
	{
		/* select mux */
		ADMUX=ADMUX&0xE0;  //11100000
		ADMUX=ADMUX|ch;


		/* start conversion*/
		SET_BIT(ADCSRA,ADSC);

		ADC_flag=1;
	}

}

u16 ADC_GetRead(void)
{
	u16 adc;
	/* wait to end */
	while(READ_BIT(ADCSRA,ADSC)); //Busy Wait
	/* get read */
	//adc=((u16)ADCH<<8|(u16)ADCL);
	//adc=ADCH<<2;
	adc=ADC;
	return adc;
}

u16 ADC_GetReadPeriodic(u16 *Pdata)
{
	if(!READ_BIT(ADCSRA,ADSC))
	{
		*Pdata=ADC;
		ADC_flag=0;
		return 1;
	}
	return 0;
}
u16 ADC_ReadVolt(ADC_Channel_type ch)
{
	u16 adc =ADC_Read(ch);
	u16 volt =(ADC_VREF *adc)/1024;
	return volt;
}

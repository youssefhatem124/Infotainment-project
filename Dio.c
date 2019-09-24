#include"STD_TYPES.h"
#include"Macros.h"
#include"Dio.h"
void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{

	if(PinNum < 8)
	{
		if(PinValue)
		{
			Set_Bit(PORTA,PinNum);
		}
		else
		{
			Clear_Bit(PORTA,PinNum);
		}
	}

	else if(PinNum > 7 && PinNum < 16)
	{
		if(PinValue)
		{
			Set_Bit(PORTB,(PinNum-8));
		}
		else
		{
			Clear_Bit(PORTB,(PinNum-8));
		}
	}

	else if(PinNum > 15 && PinNum < 24)
	{
		if(PinValue)
		{
			Set_Bit(PORTC,(PinNum-16));
		}
		else
		{
			Clear_Bit(PORTC,(PinNum-16));
		}
	}

	else if(PinNum > 23 && PinNum < 32)
	{
		if(PinValue)
		{
			Set_Bit(PORTD,(PinNum-24));
		}
		else
		{
			Clear_Bit(PORTD,(PinNum-24));
		}

	}
}


uint8 DIO_ReadPin(uint8 PinNum)
{
	if(PinNum < 8)
	{
		return Get_Bit(PINA,PinNum);
	}

	else if(PinNum > 7 && PinNum < 16)
	{
		return Get_Bit(PINB,(PinNum-8));
	}

	else if(PinNum > 15 && PinNum < 24)
	{
		return Get_Bit(PINC,(PinNum-16));
	}

	else if(PinNum > 23 && PinNum < 32)
	{
		return Get_Bit(PIND,(PinNum-32));
	}


}

void DIO_SetPinDirection(uint8 PinNum, uint8 PinDirection)
{

if(PinNum < 8)
{
	if(PinDirection)
	{
		Set_Bit(DDRA,PinNum);
	}
	else
	{
		Clear_Bit(DDRA,PinNum);
	}
}

else if(PinNum > 7 && PinNum < 16)
{
	if(PinDirection)
	{
		Set_Bit(DDRB,(PinNum)-8);
	}
	else
	{
		Clear_Bit(DDRB,(PinNum)-8);
	}
}

else if(PinNum > 15 && PinNum < 24)
{
	if(PinDirection)
	{
		Set_Bit(DDRC,(PinNum)-16);
	}
	else
	{
		Clear_Bit(DDRC,(PinNum)-16);
	}
}

else if(PinNum > 23 && PinNum < 32)
{
	if(PinDirection)
	{
		Set_Bit(DDRC,(PinNum)-16);
	}
	else
	{
		Clear_Bit(DDRC,(PinNum)-16);
	}
}


}




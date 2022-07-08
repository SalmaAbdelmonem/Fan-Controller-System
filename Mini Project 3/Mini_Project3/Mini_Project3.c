/******************************************************************************
 *
 * Date: 4/10/2021
 *
 * File Name: Mini Project 3
 *
 * Description: Fan Controller system
 *
 * Author: Salma AbdelMonem
 *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "pwm.h"
#include "dc_motor.h"

int main(void)
{
	uint8 temp = 0;

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {INTERNAL_2_56,F_CPU_8};

	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Config); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC-Motor driver */

	/* Display this string "Fan is  " only once on LCD at the first row */
	LCD_displayString("   FAN is     ");

	/* Move cursor to the beginning of second row */
	LCD_moveCursor(1,0);

	/* Display this string "Temp =   C" only once on LCD at the second row */
	LCD_displayString("   Temp =     C");

	while(1)
	{
		temp = LM35_getTemperature();

		if(temp < 30)
		{
			/* function sets direction & speed of motor according to sensed temperature*/
			DcMotor_Rotate(STOP,0);

			LCD_moveCursor(0,0x0A);

			/* Display state of motor */
			LCD_displayString( "OFF" );

			LCD_moveCursor(1,0x0A);

			/* Display sensed temperature */
			if(temp >= 100)
			{
				LCD_intgerToString( temp );
			}
			else
			{
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_intgerToString( temp );
				LCD_displayCharacter(' ');
			}
		}

		else if( (temp >= 30) && ( temp < 60) )
		{
			DcMotor_Rotate(CW,25);

			LCD_moveCursor(0,0x0A);
			LCD_displayString( "ON " );

			LCD_moveCursor(1,0x0A);

			if(temp >= 100)
			{
				LCD_intgerToString( temp );
			}
			else
			{
				LCD_intgerToString( temp );
				LCD_displayCharacter(' ');
			}
		}

		else if( (temp >= 60) && ( temp < 90) )
		{
			DcMotor_Rotate(CW,50);

			LCD_moveCursor(0,0x0A);
			LCD_displayString( "ON " );

			LCD_moveCursor(1,0x0A);

			if(temp >= 100)
			{
				LCD_intgerToString( temp );
			}
			else
			{
				LCD_intgerToString( temp );
				LCD_displayCharacter(' ');
			}
		}

		else if( (temp >= 90) && ( temp < 120) )
		{
			DcMotor_Rotate(CW,75);

			LCD_moveCursor(0,0x0A);
			LCD_displayString( "ON " );

			LCD_moveCursor(1,0x0A);

			if(temp >= 100)
			{
				LCD_intgerToString( temp );
			}
			else
			{
				LCD_intgerToString( temp );
				LCD_displayCharacter(' ');
			}
		}

		else if(temp >= 120)
		{
			DcMotor_Rotate(CW,100);

			LCD_moveCursor(0,0x0A);
			LCD_displayString( "ON " );

			LCD_moveCursor(1,0x0A);

			if(temp >= 100)
			{
				LCD_intgerToString( temp );
			}
			else
			{
				LCD_intgerToString( temp );
				LCD_displayCharacter(' ');
			}
		}
	}
}

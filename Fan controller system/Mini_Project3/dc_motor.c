/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the AVR DC_Motor driver
 *
 * Author: Salma AbdelMonem
 *
 *******************************************************************************/

#include"std_types.h"
#include "gpio.h"
#include "pwm.h"
#include "dc_motor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_Init(void)
{
	/* Configure the direction for 2 pins of motor as output pins */
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);

	/* Initialize motor to stop mode */
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}


void DcMotor_Rotate(uint8 state,uint8 speed)
{
	/* insert state of motor in the two first pins of PORT B*/
	GPIO_writePort(PORTB_ID, state);

	/*set speed of motor by using PWM of Timer 0*/
	PWM_Timer0_Start(speed);
}

/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the AVR DC_Motor driver
 *
 * Author: Salma AbdelMonem
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	STOP,CW,ACW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the DC Motor:
 * 1. Setup Port A Pin 0,1 directions as output by use the GPIO driver.
 * 2. Setup Port A Pin 0,1 to start with 0 by use the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Setup the DC Motor according to temperature:
 * 1. Set direction of rotation of motor.
 * 2. Set speed of motor.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */

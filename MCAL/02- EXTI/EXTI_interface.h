/*
 * EXTI_interface.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Kishk
 */

#ifndef MCAL_02__EXTI_EXTI_INTERFACE_H_
#define MCAL_02__EXTI_EXTI_INTERFACE_H_

#define EXTI_LINE0		0
#define EXTI_LINE1		1
#define EXTI_LINE2		2


#define EXTI_FALLING_EDGE	0
#define EXTI_RISING_EDGE	1
#define EXTI_LOW_LEVEL		2
#define EXTI_ON_CHANGE		3

void EXTI_voidInit( void );
void EXTI_voidEnable( u8 Copy_u8SenseMode , u8 Copy_u8Line);
void EXTI_voidDisable( u8 Copy_u8Line );
void EXTI_voidClearFlag( u8 Copy_u8Line );

void EXTI_voidCallBack( void (*Copy_pvoidCallBack) (void) , u8 Copy_u8EXTILine);


#endif /* MCAL_02__EXTI_EXTI_INTERFACE_H_ */

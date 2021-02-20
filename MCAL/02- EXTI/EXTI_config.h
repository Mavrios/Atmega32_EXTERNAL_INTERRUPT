/*
 * EXTI_config.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Kishk
 */

#ifndef MCAL_02__EXTI_EXTI_CONFIG_H_
#define MCAL_02__EXTI_EXTI_CONFIG_H_

/*
 * OPTIONS:-
 * Just Comment The Line To Diable Line Interrupt
 *
 */

#define EXTI_LINE0_ENABLE							//-> PD2
#define EXTI_LINE1_ENABLE							//-> PD3
#define EXTI_LINE2_ENABLE							//-> PB2


/*
 * OPTIONS:-
 * 		EXTI_FALLING_EDGE
 * 		EXTI_RISING_EDGE
 *		EXTI_LOW_LEVEL
 *		EXTI_ON_CHANGE
 */
#define EXTI_u8Line0_Mode			EXTI_RISING_EDGE
#define EXTI_u8Line1_Mode			EXTI_RISING_EDGE

/*
 * OPTIONS:-
 * 		EXTI_FALLING_EDGE
 * 		EXTI_RISING_EDGE
 */

#define EXTI_u8Line2_Mode			EXTI_RISING_EDGE




#endif /* MCAL_02__EXTI_EXTI_CONFIG_H_ */

/*
 * EXTI_private.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Kishk
 */

#ifndef MCAL_02__EXTI_EXTI_PRIVATE_H_
#define MCAL_02__EXTI_EXTI_PRIVATE_H_

#define NULL	0

/* EXTERNAL INTERRUPT 0 BITS*/
#define GICR_INT0_BIT	6
#define MCUCR_ISC00_BIT	0
#define MCUCR_ISC01_BIT	1
#define GIFR_INTF0_BIT	6

/* EXTERNAL INTERRUPT 1 BITS*/
#define GICR_INT1_BIT	7
#define MCUCR_ISC10_BIT	2
#define MCUCR_ISC11_BIT	3
#define GIFR_INTF1_BIT	7

/* EXTERNAL INTERRUPT 2 BITS*/
#define GICR_INT2_BIT	5
#define MCUCSR_ISC2_BIT	2
#define GIFR_INTF2_BIT	5



#define MCUCR_REG   *((volatile u8 *)0x55)
#define MCUCSR_REG  *((volatile u8 *)0x54)
#define GICR_REG    *((volatile u8 *)0x5B)
#define GIFR_REG    *((volatile u8 *)0x5A)

void (*EXTI_CallBack[3])(void) = {NULL};


void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));


#endif /* MCAL_02__EXTI_EXTI_PRIVATE_H_ */

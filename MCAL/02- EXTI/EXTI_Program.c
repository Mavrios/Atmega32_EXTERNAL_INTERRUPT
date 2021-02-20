/*
 * EXTI_Program.c
 *
 *  Created on: Feb 20, 2021
 *      Author: Kishk
 */
#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_voidInit(void) {

	/*EXTERNAL INTERRUPT 0*/
#ifdef EXTI_LINE0_ENABLE
	SET_BIT(GICR_REG, GICR_INT0_BIT);
#if EXTI_u8Line0_Mode == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
	CLR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
#elif EXTI_u8Line0_Mode == EXTI_ON_CHANGE
	SET_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
	CLR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
#elif EXTI_u8Line0_Mode == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
	SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
#elif EXTI_u8Line0_Mode == EXTI_RISING_EDGE
	SET_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
	SET_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
#endif
#endif

	/*EXTERNAL INTERRUPT 1*/
#ifdef EXTI_LINE1_ENABLE
	SET_BIT(GICR_REG,GICR_INT1_BIT);
#if EXTI_u8Line1_Mode == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
	CLR_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
#elif EXTI_u8Line1_Mode == EXTI_ON_CHANGE
	SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
	CLR_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
#elif EXTI_u8Line1_Mode == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
	SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
#elif EXTI_u8Line1_Mode == EXTI_RISING_EDGE
	SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
	SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
#endif
#endif

	/*EXTERNAL INTERRUPT 2*/
#ifdef EXTI_LINE2_ENABLE
	SET_BIT(GICR_REG,GICR_INT2_BIT);
#if EXTI_u8Line1_Mode == EXTI_FALLING_EDGE
	CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
#elif EXTI_u8Line1_Mode == EXTI_RISING_EDGE
	SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
#endif
#endif
}

void EXTI_voidEnable(u8 Copy_u8SenseMode, u8 Copy_u8Line) {

	switch (Copy_u8Line) {

	case EXTI_LINE0:
		SET_BIT(GICR_REG, GICR_INT0_BIT);
		switch (Copy_u8SenseMode) {
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
			break;
		case EXTI_RISING_EDGE:
			CLR_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
			break;
		}
		break;

	case EXTI_LINE1:
		SET_BIT(GICR_REG, GICR_INT1_BIT);
		switch (Copy_u8SenseMode) {
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
			break;
		case EXTI_RISING_EDGE:
			CLR_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
			break;
		}
		break;

	case EXTI_LINE2:
		SET_BIT(GICR_REG, GICR_INT2_BIT);
		switch (Copy_u8SenseMode) {
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR_REG, MCUCSR_ISC2_BIT);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR_REG, MCUCSR_ISC2_BIT);
			break;
		}
		break;
	}
}


void EXTI_voidDisable(u8 Copy_u8Line) {
	switch (Copy_u8Line) {
	case EXTI_LINE0:
		CLR_BIT(GICR_REG, GICR_INT0_BIT);
		break;
	case EXTI_LINE1:
		CLR_BIT(GICR_REG, GICR_INT1_BIT);
		break;
	case EXTI_LINE2:
		CLR_BIT(GICR_REG, GICR_INT2_BIT);
		break;
	}
}


void EXTI_voidClearFlag(u8 Copy_u8Line) {
	switch (Copy_u8Line) {
	case EXTI_LINE0:
		SET_BIT(GIFR_REG, GIFR_INTF0_BIT);
		break;
	case EXTI_LINE1:
		SET_BIT(GIFR_REG, GIFR_INTF1_BIT);
		break;
	case EXTI_LINE2:
		SET_BIT(GICR_REG, GICR_INT2_BIT);
		break;
	}
}

void EXTI_voidCallBack(void (*Copy_pvoidCallBack)(void), u8 Copy_u8EXTILine) {

	if (Copy_pvoidCallBack != NULL) {
		EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack;
	}
}

void __vector_1(void) {
	if (EXTI_CallBack[0] != NULL) {
		EXTI_CallBack[0]();
		EXTI_voidClearFlag(EXTI_LINE0);
	}
}

void __vector_2(void) {
	if (EXTI_CallBack[1] != NULL) {
		EXTI_CallBack[1]();
		EXTI_voidClearFlag(EXTI_LINE1);
	}
}

void __vector_3(void) {
	if (EXTI_CallBack[2] != NULL) {
		EXTI_CallBack[2]();
		EXTI_voidClearFlag(EXTI_LINE2);

	}
}

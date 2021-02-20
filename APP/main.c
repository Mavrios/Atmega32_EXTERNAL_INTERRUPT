/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"
#include "util/delay.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../MCAL/02- EXTI/EXTI_interface.h"
#include "../MCAL/03- GIE/GIE_interface.h"

void Interrupt_Toggle0LED(void);
void Interrupt_Toggle1LED(void);
void Interrupt_Toggle2LED(void);

int main(void) {
	DIO_enumSetPinDirection(DIO_PORTD_PIN2, DIO_INPUT);
	DIO_enumSetPinDirection(DIO_PORTD_PIN3, DIO_INPUT);
	DIO_enumSetPinDirection(DIO_PORTB_PIN2, DIO_INPUT);
	DIO_voidActivePullUp(DIO_PORTD_PIN2);
	DIO_voidActivePullUp(DIO_PORTD_PIN3);
	DIO_voidActivePullUp(DIO_PORTB_PIN2);
	DIO_enumSetPinDirection(DIO_PORTA_PIN0, DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC_PIN0, DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC_PIN1, DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTC_PIN2, DIO_OUTPUT);
	EXTI_voidInit();
	EXTI_voidCallBack(Interrupt_Toggle0LED , EXTI_LINE0);
	EXTI_voidCallBack(Interrupt_Toggle1LED , EXTI_LINE1);
	EXTI_voidCallBack(Interrupt_Toggle2LED , EXTI_LINE2);
	GIE_void_Enable();
	while (1) {
		DIO_enumTogglePinValue(DIO_PORTA_PIN0);
		_delay_ms(1000);
	}

}

void Interrupt_Toggle0LED(void) {
	_delay_ms(300);
	DIO_enumTogglePinValue(DIO_PORTC_PIN0);
}

void Interrupt_Toggle1LED(void) {
	_delay_ms(300);
	DIO_enumTogglePinValue(DIO_PORTC_PIN1);
}

void Interrupt_Toggle2LED(void) {
	_delay_ms(300);
	DIO_enumTogglePinValue(DIO_PORTC_PIN2);
}

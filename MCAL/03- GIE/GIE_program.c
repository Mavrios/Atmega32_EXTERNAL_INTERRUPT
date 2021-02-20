/*
 * GIE_program.c
 *
 *  Created on: Feb 20, 2021
 *      Author: Kishk
 */
#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"
#include "GIE_interface.h"
#include "GIE_private.h"



void GIE_void_Enable(void){
	SET_BIT(SREG_REG,GIE_BIT);
}

void GIE_void_Disable(void){
	CLR_BIT(SREG_REG,GIE_BIT);

}

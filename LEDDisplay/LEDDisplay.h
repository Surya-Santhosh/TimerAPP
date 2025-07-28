//****************************** LEDDisplay ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
//
// Summary : LED blink with delay of 840ms ON and 532ms OFF.
// Note    : None
// 
//****************************************************************************** 
#ifndef _LEDDISPLAY_H_
#define _LEDDISPLAY_H_

//******************************* Include Files ********************************
#include "common.h"

//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define DELAY_LED_ON        (840000)
#define DELAY_LED_OFF       (542000)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool LEDPrintStatus();

#ifdef ENABLE_LED_ON_RPI

bool LEDBlink(struct gpiod_line **pstline);

#endif

//*********************** Inline Method Implementations ************************ 

#endif 
// _LEDDISPLAY_H_ 
// EOF 
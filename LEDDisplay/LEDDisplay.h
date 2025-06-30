//******************************* AppTimer *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
//
// Summary : Display LED ON, LED OFF with a 1-second delay.
// Note    : None
// 
//****************************************************************************** 
#ifndef _LEDDISPLAY_H_
#define _LEDDISPLAY_H

//******************************* Include Files ********************************
#include <stdbool.h>
#include <stdio.h>
#include "common.h"

//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define LED_ON             (1)
#define LED_OFF            (0)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool LEDStatus(uint8 *pucLedStatus);

//*********************** Inline Method Implementations ************************ 

#endif 
// _APPTIMER_H_ 
// EOF 
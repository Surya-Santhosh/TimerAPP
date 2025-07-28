//****************************** GPIOControl ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
//
// Summary : Initialize GPIO chip and line, Set line as output.
// Note    : None
// 
//****************************************************************************** 
#ifndef _GPIOCONTROL_H_
#define _GPIOCONTROL_H_

//******************************* Include Files ********************************
#include "common.h"

//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define GPIO_LINE             (5)
#define LED_ON                (1)
#define LED_OFF               (0)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool GPIOControlSet(struct gpiod_chip **pstchip, 
                    struct gpiod_line **pstline);
bool GPIOControlRelease(struct gpiod_chip **pstchip, 
                        struct gpiod_line **pstline);

//*********************** Inline Method Implementations ************************ 

#endif 
// _GPIOCONTROL_H_ 
// EOF 
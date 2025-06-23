//******************************* AppTimer *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
//
// Summary : Display the system's current time in real time.
// Note    : None
// 
//****************************************************************************** 
#ifndef _APPTIMER_H_
#define _APPTIMER_H

//******************************* Include Files ********************************
#include <stdbool.h>
#include <stdio.h>
#include "common.h"

//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define SECONDS                    (60)
#define MINUTES                    (60)
#define HOURS                      (24)
#define DAYS                       (365)
#define MONTH_DAYS                 (30)
#define MONTH                      (12)
#define HALFYEAR_MONTH             (6)
#define HALFDAY_HOUR               (12)
#define UTC_YEAR                   (1970)
#define SECOND_MONTH               (1)
#define EVEN                       (2)
#define ONE                        (1)
#define ZERO                       (0)
#define LEAPYEAR_CHECK_FOUR        (4)
#define LEAPYEAR_CHECK_HUNDRED     (100)
#define TIME_DIFF_IST              (19800)
#define TIME_DIFF_PST              (25200)
#define THIRTYONE_DAYS             (31)
#define THIRTY_DAYS                (30)
#define TWENTYEIGHT_DAYS           (28)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool appTimer(uint32 ulEpoch);

//*********************** Inline Method Implementations ************************ 

#endif 
// _APPTIMER_H_ 
// EOF 
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
#define SECONDS                      (60)
#define MINUTES                      (60)
#define DAY_HOURS                    (24)
#define HALFDAY_HOUR                 (12)
#define TOTAL_DAYS_IN_YEAR           (365)
#define MONTH                        (12)
#define EIGHTH_MONTH                 (8)
#define UNIX_EPOCH_YEAR              (1970)
#define SECOND_MONTH                 (2)
#define EVEN_NUMBER                  (2)
#define MONTH_START                  (1)
#define LEAPYEAR_CHECK_4             (4)
#define LEAPYEAR_CHECK_100           (100)
#define LEAPYEAR_CHECK_400           (400)
#define TIME_DIFF_IST                (19800)
#define TIME_DIFF_PST                (25200)
#define THIRTYONE_DAYS               (31)
#define THIRTY_DAYS                  (30)
#define TWENTYEIGHT_DAYS             (28)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool AppTimer(uint32 ulEpoch);

//*********************** Inline Method Implementations ************************ 

#endif 
// _APPTIMER_H_ 
// EOF 
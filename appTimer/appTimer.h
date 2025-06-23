//******************************* TimerApp *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
//
// Summary : Display the system's current time in real time.
// Note    : None
// 
//****************************************************************************** 
#ifndef _APPTIMER_H_
#define _APPTIMER_H_

//******************************* Include Files ********************************
#include"../common.h"

//******************************* Global Types ********************************* 

//***************************** Global Constants ******************************* 
#define SECONDS            (60)
#define HOURS              (24)
#define DAYS               (365)
#define MONTH_DAYS         (30)
#define MONTH              (12)
#define UTC_YEAR           (1970)
#define ZERO               (0)
#define FOUR               (4)
#define HUNDRED            (100)
#define TWO                (2)
#define ONE                (1)
#define APRIL_DAYS         (29)
#define TIME_DIFF_IST      (19800)
#define TIME_DIFF_PST      (25200)
#define THOUSAND           (1000)
#define THIRTYONE_DAYS     (31)
#define THIRTY_DAYS        (30)
#define TWENTYEIGHT_DAYS   (28)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 

bool appTimerUTC(uint32 ulEpochUTC,uint32 ulEpoch);
bool appTimerIST(uint32 ulEpochIST);
bool appTimerPST(uint32 ulEpochPST);


//*********************** Inline Method Implementations ************************ 

#endif 
// _APPTIMER_H_ 
// EOF 
//******************************** TimerApp ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
//
// File    : appTimer.c
// Summary : Display date and time in UTC,IST,PST.
// Note    : appTimer.h - macros, functions, global variables are included.
// Note    : common.h - typdefs are included.
// Author  : Surya Santhosh
// Date    : 19/JUN/2024
//
//******************************************************************************
//******************************* Include Files ********************************
#include<stdio.h>
#include<stdbool.h>
#include"appTimer.h"
#include"../common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************
static uint8 ucFlag;
static uint32 ulYear;
static uint32 ulMonth;
static uint32 ulHour;
static uint32 ulMinute;
static uint32 ulSeconds;
static uint32 ulDay;
static uint16 unIndex;
static uint32 ulMonthName[MONTH] = {THIRTYONE_DAYS, TWENTYEIGHT_DAYS, 
    THIRTYONE_DAYS, THIRTY_DAYS, THIRTYONE_DAYS, THIRTY_DAYS, THIRTYONE_DAYS, 
    THIRTYONE_DAYS, THIRTY_DAYS, THIRTYONE_DAYS, THIRTY_DAYS, THIRTYONE_DAYS};

//****************************** Local Functions *******************************

//******************************.appTimerUTC.***********************************
// Purpose : Display date and time in UTC.
// Inputs  : ulEpochUTC - Seconds in UTS.
// Outputs : None
// Return  : true
// Notes   : None
//****************************************************************************** 
bool appTimerUTC(uint32 ululEpochUTC)
{
    if (ZERO == ululEpochUTC)
    {
        return false;
    }
    ucFlag = ZERO;
    ulYear = ululEpochUTC / (SECONDS * SECONDS * HOURS * DAYS);
    ululEpochUTC = ululEpochUTC - (ulYear * (SECONDS * SECONDS * HOURS * DAYS));
    ulYear = ulYear + UTC_YEAR;

    ulDay = ululEpochUTC / (SECONDS * SECONDS * HOURS);
    ululEpochUTC = ululEpochUTC - (ulDay * (SECONDS * SECONDS * HOURS));

    for (unIndex = UTC_YEAR; unIndex <= ulYear; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucFlag++;
        }
    }
    ulDay = ulDay - ucFlag;
    for (unIndex = ZERO; unIndex < MONTH; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ulMonthName[ONE] = APRIL_DAYS;
        }
        if (ulDay > ulMonthName[unIndex])
        {
            ulDay = ulDay - ulMonthName[unIndex];
        }
        else
        {
            ulMonth = unIndex + ONE;
            break;
        }
    }

    ulHour = ululEpochUTC / (SECONDS * SECONDS);
    ululEpochUTC = ululEpochUTC % (SECONDS * SECONDS);

    ulMinute = ululEpochUTC / (SECONDS);
    ululEpochUTC = ululEpochUTC % (SECONDS);

    ulSeconds = ululEpochUTC;

    printf("\n");
    printf("UTC (0:0)\n");
    printf("-----------------------\n");
    printf("Time  : %02ld:%02ld:%02ld ",ulHour,ulMinute,ulSeconds);
    if (MONTH <= ulHour)
    {
        printf("PM");
    }
    else
    {
        printf("AM");
    }

    printf("\nDate  : %02ld/%02ld/%02ld\n",ulDay,ulMonth,ulYear);
    printf("Epoch  : %d\n",ulEpoch);

    return true;
}

//*******************************.appTimerIST.**********************************
// Purpose : Display date and time in IST.
// Inputs  : ulEpochIST - Seconds in IST.
// Outputs : None
// Return  : true
// Notes   : None
//****************************************************************************** 
bool appTimerIST(uint32 ulEpochIST)
{
    if (ZERO == ulEpochPST)
    {
        return false;
    }
    ucFlag = ZERO;
    ulYear = ulEpochIST / (SECONDS * SECONDS * HOURS * DAYS);
    ulEpochIST = ulEpochIST - (ulYear * (SECONDS * SECONDS * HOURS * DAYS));
    ulYear = ulYear + UTC_YEAR;

    ulDay = ulEpochIST / (SECONDS * SECONDS * HOURS);
    ulEpochIST = ulEpochIST - (ulDay * (SECONDS * SECONDS * HOURS));

    for (unIndex = UTC_YEAR; unIndex <= ulYear; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucFlag++;
        }
    }
    ulDay = ulDay - ucFlag;
    for (unIndex = ZERO; unIndex < MONTH; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ulMonthName[ONE] = APRIL_DAYS;
        }
        if (ulDay > ulMonthName[unIndex])
        {
            ulDay = ulDay - ulMonthName[unIndex];
        }
        else
        {
            ulMonth = unIndex + ONE;
            break;
        }
    }
    
    ulEpochIST = ulEpochIST % (SECONDS * SECONDS * HOURS);

    ulHour = ulEpochIST / (SECONDS * SECONDS);
    ulEpochIST = ulEpochIST % (SECONDS * SECONDS);

    ulMinute = ulEpochIST / (SECONDS);
    ulEpochIST = ulEpochIST % (SECONDS);

    ulSeconds = ulEpochIST;

    printf("\n");
    printf("IST (5:30)\n");
    printf("-----------------------\n");
    printf("Time  : %02ld:%02ld:%02ld ",ulHour,ulMinute,ulSeconds);
    if (MONTH <= ulHour)
    {
        printf("PM");
    }
    else
    {
        printf("AM");
    }

    printf("\nDate  : %02ld/%02ld/%02ld\n",ulDay,ulMonth,ulYear);
    
    return true;
}

//*****************************.appTimerPST.************************************
// Purpose : Display date and time in PST.
// Inputs  : ulEpochPST - Seconds in PST
// Outputs : None
// Return  : true
// Notes   : None
//****************************************************************************** 
bool appTimerPST(uint32 ulEpochPST)
{
    if (ZERO == ulEpochPST)
    {
        return false;
    }
    ucFlag = ZERO;
    ulYear = ulEpochPST / (SECONDS * SECONDS * HOURS * DAYS);
    ulEpochPST = ulEpochPST - (ulYear * (SECONDS * SECONDS * HOURS * DAYS));
    ulYear = ulYear + UTC_YEAR;

    ulDay = ulEpochPST / (SECONDS * SECONDS * HOURS);
    ulEpochPST = ulEpochPST - (ulDay * (SECONDS * SECONDS * HOURS));

    for (unIndex = UTC_YEAR; unIndex <= ulYear; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucFlag++;
        }
    }

    ulDay = ulDay - ucFlag;
    for (unIndex = ZERO; unIndex < MONTH; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ulMonthName[ONE] = APRIL_DAYS;
        }
        if (ulDay > ulMonthName[unIndex])
        {
            ulDay = ulDay - ulMonthName[unIndex];
        }
        else
        {
            ulMonth = unIndex + ONE;
            break;
        }
    }

    ulEpochPST = ulEpochPST % (SECONDS * SECONDS * HOURS);

    ulHour = ulEpochPST / (SECONDS * SECONDS);
    ulEpochPST = ulEpochPST % (SECONDS * SECONDS);

    ulMinute = ulEpochPST / (SECONDS);
    ulEpochPST = ulEpochPST % (SECONDS);

    ulSeconds = ulEpochPST;

    printf("\n");
    printf("PST (7:00)\n");
    printf("-----------------------\n");
    printf("Time  : %02ld:%02ld:%02ld ",ulHour,ulMinute,ulSeconds);
    if (MONTH <= ulHour)
    {
        printf("PM");
    }
    else
    {
        printf("AM");
    }

    printf("\nDate  : %02ld/%02ld/%02ld\n",ulDay,ulMonth,ulYear);
    
    return true;
}
// EOF
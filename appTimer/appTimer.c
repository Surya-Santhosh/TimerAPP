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
static uint32 cYear;
static uint32 cMonth;
static uint32 cHour;
static uint32 cMiniute;
static uint32 cSeconds;
static uint32 cDay;
static uint16 unIndex;
static uint32 ucMonth[MONTH] = {THIRTYONE_DAYS, TWENTYEIGHT_DAYS, 
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
    cYear = ululEpochUTC / (SECONDS * SECONDS * HOURS * DAYS);
    ululEpochUTC = ululEpochUTC - (cYear * (SECONDS * SECONDS * HOURS * DAYS));
    cYear = cYear + UTC_YEAR;

    cDay = ululEpochUTC / (SECONDS * SECONDS * HOURS);
    ululEpochUTC = ululEpochUTC - (cDay * (SECONDS * SECONDS * HOURS));

    for (unIndex = UTC_YEAR; unIndex <= cYear; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucFlag++;
        }
    }
    cDay = cDay - ucFlag;
    for (unIndex = ZERO; unIndex < MONTH; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucMonth[ONE] = APRIL_DAYS;
        }
        if (cDay > ucMonth[unIndex])
        {
            cDay = cDay - ucMonth[unIndex];
        }
        else
        {
            cMonth = unIndex + ONE;
            break;
        }
    }

    cHour = ululEpochUTC / (SECONDS * SECONDS);
    ululEpochUTC = ululEpochUTC % (SECONDS * SECONDS);

    cMiniute = ululEpochUTC / (SECONDS);
    ululEpochUTC = ululEpochUTC % (SECONDS);

    cSeconds = ululEpochUTC;

    printf("\n");
    printf("UTC (0:0)\n");
    printf("-----------------------\n");
    printf("Time  : %02d:%02d:%02d ",cHour,cMiniute,cSeconds);
    if (MONTH <= cHour)
    {
        printf("PM");
    }
    else
    {
        printf("AM");
    }

    printf("\nDate  : %02d/%02d/%02d\n",cDay,cMonth,cYear);
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
    cYear = ulEpochIST / (SECONDS * SECONDS * HOURS * DAYS);
    ulEpochIST = ulEpochIST - (cYear * (SECONDS * SECONDS * HOURS * DAYS));
    cYear = cYear + UTC_YEAR;

    cDay = ulEpochIST / (SECONDS * SECONDS * HOURS);
    ulEpochIST = ulEpochIST - (cDay * (SECONDS * SECONDS * HOURS));

    for (unIndex = UTC_YEAR; unIndex <= cYear; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucFlag++;
        }
    }
    cDay = cDay - ucFlag;
    for (unIndex = ZERO; unIndex < MONTH; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucMonth[ONE] = APRIL_DAYS;
        }
        if (cDay > ucMonth[unIndex])
        {
            cDay = cDay - ucMonth[unIndex];
        }
        else
        {
            cMonth = unIndex + ONE;
            break;
        }
    }
    
    ulEpochIST = ulEpochIST % (SECONDS * SECONDS * HOURS);

    cHour = ulEpochIST / (SECONDS * SECONDS);
    ulEpochIST = ulEpochIST % (SECONDS * SECONDS);

    cMiniute = ulEpochIST / (SECONDS);
    ulEpochIST = ulEpochIST % (SECONDS);

    cSeconds = ulEpochIST;

    printf("\n");
    printf("IST (5:30)\n");
    printf("-----------------------\n");
    printf("Time  : %02d:%02d:%02d ",cHour,cMiniute,cSeconds);
    if (MONTH <= cHour)
    {
        printf("PM");
    }
    else
    {
        printf("AM");
    }

    printf("\nDate  : %02d/%02d/%02d\n",cDay,cMonth,cYear);
    
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
    cYear = ulEpochPST / (SECONDS * SECONDS * HOURS * DAYS);
    ulEpochPST = ulEpochPST - (cYear * (SECONDS * SECONDS * HOURS * DAYS));
    cYear = cYear + UTC_YEAR;

    cDay = ulEpochPST / (SECONDS * SECONDS * HOURS);
    ulEpochPST = ulEpochPST - (cDay * (SECONDS * SECONDS * HOURS));

    for (unIndex = UTC_YEAR; unIndex <= cYear; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucFlag++;
        }
    }

    cDay = cDay - ucFlag;
    for (unIndex = ZERO; unIndex < MONTH; unIndex++)
    {
        if ((unIndex % FOUR == ZERO && unIndex % HUNDRED != ZERO) || 
        (unIndex % FOUR * HUNDRED) == ZERO)
        {
            ucMonth[ONE] = APRIL_DAYS;
        }
        if (cDay > ucMonth[unIndex])
        {
            cDay = cDay - ucMonth[unIndex];
        }
        else
        {
            cMonth = unIndex + ONE;
            break;
        }
    }

    ulEpochPST = ulEpochPST % (SECONDS * SECONDS * HOURS);

    cHour = ulEpochPST / (SECONDS * SECONDS);
    ulEpochPST = ulEpochPST % (SECONDS * SECONDS);

    cMiniute = ulEpochPST / (SECONDS);
    ulEpochPST = ulEpochPST % (SECONDS);

    cSeconds = ulEpochPST;

    printf("\n");
    printf("PST (7:00)\n");
    printf("-----------------------\n");
    printf("Time  : %02d:%02d:%02d ",cHour,cMiniute,cSeconds);
    if (MONTH <= cHour)
    {
        printf("PM");
    }
    else
    {
        printf("AM");
    }

    printf("\nDate  : %02d/%02d/%02d\n",cDay,cMonth,cYear);
    
    return true;
}
// EOF
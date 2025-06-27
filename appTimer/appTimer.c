//******************************** appTimer ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
//
// File    : appTimer.c
// Summary : Display date and time in UTC,IST,PST.
// Note    : appTimer.h, common.h are included.
// Author  : Surya Santhosh
// Date    : 19/JUN/2024
//
//******************************************************************************

//******************************* Include Files ********************************
#include "common.h"
#include "appTimer.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//*********************************.AppTimer.***********************************
// Purpose : Display date and time in UTC,GST,PST.
// Inputs  : ulEpoch - Epoch time.
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
bool AppTimer(uint32 ulEpoch)
{
    uint32 ulEpochPST = 0;
    uint32 ulEpochIST = 0;
    uint32 ulEpochUTC = 0;
    bool blResult    = true;

    if (0 == ulEpoch)
    {
        blResult = false;
    }
    else
    {
        ulEpochUTC = ulEpoch;

        printf("UTC (0:0)\n");
        printf("-----------------------\n");

        if (AppTimerDisplayTimeDate(ulEpochUTC) == false)
        {
            printf("Epoch Time is Zero.");
        }
        
        printf("Epoch  : %ld\n",ulEpoch);

        //IST
        printf("\n");
        printf("IST (+5:30)\n");
        printf("-----------------------\n");

        ulEpochIST = ulEpoch + TIME_DIFF_IST;

        if (AppTimerDisplayTimeDate(ulEpochIST) == false)
        {
            printf("Epoch Time is Zero.");
        }

        //PST
        ulEpochPST = ulEpoch - TIME_DIFF_PST;
        
        printf("\n");
        printf("PST (-7:00)\n");
        printf("-----------------------\n");

        if (AppTimerDisplayTimeDate(ulEpochPST) == false)
        {
            printf("Epoch Time is Zero.");
        }
        blResult = true;
    }

    return blResult;
}

//*************************.appTimerDisplayTimeDate.****************************
// Purpose : Display date and time.
// Inputs  : ulEpoch - Epoch time.
// Outputs : None
// Return  : blResult
// Notes   : None
//****************************************************************************** 
bool AppTimerDisplayTimeDate(uint32 ulEpoch)
{
    uint32 ulYear    = 0;
    uint32 ulMonth   = 0;
    uint32 ulHour    = 0;
    uint32 ulMinute  = 0;
    uint32 ulSeconds = 0;
    uint32 ulDay     = 0;
    uint16 unIndex   = 0;
    bool blResult    = true;
    
    if (0 == ulEpoch)
    {
        blResult = false;
    }
    else
    {
        ulYear = ulEpoch / (SECONDS * MINUTES * DAY_HOURS * TOTAL_DAYS_IN_YEAR);
        ulEpoch -= (ulYear * 
                   (SECONDS * MINUTES * DAY_HOURS * TOTAL_DAYS_IN_YEAR));
        // Add 1970 to get the actual year.
        ulYear += UNIX_EPOCH_YEAR; 
        ulDay = ulEpoch / (SECONDS * MINUTES * DAY_HOURS);
        ulEpoch -= (ulDay * (SECONDS * MINUTES * DAY_HOURS));

        // Decrement the number of days as per leap year count. 
        for (unIndex = UNIX_EPOCH_YEAR; unIndex <= ulYear; unIndex++)
        {
            if (((0 == (unIndex % LEAPYEAR_CHECK_4)) && 
               (0 != (unIndex % LEAPYEAR_CHECK_100))) || 
               (0 == (unIndex % LEAPYEAR_CHECK_400)))
            {
                ulDay--;
            }
        }

        // Increment by 1 because calender days start from 1 january.
        ulDay ++; 

        // Decrement the number of days as per number of days in each month.
        for (unIndex = MONTH_START; unIndex <= MONTH; unIndex++)
        {
            if (EIGHTH_MONTH <= unIndex)
            {
                if (0 == (unIndex % EVEN_NUMBER))
                {
                    if (THIRTY_DAYS < ulDay)
                    {
                        ulDay -= THIRTY_DAYS;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (THIRTYONE_DAYS < ulDay)
                    {
                        ulDay -= THIRTYONE_DAYS;
                    }
                    else
                    {
                        break;
                    }
                } 
            }
            else
            {
                if (SECOND_MONTH == unIndex)
                {
                    if (TWENTYEIGHT_DAYS < ulDay)
                    {
                        ulDay -= TWENTYEIGHT_DAYS;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (0 == (unIndex % EVEN_NUMBER))
                {
                    if (THIRTY_DAYS < ulDay)
                    {
                        ulDay -= THIRTY_DAYS;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (THIRTYONE_DAYS < ulDay)
                    {
                        ulDay -= THIRTYONE_DAYS;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        ulMonth = unIndex;
        ulHour = ulEpoch / (SECONDS * MINUTES);
        ulEpoch %= (SECONDS * MINUTES);
        ulMinute = ulEpoch / (SECONDS);
        ulEpoch %= (SECONDS);
        ulSeconds = ulEpoch;

        printf("Time  : %02ld:%02ld:%02ld ",ulHour,ulMinute,ulSeconds);

        if (DAY_HOURS <= ulHour)
        {
            printf("PM");
        }
        else
        {
            printf("AM");
        }

        printf("\nDate  : %02ld/%02ld/%02ld\n",ulDay,ulMonth,ulYear);

        blResult = true;

    }

    return blResult;
}
// EOF
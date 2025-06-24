//******************************** AppTimer ************************************
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

//******************************.appTimer.***********************************
// Purpose : Display date and time.
// Inputs  : ulEpoch - Epoch time.
// Outputs : None
// Return  : blResult
// Notes   : None
//****************************************************************************** 
bool appTimer(uint32 ulEpoch)
{
    uint32 ulYear = 0;
    uint32 ulMonth = 0;
    uint32 ulHour = 0;
    uint32 ulMinute = 0;
    uint32 ulSeconds = 0;
    uint32 ulDay = 0;
    uint16 unIndex = 0;
    bool blResult = true;
    
    if (ZERO == ulEpoch)
    {
        blResult = false;
    }
    else
    {
        ulYear = ulEpoch / (SECONDS * MINUTES * HOURS * DAYS);
        ulEpoch -= (ulYear * (SECONDS * MINUTES * HOURS * DAYS));
        ulYear += UTC_YEAR;
        ulDay = ulEpoch / (SECONDS * MINUTES * HOURS);
        ulEpoch -= (ulDay * (SECONDS * MINUTES * HOURS));

        // Decrement the number of days as per leap year count. 
        for (unIndex = UTC_YEAR; unIndex <= ulYear; unIndex++)
        {
            if (((ZERO == (unIndex % LEAPYEAR_CHECK_FOUR)) && 
            (ZERO != (unIndex % LEAPYEAR_CHECK_HUNDRED))) || 
            (ZERO == (unIndex % LEAPYEAR_CHECK_FOUR * LEAPYEAR_CHECK_HUNDRED)))
            {
                ulDay--;
            }
        }

        //Adding 1 because days start from 0 but in calender days start from 1.
        ulDay += ONE; 

        // Decrement the number of days as per number of days in each month.
        for (unIndex = ZERO; unIndex < MONTH; unIndex++)
        {
            if (HALFYEAR_MONTH <= unIndex)
            {
                if ((unIndex % EVEN) == 0)
                {
                    if (ulDay > THIRTYONE_DAYS)
                    {
                        ulDay -= THIRTY_DAYS;
                    }
                    else
                    {
                        ulMonth = unIndex;
                        break;
                    }
                }
                else
                {
                    if (ulDay > THIRTYONE_DAYS)
                    {
                        ulDay -= THIRTYONE_DAYS;
                    }
                    else
                    {
                        ulMonth = unIndex;
                        break;
                    }
                } 
            }
            else
            {
                if (SECOND_MONTH == unIndex)
                {
                    if (ulDay > TWENTYEIGHT_DAYS)
                    {
                        ulDay -= TWENTYEIGHT_DAYS;
                    }
                    else
                    {
                        ulMonth = unIndex;
                        break;
                    }
                }
                else if ((unIndex % EVEN) == 0)
                {
                    if (ulDay > THIRTYONE_DAYS)
                    {
                        ulDay -= THIRTYONE_DAYS;
                    }
                    else
                    {
                        ulMonth = unIndex;
                        break;
                    }
                }
                else
                {
                    if (ulDay > THIRTYONE_DAYS)
                    {
                        ulDay -= THIRTY_DAYS;
                    }
                    else
                    {
                        ulMonth = unIndex;
                        break;
                    }
                }
            }
        }

        ulMonth += ONE;
        ulHour = ulEpoch / (SECONDS * MINUTES);
        ulEpoch %= (SECONDS * MINUTES);
        ulMinute = ulEpoch / (SECONDS);
        ulEpoch %= (SECONDS);
        ulSeconds = ulEpoch;

        printf("Time  : %02ld:%02ld:%02ld ",ulHour,ulMinute,ulSeconds);

        if (HALFDAY_HOUR <= ulHour)
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
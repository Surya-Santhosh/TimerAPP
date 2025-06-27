//******************************* AppTimer *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Display date and time in UTC,IST,PST.
// Note    : None
// Author  : Surya Santhosh
// Day     : 19/June/2025
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "appTimer.h"
#include "common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.mainFunction.**********************************
// Purpose : Print date and time in UTC,IST,PST.
// Inputs  : none
// Outputs : none
// Return  : 0
// Notes   : None
//******************************************************************************
int main()
{
    uint32 ulEpoch = 0;
    uint32 ulEpochPST = 0;
    uint32 ulEpochIST = 0;
    uint32 ulEpochUTC = 0;

    while (true)
    {
        time_t ulTime;

        ulEpoch = time(&ulTime);

        //UTC
        ulEpochUTC = ulEpoch;

        printf("UTC (0:0)\n");
        printf("-----------------------\n");

        if (appTimer(ulEpochUTC) == false)
        {
            printf("Epoch Time is Zero.");
        }
        
        printf("Epoch  : %lu\n",ulEpoch);

        //IST
        printf("\n");
        printf("IST (+5:30)\n");
        printf("-----------------------\n");

        ulEpochIST = ulEpoch + TIME_DIFF_IST;

        if (false == appTimer(ulEpochIST))
        {
            printf("Epoch Time is Zero.");
        }

        //PST
        ulEpochPST = ulEpoch - TIME_DIFF_PST;
        
        printf("\n");
        printf("PST (-7:00)\n");
        printf("-----------------------\n");

        if (false == appTimer(ulEpochPST))
        {
            printf("Epoch Time is Zero.");
        }

        sleep(1);

        printf("\x1b[H"); // Move Cursor to top-left
        printf("\x1b[J"); // clear screen
    }

    return 0;
}

// EOF
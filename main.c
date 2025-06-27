//******************************* AppTimer *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Display date and time in UTC,IST,PST and "LED ON" "LED OFF".
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
// Purpose : Print date and time in UTC,IST,PST and LED ON, LED OFF.
// Inputs  : none
// Outputs : none
// Return  : 0
// Notes   : None
//******************************************************************************
int main()
{
    uint32 ulEpoch = 0;

    while (true)
    {
        time_t ulTime;

        ulEpoch = time(&ulTime);

        // Print date and time in UTC,IST,PST. 
        if (false == AppTimer(ulEpoch))
        {
            printf("Epoch Time is Zero.");
        }

        printf("\nLED ON\n");

        sleep(1);
        
        printf("\x1b[H"); // Move Cursor to top-left
        printf("\x1b[J"); // clear screen

        ulEpoch = time(&ulTime);

        // Print date and time in UTC,IST,PST. 
        if (false == AppTimer(ulEpoch))
        {
            printf("Epoch Time is Zero.");
        }

        printf("\nLED OFF\n");

        sleep(1);
        
        printf("\x1b[H"); // Move Cursor to top-left
        printf("\x1b[J"); // clear screen

    }

    return 0;
}
// EOF
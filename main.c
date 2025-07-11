//********************************** main **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Display date and time in UTC,IST,PST and 
//           LED blink with delay of 840ms ON and 532ms OFF.
// Note    : None
// Author  : Surya Santhosh
// Day     : 19/June/2025
//******************************************************************************

//******************************* Include Files ********************************
#include "appTimer.h"
#include "LEDDisplay.h"

#ifdef ENABLE_LED_BLINK

#include "GPIOControl.h"

#endif

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.mainFunction.**********************************
// Purpose : Print date and time in UTC, IST, PST, and LED blink with delay of 
//           840ms ON and 532ms OFF.
// Inputs  : none
// Outputs : none
// Return  : 0
// Notes   : None
//******************************************************************************
int main()
{
    uint32 ulEpoch = 0; 

    // Set GPIO.
    #ifdef ENABLE_LED_BLINK

    struct gpiod_chip *stpchip = NULL;
    struct gpiod_line *stpline = NULL;

    GPIOControlSet(&stpchip, &stpline);

    #endif
    
    while (true)
    {
        time_t ulTime;

        ulEpoch = time(&ulTime);

        // Print date and time in UTC,IST,PST. 
        if (false == AppTimerTimeConverter(ulEpoch))
        {
            printf("Epoch Time is Zero.");
        }

        // LED Status Print with delay of 840ms ON and 532ms OFF.
        LEDPrintStatus();

        #ifdef ENABLE_LED_BLINK

        // LED blink with delay of 840ms ON and 532ms OFF.
        LEDBlink(&stpline);

        #endif

        printf("\x1b[H"); // Move Cursor to top-left
        printf("\x1b[J"); // clear screen
    }

    // Release GPIO.
    #ifdef ENABLE_LED_BLINK

    GPIOControlRelease(&stpchip, &stpline);

    #endif

    return 0;
}
// EOF
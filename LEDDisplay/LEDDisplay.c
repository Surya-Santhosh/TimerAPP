//******************************* LEDDisplay ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : LEDDisplay.c
// Summary : LED blink with delay of 840ms ON and 532ms OFF.
// Note    : None
// Author  : Surya Santhosh
// Date    : 30/JUN/2024
//******************************************************************************

//******************************* Include Files ********************************
#include "LEDDisplay.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.LEDPrintStatus.********************************
// Purpose : Print LED ON and LED OFF with delay of 840ms ON and 532ms OFF.
// Inputs  : None
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool LEDPrintStatus()
{
    static bool sblLedStatus = true;

    if (true == sblLedStatus)
    {
        printf("\nLED ON\n");

        //LED ON with delay 840ms.
        usleep(DELAY_LED_ON);
        sblLedStatus = false;
    }
    else
    {
        printf("\nLED OFF\n");

        //LED OFF with delay 532ms.
        usleep(DELAY_LED_OFF);
        sblLedStatus = true;
    }

    return true;
}
//*********************************.LEDBlink.***********************************
// Purpose : LED blink with delay of 840ms ON and 532ms OFF.
// Inputs  : None
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
#ifdef ENABLE_LED_ON_RPI

bool LEDBlink(struct gpiod_line **pstline)
{
    static bool sblLedStatus = true;

    if (true == sblLedStatus)
    {
        gpiod_line_set_value(*pstline, sblLedStatus);

        //LED ON with delay 840ms.
        sblLedStatus = false;
    }
    else
    {
        gpiod_line_set_value(*pstline, sblLedStatus);

        //LED OFF with delay 532ms.
        sblLedStatus = true;
    }

    return true;
}

#endif
// EOF
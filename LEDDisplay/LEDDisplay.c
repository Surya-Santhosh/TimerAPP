//******************************** AppTimer ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : LEDDisplay.c
// Summary : Display LED ON, LED OFF.
// Note    : None
// Author  : Surya Santhosh
// Date    : 30/JUN/2024
//******************************************************************************

//******************************* Include Files ********************************
#include "common.h"
#include "LEDDisplay.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//********************************.LEDStatus.**********************************
// Purpose : Display LED ON, LED OFF.
// Inputs  : ulflag.
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
bool LEDStatus(uint8 *ulLedStatus)
{
    bool blResult = true;

    if (NULL == ulLedStatus)
    {
        blResult = false;
    }
    else
    {
        if (LED_OFF == *ulLedStatus)
        {
            printf("\nLED OFF\n");

            *ulLedStatus = LED_ON;
        }
        else
        {
            printf("\nLED ON\n");

            *ulLedStatus = LED_OFF;
        }

        blResult = true;
    }

    return blResult;
}
// EOF
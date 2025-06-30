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
static uint8 sucLedStatus = 0;

//****************************** Local Functions *******************************

//********************************.LEDStatus.**********************************
// Purpose : Display LED ON, LED OFF.
// Inputs  : None
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
bool LEDStatus()
{
    bool blResult = true;

    if (CHECK_ONE < sucLedStatus)
    {
        blResult = false;
    }
    else
    {
        if (LED_OFF == sucLedStatus)
        {
            printf("\nLED OFF\n");

            sucLedStatus = LED_ON;
        }
        else
        {
            printf("\nLED ON\n");

            sucLedStatus = LED_OFF;
        }

        blResult = true;
    }

    return blResult;
}
// EOF
//******************************* LEDDisplay ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : LEDDisplay.c
// Summary : Display LED ON and LED OFF.
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

//********************************.LEDStatus.**********************************
// Purpose : Display LED ON and LED OFF.
// Inputs  : None
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool LEDStatus()
{
    static bool sblLedStatus = true;

    if (true == sblLedStatus)
    {
        printf("\nLED ON\n");

        sblLedStatus = false;
    }
    else
    {
        printf("\nLED OFF\n");

        sblLedStatus = true;
    }

    return true;
}
// EOF
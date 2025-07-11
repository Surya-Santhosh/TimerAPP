//******************************* LEDBlink *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : GPIOControl.c
// Summary : Initialize GPIO chip and line, Set line as output.
// Note    : None
// Author  : Surya Santhosh
// Date    : 08/JUly/2024
//******************************************************************************

//******************************* Include Files ********************************
#include "GPIOControl.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.GPIOControlSet.********************************
// Purpose : Initialize GPIO chip and line, Set line as output.
// Inputs  : stpchip - GPIO chip
//         : stpline - GPIO line
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
bool GPIOControlSet(struct gpiod_chip **stpchip, 
                    struct gpiod_line **stpline)
{
    uint8 cState;
    bool blResult = true;

    *stpchip = gpiod_chip_open_by_name("gpiochip0");

    if (!*stpchip)
    {
        printf("Failed to find gpio Chip.");

        blResult = false;
    }

    *stpline = gpiod_chip_get_line(*stpchip,GPIO_LINE);

    if(!*stpline)
    {
        printf("Failed to find gpioline.");
        gpiod_chip_close(*stpchip);

        blResult = false;
    }

    cState = gpiod_line_request_output(*stpline,"LED Blink", 0);
    
    if(0 > cState)
    {
        printf("Failed to request gpio line as output.");
        gpiod_chip_close(*stpchip);

        blResult = false;
    }

    return blResult;
}
//***************************.GPIOControlRelease.*******************************
// Purpose : Release GPIO chip and line.
// Inputs  : stpchip - GPIO chip
//         : stpline - GPIO line
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool GPIOControlRelease(struct gpiod_chip **stpchip,
                        struct gpiod_line **stpline)
{
    gpiod_line_release(*stpline);
    gpiod_chip_close(*stpchip);

    return true;
}
// EOF
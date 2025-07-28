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
// Inputs  : ppstchip - GPIO chip
//         : ppstline - GPIO line
// Outputs : None
// Return  : blResult
// Notes   : None
//******************************************************************************
bool GPIOControlSet(struct gpiod_chip **ppstchip, 
                    struct gpiod_line **ppstline)
{
    bool blResult = true;
    uint8 cState = 0;

    *ppstchip = gpiod_chip_open_by_name("gpiochip0");

    if (!*ppstchip)
    {
        printf("Failed to find gpio Chip.");

        blResult = false;
    }

    *ppstline = gpiod_chip_get_line(*ppstchip, GPIO_LINE);

    if(!*ppstline)
    {
        printf("Failed to find gpioline.");
        gpiod_chip_close(*ppstchip);

        blResult = false;
    }

    cState = gpiod_line_request_output(*ppstline, "LED Blink", 0);
    
    if(0 > cState)
    {
        printf("Failed to request gpio line as output.");
        gpiod_chip_close(*ppstchip);

        blResult = false;
    }

    return blResult;
}
//***************************.GPIOControlRelease.*******************************
// Purpose : Release GPIO chip and line.
// Inputs  : ppstchip - GPIO chip
//         : ppstline - GPIO line
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool GPIOControlRelease(struct gpiod_chip **ppstchip,
                        struct gpiod_line **ppstline)
{
    gpiod_line_release(*ppstline);
    gpiod_chip_close(*ppstchip);

    return true;
}
// EOF
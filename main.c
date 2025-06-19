//******************************* TimerApp *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
//
// File    : main.c
// Summary : Display date and time in UTC,IST,PST.
// Note    : None
// Author  : Surya Santhosh
// Day     : 19/June/2025
//
//******************************************************************************

//******************************* Include Files ********************************
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"appTimer.h"

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
    uint32 ulEpoch;
    uint32 ulEpochPST;
    uint32 ulEpochIST;
    uint32 ulEpochUTC;
    while (ONE)
    {
        time_t tTime;
        struct tm *CurrentTime;

        ulEpoch = time(&tTime);
        CurrentTime = localtime(&tTime);

        //UTC
        ulEpochUTC = ulEpoch;
        appTimerUTC(ulEpochUTC, ulEpoch);

        //IST
        ulEpochIST = ulEpoch + TIME_DIFF_IST;
        appTimerIST(ulEpochIST);

        //PST
        ulEpochPST = ulEpoch - TIME_DIFF_PST;
        appTimerPST(ulEpochPST);

        Sleep(THOUSAND);
    }
    return 0;
}

// EOF
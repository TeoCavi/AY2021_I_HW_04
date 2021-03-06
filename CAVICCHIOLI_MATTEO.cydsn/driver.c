/* ========================================
 *
 * Copyright LTEBS, 29/10/2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF LTEBS.
 *
 * ========================================
*/
#include "driver.h"

//static variables used to compute locally the mean and assign it to relative DataBuffer adress
static uint32 meanbright32;
static uint32 meanintensity32;

//start of CLK, PWM, TIMER, ADC
void StartComponents()
{
    CLK_PWM_Start();
    CLK_TIMER_Start();
    PWM_Start();
    ADC_Start();
    TIMER_Start();
}

//stop of CLK, PWM, TIMER, ADC
void StopComponents()
{
    CLK_PWM_Stop();
    CLK_TIMER_Stop();
    PWM_Stop();
    ADC_Stop();
    TIMER_Stop();
}

//writing fixed value inside DataBuffer
void FixedBytesToSend()
{
    DataBuffer[HEAD] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    DataBuffer[T_HOLD_MSB] = THRESHOLD >> 8;
    DataBuffer[T_HOLD_LSB] = THRESHOLD & 0xFF;
}

//writing mean inside DataBuffer and write PWM compare to control led intensity
void VariableBytesToSend()
{
    meanbright32 = sumbright32/10;
    meanintensity32 = sumintensity32/10;
    PWM_WriteCompare(meanintensity32/PWM_FROM_16_TO_8);
    DataBuffer[BRIGHT_MSB] = meanbright32 >> 8;
    DataBuffer[BRIGHT_LSB] = meanbright32 & 0xFF;
    DataBuffer[POT_MSB] = meanintensity32 >> 8;
    DataBuffer[POT_LSB] = meanintensity32 & 0xFF;
}
    
    
    



/* [] END OF FILE */

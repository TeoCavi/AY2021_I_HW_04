/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "driver.h"

void StartComponents()
{
    UART_Start();
    CLK_PWM_Start();
    CLK_TIMER_Start();
    PWM_Start();
    ADC_Start();
    TIMER_Start();
}

void FixedBytesToSend()
{
    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    DataBuffer[T_HOLD_MSB] = THRESHOLD_MSB;
    DataBuffer[T_HOLD_LSB] = THRESHOLD_LSB;
}

void VariableBytesToSend()
{
    DataBuffer[BRIGHT_MSB] = bright32 >> 8;
    DataBuffer[BRIGHT_LSB] = bright32 & 0xFF;
    DataBuffer[POT_MSB] = intensity32 >> 8;
    DataBuffer[POT_LSB] = intensity32 & 0xFF;
}
    
    
    



/* [] END OF FILE */

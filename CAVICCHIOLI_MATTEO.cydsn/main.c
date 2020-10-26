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
#include "project.h"
#include "interruptroutines.h"

volatile uint8 status = UART_RX_STOP;
volatile uint8 adc_clock = ADC_ENABLE;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    CLK_PWM_Start();
    CLK_TIMER_Start();
    PWM_Start();
    ADC_Start();
    TIMER_Start();
    ISR_UART_StartEx(Custom_UART_ISR);
    ISR_TIMER_StartEx(Custom_ADC_ISR);
    
    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    DataBuffer[T_HOLD_MSB] = THRESHOLD_MSB;
    DataBuffer[T_HOLD_LSB] = THRESHOLD_LSB;
    
    for(;;)
    {
        if(uart_status && adc_clock)
        {
            UART_PutArray(DataBuffer,TRANSMIT_BUFFER_SIZE);
            adc_clock = 0;
        }
    }
}

/* [] END OF FILE */

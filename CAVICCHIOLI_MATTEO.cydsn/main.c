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
#include "globalvariables.h"
#include "driver.h"

volatile uint8 status = UART_RX_STOP;
volatile uint8 adc_clock = ADC___DISABLED;

int main(void)
{
    CyGlobalIntEnable; 
    
    StartComponents();
    
    ISR_UART_StartEx(Custom_UART_ISR);
    ISR_TIMER_StartEx(Custom_ADC_ISR);
    
    FixedBytesToSend();
    
    for(;;)
    {
        if((uart_status == UART_RX_START) && (adc_clock == ADC_ENABLED))
        {
            VariableBytesToSend();
            UART_PutArray(DataBuffer,TRANSMIT_BUFFER_SIZE);
            adc_clock = 0;
        }
    }
}

/* [] END OF FILE */

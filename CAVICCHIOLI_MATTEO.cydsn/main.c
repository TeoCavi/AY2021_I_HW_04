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

volatile uint8 status = UART_RX_STOP;
volatile uint8 adc_clock = ADC___DISABLED;

int main(void)
{
    CyGlobalIntEnable; 
    
    UART_Start();
    ISR_UART_StartEx(Custom_UART_ISR);
    ISR_TIMER_StartEx(Custom_ADC_ISR);
    
    sumbright32 = 0;
    sumintensity32 = 0;
    
    FixedBytesToSend();
    
    for(;;)
    {
        if((uart_status == UART_RX_START) && (adc_clock == HUNDRED_MS))
        {
            VariableBytesToSend();
            UART_PutArray(DataBuffer,TRANSMIT_BUFFER_SIZE);
            sumbright32 = 0;
            sumintensity32 = 0;
            adc_clock = 0; 
        }
    }
}

/* [] END OF FILE */

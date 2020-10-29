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

#include "project.h"
#include "interruptroutines.h"
#include "globalvariables.h"

//definition of UART recived byte flag
volatile uint8 status = UART_RX_STOP;

//definition of ADC conversion flag
volatile uint8 adc_clock = ADC___END;

int main(void)
{
    CyGlobalIntEnable; 
    
    //Start of UART and ISR (UART and ISR will never be stopped after 'b')
    UART_Start();
    ISR_UART_StartEx(Custom_UART_ISR);
    ISR_TIMER_StartEx(Custom_ADC_ISR);
    
    //variables to compute the mean of samples
    sumbright32 = 0;
    sumintensity32 = 0;
    
    //function that assign head, tail and threshold (2 bytes) to array DataBuffer  
    FixedBytesToSend();
    
    for(;;)
    {
        //verified only when 'b' or 'B' is received and 100ms have passed
        if((uart_status == UART_RX_START) && (adc_clock == HUNDRED_MS))  
        {
            //function that assign te brightness and intensity (potentiometer value not re-mapped to 8bit) to array DataBuffer
            VariableBytesToSend();
            
            //once DataByffer is comopleted it's sent to Terminal by UART
            UART_PutArray(DataBuffer,TRANSMIT_BUFFER_SIZE);
            
            //the two sum and the adc clock are set to zero
            sumbright32 = 0;
            sumintensity32 = 0;
            adc_clock = ADC___END; 
        }
    }
}

/* [] END OF FILE */

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

#include "interruptroutines.h"
#include "project.h"
#include "stdio.h"


int32 bright32;
int32 intensity32;

CY_ISR(Custom_UART_ISR)
{
    uint8 recived = UART_ReadRxData();
    switch (recived)
    {
        case 'b':
        case 'B':
            uart_status = UART_RX_START;
            UART_LED_Write(ON);
            StartComponents();
            break;
        case 's':
        case 'S':
            uart_status = UART_RX_STOP;
            UART_LED_Write(OFF);
            break;
        default:
            break;
    }
}

CY_ISR_PROTO(Custom_ADC_ISR)
{
    TIMER_ReadStatusRegister();
    adc_clock ++;
    
    switch(uart_status)
    {
        case UART_RX_START:
        
            MUX_Select(PHOTORESISTOR);
            bright32 = ADC_Read32();
            
            if (bright32 > ADC_MAX)    
                bright32 = ADC_MAX;
            if (bright32 < ADC_MIN)
                bright32 = ADC_MIN;
            
            sumbright32 = sumbright32 + bright32;
            
            if (bright32 < THRESHOLD)
            {
                MUX_Select(POTENTIOMETER);
                intensity32 = ADC_Read32();
                
                if (intensity32 > ADC_MAX)
                    intensity32 = ADC_MAX;
                if (intensity32 < ADC_MIN)
                    intensity32 = ADC_MIN;
            }
            else
            {
                intensity32 = OFF;
            }
            sumintensity32 = sumintensity32 + intensity32;
            break;
            
        case UART_RX_STOP:
            StopComponents();
            break;
    }
    
        
        
        
        
        
    
    
    
}
            
            
            
        
       
       
        
        
        
    
    
    
        
        
    

/* [] END OF FILE */

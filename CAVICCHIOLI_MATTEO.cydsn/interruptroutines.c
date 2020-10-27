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

CY_ISR(Custom_UART_ISR)
{
    uint8 recived = UART_ReadRxData();
    switch (recived)
    {
        case 'b':
        case 'B':
            uart_status = UART_RX_START;
            UART_LED_Write(ON);
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
    adc_clock = ADC___ENABLED;
    switch(uart_status)
    {
        case UART_RX_START:
        
            ADC_StopConvert();
            MUX_Select(PHOTORESISTOR);
            ADC_StartConvert();
            bright32 = ADC_Read32();
            
            if (bright32 > ADC_MAX)    
                bright32 = ADC_MAX;
            if (bright32 < ADC_MIN)
                bright32 = ADC_MIN;
            
            if (bright32 < THRESHOLD)
            {
                ADC_StopConvert();
                MUX_Select(POTENTIOMETER);
                ADC_StartConvert();
                intensity32 = ADC_Read32();
                
                if (intensity32 > ADC_MAX)
                    intensity32 = ADC_MAX;
                if (intensity32 < ADC_MIN)
                    intensity32 = ADC_MIN;
                
                PWM_WriteCompare((intensity32)/257);
            }
            else
            {
                intensity32 = OFF;
                PWM_WriteCompare(OFF);
            }
            break;
            
        case UART_RX_STOP:
            PWM_WriteCompare(OFF);
            break;
    }
    
        
        
        
        
        
    
    
    
}
            
            
            
        
       
       
        
        
        
    
    
    
        
        
    

/* [] END OF FILE */

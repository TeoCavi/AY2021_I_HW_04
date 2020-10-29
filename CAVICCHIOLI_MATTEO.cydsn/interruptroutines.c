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

#include "interruptroutines.h"
#include "project.h"
#include "stdio.h"

//local ISR variables use to compute the sum of two signals that are set as global (for security is passed sum)
int32 bright32;
int32 intensity32;

CY_ISR(Custom_UART_ISR)
{
    //
    uint8 Byte_Received = UART_ReadRxData();
    switch (Byte_Received)
    {
        //case in which Byte_Received is equal to the starting value
        case 'b':
        case 'B':
            //here ADC is informed that it can start and a status led is switched on
            uart_status = UART_RX_START;
            UART_LED_Write(ON);
            StartComponents();  //components to complete the task are switched on
            break;
        
        //case in which Byte_Received is equal to the stopping vale (I've preferred to stop all inside ADC ISR to let ADC to fully complete last sampling)
        case 's':
        case 'S':
            uart_status = UART_RX_STOP;
            UART_LED_Write(OFF);    //status led is switched off
            break;
            
        //all other cases that are not considered
        default:
            break;
    }
}

CY_ISR_PROTO(Custom_ADC_ISR)
{
    //put ISR line low again to let timer able to start counting again
    TIMER_ReadStatusRegister();
    
    //10ms are passed
    adc_clock ++;
    
    //based on UART status either the ADC can start converting or all components are stopped
    switch(uart_status)
    {
        //Start Byte has been received
        case UART_RX_START:
        
            //selection of MUX photoresistor channel fast and then read ADC buffer putting its value inside bright32
            MUX_Select(PHOTORESISTOR);
            bright32 = ADC_Read32();
            
            //Byte consistency check
            if (bright32 > ADC_MAX)    
                bright32 = ADC_MAX;
            if (bright32 < ADC_MIN)
                bright32 = ADC_MIN;
            
            //compute the sum of brightness samples
            sumbright32 = sumbright32 + bright32;
            
            //if brightness has overcame the threshold then ADC start also the potentiometer signal conversion
            if (bright32 < THRESHOLD)
            {
                //selection of MUX potentiometer channel fast and then read ADC buffer putting its value inside intensity32
                MUX_Select(POTENTIOMETER);
                intensity32 = ADC_Read32();
                
                //Byte consistency check
                if (intensity32 > ADC_MAX)
                    intensity32 = ADC_MAX;
                if (intensity32 < ADC_MIN)
                    intensity32 = ADC_MIN;
            }
            
            //if brightness is under threshold then intensity32 is automatically set to 0 (LED OFF)
            else
            {
                intensity32 = OFF;
            }
            
            ////compute the sum of intensity samples
            sumintensity32 = sumintensity32 + intensity32;
           
            break;
            
        //Stop Byte has been received    
        case UART_RX_STOP:
            
            //all components are stopped and wait next starting byte
            StopComponents();
            
            break;
    }
    
        
        
        
        
        
    
    
    
}
            
            
            
        
       
       
        
        
        
    
    
    
        
        
    

/* [] END OF FILE */

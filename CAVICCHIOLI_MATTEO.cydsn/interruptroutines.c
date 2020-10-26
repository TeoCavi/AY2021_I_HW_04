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
            break;
        case 's':
        case 'S':
            uart_status = UART_RX_STOP;
            // come sopra
            break;
        default:
            break;
    }
}

CY_ISR_PROTO(Custom_ADC_ISR)
{
    TIMER_ReadStatusRegister();
    adc_clock = 1;
    switch(uart_status)
    {
        case UART_RX_START:
            ADC_StopConvert();
            MUX_Select(PHOTORESISTOR);
            ADC_StartConvert();
            bright32 = ADC_Read32();
            if (bright32 > 65535)    
                bright32 = 65535;
            if (bright32 < 0)
                bright32 = 0;
            DataBuffer[BRIGHT_MSB] = bright32 >> 8;
            DataBuffer[BRIGHT_LSB] = bright32 & 0xFF;
            if (bright32 < THRESHOLD)
            {
                ADC_StopConvert();
                MUX_Select(POTENTIOMETER);
                ADC_StartConvert();
                intensity32 = ADC_Read32();
                
                if (intensity32 > 65535)
                    intensity32 = 65535;
                if (intensity32 < 0)
                    intensity32 = 0;
                
                PWM_WriteCompare((intensity32)/257);
                DataBuffer[POT_MSB] = intensity32 >> 8;
                DataBuffer[POT_LSB] = intensity32 & 0xFF;
  
            }
            else
            {
                DataBuffer[POT_MSB] = 0x00;
                DataBuffer[POT_LSB] = 0x00;
                PWM_WriteCompare(0);
                
            }
            break;

        case UART_RX_STOP:
            PWM_WriteCompare(0);
            break;
    }
    
        
        
        
        
        
    
    
    
}
            
            
            
        
       
       
        
        
        
    
    
    
        
        
    

/* [] END OF FILE */

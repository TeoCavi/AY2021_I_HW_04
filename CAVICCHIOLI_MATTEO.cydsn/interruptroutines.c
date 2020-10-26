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

int32 bright32; //
uint16 bright16;
int32 intensity32;
//uint16 intensity16;
//static int8 brightness_mv;
//static uint8 intensity;

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
            bright16 = bright32 & 0xFFFF;
            if (bright16 < 30000)
            {
                ADC_StopConvert();
                MUX_Select(POTENTIOMETER);
                ADC_StartConvert();
                intensity32 = ADC_Read32();
                if (intensity32 > 65535)
                    intensity32 = 65535;
                if (intensity32 < 0)
                    intensity32 = 0;
                //intensity16 = intensity32 & 0xFFFF;
                PWM_WriteCompare((intensity32 & 0xFFFF)/257);
            }
            else
            PWM_WriteCompare(0);
            break;
        case UART_RX_STOP:
            PWM_WriteCompare(0);
           
            break;
    }
    
        
        
        
        
        
    
    
    
}
            
            
            
        
       
       
        
        
        
    
    
    
        
        
    

/* [] END OF FILE */

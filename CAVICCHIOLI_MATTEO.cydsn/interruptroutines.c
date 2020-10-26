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
    PWM_ReadStatusRegister();
    adc_clock ++;
    //UART_PutChar('a');
    /*switch (adc_clock)
    {
        case ONE_SEC:
            ADC_StopConvert();
            MUX_Select(PHOTORESISTOR);
            ADC_StartConvert();
            brightness = ADC_Read8();
            if (brightness > 65535)
                brightness = 65535;
            if (brightness < 0)
                brightness = 0;
            brightness_mv = ADC_CountsTo_mVolts(brightness);
            UART_PutChar(brightness_mv);
            adc_clock = 0;
            break;
    }*/
    ADC_StopConvert();
    MUX_Select(PHOTORESISTOR);
    ADC_StartConvert();
    bright32 = ADC_Read32();
    if (bright32 > 65535)
        bright32 = 65535;
    if (bright32 < 0)
        bright32 = 0;
    bright16 = bright32 & 0xFFFF;
    if (bright16 < 0x4E20)
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
        PWM_WriteCompare(intensity32 & 0xFFFF);
    }
    else
    PWM_WriteCompare(0);
    
        
        
        
        
        
    
    
    
}
            
            
            
        
       
       
        
        
        
    
    
    
        
        
    

/* [] END OF FILE */

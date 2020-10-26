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
volatile uint16 adc_clock = ADC_ENABLE;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    CLK_PWM_Start();
    PWM_Start();
    ADC_Start();
    ISR_UART_StartEx(Custom_UART_ISR);
    ISR_PWM_StartEx(Custom_ADC_ISR);


    for(;;)
    {
        
        

    }
}

/* [] END OF FILE */

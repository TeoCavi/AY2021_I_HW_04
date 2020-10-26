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

#ifndef __INTERRUPT_ROUTINE_H__
    #define __INTERRUPT_ROUTINE_H__
    
    #include "cytypes.h"
    
    #define POTENTIOMETER 1
    #define PHOTORESISTOR 0
    #define UART_RX_START 1
    #define UART_RX_STOP 0
    #define ONE_SEC 10
    #define ADC_ENABLE 0
    
    volatile uint8 uart_status;
    volatile uint16 adc_clock;
    
    CY_ISR_PROTO(Custom_UART_ISR);
    CY_ISR_PROTO(Custom_ADC_ISR);
    
    
    
#endif
/* [] END OF FILE */

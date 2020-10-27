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
    
    #include "globalvariables.h"
    
    volatile uint8 uart_status;
    volatile uint8 adc_clock;

    //uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
    
    CY_ISR_PROTO(Custom_UART_ISR);
    CY_ISR_PROTO(Custom_ADC_ISR);
    
    
    
#endif
/* [] END OF FILE */

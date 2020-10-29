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

#ifndef __INTERRUPT_ROUTINE_H__
    #define __INTERRUPT_ROUTINE_H__
    
    #include "globalvariables.h"
    #include "driver.h"
    
    volatile uint8 uart_status;
    volatile uint8 adc_clock;

    //custom isr functions
    CY_ISR_PROTO(Custom_UART_ISR);
    CY_ISR_PROTO(Custom_ADC_ISR);
    
    
    
#endif
/* [] END OF FILE */

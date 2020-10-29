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
#include "cytypes.h"

#define ON 1
#define OFF 0
#define POTENTIOMETER 1
#define PHOTORESISTOR 0
#define UART_RX_START 1
#define UART_RX_STOP 0
#define ADC___DISABLED 0
#define HUNDRED_MS 10
#define ADC_MAX 65535
#define ADC_MIN 0
#define PWM_FROM_16_TO_8 257 //aggiunta per risparmio di UDB
#define THRESHOLD 30000
#define BYTES_TO_SEND 6
#define HEAD 0
#define BRIGHT_MSB 1
#define BRIGHT_LSB 2
#define POT_MSB 3
#define POT_LSB 4
#define T_HOLD_MSB 5
#define T_HOLD_LSB 6
#define TRANSMIT_BUFFER_SIZE 8

int32 sumbright32;
int32 sumintensity32;
uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];

/* [] END OF FILE */

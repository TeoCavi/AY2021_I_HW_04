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
#include "cytypes.h"

#define ON 1                    //Generic ON
#define OFF 0                   //Generic OFF
#define POTENTIOMETER 1         //Potentiometer aMux Channel
#define PHOTORESISTOR 0         //Photoresistor aMux Channel
#define UART_RX_START 1         //Start Byte Received
#define UART_RX_STOP 0          //Stop Byte Received
#define ADC___END 0             //Initial state of ADC
#define HUNDRED_MS 10           //10 MS index
#define ADC_MAX 65535           //Max value of 16bit ADC
#define ADC_MIN 0               //Min value of 16bit ADC
#define PWM_FROM_16_TO_8 257    //Conversion Factor to map potentiometer compare 16bit-->8bit 
#define THRESHOLD 30000         //Brightness threshold
#define BYTES_TO_SEND 6         //N° of variable Bytes to send using UART
#define HEAD 0                  //Head index
#define BRIGHT_MSB 1            //Brightness indexes
#define BRIGHT_LSB 2
#define POT_MSB 3               //Intensity indexes
#define POT_LSB 4
#define T_HOLD_MSB 5            //Threshold indexes
#define T_HOLD_LSB 6
#define TRANSMIT_BUFFER_SIZE 8  //Effective dimension of Packet

//global variables
int32 sumbright32;
int32 sumintensity32;
uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];

/* [] END OF FILE */

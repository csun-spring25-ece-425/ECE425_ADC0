/*
 * @file main.c
 *
 * @brief Main source code for the ADC program.
 *
 * This file contains the main entry point and function definitions for the ADC program.
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "EduBase_LCD.h"
#include "ADC.h"

static double adc_buffer[8];

int main(void)
{
	// Initialize the SysTick timer used to provide blocking delay functions
	SysTick_Delay_Init();
	
	// Initialize ADC0 module and configure PE2 as an input analog source
	ADC_Init();
	
	while(1)
	{		
		ADC_Sample(adc_buffer);
		double measured_voltage = adc_buffer[0];
		SysTick_Delay1ms(500);
	}
}

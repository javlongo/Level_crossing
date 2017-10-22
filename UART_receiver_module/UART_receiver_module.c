// *
// * Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

#include <stdbool.h>
#include "TM4C123GH6PM.h"
#include "PWM_module\PWM_module.h"
#include "UART_receiver_module.h"
#include "UART_sender_module\UART_sender_module.h"
#include "LEDs_module\LEDs_module.h"
#include "Testing_module\Testing_module.h"

char signal;

void mcu_rx_uart4(void){
	leds_initialization();
	signal = receive_data_uart4();
	
		switch(signal){
			case 'h':
				set_comparator(SHAFT_HORIZONTAL_POSITION);
				set_ack_uart_4(3);
				turn_off_all_leds();
				turn_on_red_led();
			break;
			
			case 'v':
				set_comparator(SHAFT_VERTICAL_POSITION);
				set_ack_uart_4(2);
				turn_off_all_leds();
				turn_on_green_led();
			break;
		}
}

void initialize_uart4_receive_interrupt(void){
	
	UART4->IM |= UART_RECEIVE_INTERRUPT_MASK_BIT_4;	
	NVIC->ISER[1] |= NVIC_INTERRUPT_SET_ENABLE_IRQ_60_MOD_32_BIT_28;
	UART4->ICR  |= UART_RECEIVE_INTERRUPT_CLEAR_BIT_4; 
	
}

void UART4_Handler(void){
	mcu_rx_uart4();
	UART4->ICR  |= UART_RECEIVE_INTERRUPT_CLEAR_BIT_4;	
}


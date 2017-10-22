// *
// * Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

#include "TM4C123GH6pm.h"
#include "UART_sender_module_3\UART_sender_module_3.h"
#include "UART_receiver_module_3\UART_receiver_module_3.h"
#include "PWM_module\PWM_module.h"
#include "UART_receiver_module_3.h"
#include "UART_receiver_module\UART_receiver_module.h"
#include "Testing_module\Testing_module.h"
#include "LEDs_module\LEDs_module.h"

char signal_3;

void mcu_rx_uart3(void){
	leds_initialization();
	
	signal_3 = receive_data_uart_3();
	
		switch(signal_3){
			case 'h':
				set_comparator(SHAFT_HORIZONTAL_POSITION);
				set_ack_uart_3(3);
				turn_off_all_leds();
				turn_on_red_led();
			break;
			
			case 'v':
				set_comparator(SHAFT_VERTICAL_POSITION);
				set_ack_uart_3(2);
				turn_off_all_leds();
				turn_on_green_led();
			break;			
			
		}
}

void initialize_receive_interrupt_uart_3(void){
	
	UART3->IM |= UART_RECEIVE_INTERRUPT_MASK_BIT_4;	
	NVIC->ISER[1] |= NVIC_INTERRUPT_SET_ENABLE_IRQ_60_MOD_32_BIT_27;
	UART3->ICR  |= UART_RECEIVE_INTERRUPT_CLEAR_BIT_4; 
	
}

void UART3_Handler(void){
	mcu_rx_uart3();
	UART3->ICR  |= UART_RECEIVE_INTERRUPT_CLEAR_BIT_4;	
}




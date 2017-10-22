// * 
// *  Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *



#include "TM4C123GH6PM.h"
#include "Switch_1_module.h"
#include "UART_sender_module\UART_sender_module.h"
#include "UART_sender_module_3\UART_sender_module_3.h"
#include "PWM_module\PWM_module.h"


int multiple_signals;

void initialize_user_switch_1(void){
	gpio_port_f_clock();
	unlock_gpio_port_f_pin_0();
	interrupt_set_enable_register();
	gpio_port_f_direction();
	gpio_port_f_pullup();
	gpio_port_f_digital();
	gpio_port_f_interrupt_sense();
	gpio_port_f_interrupt_both_edges();
	gpio_port_f_interrupt_event();
	gpio_port_f_interrupt_mask();
	gpio_port_f_interrupt_clear();
}


void unlock_gpio_port_f_pin_0(void){
	GPIOF->LOCK = 0x4C4F434B;
	GPIOF->CR |= 0x01;
	GPIOF->LOCK = 0x0;
}
void interrupt_set_enable_register(void){
	NVIC->ISER[0] |= INTERRUPT_SET_ENABLE_REGISTER_GPIO_PORT_F_BIT_30;
}

void gpio_port_f_direction(void){
	GPIOF->DIR &=~0x11;
}

void gpio_port_f_pullup(void){
		GPIOF->PUR |=0x11;
}

void gpio_port_f_digital(void){
		GPIOF->DEN |=0x11;
}

void gpio_port_f_interrupt_sense(void){
		GPIOF->IS &=~0x11;
}

void gpio_port_f_interrupt_both_edges(void){
		GPIOF->IBE &=~0x11;
}

void gpio_port_f_interrupt_event(void){
		GPIOF->IEV &=~0x11;
}

void gpio_port_f_interrupt_mask(void){
		GPIOF->IM |=0x11;
}

void gpio_port_f_interrupt_clear(void){
		GPIOF->ICR |= 0x11;
}

void gpio_port_f_clock(void){
	SYSCTL->RCGCGPIO |= GPIO_PORT_F_ENABLE_CLOCK;
}

void GPIOF_Handler(void){
	
	
	if(GPIOF->RIS & 0x10){	
		for(multiple_signals = 0; multiple_signals < 10; multiple_signals++){
				user_switch_1_vertical_signal_uart_3();
				user_switch_1_vertical_signal();
		}
		
		GPIOF->ICR = 0x10;
	}	
	
	if(GPIOF->RIS & 0x01){	
		
		for(multiple_signals = 0; multiple_signals < 10; multiple_signals++){
			user_switch_2_horizontal_signal_uart_3();
			user_switch_2_horizontal_signal();
			}
		GPIOF->ICR = 0x01;
	}
	
	
}

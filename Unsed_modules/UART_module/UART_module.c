// *
// * Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

#include <stdbool.h>
#include "TM4C123GH6PM.h"
#include "UART_module.h"
#include "PWM_module\PWM_module.h"
//#include "driverlib\sysctl.h"

char signal;
int delay;
//int clock_speed_2;



int main(void){
	//clock_speed_2 = SysCtlClockGet();
	pwm_initialization();
	uart_initialization();
	// set_comparator(13597);
	//user_switch_2_horizontal_signal();
	
	while(1){
		for(delay=0; delay<1000000;delay++);
		user_switch_2_horizontal_signal();
		for(delay=0; delay<1000000;delay++);
		user_switch_1_vertical_signal();
		for(delay=0; delay<1000000;delay++);
	
	}

}

void uart_initialization(void){
	initialize_uart4_gpio_port();
	initialize_uart4_module();
	//initialize_uart4_receive_interrupt();
	
}

void initialize_uart4_module(void){
	uart_disable_control();
	uart_interger_baud_rate_divisor();
	uart_fractional_baud_rate_divisor();
	uart_line_control();
	uart_baud_clock_source();
	uart_enable_control();
	
}

void initialize_uart4_gpio_port(void){
	uart_clock_gating_control();
	gpio_port_c_clock_gating_control();	
	gpio_port_c_alternate_function();
	gpio_port_c_peripheral_uart_control();
	gpio_port_c_digital_enable();
}


void transmit_data_uart4(char data){
	while((UART4->FR & UART_TRANSMIT_FIFO_FLAG_STATUS_BIT_5)!= UART_TRANSMIT_FIFO_NOT_FULL);
	UART4->DR = data;
}

char receive_data_uart4(void){
	char read_data;
	while((UART4->FR & UART_RECEIVE_FIFO_FLAG_STATUS_BIT_4) != UART_RECEIVE_FIFO_NOT_EMPTY);
	read_data = UART4->DR;
	return read_data;
}

void uart_disable_control(void){
		UART4->CTL &= ~(UART_ENABLE);
}

void uart_interger_baud_rate_divisor(void){
	UART4->IBRD = UART_INTEGER_BAUD_RATE_DIVISOR_50MHZ_CLOCK_9600_SPEED;
}

void uart_fractional_baud_rate_divisor(void){
	UART4->FBRD = UART_FRACTIONAL_BAUD_RATE_DIVISOR_50MHZ_CLOCK_9600_SPEED;
}

void uart_line_control(void){
	UART4->LCRH = UART_WORD_LENGTH_8_BITS_FIFO_R_T_BUFFER_ENABLE;
}

void uart_baud_clock_source(void){
	UART4->CC = UART_BAUD_CLOCK_SOURCE_SYSTEM_CLOCK;
}

void uart_enable_control(void){
	UART4->CTL = UART_CONTROL_BIT_9_RECEIVE_SECTION_ENABLE_BIT_8_TRANSMIT_SECTION_ENABLE_BIT_0_UART_ENABLE;
}

void uart_clock_gating_control(void){
	SYSCTL->RCGCUART |= UART_MODULE_4_CLOCK_ENABLE;
}

void gpio_port_c_clock_gating_control(void){
	SYSCTL->RCGCGPIO |= GPIO_PORT_C_PERIPHERAL_READY;
}

void gpio_port_c_alternate_function(void){
	GPIOC->AFSEL |= GPIO_PORT_C_ALTERNATE_FUNCTION_PIN_4_PIN_5;
}

void gpio_port_c_peripheral_uart_control(void){
	GPIOC->PCTL |= GPIO_PORT_C_PERIPHERAL_UART_CONTROL_SIGNAL_PIN_4_PIN_5;
}

void gpio_port_c_digital_enable(void){
	GPIOC->DEN |= GPIO_PORT_C_DIGITAL_FUNCTION_ENABLE_PIN_4_PIN_5;
}

void user_switch_1_vertical_signal(void){
	transmit_data_uart4('v');
}
void user_switch_2_horizontal_signal(void){
	transmit_data_uart4('h');
}

//void mcu_rx_uart4(void){
//	
//	signal = receive_data_uart4();
//	
//		switch(signal){
//			case 'h':
//			set_comparator(13597);
//			break;
//			
//			case 'v':
//				set_comparator(15128);
//			break;
//		}
//}

//void initialize_uart4_receive_interrupt(void){
//	
//	UART4->IM |= UART_RECEIVE_INTERRUPT_MASK_BIT_4;	
//	NVIC->ISER[1] |= NVIC_INTERRUPT_SEt_ENABLE_IRQ_60_MOD_32_BIT_28;
//	UART4->ICR  |= UART_RECEIVE_INTERRUPT_CLEAR_BIT_4; 
//	
//}

//void UART4_Handler(void){
//	mcu_rx_uart4();
//	UART4->ICR  |= UART_RECEIVE_INTERRUPT_CLEAR_BIT_4;	
//}


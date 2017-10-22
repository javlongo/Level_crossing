#include "TM4C123GH6pm.h"
#include "UART_sender_module_3.h"
#include "UART_sender_module\UART_sender_module.h"



void initialization_uart_3(void){
	initialize_gpio_port_uart_3();
	initialize_module_uart_3();
}

void initialize_module_uart_3(void){
	disable_control_uart_3();
	interger_baud_rate_divisor_uart_3();
	fractional_baud_rate_divisor_uart_3();
	line_control_uart_3();
	baud_clock_source_uart_3();
	enable_control_uart_3();
	
}

void initialize_gpio_port_uart_3(void){
	clock_gating_control_uart_3();
	gpio_port_c_clock_gating_control_uart_3();	
	gpio_port_c_alternate_function_uart_3();
	gpio_port_c_peripheral_uart_control_uart_3();
	gpio_port_c_digital_enable_uart_3();
}

void gpio_port_c_clock_gating_control_uart_3(void){
	SYSCTL->RCGCGPIO |= GPIO_PORT_C_PERIPHERAL_READY;
}

void transmit_data_uart_3(char data){
	while((UART3->FR & UART_TRANSMIT_FIFO_FLAG_STATUS_BIT_5)!= UART_TRANSMIT_FIFO_NOT_FULL);
	UART3->DR = data;
}

char receive_data_uart_3(void){
	char read_data;
	while((UART3->FR & UART_RECEIVE_FIFO_FLAG_STATUS_BIT_4) != UART_RECEIVE_FIFO_NOT_EMPTY);
	read_data = UART3->DR;
	return read_data;
}

void disable_control_uart_3(void){
		UART3->CTL &= ~(UART_ENABLE);
}

void interger_baud_rate_divisor_uart_3(void){
	UART3->IBRD = UART_INTEGER_BAUD_RATE_DIVISOR_50MHZ_CLOCK_9600_SPEED;
}

void fractional_baud_rate_divisor_uart_3(void){
	UART3->FBRD = UART_FRACTIONAL_BAUD_RATE_DIVISOR_50MHZ_CLOCK_9600_SPEED;
}

void line_control_uart_3(void){
	UART3->LCRH = UART_WORD_LENGTH_8_BITS_FIFO_R_T_BUFFER_ENABLE;
}

void baud_clock_source_uart_3(void){
	UART3->CC = UART_BAUD_CLOCK_SOURCE_SYSTEM_CLOCK;
}

void enable_control_uart_3(void){
	UART3->CTL = UART_CONTROL_BIT_9_RECEIVE_SECTION_ENABLE_BIT_8_TRANSMIT_SECTION_ENABLE_BIT_0_UART_ENABLE;
}

void clock_gating_control_uart_3(void){
	SYSCTL->RCGCUART |= UART_MODULE_3_CLOCK_ENABLE;
}

void user_switch_1_vertical_signal_uart_3(void){
	transmit_data_uart_3('v');
}

void user_switch_2_horizontal_signal_uart_3(void){
	transmit_data_uart_3('h');
}

void gpio_port_c_alternate_function_uart_3(void){
	GPIOC->AFSEL |= GPIO_PORT_C_PIN_6_PIN_7;
}

void gpio_port_c_peripheral_uart_control_uart_3(void){
	GPIOC->PCTL |=  GPIO_PORT_C_PERIPHERAL_UART_CONTROL_SIGNAL_PIN_6_PIN_7;
}

void gpio_port_c_digital_enable_uart_3(void){
	GPIOC->DEN |= GPIO_PORT_C_PIN_6_PIN_7;
}



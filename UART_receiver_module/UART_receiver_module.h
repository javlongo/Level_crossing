// *
// * Copyright (C) 2017 Javier E. Longo. All rights reserved.
// * 

// Constants

//#define UART_TRANSMIT_FIFO_NOT_FULL	0x00000000
//#define UART_TRANSMIT_FIFO_FLAG_STATUS_BIT_5	0x00000020
//#define UART_RECEIVE_FIFO_FLAG_STATUS_BIT_4	0x00000010
//#define UART_RECEIVE_FIFO_NOT_EMPTY	0x00000000
//#define UART_ENABLE	0x00000001
//#define UART_INTEGER_BAUD_RATE_DIVISOR_50MHZ_CLOCK_9600_SPEED	325
//#define UART_FRACTIONAL_BAUD_RATE_DIVISOR_50MHZ_CLOCK_9600_SPEED	33
//#define UART_WORD_LENGTH_8_BITS_FIFO_R_T_BUFFER_ENABLE	0x0070
//#define UART_BAUD_CLOCK_SOURCE_SYSTEM_CLOCK	0x00000000
//#define UART_CONTROL_BIT_9_RECEIVE_SECTION_ENABLE_BIT_8_TRANSMIT_SECTION_ENABLE_BIT_0_UART_ENABLE	0x00000301
//#define UART_MODULE_4_CLOCK_ENABLE 0x00000010
//#define GPIO_PORT_C_PERIPHERAL_READY	0x00000004
//#define GPIO_PORT_C_ALTERNATE_FUNCTION_PIN_4_PIN_5	0x00000030
//#define GPIO_PORT_C_PERIPHERAL_UART_CONTROL_SIGNAL_PIN_4_PIN_5	0x00110000
//#define GPIO_PORT_C_DIGITAL_FUNCTION_ENABLE_PIN_4_PIN_5	0x00000030

#define UART_RECEIVE_INTERRUPT_MASK_BIT_4	0x00000010
#define NVIC_INTERRUPT_SET_ENABLE_IRQ_60_MOD_32_BIT_28	0x10000000
#define UART_RECEIVE_INTERRUPT_CLEAR_BIT_4	0x00000010
#define SHAFT_VERTICAL_POSITION	15128
// #define SHAFT_HORIZONTAL_POSITION	13597
#define SHAFT_HORIZONTAL_POSITION	14510

// Protocols of functions
void mcu_rx_uart4(void);
void initialize_uart4_receive_interrupt(void);

//void uart_initialization(void);
//void initialize_uart4_module(void);
//void initialize_uart4_gpio_port(void);
//void transmit_data_uart4(char data);
//char receive_data_uart4(void);
//void initialize_uart4_receive_interrupt(void);
//void user_switch_1_vertical_signal(void);
//void user_switch_2_horizontal_signal(void);
//void uart_disable_control(void);
//void uart_interger_baud_rate_divisor(void);
//void uart_fractional_baud_rate_divisor(void);
//void uart_line_control(void);
//void uart_baud_clock_source(void);
//void uart_enable_control(void);
//void uart_clock_gating_control(void);
//void gpio_port_c_clock_gating_control(void);	
//void gpio_port_c_alternate_function(void);
//void gpio_port_c_peripheral_uart_control(void);
//void gpio_port_c_digital_enable(void);
//void mcu_rx_uart4(void);

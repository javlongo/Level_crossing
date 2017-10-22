// *
// * Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

// Constants
#define UART_MODULE_3_CLOCK_ENABLE 0x00000008
#define GPIO_PORT_C_PIN_6_PIN_7	0x000000C0
#define GPIO_PORT_C_PERIPHERAL_UART_CONTROL_SIGNAL_PIN_6_PIN_7	0x11000000
#define GPIO_PORT_C_PERIPHERAL_READY	0x00000004

// Protocols of functions
// GPIOs
void gpio_port_c_digital_enable_uart_3(void);
void gpio_port_c_peripheral_uart_control_uart_3(void);
void gpio_port_c_alternate_function_uart_3(void);
void gpio_port_c_clock_gating_control_uart_3(void);

void initialization_uart_3(void);
void initialize_module_uart_3(void);
void initialize_gpio_port_uart_3(void);
void transmit_data_uart_3(char data);
char receive_data_uart_3(void);
void initialize_receive_interrupt_uart_3(void);
void disable_control_uart_3(void);
void user_switch_1_vertical_signal_uart_3(void);
void user_switch_2_horizontal_signal_uart_3(void);
void uart_clock_gating_control_uart_3(void);	
void gpio_port_c_clock_gating_control_uart_3(void);
void mcu_rx_uart3(void);
void line_control_uart_3(void);
void fractional_baud_rate_divisor_uart_3(void);
void interger_baud_rate_divisor_uart_3(void);
void baud_clock_source_uart_3(void);
void enable_control_uart_3(void);
void clock_gating_control_uart_3(void);

// * 
// *  Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

// Constants
#define INTERRUPT_SET_ENABLE_REGISTER_GPIO_PORT_F_BIT_30	0x40000000
#define GPIO_PORT_F_PIN_4	0x00000010
#define GPIO_PORT_F_PIN_0	0x00000001
#define GPIO_PORT_F_ENABLE_CLOCK 0x00000020

// Protocols of functions
void unlock_gpio_port_f_pin_0(void);
void initialize_user_switch_1(void);
void gpio_port_f_clock(void);
void interrupt_set_enable_register(void);
void gpio_port_f_direction(void);
void gpio_port_f_pullup(void);
void gpio_port_f_digital(void);
void gpio_port_f_interrupt_sense(void);
void gpio_port_f_interrupt_both_edges(void);
void gpio_port_f_interrupt_event(void);
void gpio_port_f_interrupt_mask(void);
void gpio_port_f_interrupt_clear(void);






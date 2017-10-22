// *
// Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

// Constants
#define PWM_MODULE_1_CLOCK_ENABLE	0x00000002 
#define GPIO_PORT_D_CLOCK_ENABLE	0x00000008
#define GPIO_PORT_D_PIN_0_ALTERNATE_FUNCTION_ENABLE	0x00000001
#define GPIO_PORT_D_PIN_0_ANALOG_FUNCTION_DISABLE	0x00000001
#define GPIO_PORT_D_PIN_0_DIGITAL_FUNCTION_ENABLE	0x00000001
#define GPIO_PORT_D_PIN_0_DIRECTION_OUTPUT	0x00000001
#define GPIO_PORT_D_PIN_0_PERIPHERAL_PWM	0x00000005	
#define PWM_CLOCK_DIVIDER_SOURCE	0x00100000
#define PWM_UNIT_CLOCK_DIVISOR_64_DIVISOR_VALUE	0x00500000
#define PWM_BLOCK_DISABLE	0x00000000
#define PWMA_SIGNAL_LOAD_HIGH_CMPA_LOW 0x0000008C

#define PWM_15623_CLOCK_TICKS_PER_20ms_PERIOD 0x00003D07
#define PWM_13588_COMPARATOR_VALUE_SERVO_VERTICAL 0x3514
#define PWM_14437_COMPARATOR_VALUE_SERVO_HORIZONTAL 0x3865
#define PWM_BLOCK_ENABLE	0x00000001
#define M1PWM0_OUTPUT_ENABLE 0x00000001

// Protocols of functions
void pwm_initialization(void);
int return_comparator(void);
void pulse_width_modulator_peripheral_ready(void);
void enable_pwm_clock(void);
void enable_gpio_clock(void);
void enable_pin_direction(void);
void enable_pin_digital(void);
void disable_analog_function(void);
void enable_pin_alternate_function(void);
void select_pwm_peripheral(void);
void enable_pwm_divide_divider(void);
void configure_pwm_generator_countdown(void);
void set_period(void);
void set_comparator(int x);
void start_timer(void);
void enable_pwm_output(void);
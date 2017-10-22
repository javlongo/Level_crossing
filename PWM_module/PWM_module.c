// *
// Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

#include "TM4C123GH6PM.h"
#include "PWM_module.h"


int comparator;

void pwm_initialization(void){
	
	enable_pwm_clock();
	enable_gpio_clock();
	enable_pin_alternate_function();
	select_pwm_peripheral();
	pulse_width_modulator_peripheral_ready(); 
	enable_pwm_divide_divider();
	configure_pwm_generator_countdown();
	enable_pin_direction();
	enable_pin_digital();
	disable_analog_function();
	set_period();
	start_timer();
	enable_pwm_output();
}

void pulse_width_modulator_peripheral_ready(void){
	while((SYSCTL->PRPWM & PWM_MODULE_1_CLOCK_ENABLE)==0);
}

void enable_pwm_clock(void){ 
		SYSCTL->RCGCPWM |= PWM_MODULE_1_CLOCK_ENABLE;
}

void enable_gpio_clock(void){
	SYSCTL->RCGCGPIO |= GPIO_PORT_D_CLOCK_ENABLE;
}

void enable_pin_alternate_function(void){
	GPIOD->AFSEL |= GPIO_PORT_D_PIN_0_ALTERNATE_FUNCTION_ENABLE;
}

void disable_analog_function(void){
	GPIOD->AMSEL &= GPIO_PORT_D_PIN_0_ANALOG_FUNCTION_DISABLE;
}

void enable_pin_digital(void){
	GPIOD->DEN |= GPIO_PORT_D_PIN_0_DIGITAL_FUNCTION_ENABLE;
}

void enable_pin_direction(void){
	GPIOD->DIR |= GPIO_PORT_D_PIN_0_DIRECTION_OUTPUT;
}

void select_pwm_peripheral(void){
	GPIOD->PCTL |= GPIO_PORT_D_PIN_0_PERIPHERAL_PWM;
}

void enable_pwm_divide_divider(void){
	SYSCTL->RCC |= PWM_CLOCK_DIVIDER_SOURCE;
	SYSCTL->RCC |= PWM_UNIT_CLOCK_DIVISOR_64_DIVISOR_VALUE;
}

void configure_pwm_generator_countdown(void){
	
	PWM1->_0_CTL = PWM_BLOCK_DISABLE;
	PWM1->_0_GENA = PWMA_SIGNAL_LOAD_HIGH_CMPA_LOW;
}

void set_period(void){
	PWM1->_0_LOAD = PWM_15623_CLOCK_TICKS_PER_20ms_PERIOD;
}

void set_comparator(int x){
	PWM1->_0_CMPA = x;
	comparator = x;
}

int return_comparator(void){
	return comparator;
}


void start_timer(void){
	PWM1->_0_CTL = PWM_BLOCK_ENABLE;
}

void enable_pwm_output(void){
	PWM1->ENABLE = M1PWM0_OUTPUT_ENABLE;
}



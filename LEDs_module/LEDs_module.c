
#include "TM4C123GH6PM.h"
#include "LEDs_module.h"

int delay;

void leds_initialization(void){
	enable_por_f_clock();
	set_direction_port_f_pins_1_2_3();
	set_digital_port_f_pins_1_2_3();
	set_pullup_port_f_pins_1_2_3();
}
void enable_por_f_clock(void){
	SYSCTL->RCGCGPIO |= ENABLE_CLOCK_PORT_F_PIN_5;
}

void set_direction_port_f_pins_1_2_3(void){
	GPIOF->DIR |= PORT_F_PINS_1_2_3;
}

void set_digital_port_f_pins_1_2_3(void){
	GPIOF->DEN |= PORT_F_PINS_1_2_3;
}

void set_pullup_port_f_pins_1_2_3(void){
	GPIOF->PUR |= PORT_F_PINS_1_2_3;
}

void turn_on_red_led(void){
	GPIOF->DATA |= RED_LED;
}

void turn_off_red_led(void){
	GPIOF->DATA &= ~RED_LED;
}

void turn_on_blue_led(void){
	GPIOF->DATA |= BLUE_LED;
}

void turn_off_blue_led(void){
	GPIOF->DATA &= ~BLUE_LED;
}
	
void turn_on_green_led(void){
	GPIOF->DATA |= GREEN_LED;
}

void turn_off_green_led(void){
	GPIOF->DATA &= ~GREEN_LED;
}
	
void red_blue_green_sequence(void){
	
		turn_on_red_led();
		for(delay = 0; delay < 1000000; delay++);
		turn_off_red_led();
		for(delay = 0; delay < 1000000; delay++);
		turn_on_blue_led();
		for(delay = 0; delay < 1000000; delay++);
		turn_off_blue_led();
		for(delay = 0; delay < 1000000; delay++);
		turn_on_green_led();
		for(delay = 0; delay < 1000000; delay++);
		turn_off_green_led();
		for(delay = 0; delay < 1000000; delay++);

}

void turn_off_all_leds(void){
	turn_off_red_led();
	turn_off_blue_led();
	turn_off_green_led();
}

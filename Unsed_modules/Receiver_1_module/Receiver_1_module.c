#include "UART_module\UART_module.h"
#include "LEDs_module\LEDs.h"
#include "PWM_module\PWM_module.h"

int main(void){
	uart_initialization();
	pwm_initialization();

}
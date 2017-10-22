#include "UART_receiver_module_3\UART_receiver_module_3.h"
#include "PWM_module\PWM_module.h"

int main(void){
	pwm_initialization();
	initialization_uart_3();
	initialize_receive_interrupt_uart_3();

while(1);
}
	
	
#include "Switch_1_module\Switch_1_module.h"
#include "UART_sender_module\UART_sender_module.h"
#include "UART_sender_module_3\UART_sender_module_3.h"

int main(void){
	
	initialize_user_switch_1();
	initialization_uart_3();

	while(1);
}

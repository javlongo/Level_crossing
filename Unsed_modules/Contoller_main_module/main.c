#include "TM4C123GH6PM.h"
#include "Switch_1_module\Switch_1_module.h"
#include "UART_module\UART_module.h"

int main(void){
	
	uart_initialization();
	initialize_user_switch_1();
	
	while(1);

}
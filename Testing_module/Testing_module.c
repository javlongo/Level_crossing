// *
// * Copyright (C) 2017 Javier E. Longo. All rights reserved.
// *

// Sender headers
#include "TM4C123GH6PM.h"
#include "Switch_1_module\Switch_1_module.h"
#include "UART_sender_module\UART_sender_module.h"
#include "UART_sender_module_3\UART_sender_module_3.h"

// Receiver headers
#include "UART_receiver_module_3\UART_receiver_module_3.h"
#include "UART_receiver_module\UART_receiver_module.h"
#include "PWM_module\PWM_module.h"

#include "Testing_module.h"
#include "LEDs_module\LEDs_module.h"

// Working sender/receiver configuration using 
// UART 4 and UART 3



int ack_uart_3 = 0;
int ack_uart_4 = 0;
char response_uart_3 = 'z';
char response_uart_4 = 'z';
int multiple_sends;
int wait;

int main(void){
	

	
//	Sender

	initialize_user_switch_1();
	uart_initialization();
	initialization_uart_3();
	leds_initialization();


//	Receiver uart 4

//	uart_initialization();
//	pwm_initialization();
//	initialize_uart4_receive_interrupt();
	
	
// 	Receiver uart 3
//	
//	initialization_uart_3();
//	pwm_initialization();
//	initialize_receive_interrupt_uart_3();


	
	while(1){	
		
		// Sender
		
		response_uart_3 = receive_data_uart_3();
		response_uart_4 = receive_data_uart4();
		
		if((response_uart_4 =='v')&&(response_uart_3 =='v')){
			turn_off_all_leds();
			turn_on_green_led();
		}
		
		else if((response_uart_4 =='h')&&(response_uart_3 =='h')){
			turn_off_all_leds();
			turn_on_red_led();
		}
		
		else{
			turn_off_all_leds();
			turn_on_blue_led();
		}
		
		
		
		
// 		Receiver UART 3
		
//		ack_uart_3 = get_ack_uart_3();
//		
//		if (ack_uart_3 == 2){
//				for(multiple_sends = 0; multiple_sends <10; multiple_sends++){
//					transmit_data_uart_3('v');
//				}	
//		}
//		if (ack_uart_3 == 3){
//			for(multiple_sends = 0; multiple_sends <10; multiple_sends++){
//				transmit_data_uart_3('h');
//			}
//		}	



	
// 		Receiver UART 4
//		
//		ack_uart_4 = get_ack_uart_4();
//		
//		if (ack_uart_4 == 2){
//				for(multiple_sends = 0; multiple_sends <10; multiple_sends++){
//					transmit_data_uart4('v');
//				}	
//		}
//		if (ack_uart_4 == 3){
//			for(multiple_sends = 0; multiple_sends <10; multiple_sends++){
//				transmit_data_uart4('h');
//			}
//		}		
//		
		
		

	}	// End while


}	// End main



// Receiver UART 3 functions

//	void set_ack_uart_3(int i){
//		ack_uart_3 = i;
//	}

//	int get_ack_uart_3(void){
//		return ack_uart_3;
//	}



// Receiver UART 4 functions

//	void set_ack_uart_4(int i){
//		ack_uart_4 = i;
//	}

//	int get_ack_uart_4(void){
//		return ack_uart_4;
//	}


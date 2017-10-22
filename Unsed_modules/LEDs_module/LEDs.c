#include "TM4C123GH6PM.h"
#include "LEDs.h"

void initialize_leds(void){
	
	// Initialize on board LEDs
	
	GPIOF->DIR |= (0x01<<3)|(0x01<<2)|(0x01<<1);
	GPIOF->DEN |= (0x01<<3)|(0x01<<2)|(0x01<<1);
	GPIOF->DATA &= ~(0x01<<1);
	GPIOF->DATA &= ~(0x01<<2);
	GPIOF->DATA &= ~(0x01<<3);	
	
}
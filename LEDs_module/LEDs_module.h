#define ENABLE_CLOCK_PORT_F_PIN_5	0x20
#define PORT_F_PINS_1_2_3	0x0E
#define RED_LED	0x02
#define BLUE_LED	0x04
#define GREEN_LED	0x08

void leds_initialization(void);
void enable_por_f_clock(void);
void set_direction_port_f_pins_1_2_3(void);
void set_digital_port_f_pins_1_2_3(void);
void set_pullup_port_f_pins_1_2_3(void);
void turn_on_red_led(void);
void turn_off_red_led(void);
void turn_on_blue_led(void);
void turn_off_blue_led(void);
void turn_on_green_led(void);
void turn_off_green_led(void);
void red_blue_green_sequence(void);
void turn_off_all_leds(void);
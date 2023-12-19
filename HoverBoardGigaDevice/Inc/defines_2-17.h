#ifdef MASTER_OR_SINGLE		// layout 2.2 and 2.7 have buzzer on the slave board.
	#define HAS_BUZZER
#endif

/* GD32F130 48pin possible IO pins: 
	C13 C14 C15 F0 F1 A0 A1 A2 
	A3 A4 A5 A6 A7 B0 B1 B2 B10 B11
	B12 B13 B14 B15 A8 A9 A10 A11 A12 A13 F6 F7
	A14 A15 B3 B4 B5 B6 B7 B8 B9 
	
	mostly used for 6 BLDC mosfet pins: B13 B14 B15 A8 A9 A10
	mostly used for USART0: B6 B7
	mostly used for USART1: A2 A3
	ST-Flash pins: A13 A14 (also used as green and red led on 2.2)
	
	so mostly available for other use:	
	C13 C14 C15 F0 F1 A0 A1 A4 A5 A6 A7 B0 B1 B2 B10 B11 B12 A11 F6 F7 A12 A15 B3 B4 B5 B8 B9 
	so available for analog input:
	A0 A1 A2 A3 A4 A5 A6 A7 B0 B1 	
*/

#define TODO_PIN PF4	// PF4 is only accessible on the largest GD32F130Rx LQFP64 pinouts mcu

// LED defines
// For this layout, Master has no LEDs
#define LED_ORANGE TODO_PIN	//PA15	// ORANGE LED 
#define LED_GREEN TODO_PIN	//PB3	  // GREEN LED
#define LED_RED TODO_PIN	//PB4			// RED LED

#define UPPER_LED	TODO_PIN	//PB5			// LED 
#define LOWER_LED	TODO_PIN	//PC13	// IN THE AIR


// Mosfet output, little onboard led
#define MOSFET_OUT	TODO_PIN	//<<<<<<<<<<<<-----------??????????????

// Brushless Control DC (BLDC) defines
#define BLDC_GH PA10		// green	, all bldc pins same as 2.0
#define BLDC_GL PB15		
#define BLDC_BH PA9			// blue 
#define BLDC_BL PB14		
#define BLDC_YH PA8			// yellow
#define BLDC_YL PB13		
#define TIMER_BLDC_PULLUP	GPIO_PUPD_NONE	// robo: not sure if some boards indeed nned GPIO_PUPD_PULLUP like 2.2 or 2.3


// Timer BLDC short circuit emergency shutoff define
#define TIMER_BLDC_EMERGENCY_SHUTDOWN	TODO_PIN

// Hall sensor defines
#define HALL_A	PF1		  // Confirmed AndyShmandy 12/19/2023
#define HALL_B	PA0     // Confirmed AndyShmandy 12/19/2023
#define HALL_C	PC15    // Confirmed AndyShmandy 12/19/2023

// GD32F130 USART0 TX/RX:	(PA9/PA10)AF1	, (PB6/PB7)AF0 , 	(PA2/PA3)AF1 , (PA14/PA15)AF1 GD32F130x4 only!
#define HAS_USART0	// uncomment if this layout has a usart0
#ifdef HAS_USART0
	#define USART0_TX	PB6
	#define USART0_RX	PB7
	
	//#define USART0_MASTERSLAVE		// uncomment if this usart is used for master-slave communication
	#define USART0_REMOTE						// uncomment if this usart is used for optional remote control
#endif

// GD32F130 USART1 GD32F130 TX/RX: (PA14/PA15)AF1 , (PA2,PA3)AF1	, (PA8/PB0)AlternateFunction4
//#define HAS_USART1	// uncomment if this layout has a usart1
#ifdef HAS_USART1
	#define USART1_TX		PA2
	#define USART1_RX		PA3
	
	#define USART1_MASTERSLAVE		// uncomment if this usart is used for master-slave communication
	//#define USART1_REMOTE				// uncomment if this usart is used for optional remote control
#endif

// ADC defines
#define VBATT	TODO_PIN	//PA5??				
#define CURRENT_DC	TODO_PIN		

// Self hold defines
#define SELF_HOLD	PC13  // Confirmed AndyShmandy 12/19/2023

// Button defines
#define BUTTON	 PB2 		// Confirmed AndyShmandy 12/19/2023

#ifdef HAS_BUZZER
	// Buzzer defins
	#define BUZZER	TODO_PIN //PC14
#endif

#ifdef MASTER
	// Charge state defines
	#define CHARGE_STATE	PF0	// todo
#endif

// Debug pin defines -  no longer has any function in code !
#define DEBUG_PIN TODO_PIN
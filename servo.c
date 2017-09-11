#include"tbw.h"
void init_servo()
{
	//set OC1A FOR generating PWM
	sbi(DDRB,PB1);
	cbi(PORTB,PB1);

	//SELECT MODE:
	//fast PWM: (with top = ICR1 & update its value @ BOTTOM , TOV flag set on TOP)
	sbi(TCCR1A,WGM11);
	cbi(TCCR1A,WGM10);
	sbi(TCCR1B,WGM13);
	sbi(TCCR1B,WGM12);
	// inverting mode : to control on servo motion @ last 2ms in period
	sbi(TCCR1A,COM1A0);
	sbi(TCCR1A,COM1A1);

	//PRECALING (8):(to have 40000 cycle per second which means that every ms has 2000 cycles)
	sbi(TCCR1B,CS11);
	//sbi(TCCR1B,CS10);
	//setting top value equal 39999 @which starting a new clock
	ICR1=39999;
}
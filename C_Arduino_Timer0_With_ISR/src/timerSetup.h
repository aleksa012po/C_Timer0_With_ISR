/*
 * timerSetup.h
 *
 * Created: 24.11.2022. 10:11:49
 *  Author: Aleksandar Bogdanovic
 */ 


#ifndef TIMERSETUP_H_
#define TIMERSETUP_H_


void timerSetup() {
	TCCR0A = (1 << WGM01);						// TCCR0A = 0b00000010
	OCR0A = 156;
	TIMSK0 = (1 << OCIE0A);						// TIMSK0 = 0b00000010, OCIE0A: Timer/Counter0 Output Compare Match A Interrupt Enable
	
	sei();										// Sets the I bit, external interrupt enable
	
	TCCR0B = (1 << CS02) | (1 << CS00);			// TCCR0B = 0b00000101 - prescaler clk/1024
}


#endif /* TIMERSETUP_H_ */

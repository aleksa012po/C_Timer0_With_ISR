/*
 * C_Arduino_Asembler_Timers.c
 *
 * Created: 24.11.2022. 08:35:51
 * Author : Aleksandar Bogdanovic
 */ 

// Arduino Asembler, Tajmeri. Proci tajmere koriscenjem interapt-a
// 8 bit Timer - 256 clock cycles
// TCCR0A – Timer/Counter Control Register A
// TCCR0B – Timer/Counter Control Register B
// TIMSK0 – Timer/Counter Interrupt Mask Register
// Real time 0.01 sek, total timer ticks 156.25, freq 100Hz, delay 500ms, clk 16MHz

#define F_CPU 16000000							// 16MHz

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "init.h"
#include "timerSetup.h"

int extraTime = 0;

int main(void)
{	
	init();
	timerSetup();	
    while (1) 
    {
		// Loop
    }
}

ISR(TIMER0_COMPA_vect) {
	extraTime++;
	if(extraTime > 255) {
		PORTB ^= (1 << PORTB0);
		_delay_ms(500);
	}
}

#include "task3.h"
#include <Arduino.h>
#include <avr/interrupt.h>

void task_3_setup(void)
{
  DDRB |= (1 << PB1); //led set as output

  DDRD &= ~(1 << PD2); //button set as input
  PORTD |= (1 << PD2); //button pull-up

  EICRA = (EICRA | (1 << ISC01)) & ~(1 << ISC00); //falling edge

  EIMSK |= (1 << INT0);

  sei();
}

ISR(INT0_vect)
{
  PORTB ^= (1 << PB1); //toggle led
}
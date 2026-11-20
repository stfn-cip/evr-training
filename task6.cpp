#include <Arduino.h>
#include "task6.h"

uint16_t readADC(void)
{
  ADCSRA |= (1 << ADSC);
  while(ADCSRA & (1 << ADSC));
  return ADC;
}

void task_6_setup(void)
{
  DDRC &= ~(1 << PC0);
  PORTC &= ~(1 << PC0);
  DDRB |= (1 << PB3);

  //ADC
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  ADMUX = (1 << REFS0);
  
  //Timer2
  TCCR2A = (1 << COM2A1) | (1 << COM2A0) | (1 << WGM21) | (1 << WGM20);
  TCCR2B = (1 << CS22);

}

void task_6(void)
{
  OCR2A = readADC() >> 2;
  
}
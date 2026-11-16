#include <stdint.h>
#include <Arduino.h>
#include "task1.h"

volatile static int l = 0;

void task_1_setup(void)
{
  TCCR1A = 0;

  OCR1A = 62499; //TOP value

  TIMSK1 = (1 << OCIE1A); //output compare A match interrupt enable

  TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10); //CTC mode + 64 prescaler
}

void task_1(void) {
    if(l == 0)
      PORTD &= ~((1 << PD3) | (1 << PD4) | (1 << PD5));
    else if(l == 1)
      PORTD |= (1 << PD3);
    else if(l == 2)
      PORTD |= (1 << PD4);
    else if(l == 3)
      PORTD |= (1 << PD5);
}

ISR(TIMER1_COMPA_vect)
{
  l++;
  if(l > 3) l = 0;
}

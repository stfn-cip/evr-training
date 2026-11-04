#include "task3.h"

void task_3_setup(void)
{
  DDRB |= (1 << DDRB1);

  DDRD &= ~(1 << DDD2);
  PORTD |= (1 << PORTD2);

  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);

  EIMSK |= (1 << INT0);

  
}
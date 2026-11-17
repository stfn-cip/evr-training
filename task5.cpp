#include <Arduino.h>
#include "task5.h"

//uses Timer0 8 bit

static volatile int16_t duty = 0;
static volatile int8_t step = 1;
static volatile int8_t counter = 0;

void task_5_setup(void)
{
  DDRD |= (1 << PD5);

  TCCR0A = (1 << WGM01) | (1 << WGM00) | (1 << COM0B1); //Mode 7 FastPWM and Compare Output Mode;

  OCR0A = 249;

  TIMSK0 = (1 << OCIE0A); //overflow interrupt enable

  OCR0B = duty;

  TCCR0B = (1 << CS01) | (1 << CS00) | (1 << WGM02); //prescaler set to 64 and Mode 7 FastPWM
}

ISR(TIMER0_COMPA_vect)
{
  if(counter == 0)
  {
    if(duty + step < 0 || duty + step > 249)
      step *= -1;
    duty += step;
    OCR0B = duty;
  }
  counter++;
  counter = counter % 8;
}
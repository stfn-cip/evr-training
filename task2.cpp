#include <Arduino.h>
#include "task2.h"

static bool prev = false;
static uint8_t led = 0;

bool readBtn(void)
{
  return !(PINB & (1 << PB0));
}

void task_2(void)
{
  bool now = readBtn();

  if(now && !prev)
    led = (led + 1) % 2;

  prev = now;

  if(!led)
  {
    PORTD |= (1 << PORTD6);
    PORTD &= ~(1 << PORTD7);
  } else {
    PORTD &= ~(1 << PORTD6);
    PORTD |= (1 << PORTD7);
  }
}
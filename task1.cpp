#include <stdint.h>
#include <Arduino.h>
#include "task1.h"

static int l = 0;

void task_1(void) {
  static uint32_t prev = 0;
  
  if(millis() - prev >= 500)
  {
    if(l > 3) l = 0;

    if(l == 0)
      PORTD &= ~((1 << PORTD3) | (1 << PORTD4) | (1 << PORTD5));
    else if(l == 1)
      PORTD |= (1 << PORTD3);
    else if(l == 2)
      PORTD |= (1 << PORTD4);
    else if(l == 3)
      PORTD |= (1 << PORTD5);

    l++;
    
    prev = millis();
  }
}

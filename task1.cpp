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
      PORTD &= ~((1 << PD3) | (1 << PD4) | (1 << PD5));
    else if(l == 1)
      PORTD |= (1 << PD3);
    else if(l == 2)
      PORTD |= (1 << PD4);
    else if(l == 3)
      PORTD |= (1 << PD5);

    l++;
    
    prev = millis();
  }
}

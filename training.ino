#include "task1.h"
#include "task2.h"

volatile uint32_t i = 0;

void setup() {
  DDRD = (1 << DDD5) | (1 << DDD4) | (1 << DDD3) | (1 << DDD6) | (1 << DDD7);
  DDRB &= ~(1 << DDB0);
  PORTB |= (1 << PORTB0);
  Serial.begin(9600);
}

void loop() {
  task_1();
  task_2();

  // while(i <= 300000)
  //   i++;
  // i=0;
}
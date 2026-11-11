#include "task1.h"
#include "task2.h"
#include "task3.h"

volatile uint32_t i = 0;

void setup() {
  DDRD = (1U << PD5) | (1U << PD4) | (1U << PD3) | (1U << PD6) | (1U << PD7);
  DDRB &= ~(1 << PB0);
  PORTB |= (1 << PB0);
  task_3_setup();
  Serial.begin(9600);
}

void loop() {
  task_1();
  task_2();

  // while(i <= 300000)
  //   i++;
  // i=0;
}
#include "avr/io.h"
#include "avr/interrupt.h"

int main()
{
  DDRD &= ~(1 << PD2);

  DDRB |= (1 << PB5);


  EIMSK |= (1 << INT0);

  EICRA |= (1 << ISC00);
  EICRA |= (1 << ISC01);

  sei();

  while(1);
}

ISR (INT0_vect)
{
  PORTB ^= (1 << PB5);
}

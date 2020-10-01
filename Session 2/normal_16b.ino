// fo ~ 1hz
// with 16bit timer
int main() {
cli();
DDRB |= 1 << PB5;
TCCR1B |= (1 << CS12) | (0 << CS10); //256 ps
TIMSK1 |= 1 << TOIE1;
sei();
while (1);
return 0;
}

ISR(TIMER1_OVF_vect) {
PORTB ^= (1 << PB5);
}
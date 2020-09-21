#include <avr/io.h>
#include <util/delay.h>

int main(void) {
// -------- Inits --------- //
DDRB = 0b00011111; /* Set up the 5 pins of LED pins for output */
// ------ Event loop ------ //
while (1) { /* mainloop */
PORTB=(0b00010001);
_delay_ms(20);
PORTB=(0b00011001);
_delay_ms(20);
PORTB=(0b00010101);
_delay_ms(20);
PORTB=(0b00010011);
_delay_ms(20);
PORTB=(0b00010001);
_delay_ms(20);

PORTB = 0;
_delay_ms(50);
} /* end mainloop */
return (0);
}

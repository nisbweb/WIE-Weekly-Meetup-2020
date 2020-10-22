#include <avr/io.h>
#include<util/delay.h>
void init_ports()
{
 DDRC = 0b00000000;//i/p
 DDRB = 0xff;//o/p
 PORTB = 0xff;
}
void ADC_init()
{
 ADCSRA |= (1<<ADEN)| (1<<ADPS2); // enable and prescaler
 ADMUX = (1<<REFS0); // Reference volt
}
int get_resist()
{
 _delay_ms(10);
 ADCSRA |= (1<<ADSC);
 while(ADCSRA & (1<<ADSC)); //0b10101100 & 0b00000000
 _delay_ms(10);
 return(ADC); //result
}
int main(void)
{

 init_ports(); //initialize ports
 ADC_init();
while (1)
 {
 
 if(get_resist() > 256 )
 {
 PORTB = 0x00;
 }
 else
 {
 PORTB = 0xff;
 }

#include<stdint.h>
#define HIGH 1
#define LOW 0
volatile uint8_t* ddr[11] = { // ddr is a data direction register used to define as input or ouptut
	(volatile uint8_t *)0x21, //
	(volatile uint8_t *)0x24, 
	(volatile uint8_t *)0x27, 
	(volatile uint8_t *)0x2a, 
	(volatile uint8_t *)0x2d, 
	(volatile uint8_t *)0x30,
	(volatile uint8_t *)0x33, 
	(volatile uint8_t *)0x101, 
	(volatile uint8_t *)0x104,
	(volatile uint8_t *)0x107, 
	(volatile uint8_t *)0x10a 
};
volatile uint8_t* port[11] = {  // data register 
	(volatile uint8_t *)0x22, 
	(volatile uint8_t *)0x25,
	(volatile uint8_t *)0x28, 
	(volatile uint8_t *)0x2b, 
	(volatile uint8_t *)0x2e, 
	(volatile uint8_t *)0x31, 
  (volatile uint8_t *)0x34,
	(volatile uint8_t *)0x102, 
	(volatile uint8_t *)0x105,
	(volatile uint8_t *)0x108,
	(volatile uint8_t *)0x10b 
};
volatile uint8_t* pin_in[11] = {  // input register
	(volatile uint8_t *)0x20, 
	(volatile uint8_t *)0x23,
	(volatile uint8_t *)0x26,
	(volatile uint8_t *)0x29, 
	(volatile uint8_t *)0x2c, 
	(volatile uint8_t *)0x2f, 
	(volatile uint8_t *)0x32, 
	(volatile uint8_t *)0x100,
	(volatile uint8_t *)0x103, 
	(volatile uint8_t *)0x106, 
	(volatile uint8_t *)0x109 
};
// GPIO WRITE 

void gpio_write(unsigned char portnum, uint8_t pinnum,unsigned char value)
{
    if(value == HIGH)
    {
        *port[portnum] |= (1 << pinnum);
    }
    else
    {
        *port[portnum] &= ~(1 << pinnum);
    }
}


//PIN MODE                                          
void pinmode(unsigned char portnum,uint8_t pinnum,unsigned char mode){
  if(mode==1){
    *ddr[portnum] |=(1<<pinnum);
  }
  else{
     *ddr[portnum] &= ~(1 << pinnum);
  }}
// read mode 
  uint8_t gpio_read(uint8_t portnum, uint8_t pinnum)
{
    if(*pin_in[portnum] & (1 << pinnum))
    {
        return HIGH;
    }
    else
    {
        return LOW;
    }
}
// toggle 
void gpio_toggle(uint8_t portnum, uint8_t pinnum)
{
    *port[portnum] ^= (1 << pinnum);
}
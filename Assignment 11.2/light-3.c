#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main(){
  uint16_t light;
  init_peri();
  while(1){
    light = read_adc(PC4);
    if(light > 800)
      set_led_value(0b100);
    else if(light > 600)
      set_led_value(0b010);
    else
      set_led_value(0b001);

  }
}

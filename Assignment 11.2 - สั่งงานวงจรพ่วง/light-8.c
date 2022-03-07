#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main(){
  uint16_t light;
  init_peri();
  int theshold[] = {};
  while(1){
    light = read_adc(PC4);
    //for(int i=0;i<8;i++){
    //if(light < 400+(50*i)){
    //set_led_value(i);
    //break;
    //}
    //}
    if(light > 800)
          set_led_value(0b111);
    else if(light > 750)
          set_led_value(0b110);
    else if(light > 700)
          set_led_value(0b101);
    else if(light > 650)
          set_led_value(0b100);
    else if(light > 600)
          set_led_value(0b011);
    else if(light > 550)
          set_led_value(0b010);
    else if(light > 500)
          set_led_value(0b001);
    else
          set_led_value(0b000);
  }
}

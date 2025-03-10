#include <16f887.h>
#define motor_en pin_c7
#define echo pin_a6
#define trigger pin_a7
#define led pin_c0
#use delay(clock = 20MHz)
#fuses HS

float distance, time;
int16 xung, KQ; 

void trigger_pulse()
{
   output_high(trigger);
   delay_us(100);
   output_low(trigger);
}

void get_distance()
{
   set_timer1(0);
   while(!input(echo));
   setup_timer_1(T1_Internal | T1_DIV_BY_4);          // ( Focs = 20MHz ) chia truoc 4 = 5Mhz
                                                      // => 1us thi` TMR d�m 0.8 l�`n (Prescaler = 4)
                                                      //=> TMR * 0.8 = t (us)
                                                      //d = t / 58
                                                      //=> d = (TMR*0.8)/58
   while(input(echo));
   setup_timer_1(T1_Disabled);
   time=xung*0.8;
   distance = (time/58);
}

void main()
{
   setup_timer_1(T1_Disabled);
   while(true)
   {
   trigger_pulse();
   get_distance();
   KQ = (unsigned int16) distance;
   if(KQ<5) output_high(led);
   else if (KQ>5) output_low(led);
   }
}


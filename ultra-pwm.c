
#define motor_en pin_c7
#define echo pin_c3
#define trigger pin_c4
#define led pin_c0
#fuses HS

float distance, time;
int16 xung; 

void get_distance()
{ 
   output_high (trigger);
   delay_us(20);
   output_low (trigger); 
   set_timer1(0);
   while(!input(echo));
   setup_timer_1(T1_Internal | T1_DIV_BY_4);  // ( Focs = 20MHz ) chia truoc 4 = 5Mhz
                                                      // => 1us thi` TMR d?m 0.8 l?`n (Prescaler = 4)
    //=> TMR * 0.8 = t (us)
                                                      //d = t / 58
                                                      //=> d = (TMR*0.8)/58
   while(input(echo));
   xung = get_timer1();
   setup_timer_1(T1_Disabled);
   time=xung*0.8;
   distance = (time/58.2);
}

void ultra()
{
         set_tris_c(0x00);
   set_tris_d(0x00);       set_tris_e(0x00);
   setup_ccp1(ccp_pwm);
   setup_ccp2(ccp_pwm);
   setup_timer_2(t2_div_by_16,249,1);
   set_pwm1_duty(0);    set_pwm2_duty(0);
   output_high(motor_en); 
   delay_ms(100);

    
   while(true)
   { 
     get_distance();
         IF ((distance < 4))
         {
         output_high(led);
         set_pwm2_duty(1000);
         set_pwm1_duty(0);   
         delay_ms(20);
         }
         else if (distance > 4)
         {
         output_low(led);
         set_pwm1_duty(1000);
         set_pwm2_duty(0); 

         delay_ms(20);
         }
      

  break;
   }
}


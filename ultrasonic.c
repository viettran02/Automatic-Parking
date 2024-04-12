#define motor_en pin_c7
#define echo pin_c3
#define trigger pin_c4
#define led pin_c0

#fuses HS

float distance, time,f;
int16 xung; 

float get_distance(void)
{ 
   output_high (trigger);
   delay_ms(12);
   output_low (trigger); 
   while(echo ==0);
   setup_timer_1(t1_internal |T1_div_by_1);
   set_timer1(0);
   while(echo == 1);
   setup_timer_1(T1_disabled);  // ( Focs = 20MHz ) chia truoc 4 = 5Mhz
    time = get_timer1();                                                  // => 1us thi` TMR d�m 0.8 l�`n (Prescaler = 4)
    xung = (float)time/58f;     //=> TMR * 0.8 = t (us)
   distance = xung*0.2f;                                                  //d = t / 58
     return xung;                                                 //=> d = (TMR*0.8)/58
 
}

void ultra()
{
   set_tris_c(0x00);
   set_tris_d(0x00);       set_tris_e(0x00);
   setup_ccp1(ccp_pwm);
   setup_ccp2(ccp_pwm);
   setup_timer_2(t2_div_by_16,249,1);
   set_pwm1_duty(0);    set_pwm2_duty(0);
   output_high(motor_en); output_high(led);
   delay_ms(100);

  // tocdo(200); 
   while(true)
   {  
  distance = get_distance();
   
         IF ((distance> 4)&& (distance <7))
         {
         output_high(led);
         set_pwm2_duty(500);
         set_pwm1_duty(0);     delay_ms(200); 
         }
         else if (distance < 4)
         {
         output_low(led);
         set_pwm2_duty(0);
         set_pwm1_duty(500);     delay_ms(200);
         }
         else if (distance > 7)
         {
         output_high(led);
         set_pwm1_duty(0);
         set_pwm2_duty(0);
         }
   break;
   }
}


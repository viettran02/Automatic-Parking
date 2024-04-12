#INCLUDE <16F887.h>
#DEVICE ADC=10
#FUSES NOWDT, NOMCLR, NOBROWNOUT, PUT, HS, NOPROTECT, NOLVP
#use delay(clock = 20MHz)
#define motor_en pin_c7
#define trigger pin_a7
#define echo pin_a6
#define sl1 pin_a0
#define sl2 pin_a1
#define sl3 pin_a2
#define sl4 pin_a3
#include<tv_lcd.c>
#include <Danduong.c>
#include <ultra-pwm.c>
void main()
{      
   
   While(true)
   {  
      OUTPUT_C(0x01); output_b(0x00); 
      lcd_setup();
   
      while(input(sl1)) //slot 1 trong
      { checknhietdo(); free();ultra(); }    
      while(!input(sl1)) //co xe o slot 1 
      {
      slot2(); checknhietdo(); ultra();
         while(!input(sl2)) //co xe o slot 1 va 2
         {
         slot3(); checknhietdo();ultra();
         while(input(sl1)==1) slot1(); checknhietdo(); ultra(); //co xe o slot 2
         
            while(!input(sl3)) //co xe o slot 1, 2 va 3
            {
            slot4(); checknhietdo();ultra(); 
            while(input(sl2)==1) {slot2(); checknhietdo(); ultra();//co xe o slot 1 va 3
                                 while(input(sl1)==1) slot1(); checknhietdo(); ultra();} //co xe o slot 3
            while(input(sl1)==1) slot1(); checknhietdo();ultra(); //co xe o slot 2 va 3
            
               while(!input(sl4)) //co xe o slot 1, 2, 3 va 4
               {
               full(); checknhietdo();ultra();
               while(input(sl1)==1) {slot1(); checknhietdo();ultra(); } //co xe o slot 2, 3 va 4
               while(input(sl2)==1) {slot2();  checknhietdo(); ultra();//co xe o slot 1, 3 va 4
                                     while(input(sl1)==1) slot1(); checknhietdo();  ultra();} //co xe o slot 3 va 4  
               while(input(sl3)==1) {slot3(); checknhietdo(); ultra();//co xe o slot 1, 2 va 4
                                     while(input(sl2)==1) {slot2(); checknhietdo();ultra(); //co xe o slot 1 va 4
                                                           while(input(sl1)==1) slot1(); checknhietdo();ultra(); } //co xe o slot 4
                                     while(input(sl1)==1) slot1(); checknhietdo(); ultra(); } //co xe o slot 2 va 4
                                     
              }
            }
         }
      }
      }
      }
         
 
 

UNSIGNED INT16 KQADC=0;

void checknhietdo()
{      
    SETUP_ADC(ADC_CLOCK_DIV_32);
    SETUP_ADC_PORTS(SAN4);
         output_c(0x01);
         SET_ADC_CHANNEL(4); delay_ms(10);
         KQADC=READ_ADC();
         DELAY_MS(10);
         KQADC= KQADC /2.046;
      //   delay_ms(100);
    If(KQADC >= 50)
        {OUTPUT_C(0x01); DELAY_MS(200);
        OUTPUT_C(0x00); OUTPUT_B(0x00); 
        lcd_command(0x80); delay_us(10); lcd_data("!CanhBao!  "); 
        lcd_command(0xc0); delay_us(10); lcd_data("!!!!!!!!!!!!!");
        }}

void slot1()
   {
   lcd_command(0x80);delay_us(10);
   lcd_data("Welcome!  ");
   lcd_command(0xc0);delay_us(10);
   lcd_data("----> Slot1    ");  
      
   output_b(0x0f); output_low(pin_b1); output_low(pin_b2); output_low(pin_b3); output_high(pin_b4); delay_ms(300);
   //dan duong vao slot1
   }
void slot2()
   { 
   lcd_command(0x80);delay_us(10);
   lcd_data("Welcome!  ");
   lcd_command(0xc0);delay_us(10);
   lcd_data("----> Slot2   "); 
   output_low(pin_b4); output_b(0x0f); output_low(pin_b2); output_low(pin_b3); output_high(pin_b5); 
   //dan duong vao slot 2 , slot da su dung: slot 1
   }  
void slot3()
   { 
   lcd_command(0x80);delay_us(10);
   lcd_data("Welcome!  ");
   lcd_command(0xc0);delay_us(10);
   lcd_data("----> Slot3   "); 
   output_low(pin_b5); output_b(0x0f); output_low(pin_b3); output_high(pin_b6);
   //khi slot1 va slot2 co xe -> dan duong vao slot3   
   }  
void slot4()
   { 
   lcd_command(0x80);delay_us(10);
   lcd_data("Welcome!  ");
   lcd_command(0xc0);delay_us(10);
   lcd_data("----> Slot4    "); 
   output_low(pin_b6); output_b(0x0f); output_high(pin_b7); 
   //khi slot1 slot2 slot3 co xe --> dan duong vao slot 4
   }  

void full()
   {
    lcd_command(0x80);delay_us(10);
   lcd_data("Sorry!   ");
    lcd_command(0xc0);delay_us(10);
    lcd_data("No slot!     "); 
    output_b(0x00);
   }

void free()
   {
   slot1();   
   }


   

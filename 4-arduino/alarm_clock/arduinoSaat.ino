#include <LiquidCrystal.h>
#define buton1 6
#define buton2 7
#define buton3 8
#define buton4 9
#define buzzer 13
const int analogPin = A0;
float gerilimDeger = 0;
float sensorDeger = 0;
float sicaklikDeger = 0;
float fahrenheit = 0;

long buttonTimer = 0;
long longPressTime = 250;

bool buttonActive = false;
bool longPressActive = false;

bool buttonActive2 = false;
bool longPressActive2 = false;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int timer = 0;
int hour=14,min=57,sec=55;
int alarm_hour=14, alarm_min=58;
int live_alarm_hour = 14, live_alarm_min = 58;

int is_pm = 0;
int is_24_mode = 1;
long prev = 0;
int buton1State = 0;
bool is_button3_pressed = false;
bool is_button4_pressed = false;
int DURATION_IN_MILLIS = 500;


int is_clock_set_mode = 0;
int temperature_unit = 0;
bool is_snooze = false;
bool is_alarm = false;
int snooze_time = 1;


bool use_cel = true;



void setup() {
  pinMode(buton1,INPUT);
  pinMode(9,INPUT);
  lcd.begin(16,2);  
  
  TCCR0A=(1<<WGM01);     
  OCR0A=0xF9; 
  TIMSK0|=(1<<OCIE0A);   
  sei(); 
  TCCR0B|=(1<<CS01);    
  TCCR0B|=(1<<CS00);
 
}


void loop() {

    clock();
    set_clock();
    check_alarm();
    snooze();
    update_screen();
 }


void set_clock(){
  if(digitalRead(buton3)){
    if(!is_button3_pressed){
      is_button3_pressed = true;

      

        if(is_clock_set_mode == 1){
            if(min < 59){
                min++;
                
            }
            else{
                min = 0;
            }

        }
        else if(is_clock_set_mode == 2){
            if(is_24_mode){
                if(hour < 23){
                    hour++;
                    
                }
                else{
                    hour = 0;
                }
            }
            else{
                if(hour < 11){
                    hour++;
                }
                else{
                    hour = 0;
                }
            }
            
        }
        else if(is_clock_set_mode == 3){
            if(alarm_min < 59){
                alarm_min++;
            }
            else{
                alarm_min = 0;
            }
        
        live_alarm_min = alarm_min;
        }
        else if(is_clock_set_mode == 4){
            if(alarm_hour < 23){
                alarm_hour++;    
            }
            else{
                alarm_hour = 0;
            } 
        live_alarm_hour = alarm_hour; 
        }     

        


     else if(is_clock_set_mode == 0){
            if(use_cel){
                use_cel = false;
            }
            else{
                use_cel = true;
            }
        }     





    }
  }
  else{
    is_button3_pressed = false;
  }
}
void clock(){  
  if (digitalRead(buton1) == HIGH) {
        if (buttonActive == false) {
            buttonActive = true;
            buttonTimer = millis();

            if(is_clock_set_mode == 1){
                is_clock_set_mode = 2;
                }
                else if(is_clock_set_mode == 2){
                is_clock_set_mode = 0;
                }
                else{
                convert_12_24();
                }
        }
        if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {
            longPressActive = true;
            is_clock_set_mode = 1;

        }

    } else {
        if (buttonActive == true) {
            if (longPressActive == true) {
                longPressActive = false;
            } 
            buttonActive = false;
        }
    }
  

  
    if(timer>=1000){
    sec = sec+1;
    timer=0;
        }

    if(sec>59){
    min = min+1;
    sec = 0;
    }


    if(min>59){
        hour = hour+1;
        min = 0;
    }


    
    if(is_24_mode){
    if(hour>24){
        hour = 0;
        }
    }
    else{
    if(hour>12){
        hour = 0;
        if(is_pm){
            is_pm = 0;
        }
        else{
            is_pm = 1;
        }
        }
    }


    
}



float get_celsius(){
   sensorDeger = analogRead(analogPin);
   gerilimDeger = (sensorDeger/1023)*5000;
   sicaklikDeger = gerilimDeger / 9.31;
   return sicaklikDeger;
  }

 float get_fahrenheit(){
    fahrenheit = get_celsius() * 1.8000 + 32.00;
    return fahrenheit;
 }




void snooze(){
    if(digitalRead(buton4)){
        if(!is_button4_pressed){
        is_button4_pressed = true;
        

            if(min + snooze_time < 60){
                live_alarm_min = min + snooze_time;
            }
            else{
                live_alarm_hour = hour + 1;
                live_alarm_min = (min + snooze_time) - 60;
            }

            noTone(buzzer);
        }
    }
    else{
        is_button4_pressed = false;
    }
}



void toggle_alarm(){
    live_alarm_min = alarm_min;  
    live_alarm_hour = alarm_hour; 

    if(is_alarm){
        is_alarm = false;
        noTone(buzzer);
    }
    else{
        is_alarm = true;
    }
    delay(250);
}

void check_alarm(){

    if (digitalRead(buton2) == HIGH) {
        if (buttonActive2 == false) {
            buttonActive2 = true;
            buttonTimer = millis();

            if(is_clock_set_mode == 3){
                is_clock_set_mode = 4;
                }
                else if(is_clock_set_mode == 4){
                is_clock_set_mode = 0;
                }
                else{
                    toggle_alarm();
                }

        }
        if ((millis() - buttonTimer > longPressTime) && (longPressActive2 == false)) {
            longPressActive2 = true;

            is_clock_set_mode = 3;

        }
    }
        else {
        if (buttonActive2 == true) {
            if (longPressActive2 == true) {
                longPressActive2 = false;
            } 
            buttonActive2 = false;
        }
    }


    if(is_alarm){
        if(is_24_mode){
            if(live_alarm_hour == hour && live_alarm_min == min){
                tone(buzzer, 250);
            }   
        }
        else{
            if((live_alarm_hour - 12) == hour && live_alarm_min == min){
                tone(buzzer, 250);
            }  
        }
    }
}








void update_screen(){

    if(is_clock_set_mode == 1){
        lcd.setCursor(0,0);
        addzero(hour);
        lcd.print(":");

        if(sec%2 == 0){
            lcd.print("  ");
        }
        else{
            addzero(min);
        }

        lcd.print(":");
        addzero(sec);

        if(is_24_mode){
        lcd.setCursor(9,0);
        lcd.print("  ");
        }
        else{
        if(is_pm){
            lcd.setCursor(9,0);
            lcd.print("PM");
        }
        else{
            lcd.setCursor(9,0);
            lcd.print("AM");
        
        }
    }
    }
    else if(is_clock_set_mode == 2){
        lcd.setCursor(0,0);
        if(sec%2 == 0){
            lcd.print("  ");
        }
        else{
            addzero(hour);
        }

        lcd.print(":");
        addzero(min);
        lcd.print(":");
        addzero(sec);

        if(is_24_mode){
        lcd.setCursor(9,0);
        lcd.print("  ");
        }
        else{
        if(is_pm){
            lcd.setCursor(9,0);
            lcd.print("PM");
        }
        else{
            lcd.setCursor(9,0);
            lcd.print("AM");
        
        }
    
    }
    }
    else if(is_clock_set_mode == 3){
        lcd.setCursor(0,0);
        addzero(alarm_hour);
        lcd.print(":");

        if(sec%2 == 0){
            lcd.print("  ");
        }
        else{
            addzero(alarm_min);
        }

        lcd.print("      ");
    }
    else if(is_clock_set_mode == 4){
        lcd.setCursor(0,0);
        if(sec%2 == 0){
            lcd.print("  ");
        }
        else{
            addzero(alarm_hour);
        }

        lcd.print(":");
        addzero(alarm_min);

        lcd.print("      ");
    }


    else{
        lcd.setCursor(0,0);
        addzero(hour);
        lcd.print(":");
        addzero(min);
        lcd.print(":");
        addzero(sec);

         if(is_24_mode){
        lcd.setCursor(9,0);
        lcd.print("  ");
        }
        else{
        if(is_pm){
            lcd.setCursor(9,0);
            lcd.print("PM");
        }
        else{
            lcd.setCursor(9,0);
            lcd.print("AM");
        
        }
    }


    }


    
    lcd.setCursor(0,1);
    addzero(live_alarm_hour);
    lcd.print(":");
    addzero(live_alarm_min);
    

    if(is_alarm){
        lcd.setCursor(13,0);
        lcd.print("on ");
    }
    else{
        lcd.setCursor(13,0);
        lcd.print("off");
    }


    if(use_cel){
        lcd.setCursor(9,1);
        lcd.print(get_celsius());
        lcd.print("c ");
    }
    else{
        lcd.setCursor(9,1);
        lcd.print(get_fahrenheit());
        lcd.print("f");
        
    }
    

 
}


void convert_12_24(){
  if(is_24_mode){
    if(hour > 12){
      hour = hour - 12;
      is_pm = 1;
    }
    else{
      is_pm = 0;
    }
    is_24_mode = 0;
  } 
  else{
    is_24_mode = 1;
    
    if(is_pm){
      hour = hour + 12;
    }
  }
  
}



ISR(TIMER0_COMPA_vect){    
  timer++;
}

void addzero(int val){
  if(val < 10){
    lcd.print("0");
    lcd.print(val);
  }
  if(val >= 10){
    lcd.print(val);
  }
}
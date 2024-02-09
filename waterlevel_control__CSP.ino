

  #include<LiquidCrystal.h>
  LiquidCrystal disp(13,12,11,10,9,8);
  
   int trig =6;
   int echo =7;
   long timeout ; 
   float percent=0;
   int led_green =4 ;
   int led_blue =3 ;
   int led_red = 2;
   int buzz = 0;
   int motor = 5;
   void less_then_30_();
   void morethen_30_and_less_then_70_();
   void more_then_70_();
   
void setup() {
    Serial.begin(9600);
    disp.begin(16,2);
    disp.setCursor(2,0);
    disp.print("staarting the ");
    disp.setCursor(5,1);
    disp.print("system");
    delay(300);
    disp.clear();
    disp.print("*** all done ***");
    delay(300);
  
   pinMode(trig , OUTPUT);
   pinMode(echo , INPUT);
   pinMode(led_green , OUTPUT);
   pinMode(led_blue , OUTPUT);
   pinMode(led_red , OUTPUT);
   pinMode(buzz , OUTPUT);
   pinMode(motor , OUTPUT);

  }

void loop() {
  
   digitalWrite(trig,LOW);
   delayMicroseconds(2);
   digitalWrite(trig,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig,LOW);

   
   timeout=pulseIn(echo,HIGH);
   percent = (100*timeout)/65009 ;
 
  Serial.print("sensor eco signal in time= ");
  Serial.println(timeout);
  Serial.print("water purcentage= ");
  Serial.println(percent);
  disp.clear();
  disp.print("tank percentage");
  disp.setCursor(4,1);
  disp.print("= ");
  disp.print(percent);
  
  

  if(percent < 30){     // code for 0% to 30% water level
    less_then_30_();
  }
  
    if((percent > 30) && (percent < 70)){    //code for 30 to 70% water level
    morethen_30_and_less_then_70_();
  }
  
    if(percent > 70){     //code for 70 %to 100% water level
    more_then_70_();
  }
  Serial.println();
  }

//  ########################### HERE FUNCTION BODY #############################
   void less_then_30_(){
      digitalWrite(led_green,LOW);
      digitalWrite(led_blue,LOW);
      digitalWrite(led_red,HIGH);

      if(percent< 3){    // start the motor after tank is less than 3%
        disp.clear();
        disp.print("  starting the ");
        disp.setCursor(2,1);
        disp.print(" water motor ");
        delay(300);
        disp.clear();
        disp.print("tank percentage");
        disp.setCursor(4,1);
        disp.print("= ");
        disp.print(percent);
        
        digitalWrite(motor , HIGH);
        digitalWrite(buzz , HIGH);
        delay(300);
        digitalWrite(buzz,LOW);
      }
     }

          
   void morethen_30_and_less_then_70_(){
      digitalWrite(led_green,LOW);
      digitalWrite(led_blue,HIGH);
      digitalWrite(led_red,LOW);
    }

      
   void more_then_70_(){
      digitalWrite(led_green,HIGH);
      digitalWrite(led_blue,LOW);
      digitalWrite(led_red,LOW);
      
       if(percent > 97){     // stop the motor after tank is more then 97%
        disp.clear();
        disp.print("   water motor ");
        disp.setCursor(2,1);
        disp.print(" was stopped ");
        delay(300);
        disp.clear();
        disp.print("tank percentage");
        disp.setCursor(4,1);
        disp.print("= ");
        disp.print(percent);
        
        digitalWrite(motor , LOW);
        digitalWrite(buzz , HIGH);
        delay(300);
        digitalWrite(buzz,LOW);
      }
     }







   
   

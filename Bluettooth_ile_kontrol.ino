#include <SoftwareSerial.h> // bluetooth için bir kütüphanedir
SoftwareSerial bluetooth(52,50); // bluetooth pinleri

int Sag_Motor_Hizi=5;  
int Sol_Motor_Hizi=7;
int Sag_Motor_ileri=16;
int Sag_Motor_geri=17;     
int Sol_Motor_ileri=15;
int Sol_Motor_geri=14;

int on_far=53;
int arka_far=49;
int sag_sinyal=51;
int sol_sinyal=47;
int buzzer=6;
char data;
void setup() 
{
  Serial.begin(9600);           
  bluetooth.begin(9600); 
        
      pinMode(Sag_Motor_ileri,OUTPUT);
      pinMode(Sag_Motor_geri,OUTPUT);
      pinMode(Sag_Motor_Hizi,OUTPUT);      
      pinMode(Sol_Motor_ileri,OUTPUT);
      pinMode(Sol_Motor_geri,OUTPUT);
      pinMode(Sol_Motor_Hizi,OUTPUT);
      pinMode(on_far,OUTPUT);
      pinMode(arka_far,OUTPUT);
      pinMode(buzzer,OUTPUT);
}

void loop() 
{
        Serial.println(data);
        data=bluetooth.read();
       
          switch(data)
         {
          case 'F': //ileri gitme fonksiyonu
            digitalWrite(Sag_Motor_ileri,1); digitalWrite(Sag_Motor_geri,0); analogWrite(Sag_Motor_Hizi,200);
            digitalWrite(Sol_Motor_ileri,1);digitalWrite(Sol_Motor_geri,0);analogWrite(Sol_Motor_Hizi, 200);
          break;
          
          case 'B': //geri gitme fonksiyonu
            digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,1); analogWrite(Sag_Motor_Hizi, 150);
            digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,1);analogWrite(Sol_Motor_Hizi,150 ); 
          break;

          case 'L': // sola dönme fonksiyonu
            digitalWrite(Sag_Motor_ileri,1); digitalWrite(Sag_Motor_geri,0);analogWrite(Sag_Motor_Hizi, 170); 
            digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,0); analogWrite(Sol_Motor_Hizi, 0);  
          break;

           case 'R': // sağa dönme fonksiyonu
            digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,0); analogWrite(Sag_Motor_Hizi, 0);                          
           digitalWrite(Sol_Motor_ileri,1);digitalWrite(Sol_Motor_geri,0); analogWrite(Sol_Motor_Hizi,170); 
          break;

          case 'S': // durma fonksiyonu
           digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,0);analogWrite(Sag_Motor_Hizi, 0); 
           digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,0); analogWrite(Sol_Motor_Hizi, 0); 
          break;

          case 'G': // çapraz_sol_ileri fonksiyonu
            digitalWrite(Sag_Motor_ileri,1); digitalWrite(Sag_Motor_geri,0); analogWrite(Sag_Motor_Hizi, 200);
            digitalWrite(Sol_Motor_ileri,1);digitalWrite(Sol_Motor_geri,0);analogWrite(Sol_Motor_Hizi, 125); 
          break;

         case 'I': // çapraz_sağ_ileri fonksiyonu
            digitalWrite(Sag_Motor_ileri,1); digitalWrite(Sag_Motor_geri,0); analogWrite(Sag_Motor_Hizi, 125);
            digitalWrite(Sol_Motor_ileri,1);digitalWrite(Sol_Motor_geri,0);analogWrite(Sol_Motor_Hizi, 200); 
          break;

          case 'H': // çapraz_sol_geri fonksiyonu
            digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,1); analogWrite(Sag_Motor_Hizi, 200);
            digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,1);analogWrite(Sol_Motor_Hizi, 125); 
          break;
        
          case 'J': // çapraz_sağ_geri fonksiyonu
            digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,1); analogWrite(Sag_Motor_Hizi, 125);
              digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,1);analogWrite(Sol_Motor_Hizi, 200); 
          break;
          
          case 'W':
           digitalWrite(on_far,1);
          break;

          case 'w':
           digitalWrite(on_far,0);
          break;

          case 'U':
           digitalWrite(arka_far,1);
          break;

          case 'u':
           digitalWrite(arka_far,0);
          break;

          case 'V':
          digitalWrite(buzzer,1);
          break;
          
          case 'v':
          digitalWrite(buzzer,0);
          break;

          case 'X': //otomatik bir şekilde park etme fonksiyonu
          digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,1); analogWrite(Sag_Motor_Hizi, 120);
          digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,1);analogWrite(Sol_Motor_Hizi, 119);   
          delay(2500);
          digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,0); analogWrite(Sag_Motor_Hizi, 0);                          
          digitalWrite(Sol_Motor_ileri,1);digitalWrite(Sol_Motor_geri,0); analogWrite(Sol_Motor_Hizi,170);  
          delay(500);
          digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,1); analogWrite(Sag_Motor_Hizi, 120);
          digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,1);analogWrite(Sol_Motor_Hizi, 120);   
          delay(4200);             
          break;
          
          case 'x':  // "herşey bitti" fonksiyonu
           digitalWrite(Sag_Motor_ileri,0); digitalWrite(Sag_Motor_geri,0);analogWrite(Sag_Motor_Hizi, 0); 
           digitalWrite(Sol_Motor_ileri,0);digitalWrite(Sol_Motor_geri,0); analogWrite(Sol_Motor_Hizi, 0); 
           digitalWrite(on_far,1);  digitalWrite(arka_far,1);  digitalWrite( buzzer,1); delay (2000);
           digitalWrite(on_far,0);  digitalWrite(arka_far,0);  digitalWrite( buzzer,0); 
          break;          

          
         }
         
}

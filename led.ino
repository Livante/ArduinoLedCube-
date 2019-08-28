#include <Servo.h>

Servo myservo;
int rr=1, rl=0, pos=90; //rotate left, rotate left 

int p1x1x1=22, p1x1x2=23, p1x1x3=24, p1x2x1=25, p1x2x2=26, p1x2x3=27, p1x3x1=28, p1x3x2=29, p1x3x3=30;
int p2x1x1=31, p2x1x2=32, p2x1x3=33, p2x2x1=34, p2x2x2=35, p2x2x3=36, p2x3x1=37, p2x3x2=38, p2x3x3=39;
int p3x1x1=40, p3x1x2=41, p3x1x3=42, p3x2x1=43, p3x2x2=44, p3x2x3=45, p3x3x1=46, p3x3x2=47, p3x3x3=48;
int p4x1x1=49, p4x1x2=50, p4x1x3=51, p4x2x1=52, p4x2x2=53, p4x2x3=2, p4x3x1=3, p4x3x2=4, p4x3x3=5; //verifica daca sunt pinurile disponibile
int sum=0;

int trigPin=11;
int echoPin=12;
long dur,cm;

void setup() {
  //servo
  myservo.attach(9);
  
 //DISTANCE SENSOR
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 

 //LEDURI
 pinMode(p1x1x1, OUTPUT); pinMode(p1x1x2, OUTPUT); pinMode(p1x1x3, OUTPUT);
 pinMode(p1x2x1, OUTPUT); pinMode(p1x2x2, OUTPUT); pinMode(p1x2x3, OUTPUT);
 pinMode(p1x3x1, OUTPUT); pinMode(p1x3x2, OUTPUT); pinMode(p1x3x3, OUTPUT);

 pinMode(p2x1x1, OUTPUT); pinMode(p2x1x2, OUTPUT); pinMode(p2x1x3, OUTPUT);
 pinMode(p2x2x1, OUTPUT); pinMode(p2x2x2, OUTPUT); pinMode(p2x2x3, OUTPUT);
 pinMode(p2x3x1, OUTPUT); pinMode(p2x3x2, OUTPUT); pinMode(p2x3x3, OUTPUT);
 
 pinMode(p3x1x1, OUTPUT); pinMode(p3x1x2, OUTPUT); pinMode(p3x1x3, OUTPUT);
 pinMode(p3x2x1, OUTPUT); pinMode(p3x2x2, OUTPUT); pinMode(p3x2x3, OUTPUT);
 pinMode(p3x3x1, OUTPUT); pinMode(p3x3x2, OUTPUT); pinMode(p3x3x3, OUTPUT);

 pinMode(p4x1x1, OUTPUT); pinMode(p4x1x2, OUTPUT); pinMode(p4x1x3, OUTPUT);
 pinMode(p4x2x1, OUTPUT); pinMode(p4x2x2, OUTPUT); pinMode(p4x2x3, OUTPUT);
 pinMode(p4x3x1, OUTPUT); pinMode(p4x3x2, OUTPUT); pinMode(p4x3x3, OUTPUT);
}

void myinit(){
    sum=sum+1;
    for (int i=1; i<=4; i=i+1){
      
      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
    
      //
      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();  
    }
}

void pattern1(){  //DELAY BUN
      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();//grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); //grija la delay

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); //grija la delay

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); 
  }

void pattern2(){  //DELAY BUN
      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();  //grija la delay
}

void pattern3(){ //DELAY BUN

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); 
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      
      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,HIGH); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

}

void pattern4(){  //DELAY BUN

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,HIGH); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,HIGH); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,HIGH); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,HIGH); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,HIGH); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,HIGH); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

}

void pattern5(){

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
     delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,HIGH); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,HIGH); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,HIGH); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,HIGH);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,HIGH); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,HIGH);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,HIGH); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,HIGH);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,HIGH); digitalWrite(p4x1x2,HIGH); digitalWrite(p4x1x3,HIGH);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,HIGH); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,HIGH);
      digitalWrite(p1x3x1,LOW); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,LOW);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,HIGH); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,HIGH);
      digitalWrite(p2x3x1,LOW); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,LOW);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,HIGH); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,HIGH);
      digitalWrite(p3x3x1,LOW); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,LOW);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,HIGH); digitalWrite(p4x2x2,HIGH); digitalWrite(p4x2x3,HIGH);
      digitalWrite(p4x3x1,LOW); digitalWrite(p4x3x2,LOW); digitalWrite(p4x3x3,LOW);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();

      digitalWrite(p1x1x1,LOW); digitalWrite(p1x1x2,LOW); digitalWrite(p1x1x3,LOW);
      digitalWrite(p1x2x1,LOW); digitalWrite(p1x2x2,LOW); digitalWrite(p1x2x3,LOW);
      digitalWrite(p1x3x1,HIGH); digitalWrite(p1x3x2,LOW); digitalWrite(p1x3x3,HIGH);
      
      digitalWrite(p2x1x1,LOW); digitalWrite(p2x1x2,LOW); digitalWrite(p2x1x3,LOW);
      digitalWrite(p2x2x1,LOW); digitalWrite(p2x2x2,LOW); digitalWrite(p2x2x3,LOW);
      digitalWrite(p2x3x1,HIGH); digitalWrite(p2x3x2,LOW); digitalWrite(p2x3x3,HIGH);
      
      digitalWrite(p3x1x1,LOW); digitalWrite(p3x1x2,LOW); digitalWrite(p3x1x3,LOW);
      digitalWrite(p3x2x1,LOW); digitalWrite(p3x2x2,LOW); digitalWrite(p3x2x3,LOW);
      digitalWrite(p3x3x1,HIGH); digitalWrite(p3x3x2,LOW); digitalWrite(p3x3x3,HIGH);
  
      digitalWrite(p4x1x1,LOW); digitalWrite(p4x1x2,LOW); digitalWrite(p4x1x3,LOW);
      digitalWrite(p4x2x1,LOW); digitalWrite(p4x2x2,LOW); digitalWrite(p4x2x3,LOW);
      digitalWrite(p4x3x1,HIGH); digitalWrite(p4x3x2,HIGH); digitalWrite(p4x3x3,HIGH);
      
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); 
      delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15);
      serv(); delay(15); serv();
}

void sen(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  dur = pulseIn(echoPin, HIGH);
  cm= (dur/2) / 29.1;
  Serial.println(cm);
  delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
  delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
  delay(15); serv(); delay(15); serv(); delay(15); serv(); delay(15); serv();
  delay(10); serv();
}

void serv(){
  if ((rr==1) && (pos==90)){
    rr=0;
    rl=1;
    pos-=1;
    myservo.write(pos);
  }
  else
  if ((rl==1) && (pos==0)){
    rr=1;
    rl=0;
    pos+=1;
    myservo.write(pos);
  }
  else 
  if ((rl==1) && (pos>0)){
    pos-=1;
    myservo.write(pos);
  }
  else
  if ((rr==1) && (pos<90)){
    pos+=1;
    myservo.write(pos);
  }
  
}

void loop() {
 
  sen();
  
  if (sum==0) myinit();
  
  else 
  
  if (cm<=20) pattern1();
 
  else 
  
  if ((cm>20) && (cm<=40)) pattern2();
  
  else 
  
  if ((cm>40) && (cm<=60)) pattern3();
  
  else 
  
  if ((cm>60) && (cm<=80))pattern4();

  else 
  pattern5();
 
}

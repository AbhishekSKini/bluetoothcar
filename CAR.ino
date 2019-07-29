int a1=10,a2=11,b1=8,b2=9,EA=7,EB=6,echo=13,tri=12;
void setup() {
 //motor
 
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(EA,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(EB,OUTPUT);

  //sensor
  pinMode(echo,INPUT);
  pinMode(tri,OUTPUT);
  

}

void loop() 
 {
  //enabling
 digitalWrite(EA,HIGH); 
 digitalWrite(EB,HIGH);

 //sensor
 digitalWrite(tri,LOW);
 delayMicroseconds(20);
 digitalWrite(tri,HIGH);
 delayMicroseconds(100);
 digitalWrite(tri,LOW);
 delayMicroseconds(20);
 int d,dur;
 dur=pulseIn(echo,HIGH);
 d=dur*0.034/2;
 Serial.println(d);

//motor
//if distance is >5
         if(d>10)
         {
          digitalWrite(a1,HIGH);
          digitalWrite(b1,HIGH);
          digitalWrite(a2,LOW);
          digitalWrite(b2,LOW);
         }
         
 //if distance is equal 5 then stop
       if(d==10)
       {
        digitalWrite(a1,LOW);
        digitalWrite(b1,LOW);
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        delay(2000);
      
        digitalWrite(a1,LOW);
        digitalWrite(b1,HIGH);
        digitalWrite(a2,LOW);
        digitalWrite(b2,LOW);
        delay(1000 ); 

         digitalWrite(a1,HIGH);
         digitalWrite(b1,HIGH);
         digitalWrite(a2,LOW);
         digitalWrite(b2,LOW);
         
        
       }
       
 
 }
  
  

  
  



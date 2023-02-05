#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define GREEN 33
#define RED 25
#define YE 26
#define LDR 32
int cnt = 0;    
Bounce debouncer = Bounce();
void setup() {
    Serial.begin(115200);
    Serial.println("BUTTON");
    debouncer.attach(BUTTON, INPUT_PULLUP);
    debouncer.interval(25); 
    ledcSetup(0, 5000, 8);
    ledcSetup(1, 5000, 8);
    ledcSetup(2, 5000, 8);
    ledcAttachPin(GREEN, 0);
    ledcAttachPin(RED, 1);
    ledcAttachPin(YE, 2);
}
int count;
void loop() {
    debouncer.update();
    if ( debouncer.fell()) { 
        count++;
        Serial.println(count);
    }
    if(count>=8){
        ledcWrite(0,0);
        ledcWrite(1,0);
        ledcWrite(2,0);
        delay(10);
        count=0;
    }
    if(count==1)
    {
        ledcWrite(0,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(1,0);
        ledcWrite(2,0);
        delay(10);
    }
    if(count==2)
    {
        ledcWrite(0,0);
        ledcWrite(1,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(2,0);
        delay(10);
    }
    if(count==3)
    {
        ledcWrite(0,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(1,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(2,0); 
        delay(10);   
    }
    if(count==4)
    {   
        ledcWrite(0,0);
        ledcWrite(1,0);
        ledcWrite(2,map(analogRead(LDR),900,2914,0,255));
        delay(10);   
    }
    if(count==5)
    {   
        ledcWrite(0,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(1,0);
        ledcWrite(2,map(analogRead(LDR),900,2914,0,255));     
    }
    if(count==6)
    {
        digitalWrite(GREEN,1);
        ledcWrite(0,0);
        ledcWrite(1,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(2,map(analogRead(LDR),900,2914,0,255));   
        delay(10); 
    }
    if(count==7){
        ledcWrite(0,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(1,map(analogRead(LDR),900,2914,0,255));
        ledcWrite(2,map(analogRead(LDR),900,2914,0,255)); 
        delay(10); 
    }
    


}
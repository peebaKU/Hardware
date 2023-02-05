#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define GREEN 33
#define RED 26
#define YELLOW 25
#define LDR 34
int cnt = 0;    
Bounce debouncer = Bounce();


void setup()
{

    ledcSetup(0, 5000, 8);
    ledcSetup(1, 5000, 8);
    ledcSetup(2, 5000, 8);

    ledcAttachPin(RED, 0);
    ledcAttachPin(GREEN,2);
    ledcAttachPin(YELLOW, 1);

    Serial.begin(115200);
    Serial.println("BUTTON");
    
    debouncer.attach(BUTTON,INPUT_PULLUP);
    debouncer.interval(25); 
}

void loop()
{
    int duty = map(analogRead(LDR),900, 4095, 0, 255);

    debouncer.update();
    if (debouncer.rose()){
        cnt++;
        Serial.println(cnt);
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
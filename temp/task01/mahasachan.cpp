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
    Serial.begin(115200);
    Serial.println("BUTTON");
    
    debouncer.attach(BUTTON,INPUT_PULLUP);
    debouncer.interval(25); 

    ledcSetup(0, 5000, 8);
    ledcSetup(1, 5000, 8);
    ledcSetup(2, 5000, 8);
    ledcAttachPin(RED, 0);
    ledcAttachPin(GREEN,2);
    ledcAttachPin(YELLOW, 1);
}

void loop()
{
    int duty = map(analogRead(LDR),900, 4095, 0, 255);

    debouncer.update();
    if (debouncer.rose()){
        cnt++;
        Serial.println(cnt);
    }
    ledcWrite(2, ((cnt & 1) == 1) ? duty:0);
    ledcWrite(1, ((cnt & 2) == 2) ? duty:0);
    ledcWrite(0, ((cnt & 4) == 4) ? duty:0);
}
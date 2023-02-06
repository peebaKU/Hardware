#include <Bounce2.h>
#define RED 26
#define YELLOW 25 
#define GREEN 33
#define LDR 32
#define BUTTON 27
Bounce b = Bounce();
int cnt = 0;
void setup() {
  b.attach(BUTTON,INPUT_PULLUP);
  b.interval(25); 
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcAttachPin(RED, 0);
  ledcAttachPin(YELLOW, 1);
  ledcAttachPin(GREEN, 2);
  ledcAttachPin(5, 2);
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // Serial.println(analogRead(LDR));
  // delay(100);
  int x = map(analogRead(LDR), 1000, 4095, 0, 255);
  b.update();
  if (b.rose()){
      cnt++;
      Serial.println(cnt);
  }
  
  ledcWrite(0, ((cnt & 4) == 4) ? x : 0);
  ledcWrite(1, ((cnt & 2) == 2) ? x : 0);
  ledcWrite(2, ((cnt & 1) == 1) ? x : 0);

}
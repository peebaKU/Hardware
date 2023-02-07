#include <Arduino.h>
#include <Bounce2.h>
#define GREEN 33
#define RED 26
#define YE 25
TaskHandle_t TaskA = NULL;
TaskHandle_t TaskB = NULL;
#define BUTTON 27
int cnt = 0;
Bounce debouncer = Bounce();

void PWM_(void *param)
{
  while (1)
  {
   for(int j=0; j<3;j++){
    for (int i = 0; i < 255; i++)
    {
      ledcWrite(j, i);
      vTaskDelay(5 / portTICK_PERIOD_MS);
    }
    for (int i = 255; i > 0; i--)
    {
      ledcWrite(j, i);
      vTaskDelay(5 / portTICK_PERIOD_MS);
    }
   }
  }
}

void setup()
{
  Serial.begin(115200);
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcAttachPin(GREEN, 0);
  ledcAttachPin(RED, 1);
  ledcAttachPin(YE, 2);
  Serial.println("BUTTON");
  debouncer.attach(BUTTON, INPUT_PULLUP);
  debouncer.interval(27);
  xTaskCreatePinnedToCore(PWM_, "Builtin_LED", 1000, NULL, 1, &TaskA, 0);
}

void loop()
{

  debouncer.update();
  if (debouncer.rose())
  {
    cnt++;
    Serial.println(cnt);
  }
}

#include <Arduino.h>
#include "baramee.h"
#define GREEN 33
TaskHandle_t TaskA = NULL;

int value_get;

void MAKE_DELAY(void *param)
{
    while (1)
    {
        GET_post();
        value_get = RETURN_value();
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void setup()
{
    pinMode(GREEN, OUTPUT);
    Serial.begin(115200);
    Connect_Wifi();
    GET_post();
    value_get = RETURN_value();
    xTaskCreatePinnedToCore(MAKE_DELAY, "MAKE_DELAY", 10240, NULL, 1, &TaskA, 0);
}
void loop()
{   
    digitalWrite(GREEN, 1);
    delay(value_get);
    digitalWrite(GREEN, 0);
    delay(value_get);
    Serial.println(value_get);
}

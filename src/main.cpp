#include <Arduino.h>
#include <WiFi.h>

    const char *ssid = "Baramee";
    const char *password = "b123456789";

    void Connect_Wifi() {
        WiFi.begin(ssid, password);
        Serial.print("Connecting to WiFi");
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.print("OK! IP=");
        Serial.println(WiFi.localIP());
    }

void setup() {
    Serial.begin(115200);
    Connect_Wifi();
}

void loop() {
    // put your main code here, to run repeatedly:
}
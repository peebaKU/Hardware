#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
int valur_GET;
const char *ssid = "B";
const char *password = "b123456789";

const String baseUrl = "https://exceed-hardware-stamp465.koyeb.app/leddelay";

int RETURN_value()
{
 return valur_GET;
}

void  GET_post(){
    DynamicJsonDocument doc(2048);
    const String url = baseUrl;
    HTTPClient http;
    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode >= 200 && httpResponseCode < 300) {
        String payload = http.getString();
        deserializeJson(doc,payload);
        valur_GET = doc["value"].as<int>();
        http.end();
    }
    else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    
}

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

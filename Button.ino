#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "Button.h"

void sendRequest(String url){
    HTTPClient http;
    http.begin(url);
    http.GET();
    http.end();
}

void setup() {
    Serial.begin(115200);
    Serial.println("");
    Serial.println("BOOT");

    WiFi.enableSTA(true);
    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("\nConnecting to ");
        Serial.println(SSID);
        WiFi.begin(SSID, PASSWORD);
    }

    for (int i = 0; i < 100 && WiFi.status() != WL_CONNECTED; i++) {
        delay(50);
        Serial.print(".");
    }

    size_t length = sizeof(requests) / sizeof(requests[0]); 

    for(int i=0; i<length; i++){
        char *request = requests[i];
        sendRequest(request);
    }

    ESP.deepSleep(0);
    delay(100);
}

void loop() {
}

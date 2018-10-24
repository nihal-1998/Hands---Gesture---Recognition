#define BLYNK_PRINT Serial

int LED= 2;
int Fan= 22;
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "9bee19a520f9452e81291a31fd5b266b";

char ssid[] = "Raghav";
char pass[] = "12345678";

void setup() {  
    pinMode(LED, OUTPUT);
    pinMode(LED, HIGH);
    pinMode(Fan, OUTPUT);
    pinMode(Fan, HIGH);
     
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  

  Blynk.begin("9bee19a520f9452e81291a31fd5b266b", ssid, pass);

}

void loop(){
    Blynk.run();  
}



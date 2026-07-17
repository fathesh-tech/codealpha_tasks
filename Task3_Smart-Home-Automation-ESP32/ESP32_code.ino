#define BLYNK_TEMPLATE_ID "TMPL3X5FfFG9t"
#define BLYNK_TEMPLATE_NAME "Home automation"
#define BLYNK_AUTH_TOKEN "aWcOKV-Y5Tt3mXqzpr80w7OeLCgnAzr5"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "vivo Y29 5G";
char pass[] = "123456789";

#define RELAY_PIN 4

BLYNK_WRITE(V0)
{
  int buttonState = param.asInt();

  if(buttonState == 1)
  {
    digitalWrite(RELAY_PIN, LOW);   // Relay ON
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
  }
}

void setup()
{
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}
#define BLYNK_PRINT Serial

#include <LwIP.h>
#include <STM32Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "kTql2zkTiKn37jtE5M97I_t0wu1aooFG";
IPAddress blynk_ip(139, 59, 206, 133);

const uint8_t LED_PIN = LED_BUILTIN;

void setup()
{
  Serial.begin(115200);
  while (!Serial) 
  {
  }
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Blynk.begin(auth, blynk_ip, 8442);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  int led_ctl = param.asInt();
  digitalWrite(LED_PIN, led_ctl);
}


#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define TRIG_PIN 5
#define ECHO_PIN 18

const char* ssid = "Wokwi-GUEST";
const char* password = "";

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883

#define AIO_USERNAME "sravani_2676"
#define AIO_KEY      "aio_Cmkl006wzoXqaCmZU9zD6gR3dsbo"

WiFiClient client;

Adafruit_MQTT_Client mqtt(
  &client,
  AIO_SERVER,
  AIO_SERVERPORT,
  AIO_USERNAME,
  AIO_KEY
);

Adafruit_MQTT_Publish distanceFeed =
Adafruit_MQTT_Publish(
  &mqtt,
  AIO_USERNAME "/feeds/distance"
);

unsigned long previousMillis = 0;
const long interval = 5000;

void connectWiFi()
{
  Serial.print("Connecting WiFi");

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
}

void connectMQTT()
{
  int8_t ret;

  while((ret=mqtt.connect())!=0)
  {
    Serial.println(mqtt.connectErrorString(ret));
    mqtt.disconnect();

    delay(5000);
  }

  Serial.println("MQTT Connected");
}

float readDistance()
{
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN,LOW);

  long duration =
    pulseIn(ECHO_PIN,HIGH,30000);

  float distance =
    (duration/2.0)*0.0343;

  return distance;
}

void setup()
{
  Serial.begin(115200);

  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  connectWiFi();
  connectMQTT();
}

void loop()
{
  mqtt.processPackets(10);

  if(!mqtt.connected())
  {
    connectMQTT();
  }

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    float distance = readDistance();

    Serial.println("====================");

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if(distance < 50)
    {
      Serial.println("INTRUDER DETECTED");
    }
    else if(distance < 100)
    {
      Serial.println("WARNING");
    }
    else
    {
      Serial.println("SAFE");
    }

    distanceFeed.publish(distance);
  }
}

int soilPin = 34;
int relayPin = 26;
int moistureValue;
void setup() {
 Serial.begin(115200);
 pinMode(relayPin, OUTPUT);
}
 void loop() {
 moistureValue = analogRead(soilPin);
Serial.print("Moisture Value = ");
 Serial.println(moistureValue);

if (moistureValue < 2000) {

Serial.println("Soil is Dry");
 Serial.println("Water Pump ON");

digitalWrite(relayPin, HIGH);
  } 
  else 
  {

   Serial.println("Soil is Wet");
   Serial.println("Water Pump OFF");

   digitalWrite(relayPin, LOW);
   }

   Serial.println("----------------------");

   delay(1000);
   }
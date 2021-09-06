#include <SPI.h>
#include <LoRa.h>

int counter = 0;
int trigger=13, echo=12;
long lecture_echo, distance;

void setup() {
  Serial.begin(9600);
  //Ultrasonic sensor
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);

  while (!Serial);

  Serial.println("LoRa Sender");
 if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
lecture_echo=pulseIn(echo,HIGH);
distance=lecture_echo/58;

Serial.print("Sending packet: ");
String data="1:";
data+=distance;
Serial.println(data); 

  // send packet
  LoRa.beginPacket();
  LoRa.print(data);
  //LoRa.print(counter);
  LoRa.endPacket();

  delay(10000);
}

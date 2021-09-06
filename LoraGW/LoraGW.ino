#include <Bridge.h>
#include <SPI.h>
#include <LoRa.h>
#include <HttpClient.h>
#include <Console.h>


void setup() {
 Bridge.begin(115200);
  Console.begin();

  Console.println("LoRa Receiver");

  if (!LoRa.begin(868E6)) {
    Console.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
    HttpClient client;
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) 
  {
       String msg="";
    // read packet
    while (LoRa.available()) 
    {
      msg+=String((char)LoRa.read());  
    }

      Console.println(msg);
      String url="http://10.130.1.230/waste/index.php?data=";
      url+=msg;
       Console.println(url);
      client.get(url);
  Console.flush();
  }
  
}

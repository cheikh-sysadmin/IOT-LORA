 // Include the SX1276 and SPI library: 
#include "SX1276.h"
#include <SPI.h>

int e;
 char payload[10]="100";
 
void setup()
{
  Serial.begin(115200);
  // Print a start message
  Serial.println("SX1276 module and Arduino: send packets without ACK");
  
  // Power ON the module
  sx1276.ON();
  
  // Set transmission mode and print the result
  e = sx1276.setMode(1);
  Serial.println(e, DEC);
  
  // Select frequency channel
  e = sx1276.setChannel(CH_16_868);
  Serial.println("Setting Channel: state ");
  Serial.println(e, DEC);
  
 
  sx1276.setMaxCurrent(0x1B);
  sx1276.getMaxCurrent();
  // Select output power (Max, High or Low)
  /* H=13dBm M=17dBm  measured at the antenna connector*/
  
  e = sx1276.setPower('M');
 
  
  Serial.println("Setting Power: state ");
  Serial.println(e);
  
  // Set the node address and print the result
  e = sx1276.setNodeAddress(3);
  Serial.println(e, DEC);
  
  // Print a success message
  Serial.print("SX1276 successfully configured ");

}
 
void loop(void)
{
  
  Serial.println(payload);
   
  // Send message1 and print the result
  e = sx1276.sendPacketTimeout(8,payload);
  Serial.print("Packet sent, state ");
  Serial.println(e, DEC);

  delay(1000);  
 
}

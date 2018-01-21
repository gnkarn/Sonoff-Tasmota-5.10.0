#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>


IRsend irsend(4);  // An IR LED is controlled by GPIO pin 4 (D2)

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
 irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
}



void loop() {
 irsend.sendCarrierAC(0xB335ABE2);
/*sendCarrierAC(uint64_t data, uint16_t nbits, uint16_t repeat)*/
 Serial.println("carrier on code");

 digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}

//https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
//https://github.com/nRF24/RF24

//rx_test

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const int buzzer = 2;
const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop() {
  char text[32] = "";
  
  if (radio.available()) {
    radio.read(&text, sizeof(text));
    String transData = String(text);
    if (transData == "nrftest") {
        tone(buzzer, 1000);
        delay(500);
        noTone(buzzer);
      }    
  }
}

// //TX

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void loop() {
  const char text[] = "nrftest";
  radio.write(&text, sizeof(text));
  delay(2000);
}
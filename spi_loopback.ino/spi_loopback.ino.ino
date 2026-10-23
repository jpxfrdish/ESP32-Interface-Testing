
#include <SPI.h>

// ESP32-S3 pin assignments
const int SCK_PIN  = 12;
const int MOSI_PIN = 11;
const int MISO_PIN = 13;
const int CS_PIN   = 10;

SPIClass spi(FSPI);

void setup() {
  Serial.begin(115200);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  // Initialize SPI with our selected pins
  spi.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

  Serial.println("SPI Loopback Test");
}

void loop() {
  spi.beginTransaction(
    SPISettings(1000000, MSBFIRST, SPI_MODE0)
  );

  // Start the SPI transfer
  digitalWrite(CS_PIN, LOW);

  byte received = spi.transfer(0xA5);

  // End the transfer
  digitalWrite(CS_PIN, HIGH);

  spi.endTransaction();

  Serial.print("Sent 0xA5, received 0x");

  if (received < 0x10) {
    Serial.print("0");
  }

  Serial.println(received, HEX);

  delay(1000);
}

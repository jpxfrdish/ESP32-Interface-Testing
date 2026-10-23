
const int UART_TX_PIN = 17;
const int UART_RX_PIN = 16;

void setup() {
  Serial.begin(115200);

  Serial2.begin(
    9600,
    SERIAL_8N1,
    UART_RX_PIN,
    UART_TX_PIN
  );

  Serial.println("UART Loopback Test");
}

void loop() {
  Serial2.println("PING");

  while (Serial2.available()) {
    char received = Serial2.read();
    Serial.write(received);
  }

  delay(1000);
}

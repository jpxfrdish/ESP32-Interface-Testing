| Signal   | GPIO Used |
| :------: | :-------: |
| UART TX  | 17        |
| UART RX  | 16        |
| I2C SDA  | 8         |
| I2C SCL  | 9         |
| SPI SCK  | 12        |
| SPI MOSI | 11        |
| SPI MISO | 13        |
| SPI CS   | 10        |

1. Why does UART need both sides to use the same baud rate, while SPI uses a clock line?

UART has no separate clock line, so both devices must use the same baud rate to correctly identify when each bit starts and ends. SPI uses a clock signal from the controller to synchronize the data transfer.

2. Why can two devices with the same address not share one I²C bus?

I²C devices use addresses to identify which device should respond. If two devices share the same address, both may respond to the same request, causing conflicts and unreliable communication.

3. Why is CS set HIGH between SPI transfers?

CS is set HIGH to deselect the SPI device between transfers. Setting it LOW selects the device so it can participate in the next transfer.


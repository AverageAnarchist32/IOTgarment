# ESP32 RGB LED Control

This project involves an ESP32 microcontroller connected to an RGB LED and a light sensor. The ESP32 serves a web page through a Node.js server, allowing users to control the color of the RGB LED via a web interface.

## Hardware Requirements

- ESP32 microcontroller
- RGB LED (connected to pins D17, D18, D19)
- Light sensor (connected to pin D4)
- Power supply for the ESP32
- USB-to-Serial adapter for programming and debugging
- Resistors and wiring as necessary

## Installation

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/yourusername/esp32-rgb-led-control.git

##markdown
- Copy code
   git clone https://github.com/yourusername/esp32-rgb-led-control.git
- Open the Arduino IDE and load the esp32_rgb_led_control.ino sketch.
- Install the required libraries via the Arduino Library Manager: WiFi HTTPClient
- Update the following variables in the sketch:
ssid: Your WiFi network name.
password: Your WiFi password.
serverAddress: The IP address or hostname of your Node.js server and its port (e.g., http://localhost:8000).
Connect your ESP32 to your computer, select the appropriate board and port, and upload the sketch.
- Set up and run the Node.js server:
bash
- Copy code
- cd nodejs-server
- npm install
- node server.js
- Access the web interface by entering the ESP32 IP address in your browser.
- 
##Usage

Connect the RGB LED and light sensor to the specified pins.
Power on the ESP32.
Open a web browser and navigate to the ESP32 IP address.
Use the web interface to control the RGB LED color and observe the behavior based on the light sensor.
Troubleshooting

If you encounter issues, check the serial monitor in the Arduino IDE for debugging information.
Ensure that the Node.js server is running and accessible from the ESP32.
Verify hardware connections and power supply.

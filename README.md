# GPRS Tracking Project using SIM808 and ESP8266

The GPRS Tracking Project combines a SIM808 GSM module with a GPS unit for location data and an ESP8266 microcontroller as the central processor. This project enables tracking and data transmission over GPRS. 

## Project Structure

The project consists of several code files:

- `at.h`: Defines AT command strings for communication with the SIM808 module.
- `sim80x.h`: Initializes and handles communication with the SIM808 module.
- `GPRS-Tracker.ino`: The main project file that combines these components and controls the overall behavior of the system.

## Code Overview

### AT Commands (`at.h`)

The `at.h` file defines various AT commands that are used to interact with the SIM808 module, such as enabling GPS, establishing GPRS connection, sending HTTP requests, and more.

### SIM808 Handling (`sim80x.h`)

The `sim80x.h` file is responsible for setting up communication with the SIM808 module and handling its commands. It includes functions for initializing the SIM808 module, sending AT commands, and processing GPS data.

### Main Code (`GPRS-Tracker.ino`)

The `GPRS-Tracker.ino` file combines the functionality of all the components and controls the overall behavior of the system. It sets up the serial communication with the SIM808 module, initializes the module, sends AT commands to enable GPS and establish GPRS connectivity, retrieves GPS data, and sends it over HTTP.

The main components and functions in this code are as follows:

- `setup()`: Initializes the serial communication, the SIM808 module, and adds a boot delay.
- `loop()`: Repeatedly performs GPRS control operations, retrieves GPS data, and sends GPS data to a specified server via HTTP.

#### SIM808 Initialization

- `initSIM80XDevice()`: Initializes the SIM808 module by configuring the serial communication and setting the blinking LED.

#### GPS Data Handling

- `getGPSData()`: Retrieves GPS data from the SIM808 module using the AT command `AT+CGNSINF`. It processes the data to extract latitude and longitude information for tracking.

#### GPRS Control

- `GPRS_CTL()`: Executes a sequence of AT commands to control the GPRS connection, including enabling GPS power, configuring the connection, and setting up the access point name (APN).

#### Sending GPS Data

- `SEND_GPS_DATA()`: Sends GPS data to a remote server using HTTP. It initializes the HTTP connection, sets the URL with latitude and longitude data, sends the data, and receives a response.

## Usage

1. Ensure you have the necessary libraries installed in your Arduino IDE for the SIM808 module, SoftwareSerial, and StringSplitter.

2. Modify the AT command strings in `at.h` as needed, especially if you are connecting to a different server or if there are specific AT command configurations required for your SIM808 module.

3. Upload the project code (`GPRS-Tracker.ino`) to your ESP8266 controller.

4. Make sure the SIM808 module is properly connected to the ESP8266. Check the pin connections and power requirements.

5. Power on the ESP8266 and the SIM808 module.

6. The ESP8266 will initiate GPS tracking and GPRS data transmission according to the specified interval in the code. GPS data is sent to the server defined in the AT command strings.


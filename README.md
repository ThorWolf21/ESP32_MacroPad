# ESP32 Macropad Project

This project is designed to create a macropad using the ESP32 microcontroller. The macropad features 6 buttons, supports three layers, and provides LED indications for the current layer.

## Features

- **6 Programmable Buttons**: Each button can be configured to perform different actions based on the active layer.
- **Three Layers**: Users can switch between three different layers, allowing for a variety of functions and shortcuts.
- **LED Indication**: LEDs provide visual feedback on the current active layer.

## Project Structure

```
esp32-macropad
├── src
│   ├── main.cpp         # Entry point of the application
│   ├── buttons.cpp      # Button handling logic
│   ├── buttons.h        # Button handling declarations
│   ├── layers.cpp       # Layer management logic
│   ├── layers.h         # Layer management declarations
│   ├── leds.cpp         # LED control implementation
│   ├── leds.h           # LED control declarations
│   └── config.h         # Configuration constants
├── lib
│   └── README.md        # Documentation for libraries used
├── platformio.ini       # PlatformIO configuration file
└── README.md            # Project documentation
```

## Setup Instructions

1. **Clone the Repository**: Clone this repository to your local machine.
2. **Install PlatformIO**: Ensure you have PlatformIO installed in your development environment.
3. **Open the Project**: Open the project folder in PlatformIO.
4. **Configure the Board**: Modify the `platformio.ini` file to select the appropriate board and framework.
5. **Build the Project**: Use PlatformIO to build the project.
6. **Upload to ESP32**: Connect your ESP32 and upload the firmware.

## Usage

- Press the buttons to trigger the assigned actions based on the current layer.
- Use a specific button combination to switch between layers.
- Observe the LED indicators to know which layer is currently active.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests. Your feedback and improvements are welcome!
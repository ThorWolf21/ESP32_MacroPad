#include <Arduino.h>
#include "buttons.h"
#include "layers.h"
#include "leds.h"
#include "config.h"

void setup() {
    Serial.begin(115200);
    initButtons();
    initLayerLEDs(); // <-- Updated to use the correct LED initialization
    setLayer(0); // Start with the first layer
    bleKeyboard.begin(); // <-- Add this line
}

void loop() {
    handleButtonPresses();
    showLayer(getCurrentLayer()); // <-- Updated to use the correct LED update function
    delay(100); // Simple debounce delay
}
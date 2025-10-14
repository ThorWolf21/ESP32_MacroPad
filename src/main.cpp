#include <Arduino.h>
#include <BleKeyboard.h>
#include "buttons.h"
#include "layers.h"
#include "leds.h"
#include "config.h"

BleKeyboard bleKeyboard; // Declare the instance here

void setup() {
    Serial.begin(115200);
    initButtons();
    initLayerLEDs();
    setLayer(0); // Start with the first layer
    bleKeyboard.begin();
}

void loop() {
    readButtons(); // Call the correct function to handle button presses
    showLayer(getLayer()); // Use getLayer() for consistency
    delay(100); // Simple debounce delay
}
#include "buttons.h"
#include "config.h"
#include "layers.h"
#include <Arduino.h>
#include <BleKeyboard.h>

extern BleKeyboard bleKeyboard; // Use the instance from main.cpp

const int buttonPins[6] = {
    BUTTON_1_PIN,
    BUTTON_2_PIN,
    BUTTON_3_PIN,
    BUTTON_4_PIN,
    BUTTON_5_PIN,
    BUTTON_6_PIN
};
bool buttonStates[6] = {false, false, false, false, false, false};

void initButtons() {
    for (int i = 0; i < 6; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP); // Set button pins as input with pull-up resistors
    }
}

void readButtons() {
    for (int i = 0; i < 6; i++) {
        bool currentState = digitalRead(buttonPins[i]) == LOW; // Read button state (active low)
        if (currentState != buttonStates[i]) {
            buttonStates[i] = currentState;
            handleButtonPress(i, currentState); // Handle button press event
        }
    }
}

void handleButtonPress(int buttonIndex, bool pressed) {
    if (!pressed) return; // Only act on press, not release

    int layer = getLayer();

    // Example: Button 5 cycles to the next layer
    if (buttonIndex == 4) { // Button 5 (index starts at 0)
        int nextLayer = (layer + 1) % NUM_LAYERS;
        setLayer(nextLayer);
        return;
    }

    if (layer == 0) {
        // Layer 1 actions
        if (buttonIndex == 0) {
            // Do shortcut 1 for layer 1
        } else if (buttonIndex == 1) {
            // Do shortcut 2 for layer 1
        }
        // ...and so on for other buttons
    } else if (layer == 1) {
        // Layer 2 actions
        if (buttonIndex == 0) {
            // Do shortcut 1 for layer 2
        }
        // ...
    } else if (layer == 2) {
        // Layer 3 actions: Media volume control
        if (buttonIndex == 0) {
            // Media Volume Down
            sendMediaVolumeDown();
        } else if (buttonIndex == 1) {
            // Media Volume Up
            sendMediaVolumeUp();
        }
    }
}

void sendMediaVolumeDown() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    }
}

void sendMediaVolumeUp() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    }
}
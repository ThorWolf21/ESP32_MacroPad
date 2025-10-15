#include "buttons.h"
#include "config.h"
#include "layers.h"
#include <Arduino.h>
#include <BleKeyboard.h>

extern BleKeyboard bleKeyboard;

const int buttonPins[6] = {
    BUTTON_1_PIN,
    BUTTON_2_PIN,
    BUTTON_3_PIN,
    BUTTON_4_PIN,
    BUTTON_5_PIN,
    BUTTON_6_PIN
};
bool buttonStates[6] = {false, false, false, false, false, false};

// Macro action function type
typedef void (*MacroAction)();

void macroNone() {}

void macroNextLayer() {
    int nextLayer = (getLayer() + 1) % NUM_LAYERS;
    setLayer(nextLayer);
}

void macroVolumeDown() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    }
}

void macroVolumeUp() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    }
}

void macroMute() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_MUTE);
    }
}

// Example: Add your own macros here
void macroShortcut1() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press('t');
        bleKeyboard.releaseAll();
    }
}

// Macro table: [layer][button]
MacroAction macroTable[NUM_LAYERS][6] = {
    // Layer 0
    {macroShortcut1, macroNone, macroNone, macroNone, macroNone, macroNextLayer},
    // Layer 1
    {macroNone, macroNone, macroNone, macroNone, macroNone, macroNextLayer},
    // Layer 2
    {macroNone, macroVolumeUp, macroVolumeDown, macroMute, macroNone, macroNextLayer}
};

void initButtons() {
    for (int i = 0; i < 6; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

void readButtons() {
    for (int i = 0; i < 6; i++) {
        bool currentState = digitalRead(buttonPins[i]) == LOW;
        if (currentState && !buttonStates[i]) {
            // Button was just pressed
            handleButtonPress(i, true);
        }
        buttonStates[i] = currentState;
    }
}

void handleButtonPress(int buttonIndex, bool pressed) {
    if (!pressed) return;
    int layer = getLayer();
    if (buttonIndex < 0 || buttonIndex >= 6 || layer < 0 || layer >= NUM_LAYERS) return;
    macroTable[layer][buttonIndex]();
}
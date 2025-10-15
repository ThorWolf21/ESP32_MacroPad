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

// Layers
void macroNextLayer() {
    int nextLayer = (getLayer() + 1) % NUM_LAYERS;
    setLayer(nextLayer);
}

// browser
void macroSearchSelected() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press('c');
        bleKeyboard.releaseAll();
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press('t');
        bleKeyboard.releaseAll();
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press('v'); 
        bleKeyboard.releaseAll();
        bleKeyboard.press(KEY_NUM_ENTER);
        bleKeyboard.releaseAll();
    }
}

// Media keys
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

void macroPlayPause() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
    }
}

void macroNextTrack() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
    }
}

void macroPreviousTrack() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
    }
}

void macroMute() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_MUTE);
    }
}

// VS Code shortcuts
void macroUndo() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press('z');
        bleKeyboard.releaseAll();
    }
}

void macroRedo() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press('y');
        bleKeyboard.releaseAll();
    }
}

void macroGoBackVS() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_LEFT_ARROW);
        bleKeyboard.releaseAll();
    }
}

void macroGoForwardVS() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_RIGHT_ARROW);
        bleKeyboard.releaseAll();
    }
}

void macroSaveVS() {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press('s');
        bleKeyboard.releaseAll();
    }
}

// Macro table: [layer][button]
MacroAction macroTable[NUM_LAYERS][6] = {
    // Layer 0
    {macroSaveVS, macroGoBackVS, macroGoForwardVS, macroUndo, macroRedo, macroNextLayer},
    // Layer 1
    {macroSearchSelected, macroNone, macroNone, macroNone, macroNone, macroNextLayer},
    // Layer 2
    {macroVolumeUp, macroPreviousTrack, macroPlayPause, macroNextTrack, macroVolumeDown, macroNextLayer}
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
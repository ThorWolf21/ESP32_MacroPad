#include <Arduino.h>
#include "config.h"

const int layerLEDs[NUM_LAYERS] = {LAYER_LED_1_PIN, LAYER_LED_2_PIN, LAYER_LED_3_PIN};

void initLayerLEDs() {
    for (int i = 0; i < NUM_LAYERS; i++) {
        pinMode(layerLEDs[i], OUTPUT);
        digitalWrite(layerLEDs[i], LED_OFF);
    }
}

void showLayer(int layer) {
    for (int i = 0; i < NUM_LAYERS; i++) {
        digitalWrite(layerLEDs[i], (i == layer) ? LED_ON : LED_OFF);
    }
}
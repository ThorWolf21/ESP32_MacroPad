#include "layers.h"

static int currentLayer = 0;

void initLayerLEDs() {
    // ...existing code...
}

void showLayer(int layer) {
    // ...existing code...
}

void setLayer(int layer) {
    currentLayer = layer;
}

int getLayer() {
    return currentLayer;
}
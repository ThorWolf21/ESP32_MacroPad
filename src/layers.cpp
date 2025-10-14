#include "layers.h"

static int currentLayer = 0;
const int totalLayers = 3;

void setLayer(int layer) {
    if (layer >= 0 && layer < totalLayers) {
        currentLayer = layer;
    }
}

int getLayer() {
    return currentLayer;
}

void nextLayer() {
    currentLayer = (currentLayer + 1) % totalLayers;
}

void previousLayer() {
    currentLayer = (currentLayer - 1 + totalLayers) % totalLayers;
}
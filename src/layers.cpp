#include "layers.h"

static int currentLayer = 0;

void setLayer(int layer) {
    currentLayer = layer;
}

int getLayer() {
    return currentLayer;
}
#ifndef LAYERS_H
#define LAYERS_H

// Layer management constants
#define MAX_LAYERS 3

// Function declarations
void initLayers();
void initLayerLEDs();
void showLayer(int layer);
void setLayer(int layer);
int getLayer();

#endif // LAYERS_H
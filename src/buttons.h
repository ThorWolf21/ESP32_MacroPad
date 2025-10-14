#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include "config.h"

// Function declarations
void initButtons();
void readButtons();
void handleButtonPress(int buttonIndex, bool pressed);
void sendMediaVolumeDown();
void sendMediaVolumeUp();

#endif // BUTTONS_H
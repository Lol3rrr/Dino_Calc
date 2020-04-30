#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>

int calculateDistance(int lastX, double currentSpeed, int spawnSpread);

int calculateDistance(int lastX, double currentSpeed, int spawnSpread) {
  return lastX + 300 + (rand() % spawnSpread) * (currentSpeed / 3);
}

#endif
#ifndef CACTUS_H
#define CACTUS_H

#include <stdlib.h>

#include "entity.h"

#include "../engine/render.h"
#include "../engine/collision.h"

#define CACTUS_SPAWN_SPREAD 75

#define CACTUS_SPRITE_SCALE 2

typedef struct cactus {
  int x;
  int y;
  int type;
} cactus;

#define CACTUS_ONE_SPRITE_HEIGHT 19
#define CACTUS_ONE_SPRITE_WIDTH 12
int CACTUS_ONE_Sprite[CACTUS_ONE_SPRITE_HEIGHT][CACTUS_ONE_SPRITE_WIDTH] = {
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
};

#define CACTUS_TWO_SPRITE_HEIGHT 20
#define CACTUS_TWO_SPRITE_WIDTH 26
int CACTUS_TWO_Sprite[CACTUS_TWO_SPRITE_HEIGHT][CACTUS_TWO_SPRITE_WIDTH] = {
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS}
};

void spawnRandomCactus(cactus* pCactus, int ground, int prevBird, double currentSpeed) {
  int type = rand() % 2;
  int typeHeight = 0;
  if (type == 0) {
    typeHeight = CACTUS_ONE_SPRITE_HEIGHT;
  } else if (type == 1) {
    typeHeight = CACTUS_TWO_SPRITE_HEIGHT;
  }
  int yCoord = ground - (typeHeight * CACTUS_SPRITE_SCALE);

  pCactus->x = calculateDistance(prevBird, currentSpeed, CACTUS_SPAWN_SPREAD);
  pCactus->y = yCoord;
  pCactus->type = type;
}

int isCactusOffScreen(cactus* pCactus, int currentX) {
  int width = 0;

  int type = pCactus->type;
  if (type == 0) {
    width = CACTUS_ONE_SPRITE_WIDTH;
  } else if (type == 1) {
    width = CACTUS_TWO_SPRITE_WIDTH;
  }
  
  return pCactus->x + (width * CACTUS_SPRITE_SCALE) < currentX;
}

void renderCactus(cactus* pCactus, int currentX) {
  int renderX = pCactus->x - currentX;

  int type = pCactus->type;
  if (type == 0) {
    renderSprite(
      renderX,
      pCactus->y,
      CACTUS_ONE_SPRITE_HEIGHT,
      CACTUS_ONE_SPRITE_WIDTH,
      CACTUS_ONE_Sprite,
      CACTUS_SPRITE_SCALE);
    
    return;
  }
  if (type == 1) {
    renderSprite(
      renderX,
      pCactus->y,
      CACTUS_TWO_SPRITE_HEIGHT,
      CACTUS_TWO_SPRITE_WIDTH,
      CACTUS_TWO_Sprite,
      CACTUS_SPRITE_SCALE);
    
    return;
  }
}

static int getCactusHeight(cactus* pCactus) {
  int type = pCactus->type;

  if (type == 0) {
    return CACTUS_ONE_SPRITE_HEIGHT * CACTUS_SPRITE_SCALE;
  }
  if (type == 1) {
    return CACTUS_TWO_SPRITE_HEIGHT * CACTUS_SPRITE_SCALE;
  }
  
  return 0;
}
static int getCactusWidth(cactus* pCactus) {
  int type = pCactus->type;

  if (type == 0) {
    return CACTUS_ONE_SPRITE_WIDTH * CACTUS_SPRITE_SCALE;
  }
  if (type == 1) {
    return CACTUS_TWO_SPRITE_WIDTH * CACTUS_SPRITE_SCALE;
  }
  
  return 0;
}

int* getCactusSprite(cactus* pCactus) {
  int type = pCactus->type;
  
  if (type == 0) {
    return (int*) &CACTUS_ONE_Sprite;
  }
  if (type == 1) {
    return (int*) &CACTUS_TWO_Sprite;
  }
  
  return 0;
}
int getCactusSpriteHeight(cactus* pCactus) {
  int type = pCactus->type;

  if (type == 0) {
    return CACTUS_ONE_SPRITE_HEIGHT;
  }
  if (type == 1) {
    return CACTUS_TWO_SPRITE_HEIGHT;
  }
  
  return 0;
}
int getCactusSpriteWidth(cactus* pCactus) {
  int type = pCactus->type;

  if (type == 0) {
    return CACTUS_ONE_SPRITE_WIDTH;
  }
  if (type == 1) {
    return CACTUS_TWO_SPRITE_WIDTH;
  }
  
  return 0;
}


RECT getCactusRect(cactus* pCactus, int currentX) {
  RECT result = {
    .x = pCactus->x - currentX,
    .y = pCactus->y,
    .width = getCactusWidth(pCactus),
    .height = getCactusHeight(pCactus)
  };

  return result;
}

#endif
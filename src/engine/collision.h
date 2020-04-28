#ifndef COLLISION_H
#define COLLISION_H

typedef struct RECT {
    int x;
    int y;
    int width;
    int height;
} RECT;

typedef struct CollisionSprite {
  int x;
  int y;
  int width;
  int height;
  int *sprite;
  int scale;
} CollisionSprite;

int checkCollision(RECT* rec1, RECT* rec2);
int checkSpriteCollision(CollisionSprite cSprite1, CollisionSprite cSprite2);

// PROS: Pretty fast and effecient
// CONS: Only really useful for rough collision detection
int checkCollision(RECT* rec1, RECT* rec2) {
    // Right side rec1 < Left side rec2
    if (rec1->x + rec1->width < rec2->x) {
        return 0;
    }
    // Left side rec1 > Right side rec2
    if (rec1->x > rec2->x + rec2->width) {
        return 0;
    }

    // Top side rec1 > Bottom side rec2
    if (rec1->y > rec2->y + rec2->height) {
        return 0;
    }
    // Bottom side rec1 < Top side rec2
    if (rec1->y + rec1->height < rec2->y) {
        return 0;
    }
    
    return 1;
}

// PROS: Really accurate(pixel perfect)
// CONS: Rather Slow
int checkSpriteCollision(CollisionSprite cSprite1, CollisionSprite cSprite2) {
  int deltaX = cSprite1.x - cSprite2.x;
  int deltaY = cSprite1.y - cSprite2.y;

  for (int spriteY = 0; spriteY < cSprite1.height; spriteY++) {
    for (int yScale = 0; yScale < cSprite1.scale; yScale++) {
      int sprite1YCoord = (spriteY * cSprite1.scale) + yScale;
      int sprite2YCoord = ((sprite1YCoord + deltaY) / cSprite2.scale);
      
      if (sprite2YCoord >= cSprite2.height) {
        return 0;
      }
      if (sprite2YCoord < 0) {
        continue;
      }

      for (int spriteX = 0; spriteX < cSprite1.width; spriteX++) {
        for (int xScale = 0; xScale < cSprite1.scale; xScale++) {
          int sprite1XCoord = (spriteX * cSprite1.scale) + xScale;
          int sprite2XCoord = ((sprite1XCoord + deltaX) / cSprite2.scale);

          int sprite1Color = *(cSprite1.sprite + spriteY * cSprite1.width + spriteX);
          if (sprite1Color == C_TRANS) {
            continue;
          }

          if (sprite2XCoord < 0 || sprite2XCoord >= cSprite2.width) {
            continue;
          }

          int sprite2Color = *(cSprite2.sprite + sprite2YCoord * cSprite2.width + sprite2XCoord);
          if (sprite2Color != C_TRANS) {
            return 1;
          }
        }
      }
    }
  }
  
  return 0;
}

#endif
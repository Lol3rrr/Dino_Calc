#ifndef GAME_H
#define GAME_H

#include "general.h"

#include "ui.h"
#include "player.h"
#include "cactus.h"
#include "bird.h"

#include "engine/input.h"
#include "engine/utils.h"
#include "engine/collision.h"

#define GROUND_LEVEL 150

#define JUMP_SPEED 8
#define SLAM_SPEED 8

typedef struct gameInfo {
  int highscore;
  int score;
  int isRunning;

  player player;
  cactus nextCactus;
  bird nextBird;

	double xSpeed;
	double xAcceleration;
  double ySpeed;
  double yAcceleration;
  double gravity;
} gameInfo;

const int playerGroundY = GROUND_LEVEL - (PLAYER_SPRITE_HEIGHT * PLAYER_SPRITE_SCALE);

gameInfo* initGame(double startSpeed, double acc, double gravity, int prevHighscore) {
  gameInfo* result = (gameInfo*) malloc(1 * sizeof(gameInfo));
  result->highscore = prevHighscore;

  result->player.x = 60;
  result->player.y = playerGroundY;
  result->player.animationFrame = 0;
  result->player.isAirborn = 0;
  result->player.isSlamming = 0;
  result->player.action = PLAYER_RUNNING;

  spawnRandomCactus(&(result->nextCactus), GROUND_LEVEL, 0, startSpeed);
  spawnRandomBird(&(result->nextBird), GROUND_LEVEL, result->nextCactus.x, startSpeed);

  result->score = 0;
  result->isRunning = 1;
  
  result->xSpeed = startSpeed;
  result->xAcceleration = acc;
  result->ySpeed = 0;
  result->yAcceleration = 0;
  result->gravity = gravity;

  return result;
}

void cleanUpGame(gameInfo** info) {
  if (*info == 0) {
    return;
  }

	free(*info);
  *info = 0;
}


void handlePlayerInput(int key, gameInfo* game) {
  if (game->player.action == PLAYER_DUCKING) {
    if (game->player.isAirborn) {
      game->player.action = PLAYER_JUMPING;
    } else {
      game->player.action = PLAYER_RUNNING;
    }
  }

  if ((key == KEY_8 || key == KEY_UP) && !game->player.isAirborn) {
    game->ySpeed -= JUMP_SPEED;
    game->player.isAirborn = 1;
    game->player.action = PLAYER_JUMPING;

    return;
  }
  if ((key == KEY_2 || key == KEY_DOWN) && !game->player.isSlamming && game->player.isAirborn) {
    game->ySpeed += SLAM_SPEED;
    game->player.isSlamming = 1;
    game->player.action = PLAYER_SLAMMING;

    return;
  }
  if ((key == KEY_2 || key == KEY_DOWN) && !game->player.isAirborn) {
    game->player.action = PLAYER_DUCKING;

    return;
  }
}

int handleGamePause() {
  while (1) {
    renderInGamePauseUI();
    Bdisp_PutDisp_DD();

    int tmpKey = getInput_NonBlocking();

		// The EXIT key
		if (tmpKey == KEY_PRGM_EXIT) {
			return -2;
		}
		// The EXE key
		if (tmpKey == KEY_EXE) {
			break;
		}
  }

  return -1;
}

int runGameCycle(gameInfo* info) {
  int key = getInput_NonBlocking();


  if (info->isRunning) {
    // Pause Menu
    if (key == KEY_PRGM_MENU) {
      return handleGamePause();
    }

    handlePlayerInput(key, info);

    info->xSpeed *= info->xAcceleration;
    info->ySpeed += info->gravity;

    info->player.y += info->ySpeed;
    info->score += info->xSpeed;

    if (playerTouchesGround(&(info->player), GROUND_LEVEL)) {
      info->yAcceleration = 0;
      info->ySpeed = 0;
    }

    if (isCactusOffScreen(&(info->nextCactus), info->score)) {
      spawnRandomCactus(&(info->nextCactus), GROUND_LEVEL, info->score, info->xSpeed);
    }
    if (isBirdOffScreen(&(info->nextBird), info->score)) {
      spawnRandomBird(&(info->nextBird), GROUND_LEVEL, info->nextCactus.x, info->xSpeed);
    }

    if (checkCactusCollision(&(info->player), &(info->nextCactus), info->score)) {
      info->isRunning = 0;
    }
    if (checkBirdCollision(&(info->player), &(info->nextBird), info->score)) {
      info->isRunning = 0;
    }
  }

  renderPlayer(&(info->player), info->isRunning);
  renderCactus(&(info->nextCactus), info->score);
  renderBird(&(info->nextBird), info->score);
  // The Ground
  renderRect(0, GROUND_LEVEL, DISPLAY_WIDTH, 2, C_BLACK);

	renderInGameUI(info->score, info->highscore);

  if (!info->isRunning) {
    renderEndScreen(info->score);

    if (key == KEY_EXIT) {
      return info->score;
    }
  }

	Bdisp_PutDisp_DD();
	sleepTicks(5);

  return -1;
}


#endif

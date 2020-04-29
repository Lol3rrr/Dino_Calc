#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <string.h>

#include "../engine/collision.h"
#include "../engine/render.h"
#include "../movement.h"

#include "cactus.h"
#include "bird.h"

#define PLAYER_ANIMATION_FRAME 20

#define PLAYER_SPRITE_WIDTH 28
#define PLAYER_SPRITE_HEIGHT 22
#define PLAYER_SPRITE_SCALE 2

#define PLAYER_RUNNING 0
#define PLAYER_JUMPING 1
#define PLAYER_DUCKING 2
#define PLAYER_SLAMMING 3

typedef struct player {
  int x;
  int y;

  int action;

  int isAirborn;
  int isSlamming;
  int animationFrame;
} player;

int PLAYER_IDLE_SPRITE[PLAYER_SPRITE_HEIGHT][PLAYER_SPRITE_WIDTH] = {
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS}
};
int PLAYER_DEAD_SPRITE[PLAYER_SPRITE_HEIGHT][PLAYER_SPRITE_WIDTH] = {
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_WHITE, C_WHITE, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_WHITE, C_BLACK, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_WHITE, C_WHITE, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS}
};
int PLAYER_RUN_1_SPRITE[PLAYER_SPRITE_HEIGHT][PLAYER_SPRITE_WIDTH] = {
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS}
};
int PLAYER_RUN_2_SPRITE[PLAYER_SPRITE_HEIGHT][PLAYER_SPRITE_WIDTH] = {
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
	{C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS}
};
int PLAYER_DUCKING_1_SPRITE[PLAYER_SPRITE_HEIGHT][PLAYER_SPRITE_WIDTH] = {
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS}
};
int PLAYER_DUCKING_2_SPRITE[PLAYER_SPRITE_HEIGHT][PLAYER_SPRITE_WIDTH] = {
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS},
  {C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_WHITE, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS},
  {C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_BLACK, C_BLACK, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS}
};

void renderRunAnimation(player* pPlayer) {
  if (pPlayer->animationFrame < PLAYER_ANIMATION_FRAME / 2) {
    renderSprite(pPlayer->x, pPlayer->y, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_RUN_1_SPRITE, PLAYER_SPRITE_SCALE);
  } else {
    renderSprite(pPlayer->x, pPlayer->y, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_RUN_2_SPRITE, PLAYER_SPRITE_SCALE);
  }

  pPlayer->animationFrame = (pPlayer->animationFrame + 1) % PLAYER_ANIMATION_FRAME;
}

void renderDuckingAnimation(player* pPlayer) {
if (pPlayer->animationFrame < PLAYER_ANIMATION_FRAME / 2) {
    renderSprite(pPlayer->x, pPlayer->y, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_DUCKING_1_SPRITE, PLAYER_SPRITE_SCALE);
  } else {
    renderSprite(pPlayer->x, pPlayer->y, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_DUCKING_2_SPRITE, PLAYER_SPRITE_SCALE);
  }

  pPlayer->animationFrame = (pPlayer->animationFrame + 1) % PLAYER_ANIMATION_FRAME;
}

void renderPlayer(player* pPlayer, int alive) {
	if (pPlayer == 0) {
		return;
	}

  if (!alive) {
    renderSprite(pPlayer->x, pPlayer->y, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_DEAD_SPRITE, PLAYER_SPRITE_SCALE);
    return;
  }

  if (pPlayer->action == PLAYER_JUMPING || pPlayer->action == PLAYER_SLAMMING) {
    renderSprite(pPlayer->x, pPlayer->y, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_IDLE_SPRITE, PLAYER_SPRITE_SCALE);
    return;
  }
  if (pPlayer->action == PLAYER_RUNNING) {
    renderRunAnimation(pPlayer);
    return;
  }
  if (pPlayer->action == PLAYER_DUCKING) {
    renderDuckingAnimation(pPlayer);
    return;
  } 

  renderSprite(pPlayer->x, pPlayer->y, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, PLAYER_IDLE_SPRITE, PLAYER_SPRITE_SCALE);
}


int playerTouchesGround(player* pPlayer, int groundLevel) {
	if (pPlayer->y + (PLAYER_SPRITE_HEIGHT * PLAYER_SPRITE_SCALE) >= groundLevel) {
    pPlayer->y = groundLevel - (PLAYER_SPRITE_HEIGHT * PLAYER_SPRITE_SCALE);
    pPlayer->isAirborn = 0;
    pPlayer->isSlamming = 0;
    if (pPlayer->action != PLAYER_DUCKING) {
      pPlayer->action = PLAYER_RUNNING;
    }

		return 1;
	}

	return 0;
}

RECT getPlayerRect(player* pPlayer) {
  RECT result = {
    .x = pPlayer->x,
    .y = pPlayer->y,
    .width = PLAYER_SPRITE_WIDTH * PLAYER_SPRITE_SCALE,
    .height = PLAYER_SPRITE_HEIGHT * PLAYER_SPRITE_SCALE
  };

  return result;
}

static int* getPlayerSprite(player* pPlayer) {
  if (pPlayer->action == PLAYER_JUMPING || pPlayer->action == PLAYER_SLAMMING) {
    return (int*) &PLAYER_IDLE_SPRITE;
  }

  if (pPlayer->action == PLAYER_RUNNING) {
    if (pPlayer->animationFrame < PLAYER_ANIMATION_FRAME / 2) {
      return (int*) &PLAYER_RUN_1_SPRITE;
    } else {
      return (int*) &PLAYER_RUN_2_SPRITE;
    }
  }

  if (pPlayer->action == PLAYER_DUCKING) {
    if (pPlayer->animationFrame < PLAYER_ANIMATION_FRAME / 2) {
      return (int*) &PLAYER_DUCKING_1_SPRITE;
    } else {
      return (int*) &PLAYER_DUCKING_2_SPRITE;
    }
  }

  return 0;
}

int checkCactusCollision(player* pPlayer, cactus* pCactus, int currentX) {
  // First rough collision check for better performance
  RECT playerRect = getPlayerRect(pPlayer);
  RECT cactusRect = getCactusRect(pCactus, currentX);
  if (!checkCollision(&playerRect, &cactusRect)) {
    return 0;
  }

  // More detailed collision check based on the Sprites
  CollisionSprite playerCSprite = {
    .x = pPlayer->x,
    .y = pPlayer->y,
    .width = PLAYER_SPRITE_WIDTH,
    .height = PLAYER_SPRITE_HEIGHT,
    .sprite = getPlayerSprite(pPlayer),
    .scale = PLAYER_SPRITE_SCALE
  };
  CollisionSprite cactusCSprite = {
    .x = (pCactus->x - currentX),
    .y = pCactus->y,
    .width = getCactusSpriteWidth(pCactus),
    .height = getCactusSpriteHeight(pCactus),
    .sprite = getCactusSprite(pCactus),
    .scale = CACTUS_SPRITE_SCALE
  };

  return checkSpriteCollision(playerCSprite, cactusCSprite);
}

int checkBirdCollision(player* pPlayer, bird* pBird, int currentX) {
  // First rough collision check for better performance
  RECT playerRect = getPlayerRect(pPlayer);
  RECT birdRect = getBirdRect(pBird, currentX);
  if (!checkCollision(&playerRect, &birdRect)) {
    return 0;
  }

  // More detailed collision check based on the Sprites
  CollisionSprite playerCSprite = {
    .x = pPlayer->x,
    .y = pPlayer->y,
    .width = PLAYER_SPRITE_WIDTH,
    .height = PLAYER_SPRITE_HEIGHT,
    .sprite = getPlayerSprite(pPlayer),
    .scale = PLAYER_SPRITE_SCALE
  };
  CollisionSprite birdCSprite = {
    .x = (pBird->x - currentX),
    .y = pBird->y,
    .width = getBirdSpriteWidth(pBird),
    .height = getBirdSpriteHeight(pBird),
    .sprite = getBirdSprite(pBird),
    .scale = BIRD_SPRITE_SCALE
  };

  return checkSpriteCollision(playerCSprite, birdCSprite);
}

#endif
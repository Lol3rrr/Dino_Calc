#include <display_syscalls.h>
#include <keyboard.h>
#include <keyboard.hpp>
#include <CONVERT_syscalls.h>

#include "engine/files.h"

#include "ui.h"
#include "game.h"
#include "highscore.h"


#define RUNNING 1
#define END_SCREEN 0
#define MAIN_MENU -1

#define START_SPEED 4
#define SPEED_ACC 1.001
#define GRAVITY 0.5

int main() {
  createFolder((unsigned char*) "@DINO");

	Bdisp_AllClr_VRAM();

  int highscore = loadHighscore();

	gameInfo* info = initGame(START_SPEED, SPEED_ACC, GRAVITY, highscore);

	int status = MAIN_MENU;

	while (1) {
		Bdisp_AllClr_VRAM();

		if (status == RUNNING) {
			int result = runGameCycle(info);
			if (result == -2) {
				status = MAIN_MENU;
				continue;
			}
			if (result == -1) {
				continue;
			}

      if (result >= 0) {
				status = MAIN_MENU;
        if (result > highscore) {
          highscore = result;
          writeHighscore(highscore);
        }

				continue;
			}
		} else if (status == MAIN_MENU) {
			renderMainMenu();
			Bdisp_PutDisp_DD();

      int key;
      GetKey(&key);

			while (key != KEY_CTRL_EXE) {
				GetKey(&key);
			}

			cleanUpGame(info);
			info = initGame(START_SPEED, SPEED_ACC, GRAVITY, highscore);

			status = RUNNING;
		}
	}

	return 0;
}

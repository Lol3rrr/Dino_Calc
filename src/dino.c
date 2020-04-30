#include <display_syscalls.h>
#include <keyboard.h>
#include <keyboard.hpp>
#include <CONVERT_syscalls.h>

#include "engine/files.h"

#include "ui.h"
#include "game.h"
#include "highscore.h"
#include "menus/mainMenu.h"
#include "menus/settingsMenu.h"
#include "menus/confirmation.h"


#define RUNNING 0
#define END_SCREEN 1
#define MAIN_MENU 2
#define SETTINGS_MENU 3

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
          saveHighscore(highscore);
        }

				continue;
			}
		} else if (status == MAIN_MENU) {
			int selectedOption = mainMenu();

			if (selectedOption == 0) {
				info = initGame(START_SPEED, SPEED_ACC, GRAVITY, highscore);

				status = RUNNING;
			} else if (selectedOption == 1) {
				status = SETTINGS_MENU;
			}
		} else if (status == SETTINGS_MENU) {
			int selectedOption = settingsMenu();

			if (selectedOption == 0) {
				status = MAIN_MENU;
			}
			if (selectedOption == 1) {
				int confirmed = askConfirmation();
				if (!confirmed) {
					continue;
				}

				deleteHighscore();
				highscore = 0;
				status = MAIN_MENU;
			}
		}
	}

	return 0;
}

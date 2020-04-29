#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <keyboard.hpp>

#include "../ui.h"


// Returns
// 0: Start Game
// 1: Open Settings Menu
int displayMainMenu();

int displayMainMenu() {
  int key;
  int selected = 0;

  while (1) {
		Bdisp_AllClr_VRAM();

		renderMainMenu(selected);
		Bdisp_PutDisp_DD();
				
		GetKey(&key);

		if (key == KEY_CTRL_EXE) {
			break;
		}

		if (key == KEY_CTRL_UP) {
			selected += -1;
		}
		if (key == KEY_CTRL_DOWN) {
			selected += 1;
		}

		if (selected < 0) {
			selected = 0;
		}
		if (selected > 1) {
			selected = 1;
		}
	}

  return selected;
}

#endif
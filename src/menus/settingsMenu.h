#ifndef SETTINGS_MENU_H
#define SETTINGS_MENU_H

#include <keyboard.hpp>

#include "../ui.h"


// Returns
// 0: Back to Main-Menu
int settingsMenu();

int settingsMenu() {
  int key;
  int selected = 0;

  while (1) {
		Bdisp_AllClr_VRAM();

		renderSettingsMenu(selected);
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
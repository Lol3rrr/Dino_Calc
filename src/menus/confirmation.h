#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <keyboard.hpp>

#include "../ui.h"

// Returns
// 0: Denied
// 1: Confirmed
int askConfirmation();

int askConfirmation() {
  int key;
  int selected = 0;

  while (1) {
		Bdisp_AllClr_VRAM();

		renderConfirmation(selected);
		Bdisp_PutDisp_DD();
				
		GetKey(&key);

		if (key == KEY_CTRL_EXE) {
			break;
		}

		if (key == KEY_CTRL_LEFT) {
			selected += -1;
		}
		if (key == KEY_CTRL_RIGHT) {
			selected += 1;
		}

		if (selected < 0) {
			selected = 0;
		}
		if (selected > 1) {
			selected = 1;
		}
	}

  return (selected == 1);
}

#endif
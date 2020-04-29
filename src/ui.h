#ifndef UI_H
#define UI_H

#include "engine/render.h"
#include "player.h"

void renderInGameUI(int score, int highscore);
void renderInGamePauseUI();
void renderEndScreen(int score);
void renderMainMenu(int selected);
void renderSettingsMenu(int selected);


void renderInGameUI(int score, int highscore) {
  unsigned char buffer[12];
  itoa(score, buffer);
  renderMiniText(10, 160, buffer, COLOR_BLACK, COLOR_WHITE);

  itoa(highscore, buffer);
  renderMiniText(10, 130, buffer, COLOR_BLACK, COLOR_WHITE);
}

void renderInGamePauseUI() {
	int x1 = 50;
	int x2 = LCD_WIDTH_PX - x1;
	int y1 = 30;
	int y2 = LCD_HEIGHT_PX - y1;

  int spriteData[1][1] = {
    {C_WHITE}
  };
  renderSprite(x1, y1, 1, 1, spriteData, (x2 - x1));

	unsigned char* pauseMessage = (unsigned char*) "PAUSED";
	renderCenteredMiniText(x1, x2, y1 + 10, pauseMessage, COLOR_BLACK, COLOR_WHITE);

	unsigned char* continuePart = (unsigned char*) "Press EXE to continue...";
	renderCenteredMiniText(x1, x2, y2 - 50, continuePart, COLOR_BLACK, COLOR_WHITE);

	unsigned char* exitPart = (unsigned char*) "Press EXIT to go to the Main Menu";
	renderCenteredMiniText(x1, x2, y2 - 25, exitPart, COLOR_BLACK, COLOR_WHITE);
}

void renderEndScreen(int score) {
  unsigned char* gameOverMessage = (unsigned char*) "Game Over!";
  renderCenterMiniText(10, gameOverMessage, COLOR_BLACK, COLOR_WHITE);

  unsigned char* scoreMessage = (unsigned char*) "Score:";
  renderCenterMiniText(30, scoreMessage, COLOR_BLACK, COLOR_WHITE);

  unsigned char buffer[12];
	itoa(score, buffer);
	renderCenterMiniText(50, buffer, COLOR_BLACK, COLOR_WHITE);

	unsigned char* continueMessage = (unsigned char*) "Press EXIT to continue...";
	renderCenterMiniText(160, continueMessage, COLOR_BLACK, COLOR_WHITE);
}

void renderMainMenu(int selected) {
  unsigned char* mainMenuScreen = (unsigned char*) "Dinosaur";
	renderCenterMiniText(0, mainMenuScreen, COLOR_BLACK, COLOR_WHITE);

	unsigned char* startGame = (unsigned char*) "Start";
	if (selected == 0) {
		renderCenterMiniText(50, startGame, COLOR_WHITE, COLOR_BLACK);
	} else {
		renderCenterMiniText(50, startGame, COLOR_BLACK, COLOR_WHITE);
	}

	unsigned char* settings = (unsigned char*) "Settings";
	if (selected == 1) {
		renderCenterMiniText(75, settings, COLOR_WHITE, COLOR_BLACK);
	} else {
		renderCenterMiniText(75, settings, COLOR_BLACK, COLOR_WHITE);
	}
}

void renderSettingsMenu(int selected) {
	unsigned char* settingsStr = (unsigned char*) "Settings";
	renderCenterMiniText(0, settingsStr, COLOR_BLACK, COLOR_WHITE);

	unsigned char* backStr = (unsigned char*) "Back";
	if (selected == 0) {
		renderCenterMiniText(50, backStr, COLOR_WHITE, COLOR_BLACK);
	} else {
		renderCenterMiniText(50, backStr, COLOR_BLACK, COLOR_WHITE);
	}
}


#endif

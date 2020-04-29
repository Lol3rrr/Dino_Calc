#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "engine/files.h"
#include "engine/utils.h"

// Saves the given highscore to the
// save file and overwrites old score
void saveHighscore(int highscore);
// Deletes the old saved highscore
void deleteHighscore();
// Returns
// 0: Save file could not be found
// Else: The Value of the last Highscore
int loadHighscore();



void saveHighscore(int highscore) {
  unsigned char buffer[12];
  itoa(highscore, buffer);

  writeFile((unsigned char*) "@DINO", (unsigned char*) "highscore", buffer, 12);
}

void deleteHighscore() {
  saveHighscore(0);
}

int loadHighscore() {
  unsigned char buffer[12];
  int readWorked = readFile((unsigned char*) "@DINO", (unsigned char*) "highscore", buffer, 12);
  if (!readWorked) {
    return 0;
  }

  int length = 0;
  for (int i = 0; i < 12; i++) {
    if (buffer[i] == '\0') {
      length = i;
      break;
    }
  }

  return atoi(buffer, length);
}

#endif
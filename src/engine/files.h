#ifndef FILES_H
#define FILES_H

#include <MCS_syscalls.h>


// Returns:
// 0: does not exist
// 1: exists
int fileExists(unsigned char* folder, unsigned char* name);
// Returns:
// 0: failed to create
// 1: successfully created the file
int createFolder(unsigned char* folder);
// Returns:
// 0: failed to write data
// 1: successfully wrote the data
int writeFile(unsigned char* folder, unsigned char* name, unsigned char* buffer, int length);
// Returns:
// 0: failed to read data
// 1: successfully read the data
int readFile(unsigned char* folder, unsigned char* name, unsigned char* buffer, int length);

int fileExists(unsigned char* folder, unsigned char* name) {
  int x;
  return (MCSGetDlen2(folder, name, &x) == 0) ? 1 : 0;
}

int createFolder(unsigned char* folder) {
  return (MCS_CreateDirectory(folder) == 0) ? 1 : 0;
}

int writeFile(unsigned char* folder, unsigned char* name, unsigned char* buffer, int length) {
  int createResult = MCSPutVar2(folder, name, length, buffer);
  if (createResult == 0) {
    return 1;
  }
  if (createResult != 37) {
    return 0;
  }

  return (MCSOvwDat2(folder, name, length, buffer, 0) == 0) ? 1 : 0;
}

int readFile(unsigned char* folder, unsigned char* name, unsigned char* buffer, int length) {
  if (fileExists(folder, name)) {
    return (MCSGetData1(0, length, (void*)buffer) == 0) ? 1 : 0;
  }

  return 0;
}

#endif
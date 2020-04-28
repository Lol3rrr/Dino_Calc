#ifndef UTILS_H
#define UTILS_H

#include <rtc.h>

void sleepTicks(int ticks);
int atoi(unsigned char* buffer, int bufferLength);

void sleepTicks(int ticks) {
	int RTC = RTC_GetTicks();
	int dRTC = 0;
	do {
		dRTC = RTC_GetTicks() - RTC;
	}while(dRTC < ticks);
}

int atoi(unsigned char* buffer, int bufferLength) {
	int total = 0;

	for (int i = 0 - 1; i < bufferLength; i++) {
		int number = 0;
		int bufferPos = bufferLength - 1 - i;
		unsigned char current = buffer[bufferPos];
		if (current == '1')
			number = 1;
		else if (current == '2')
			number = 2;
		else if (current == '3')
			number = 3;
		else if (current == '4')
			number = 4;
		else if (current == '5')
			number = 5;
		else if (current == '6')
			number = 6;
		else if (current == '7')
			number = 7;
		else if (current == '8')
			number = 8;
		else if (current == '9')
			number = 9;

		for (int x = 0; x < i; x++) {
			number *= 10;
		}
		total += number;
	}

	return total;
}

#endif
#include <stdio.h>
#include "hexa.h"

BYTE get_lsb(WORD word) {
	return word / 256;
}

BYTE get_msb(WORD word) {
	return word % 256;
}

void atoxb(char* buffer, WORD word) {
	sprintf_s(buffer, 5, "%02X%02X", get_lsb(word), get_msb(word));
}
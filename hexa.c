#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hexa.h"

BYTE get_lsb(WORD word) {
	return word / 256;
}

BYTE get_msb(WORD word) {
	return word % 256;
}

char* atoxml(WORD word) {
	char* result = NULL;
	result = (char*)malloc(7);
	sprintf_s(result, 5, "%02X%02X", get_msb(word), get_lsb(word));
	return result;
}

char* atoxlm(WORD word) {
	char* result = NULL;
	result = (char*)malloc(7);
	sprintf_s(result, 5, "%02X%02X", get_lsb(word), get_msb(word));
	return result;
}
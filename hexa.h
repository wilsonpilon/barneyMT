#pragma once

#define WORD unsigned short
#define BYTE unsigned char

#ifdef __cplusplus
extern "C" {
#endif

	BYTE get_lsb(WORD word);
	BYTE get_msb(WORD word);
	void atoxb(WORD word);

#ifdef __cplusplus
};
#endif
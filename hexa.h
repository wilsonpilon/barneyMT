#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	BYTE get_lsb(WORD word);
	BYTE get_msb(WORD word);
	char* atoxml(WORD word);
	char* atoxlm(WORD word);

#ifdef __cplusplus
};
#endif
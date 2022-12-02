#pragma once
#ifdef __cplusplus
extern "C" {
#endif

	unsigned short desktop_init();
	void desktop_quit();
	bool desktop_loop(bool (*loop)());
	void desktop_window(int x, int y, int width, int height, char* title, ALLEGRO_COLOR color);

#ifdef __cplusplus
}
#endif
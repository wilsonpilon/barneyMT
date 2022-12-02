#pragma once
#ifdef __cplusplus
extern "C" {
#endif

	void MSX_print(int x, int y, char* message, ALLEGRO_COLOR color);
	void MSX_cls(ALLEGRO_COLOR color);
	void MSX_line(int sx, int sy, int dx, int dy, ALLEGRO_COLOR color);

#ifdef __cplusplus
}
#endif
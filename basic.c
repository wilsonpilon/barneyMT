#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "msx.h"
#include "basic.h"

extern ALLEGRO_FONT* font;

void MSX_print(int x, int y, char* text, ALLEGRO_COLOR color) {
	al_draw_text(font, MSX_color_black, x + 1, y + 1, 0, text);
	al_draw_text(font, color, x, y, 0, text);
}

void MSX_cls(ALLEGRO_COLOR color) {
	al_clear_to_color(color);
}

void MSX_line(int sx, int sy, int dx, int dy, ALLEGRO_COLOR color) {
	al_draw_line((float)sx, (float)sy, (float)dx, (float)dy, color, 2);
}
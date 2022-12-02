#include <stdio.h>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include "msx.h"
#include "app.h"
#include "desktop.h"
#include "hexa.h"
#include "basic.h"

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_DISPLAY* disp;
ALLEGRO_FONT* font;
ALLEGRO_EVENT event;

unsigned short desktop_init() {
	unsigned short dsk_erro = 0;
	if (!al_init())
		dsk_erro += 2;
	if (!al_install_keyboard())
		dsk_erro += 4;
	timer = al_create_timer(1.0 / 30.0);
	if (!timer)
		dsk_erro += 8;
	queue = al_create_event_queue();
	if (!queue)
		dsk_erro += 16;
	disp = al_create_display(1280, 960);
	if (!disp)
		dsk_erro += 32;

	al_init_font_addon();
	al_init_ttf_addon();
	font = al_load_font("MSX-Screen1.ttf", 16, 0);
	if (!font)
		dsk_erro += 64;

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	return dsk_erro;
}

void desktop_quit() {
	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
}

bool desktop_loop(bool (*loop)()) {
	bool done = false;
	bool redraw = true;

	al_start_timer(timer);
	while (true) {
		al_wait_for_event(queue, &event);

		switch (event.type) {
		case ALLEGRO_EVENT_TIMER:
			redraw = true;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		}
		if (done)
			break;
		if (redraw && al_is_event_queue_empty(queue)) {

			loop();

			al_flip_display();
			redraw = false;
		}
	}

	return false;
}

void desktop_window(int x, int y, int width, int height, char* title, ALLEGRO_COLOR color) {
	MSX_line(x, y, x + width, y + height, color);
	MSX_line(x, y+height, x + width, y + height, color);
	MSX_line(x, y, x, y + height, color);
	MSX_line(x + width, y, x + width, y + height, color);
}
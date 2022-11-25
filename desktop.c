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

unsigned short dsk_init() {
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

bool dsk_loop() {
	bool done = false;
	bool redraw = true;
	char buffer[81];


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
			MSX_cls(MSX_color_dark_blue);

			MSX_print(100, 100, "MSX", MSX_color_white);
			char* lsbmsb = NULL;
			char* msblsb = NULL;
			lsbmsb = atoxml(453);
			MSX_print(200, 200, lsbmsb, MSX_color_dark_yellow);
			free(msblsb);
			lsbmsb = atoxlm(453);
			MSX_print(220, 220, lsbmsb, MSX_color_dark_green);
			free(lsbmsb);

			al_flip_display();
			redraw = false;
		}
	}

	return false;
}

void dsk_quit() {
	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
}
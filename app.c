#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

#include "msx.h"
#include "app.h"
#include "desktop.h"
#include "basic.h"
#include "hexa.h"

extern ALLEGRO_TIMER* timer;
extern ALLEGRO_EVENT_QUEUE* queue;
extern ALLEGRO_DISPLAY* disp;
extern ALLEGRO_FONT* font;
extern ALLEGRO_EVENT event;


bool run(int argc, char* argv[]) {
	unsigned short init_erro;
	init_erro = desktop_init();

	if (init_erro = desktop_init()) {
		printf("Allegro Init Error: %hu", init_erro);
		return false;
	}

	while (desktop_loop(barneymt));
	desktop_quit();
	return false;
}


bool barneymt() {
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
	desktop_window(200, 200, 200, 200, " Teste ", MSX_color_dark_red);
	
	return false;
}


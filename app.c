#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

#include "app.h"
#include "desktop.h"

bool run(int argc, char* argv[]) {
	unsigned short init_erro;
	init_erro = dsk_init();

	if (init_erro = dsk_init()) {
		printf("Allegro Init Error: %hu", init_erro);
		return false;
	}



	while (dsk_loop());
	dsk_quit();
	return false;
}

bool app() {
	return false;
}
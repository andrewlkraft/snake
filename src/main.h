#ifndef MAIN_H
#define MAIN_H

#include "headers.h"

extern void 	quit_SDL		(void);
extern void 	init_SDL		(void);
extern void 	clear_screen	(void);
extern void 	draw_game		(void);
extern void 	handle_input	(Direction *facing);

Game game;
Queue q;

#endif
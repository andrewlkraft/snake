#ifndef MAIN_H
#define MAIN_H

#include "headers.h"

extern void quit_SDL(void);
extern void init_SDL(void);
extern void draw_background(void);
extern void draw_scene(void);
extern void take_input(void);

Game game;

#endif
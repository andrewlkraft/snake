#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
	SDL_Renderer *rend;
	SDL_Window *win;
	uint8_t field[FIELD_WIDTH * FIELD_HEIGHT];
} Game;

#endif
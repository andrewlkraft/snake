#include "draw.h"

void draw_background(void)
{
	SDL_SetRenderDrawColor(game.rend, 128, 255, 52, 255);
	SDL_RenderClear(game.rend);
}

void draw_scene(void)
{
	SDL_RenderPresent(game.rend);
}
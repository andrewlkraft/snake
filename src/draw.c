#include "draw.h"

void draw_background(void)
{
	SDL_SetRenderDrawColor(app.rend, 128, 255, 52, 255);
	SDL_RenderClear(app.rend);
}

void draw_scene(void)
{
	SDL_RenderPresent(app.rend);
}
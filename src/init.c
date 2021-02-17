#include "init.h"

void init_SDL(void)
{
	uint32_t render_flags, window_flags;

	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	window_flags = 0;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.win = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

	if(!app.win)
	{
		printf("Failed to open window: %s", SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.rend = SDL_CreateRenderer(app.win, -1, render_flags);

	if(!app.rend)
	{
		printf("Failed to create renderer: %s", SDL_GetError());
		exit(1);
	}
}

void quit_SDL(void)
{
	SDL_DestroyRenderer(app.rend);
	
	SDL_DestroyWindow(app.win);
	
	SDL_Quit();
}
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

	game.win = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

	if(!game.win)
	{
		printf("Failed to open window: %s", SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	game.rend = SDL_CreateRenderer(game.win, -1, render_flags);

	if(!game.rend)
	{
		printf("Failed to create renderer: %s", SDL_GetError());
		exit(1);
	}
}

void quit_SDL(void)
{
	SDL_DestroyRenderer(game.rend);
	
	SDL_DestroyWindow(game.win);

	clear(&q);
	
	SDL_Quit();
}
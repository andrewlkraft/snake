#include "input.h"

void take_input(Direction *facing)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				printf("exiting...\n");
				exit(0);
				break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.scancode)
				{
					case SDL_SCANCODE_W:
						if (*facing != DOWN)	*facing = UP;
						break;

					case SDL_SCANCODE_A:
						if (*facing != RIGHT)	*facing = LEFT;
						break;

					case SDL_SCANCODE_S:
						if (*facing != UP)		*facing = DOWN;
						break;

					case SDL_SCANCODE_D:
						if (*facing != LEFT)	*facing = RIGHT;
						break;
					
					default:
						break;
				}

			default:
				break;
		}
	}
}
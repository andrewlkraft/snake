#include "input.h"

void handle_input(Direction *facing)
{
	SDL_Event event;
	Direction dir = *facing;

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
						if (dir != DOWN)	*facing = UP;
						break;

					case SDL_SCANCODE_A:
						if (dir != RIGHT)	*facing = LEFT;
						break;

					case SDL_SCANCODE_S:
						if (dir != UP)		*facing = DOWN;
						break;

					case SDL_SCANCODE_D:
						if (dir != LEFT)	*facing = RIGHT;
						break;
					
					default:
						break;
				}

			default:
				break;
		}
	}
}
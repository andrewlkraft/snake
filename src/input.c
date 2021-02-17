#include "input.h"

void take_input(void)
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
						printf("key W pressed\n");
						break;
					case SDL_SCANCODE_A:
						printf("key A pressed\n");
						break;
					case SDL_SCANCODE_S:
						printf("key S pressed\n");
						break;
					case SDL_SCANCODE_D:
						printf("key D pressed\n");
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
}
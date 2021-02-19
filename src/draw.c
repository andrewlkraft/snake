#include "draw.h"

void clear_screen(void)
{
	SDL_SetRenderDrawColor(game.rend, 0, 0, 0, 255);
	SDL_RenderClear(game.rend);
}

void render_message(const char *msg, int x, int y)
{
	
}

void draw_game(void)
{
	SDL_Rect dest;
	Tile tile;

	for(int y = 0; y < FIELD_HEIGHT; y++)
	{
		for(int x = 0; x < FIELD_WIDTH; x++)
		{
			dest = (SDL_Rect){20*x, 20*y, TILE_SIZE, TILE_SIZE};
			tile = game.field[FIELD_WIDTH*y + x];

			if(tile == SNAKE)
			{
				SDL_SetRenderDrawColor(game.rend, 0, 255, 0, 255);
				SDL_RenderFillRect(game.rend, &dest);
			}
			else if(tile == FOOD)
			{
				SDL_SetRenderDrawColor(game.rend, 255, 0, 0, 255);
				SDL_RenderFillRect(game.rend, &dest);
			}
		}
	}
	SDL_RenderPresent(game.rend);
}
#include "draw.h"

void texture_and_rect(SDL_Renderer *rend, int x, int y, char *msg, TTF_Font *font, SDL_Color color, SDL_Texture **texture, SDL_Rect *rect)
{
	SDL_Surface *surface = TTF_RenderText_Solid(font, msg, color);
	*texture = SDL_CreateTextureFromSurface(rend, surface);
	*rect = (SDL_Rect){.x=x, .y=y, .w=surface->w, .h=surface->h};
	SDL_FreeSurface(surface);
}

void clear_screen(void)
{
	SDL_SetRenderDrawColor(game.rend, 0, 0, 0, 255);
	SDL_RenderClear(game.rend);
}

// We will only draw a tile if its value has changed, otherwise it should stay the same as before
void draw_tile(uint16_t x, uint16_t y)
{
	SDL_Rect dest = (SDL_Rect){20*x, 20*y, TILE_SIZE, TILE_SIZE};;
	Tile tile = game.field[FIELD_WIDTH*y + x];
	if(tile == SNAKE)
		SDL_SetRenderDrawColor(game.rend, 0, 255, 0, 255);

	else if(tile == FOOD)
		SDL_SetRenderDrawColor(game.rend, 255, 0, 0, 255);

	else if(tile == EMPTY)
		SDL_SetRenderDrawColor(game.rend, 0, 0, 0, 0);

	SDL_RenderFillRect(game.rend, &dest);
}
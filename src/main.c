#include "main.h"

/* REFERENCES:
 *
 * https://www.libsdl.org/
 * https://wiki.libsdl.org/FrontPage
 * https://w3.cs.jmu.edu/bernstdh/web/common/help/cpp_mingw-sdl-setup.php
 * https://www.parallelrealities.co.uk/tutorials/shooter/shooter1.php
 * https://www.geeksforgeeks.org/sdl-library-in-c-c-with-examples/
 * 
 */
void run_game(void)
{
	// Empty field and clear q to start new game
	memset(game.field, EMPTY, FIELD_WIDTH*FIELD_HEIGHT*sizeof(Tile));
	clear(&q);
	push(&q, (Coord){FIELD_WIDTH/2, FIELD_HEIGHT/2});
	clear_screen();
	
	// Define variables needed for the game
	Coord head = q.head->pos, tail = {0,0};
	uint16_t len = 1, 
			score = INITIAL_LEN, 
			foodindex = (uint16_t) rand() % (FIELD_WIDTH*FIELD_HEIGHT - len);
	Direction facing = UP;
	Tile tile;

	SDL_Texture *texture;
	SDL_Rect dest;
	char buff[20] = "Score: 0";
	
	game.field[FIELD_WIDTH*head.y + head.x] = SNAKE;
	draw_tile(head.x, head.y);
	while(game.field[foodindex] == SNAKE) 
	{
		foodindex++;
		if (foodindex > FIELD_WIDTH*FIELD_HEIGHT) foodindex = 0;
	}
	game.field[foodindex] = FOOD;
	draw_tile(foodindex % FIELD_WIDTH, foodindex/FIELD_WIDTH);

	texture_and_rect(game.rend, 0, 0, buff, game.subhead, (SDL_Color){255,255,255}, &texture, &dest);
	SDL_RenderCopy(game.rend, texture, NULL, &dest);

	// Game Loop
	while(1)
	{
		handle_game_input(&facing);

		// render the new position of the head of the snake
		switch(facing)
		{
			case UP:
				head.y--;
				break;

			case DOWN:
				head.y++;
				break;

			case LEFT:
				head.x--;
				break;

			case RIGHT:
				head.x++;
		}
			
		// game over if head goes out of bounds;
		if(head.x >= FIELD_WIDTH || head.y >= FIELD_HEIGHT)
			break;

		push(&q, head);
		tile = game.field[FIELD_WIDTH*head.y + head.x];
		if (tile == SNAKE)
			break;
		if (tile == FOOD)
		{
			score++;
			snprintf(buff, 20, "Score: %d", score - INITIAL_LEN);
			texture_and_rect(game.rend, 0, 0, buff, game.subhead, (SDL_Color){255,255,255}, &texture, &dest);
			
			SDL_SetRenderDrawColor(game.rend, 0, 0, 0, 255);
			SDL_RenderFillRect(game.rend, &dest);
			SDL_RenderCopy(game.rend, texture, NULL, &dest);

			foodindex = (uint16_t) rand() % (FIELD_WIDTH*FIELD_HEIGHT - len);
			while(game.field[foodindex] == SNAKE) 
			{
				foodindex++;
				if (foodindex > FIELD_WIDTH*FIELD_HEIGHT) foodindex = 0;
			}
			game.field[foodindex] = FOOD;
			draw_tile(foodindex % FIELD_WIDTH, foodindex/FIELD_WIDTH);
		}

		game.field[FIELD_WIDTH*head.y + head.x] = SNAKE;
		draw_tile(head.x, head.y);

		if (++len > score)
		{
			len--;
			tail = pop(&q);
			game.field[FIELD_WIDTH*tail.y + tail.x] = EMPTY;
			draw_tile(tail.x, tail.y);
		}

		// Replace score text if it gets overwritten
		if(	(head.x < 10 && head.y < 3) ||
			(foodindex % FIELD_WIDTH < 3 && foodindex / FIELD_WIDTH < 10) ||
			(tail.x < 10 && tail.y < 3) )
		{
			texture_and_rect(game.rend, 0, 0, buff, game.subhead, (SDL_Color){255,255,255}, &texture, &dest);
			SDL_RenderCopy(game.rend, texture, NULL, &dest);
		}
		
		SDL_RenderPresent(game.rend);

		// cap on framerate
		SDL_Delay(50);
	}

	// Ending Screen
	clear_screen();
	texture_and_rect(game.rend, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, "GAME OVER", game.head, (SDL_Color){255,255,255}, &texture, &dest);
	dest.x -= dest.w / 2;
	len = dest.y + dest.h;
	SDL_RenderCopy(game.rend, texture, NULL, &dest);
	texture_and_rect(game.rend, SCREEN_WIDTH/2, len, buff, game.subhead, (SDL_Color){255,0,0}, &texture, &dest);
	dest.x -= dest.w / 2;
	len = dest.y + dest.h;
	SDL_RenderCopy(game.rend, texture, NULL, &dest);
	texture_and_rect(game.rend, SCREEN_WIDTH/2, len, "Press any key to play again.", game.subhead, (SDL_Color){196,196,196}, &texture, &dest);
	dest.x -= dest.w / 2;
	SDL_RenderCopy(game.rend, texture, NULL, &dest);
	SDL_RenderPresent(game.rend);

	while(handle_any_key() == 0)
		SDL_Delay(50);
	SDL_DestroyTexture(texture);
}

int main(int argc, char** argv)
{
	// define game and q
	memset(&game, 0, sizeof(Game));
	q = (Queue) {0, 0};

	init_SDL();
	atexit(quit_SDL);
	
	// Render Title Screen
	clear_screen();
	// Prepare to render font
	SDL_Texture *texture;
	SDL_Rect dest;
	texture_and_rect(game.rend, SCREEN_WIDTH / 2, SCREEN_HEIGHT/2, "SNAKE GAME", game.head, (SDL_Color){255,255,255,255}, &texture, &dest);
	dest.x -= dest.w / 2;
	SDL_RenderCopy(game.rend, texture, NULL, &dest);
	
	texture_and_rect(game.rend, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + dest.h, "Press any key to play", game.subhead, (SDL_Color){196,196,196,255}, &texture, &dest);
	dest.x -= dest.w / 2;
	SDL_RenderCopy(game.rend, texture, NULL, &dest);
	SDL_RenderPresent(game.rend);

	while(handle_any_key() == 0)
		SDL_Delay(50);
	
	// Run main game loop/end screen until program is exited.
	while(1)
		run_game();

	return 0;
}

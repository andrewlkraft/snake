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

int main(int argc, char** argv)
{
	// define game and q
	memset(&game, 0, sizeof(Game));
	q = (Queue){0, 0};

	init_SDL();
	atexit(quit_SDL);
	
	while(1)
	{
		push(&q, (Coord){FIELD_WIDTH/2, FIELD_HEIGHT/2});
		
		Coord head = q.head->pos, tail = {0,0};
		uint16_t len = 1, score = INITIAL_LEN, foodindex = (uint16_t) rand() % (FIELD_WIDTH*FIELD_HEIGHT - len);
		Direction facing = UP;
		Tile tile;

		game.field[FIELD_WIDTH*head.y + head.x] = SNAKE;
		while(game.field[foodindex] == SNAKE) 
		{
			foodindex++;
			if (foodindex > FIELD_WIDTH*FIELD_HEIGHT) foodindex = 0;
		}
		game.field[foodindex] = FOOD;
		
		while(1)
		{
			clear_screen();

			handle_input(&facing);

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
			printf("head:\t(%d, %d)\n", head.x, head.y);
			
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
					foodindex = (uint16_t) rand() % (FIELD_WIDTH*FIELD_HEIGHT - len);
					while(game.field[foodindex] == SNAKE) 
					{
						foodindex++;
						if (foodindex > FIELD_WIDTH*FIELD_HEIGHT) foodindex = 0;
					}
					game.field[foodindex] = FOOD;
					printf("foodindex: (%d, %d)\n", foodindex/FIELD_WIDTH, foodindex%FIELD_WIDTH);
			}
			game.field[FIELD_WIDTH*head.y + head.x] = SNAKE;

			if (++len > score)
			{
				len--;
				tail = pop(&q);
				game.field[FIELD_WIDTH*tail.y + tail.x] = EMPTY;
			}
			
			draw_game();

			// cap on framerate
			SDL_Delay(50);
		}

		while(1)
		{
			clear_screen();

			handle_input(&facing);
		}
	}	
	return 0;
}

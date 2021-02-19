#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
	uint16_t x, y;
} Coord;

// Queue to represent a snake
typedef struct Node {
	struct Node *next;
	Coord pos;
};

typedef struct {
	struct Node *head, *tail;
} Queue;

// enums
typedef enum {
	UP, DOWN, LEFT, RIGHT
} Direction;

typedef enum {
	EMPTY, SNAKE, FOOD
} Tile;

// Game stores the renderer and window as well as the state of the game board
typedef struct {
	SDL_Renderer *rend;
	SDL_Window *win;
	Tile field[FIELD_WIDTH*FIELD_HEIGHT];
	TTF_Font *head, *subhead;
} Game;

#endif
#ifndef MAIN_H
#define MAIN_H

#include "headers.h"

// Init functions
extern void 	quit_SDL			(void);
extern void 	init_SDL			(void);

// Draw functions
extern void 	clear_screen		(void);
extern void 	draw_tile			(uint8_t 		x,
									uint8_t			y);
extern void		texture_and_rect	(SDL_Renderer	*rend,
									int				x,
									int				y, 
									char			*msg, 
									TTF_Font		*font, 
									SDL_Color		color, 
									SDL_Texture		**texture, 
									SDL_Rect		*rect);

// Input functions
extern void 	handle_game_input	(Direction		*facing);
extern int		handle_any_key		(void);

// Struct declarations
Game game;
Queue q;

#endif
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
	memset(&app, 0, sizeof(App));

	init_SDL();
	atexit(quit_SDL);

	while(1)
	{
		draw_background();

		take_input();
		
		draw_scene();

		SDL_Delay(16);
	}
	
	return 0;
}

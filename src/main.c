/*	
 *	The source file for csnake
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

enum gameState {TITLE, RUNNING, OVER};
enum tileState {EMPTY, SNAKE, FOOD};
enum direction {UP, DOWN, LEFT, RIGHT};

const int uScreenWidth = 100;
const int uScreenHeight = 30;

char *vField = NULL;

char* createField(int width, int height) 
{
	char *v = malloc(sizeof(*v)*width*height);
	for(int i = 0; i < width*height; i++)
	{
		v[i] = EMPTY;
	}
	return v;
}

void printToScreen(char *screen) {
	for(int i = 0; i < uScreenHeight * uScreenWidth; i++)
	{
		if(vField[i]==EMPTY)
			screen[i] = ' ';
		else
			screen[i] = 0x2588;
	}
}

int main()
{
    char *screen = malloc(sizeof(*screen)*uScreenWidth*uScreenHeight);
	for(int i = 0; i < uScreenWidth * uScreenHeight; i++)
	{
		screen[i] = ' ';
	}
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	vField = createField(uScreenWidth, uScreenHeight);

	char state = TITLE;
	char facing = UP;
	int length = 3;
	int snakeHeadX = uScreenWidth/2;
	int snakeHeadY = uScreenHeight/2;

	while(state == TITLE) /* TODO: title screen */
	{
		state = RUNNING;
	}
	while(state != OVER) /* main game loop */
	{
		Sleep(33);  /* wait 33 ms, 1 frame / 33 ms ~= 30 fps */
		
		if((GetAsyncKeyState((int)'W') & 0x8000) != 0)
		{
			facing = UP;
			state = OVER;
		}
		if((GetAsyncKeyState((int)'A') & 0x8000) != 0)
		{
			facing = LEFT;
			state = OVER;
		}
		if((GetAsyncKeyState((int)'S') & 0x8000) != 0)
		{
			facing = DOWN;
			state = OVER;
		}
		if((GetAsyncKeyState((int)'D') & 0x8000) != 0)
		{
			facing = RIGHT;
			state = OVER;
		}

		printToScreen(screen);

		WriteConsoleOutputCharacter(hConsole, screen, uScreenWidth * uScreenHeight, (COORD){ 0,0 }, &dwBytesWritten);
	}

	free(screen);
	free(vField);
	CloseHandle(hConsole);

	printf("\nGame Over\n\nYour score was: %d\n", length-3);
	return 0;
 }
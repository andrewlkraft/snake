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
#include <unistd.h>

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

int main()
{
    wchar_t *screen = malloc(sizeof(*screen)*uScreenWidth*uScreenHeight);
	for(int i = 0; i < uScreenWidth*uScreenHeight; i++)
	{
		screen[i] = L' ';
	}
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	vField = createField(uScreenWidth, uScreenHeight);

	char facing = UP;
	int length = 3;
	int snakeHeadX = uScreenWidth/2;
	int snakeHeadY = uScreenHeight/2;

	WriteConsoleOutputCharacter(hConsole, screen, uScreenWidth * uScreenHeight, (COORD){ 0,0 }, &dwBytesWritten);

	CloseHandle(hConsole);
	system("pause");
	return 0;
 }
#include <Windows.h>
#include <conio.h>
#include <iostream>

struct Line
{
	int startX;
	int startY;

	int endX;
	int endY;

	Line(int sX, int sY, int eX, int eY)
	{
		startX = sX;
		startY = sY;

		endX = eX;
		endY = eY;
	}

	Line()
	{
		startX = 0;
		startY = 0;

		endX = 0;
		endY = 0;
	}
};

class LS_Engine
{
public:
	int numberOfLines = 100;
	Line lines[100] = { };

	// declare functions
	LS_Engine();

	void Draw(HWND hWnd, HDC hdc, PAINTSTRUCT ps, COLORREF color, HPEN hpen, Line line);
	void Update();
	void Input();
	void Lines();

	// input functions that user edits
	void onUpPressed();
	void onLeftPressed();
	void onDownPressed();
	void onRightPressed();
};
﻿#include "pch.h"
#include "LS_Engine.h"


/*** moving cursor on application will slow it down immensely ***/


// this is where you declare what is rendered --> max 100 lines!
void LS_Engine::Lines()
{
	//       start x, start y, end x, end y
	lines[0] = Line(100, 100, 101, 101);
	lines[1] = Line(500, 500, 500, 600);
	lines[2] = Line(500, 600, 600, 600);
	lines[3] = Line(600, 600, 500, 500);
	lines[4] = Line(700, 500, 550, 300);

	numberOfLines = 5;
}

// this is where you handle game logic (moving cursor will interrupt this)
void LS_Engine::Update()
{
	LS_Engine::lines[0].endX = LS_Engine::lines[0].endX + 1;
	LS_Engine::lines[0].startX = LS_Engine::lines[0].startX + 1;
}


void LS_Engine::onUpPressed()
{
	//insert code for when up arrow is pressed
	std::cout << "UP";
}
void LS_Engine::onLeftPressed()
{
	//insert code for when left arrow is pressed
	std::cout << "LEFT";
}
void LS_Engine::onRightPressed()
{
	//insert code for when right arrow is pressed
	std::cout << "RIGHT";
}
void LS_Engine::onDownPressed()
{
	//insert code for when down arrow is pressed
	std::cout << "DOWN";
}


int main()
{
	LS_Engine engine;
	return 0;
}

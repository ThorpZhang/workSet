#pragma once
#include<cstdio>
#include"include\SDL.h"
#include"include\SDL_image.h"

using namespace std;

enum mouseState
{
	MOUSE_OUT = 0,
	MOUSE_OVERMOTION=1,
	MOUSE_BUTTON_UP=2,
	MOUSE_BUTTON_DOWN=3
};
class LButton
{
public:
//	const static int BUTTON_WIDTH = 100;
//	const static int BUTTON_HEIGHT = 100;

	LButton();
	~LButton() {}

	void setPosition(int x, int y);

	void handleEvent(SDL_Event *e);

	void setSize(int w, int h);

	SDL_Point getPos();

	mouseState getState();

	void render();
private:
	SDL_Point mPosition;

	mouseState currState;

	int BUTTON_WIDTH;
	int BUTTON_HEIGHT;
};


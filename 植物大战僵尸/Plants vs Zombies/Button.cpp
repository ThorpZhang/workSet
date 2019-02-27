#pragma once
#include"Button.h"

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;

	BUTTON_WIDTH = 0;
	BUTTON_HEIGHT = 0;
	currState = MOUSE_OUT;
}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::setSize(int w, int h)
{
	BUTTON_WIDTH = w;
	BUTTON_HEIGHT = h;
}
void LButton::handleEvent(SDL_Event *e)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < mPosition.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > mPosition.x + BUTTON_WIDTH)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > mPosition.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if (!inside)
		{
			currState = MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				currState = MOUSE_OVERMOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				currState = MOUSE_BUTTON_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				currState = MOUSE_BUTTON_UP;
				break;
			}
		}
	}
}

SDL_Point LButton::getPos()
{
	return mPosition;
}

mouseState LButton::getState()
{
	return currState;
}


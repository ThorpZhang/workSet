#pragma once
#include"include\SDL.h"


class Peabulletlogic
{
public:
	Peabulletlogic();
	~Peabulletlogic();

	void setPos(int x, int y);
	void setRow(int r);
	void move(SDL_Rect &zombie,int HP);

	int getRow();

	bool getBroken();

	SDL_Rect getColli();

	void broke();
	
	int getPosX();

private:
	SDL_Rect bulletColli;

	int posX, posY;
	int row;//ÐÐÊý
	double velX;
	bool broken;
};
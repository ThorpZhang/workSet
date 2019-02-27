#pragma once
#include"include\SDL.h"
#include"PlantCollisionAndMotion.h"
#include"LTimer.h"


class Plantlogic
{
public:

	//*********************拥有的成员*********************
	pColliandMove plantColli;
	LTimer timer;
	bool meetZombie;
	LTimer attackTimer;
	LTimer makeSTimer;

	Plantlogic();
	~Plantlogic();
};
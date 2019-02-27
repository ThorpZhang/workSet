#pragma once
#include"ZombCollisionAndMotion.h"
#include"LTimer.h"

class Zombies
{
public:
	//*******************拥有的成员****************************
	zColliAndMove zCAM;
	LTimer timer;
	int HP;
	bool attackflag;

	Zombies();
	~Zombies();
};
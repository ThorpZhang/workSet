#pragma once
#include"include\SDL.h"
#include"include\SDL_image.h"
#include"PlantCollisionAndMotion.h"

enum Meet
{
	meetNothing,//没遇到任何东西
	meetPlant,//遇到植物
	meetHouse//进入房子
};


class zColliAndMove
{
public:
	zColliAndMove();
	zColliAndMove(int posx, int posy );
	~zColliAndMove();

	void setPos(int x, int y);

	void setVel(int v);

    Meet move(SDL_Rect &plants,plantflag f1);//返回僵尸是否碰到植物,是否碰到房子(房子不用碰撞类检测,检测zPosX即可

	SDL_Rect & getColli();

//	virtual void render() = 0;  渲染功能分离给纹理类

	int getPosX();
	int getPosY();
protected:
	int zPosX, zPosY;

	int zVelX;//只有x轴有速度；不会跨越行；每个僵尸有自己不同的速度 

	SDL_Rect ZombCollision;//由ZombWidth 和 ZombHeight 赋值

	Meet meetflag;
};

class zombieMove :zColliAndMove
{
public:
	zombieMove(int zposx, int zposy, int zvelx);
	~zombieMove();
private:
	//int zVelX;

};
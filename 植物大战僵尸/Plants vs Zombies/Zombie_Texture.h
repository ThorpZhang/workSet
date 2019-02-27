#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"SDL_anigif.h"
#include<string>
#include"Vector.h"

using namespace std;

class ZomTexture
{
public:
	void free();

	bool TextureloadFromFile(string path, Vector<SDL_Texture *>tex , int texW, int texH, SDL_Renderer *renderer);//供派生类调用以加载纹理

	void DestroyTexture(Vector<SDL_Texture *> tex);

    void render(int x, int y, SDL_Rect *clip, Vector<SDL_Texture *>tex, int texW, int texH, SDL_Renderer *renderer, int currFrame) ;

	int walkgetWidth();
	int walkgetHeight();

	int attackgetWidth();
	int attackgetHeight();

	int lostWalkgetWidth();
	int lostWalkgetHeight();

	int lostAttackgetWidth();
	int lostAttackgetHeight();

	int deadgetWidth();
	int deadgetHeight();

	int lostHeadgetWidth();
	int lostHeadgetHeight();

	
protected:
	ZomTexture();
	~ZomTexture();
	Vector<SDL_Texture*> walkTexture;
	int walkWidth;
	int walkHeight;

	Vector<SDL_Texture *>attackTexture;
	int attackWidth;
	int attackHeight;

	Vector<SDL_Texture *>lostWalkTexture;
	int lostWalkWidth;
	int lostWalkHeight;

	Vector<SDL_Texture *>lostAttackTexture;
	int lostAttackWidth;
	int lostAttackHeight;

	Vector<SDL_Texture *>deadTexture;
	int deadWidth;
	int deadHeight;

	Vector<SDL_Texture *>lostHeadTexture;
	int lostHeadWidth;
	int lostHeadHeight;

};

class ZombieTexture :public ZomTexture
{
public:
	ZombieTexture();
	~ZombieTexture();
    bool loadFromFile(string path1, string path2, string path3, string path4, string path5, string path6, SDL_Renderer *renderer);

private:
	
};
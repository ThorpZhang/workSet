#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include"SDL_anigif.h"
#include"Vector.h"

using namespace std;

class PlantTexture
{
public:

	void free();

	bool TextureloadFromFile(string path,Vector<SDL_Texture*> tex,int texW,int texH, SDL_Renderer *renderer);

	void DestroyTexture(Vector<SDL_Texture*> tex);

	virtual void render()=0;

	int norGetWidth();
	int norGetHeight();
	
protected:
	PlantTexture();
	~PlantTexture();

	Vector<SDL_Texture *>norTexture;
	int norWidth;
	int norHeight;

	
};

class PeaShooterTexture :public PlantTexture
{
public:
	PeaShooterTexture();
	~PeaShooterTexture();
	
	void highfree();

	bool loadFromFile(string path1, string path2);
private:
	Vector<SDL_Texture*> attackTexture;
	int attackWidth;
	int attackHeight;

};

class SunFlowerTexture :public PlantTexture
{
public:
	SunFlowerTexture();
	~SunFlowerTexture();
	bool loadFromFile(string path1);
};
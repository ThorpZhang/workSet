#pragma once
#include<cstdio>
#include"include\SDL.h"
#include"include\SDL_ttf.h"
#include"include\SDL_image.h"
#include<string>

using namespace std;

class GroundTexture
{
public:
	GroundTexture();
	~GroundTexture();

	void Destroy();

	void free();

	bool loadFromFile(string path, SDL_Renderer *renderer);

	bool loadFromRenderedText(string d, SDL_Color textColor, TTF_Font *gFont, SDL_Renderer *mRenderer);

//	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void render(SDL_Renderer *renderer);
	void render( SDL_Rect renderQ, SDL_Renderer *renderer);
	void render(int x, int y, SDL_Rect renderQ, SDL_Renderer *renderer);
	void render(int x, int y,SDL_Renderer *renderer);

	int getWidth();
	int getHeight();
protected:
	SDL_Texture *groundTexture;
	
	int Width;
	int Height;
};
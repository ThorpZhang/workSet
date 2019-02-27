#pragma once
#include<cstdio>
#include"include\SDL.h"
#include"include\SDL_image.h"
#include"SDL_anigif.h"
#include<string>
#include"Vector.h"

using namespace std;

class PandZ_Texture
{
public:
	
	PandZ_Texture();
	~PandZ_Texture();

	void free();

	void DestroyTexture(Vector<SDL_Texture *>tex);

	bool TextureloadFromFile(string path,SDL_Renderer *renderer);

	void render(int x, int y ,SDL_Rect *clip ,SDL_Renderer *renderer);
	void render(SDL_Rect renderQ, SDL_Renderer* renderer);

	int getWidth();
	int getHeight();

	void nextFrame();
private:
	Vector<SDL_Texture *>mTexture;

	int mWidth, mHeight;

	int sumFrame;

	int currFrame;//尝试让每个对象有自己的currFrame 来跟踪渲染当前帧
};
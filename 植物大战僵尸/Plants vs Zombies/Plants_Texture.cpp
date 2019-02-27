#pragma once
#include"Plants_Texture.h"


PlantTexture::PlantTexture()
{
	norWidth = 0;
	norHeight = 0;
}
PlantTexture::~PlantTexture()
{
	free();
}

void PlantTexture::DestroyTexture(Vector<SDL_Texture*> tex)
{
	while (!tex.empty())
	{
		SDL_DestroyTexture(tex.pop());
	}
	tex.clear();
}

void PlantTexture::free()
{
	if (!norTexture.empty())
	{
		DestroyTexture(norTexture);
		norWidth = 0;
		norHeight = 0;
	}
}

bool PlantTexture::TextureloadFromFile(string path, Vector<SDL_Texture*> tex, int texW, int texH, SDL_Renderer *renderer)
{
	free();
//	SDL_Renderer *tempRenderer;// 临时的渲染器，函数调用结束后应该销毁，可能会出错
	int num = AG_LoadGIF(path.c_str(), NULL, 0);
	AG_Frame *frames = new AG_Frame[num];
	AG_LoadGIF(path.c_str(), frames, num);
	texW = frames[0].surface->w;
	texH = frames[0].surface->h;
	for (int i = 0; i < num; i++)
	{
		if (frames[i].surface == NULL)
		{
			printf("surface is NULL! \n");
			return false;
		}
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, frames[i].surface);
		if (texture == NULL)
		{
			printf("texture is NULL!\n");
			return false;
		}
		tex.push_back(texture);
	}
//	SDL_DestroyRenderer(tempRenderer);
	AG_FreeSurfaces(frames, num);
	//SDL_FreeSurface(&texture);
	return true;
}

int PlantTexture::norGetHeight()
{
	return norHeight;
}
int PlantTexture::norGetWidth()
{
	return norWidth;
}

PeaShooterTexture::PeaShooterTexture():PlantTexture()
{
	attackHeight = 0;
	attackWidth = 0;
}

PeaShooterTexture::~PeaShooterTexture()
{
	highfree();
}

void PeaShooterTexture::highfree()
{
	if (!attackTexture.empty())
	{
		DestroyTexture(attackTexture);
		attackHeight = 0;
		attackWidth = 0;
	}
}

bool PeaShooterTexture::loadFromFile(string path1, string path2)
{
	if (!TextureloadFromFile(path1, norTexture, norWidth, norHeight))
	{
		printf("fail to loadGIF:%s\n", path1.c_str());
		return false;
	}
	else
	{
		if (!TextureloadFromFile(path2, attackTexture, attackWidth, attackHeight))
		{
			printf("fail to loadGIF:%s\n", path2.c_str());
			return false;
		}
	}
	return true;
}

SunFlowerTexture::SunFlowerTexture():PlantTexture(){}

SunFlowerTexture::~SunFlowerTexture(){}

bool SunFlowerTexture::loadFromFile(string path1)
{
	if (!TextureloadFromFile(path1, norTexture, norWidth, norHeight))
	{
		printf("fail to loadGIF:%s\n", path1.c_str());
		return false;
	}
	return true;
}
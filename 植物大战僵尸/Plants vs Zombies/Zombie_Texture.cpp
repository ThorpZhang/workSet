#pragma once
#include"Zombie_Texture.h"
//#include"Vector.h"


ZomTexture::ZomTexture()
{
//	walkTexture = NULL;
	int walkWidth = 0;
	int walkHeight = 0;

//	attackTexture = NULL;
	int attackWidth = 0;
	int attackHeight = 0;

//	lostWalkTexture = NULL;
	int lostWalkWidth = 0;
	int lostWalkHeight = 0;

//	lostAttackTexture = NULL;
	int lostAttackWidth = 0;
	int lostAttackHeight = 0;

//	lostHeadTexture = NULL;
	int lostHeadWidth = 0;
	int lostHeadHeight = 0;

//	deadTexture = NULL;
	int deadWidth = 0;
	int deadHeight = 0;
}
ZomTexture::~ZomTexture()
{
	free();
}
void ZomTexture::free()
{
	if ((walkTexture.empty() && attackTexture.empty() && lostWalkTexture.empty() && lostAttackTexture.empty() && lostHeadTexture.empty() && deadTexture.empty()) != true)
	{
		DestroyTexture(walkTexture);
//		walkTexture = NULL;
		int walkWidth = 0;
		int walkHeight = 0;

		DestroyTexture(attackTexture);
//		attackTexture = NULL;
		int attackWidth = 0;
		int attackHeight = 0;

		DestroyTexture(lostWalkTexture);
//		lostWalkTexture = NULL;
		int lostWalkWidth = 0;
		int lostWalkHeight = 0;

		DestroyTexture(lostAttackTexture);
//		lostAttackTexture = NULL;
		int lostAttackWidth = 0;
		int lostAttackHeight = 0;

		DestroyTexture(lostHeadTexture);
//		lostHeadTexture = NULL;
		int lostHeadWidth = 0;
		int lostHeadHeight = 0;

		DestroyTexture(deadTexture);
//		deadTexture = NULL;
		int deadWidth = 0;
		int deadHeight = 0;
	}
}

void ZomTexture::DestroyTexture(Vector<SDL_Texture *> tex)
{
	while (!tex.empty())
	{
		SDL_DestroyTexture(tex.pop());
	}
	tex.clear();
}

int ZomTexture::walkgetHeight()
{
	return walkHeight;
}

int ZomTexture::walkgetWidth()
{
	return walkWidth;
}

int ZomTexture::attackgetHeight()
{
	return attackHeight;
}
int ZomTexture::attackgetWidth()
{
	return attackWidth;
}

int ZomTexture::lostWalkgetHeight()
{
	return lostWalkHeight;
}
int ZomTexture::lostWalkgetWidth()
{
	return lostWalkWidth;
}

int ZomTexture::lostAttackgetHeight()
{
	return lostAttackHeight;
}
int ZomTexture::lostAttackgetWidth()
{
	return lostAttackWidth;
}

int ZomTexture::lostHeadgetHeight()
{
	return lostHeadHeight;
}
int ZomTexture::lostHeadgetWidth()
{
	return lostHeadWidth;
}

int ZomTexture::deadgetHeight()
{
	return deadHeight;
}
int ZomTexture::deadgetWidth()
{
	return deadWidth;
}

bool ZomTexture::TextureloadFromFile(string path, Vector<SDL_Texture *>tex , int texW, int texH, SDL_Renderer *renderer)
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

void ZomTexture::render(int x, int y, SDL_Rect *clip, Vector<SDL_Texture *> tex, int texW, int texH ,SDL_Renderer *renderer, int currFrame)
{
	SDL_Rect renderQuad = { x,y,texW,texH };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy(renderer, tex.at((currFrame+1)%, clip, &renderQuad);
}

ZombieTexture::ZombieTexture():ZomTexture(){}

ZombieTexture::~ZombieTexture()
{
	free();
}

bool ZombieTexture::loadFromFile(string path1,string path2,string path3,string path4, string path5, string path6, SDL_Renderer *renderer)
{
	if (!TextureloadFromFile(path1, walkTexture, walkWidth, walkHeight,renderer))
	{
		printf("fail to loadGIF %s\n", path1.c_str());
		return false;
	}
	else
	{
		if (!TextureloadFromFile(path2, attackTexture, attackWidth, walkHeight,renderer))
		{
			printf("fail to loadGIF %s\n", path2.c_str());
			return false;
		}
		else
		{
			if (!TextureloadFromFile(path3, lostWalkTexture, lostWalkWidth, lostWalkHeight,renderer))
			{
				printf("fail to loadGIF %s\n", path3.c_str());
				return false;
			}
			else
			{
				if (!TextureloadFromFile(path4, lostAttackTexture, lostAttackWidth, lostAttackHeight,renderer))
				{
					printf("fail to loadGIF %s\n", path4.c_str());
					return false;
				}
				else
				{
					if (!TextureloadFromFile(path5, deadTexture, deadWidth, deadHeight,renderer))
					{
						printf("fail to loadGIF %s\n", path5.c_str());
						return false;
					}
					else
					{
						if (!TextureloadFromFile(path6, lostHeadTexture, lostHeadWidth, lostHeadHeight,renderer))
						{
							printf("fail to loadGIF %s\n", path6.c_str());
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}
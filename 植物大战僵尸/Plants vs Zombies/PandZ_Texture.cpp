#pragma once
#include"PandZ_Texture.h"

PandZ_Texture::PandZ_Texture()
{
	mWidth = 0;
	mHeight = 0;
	sumFrame = 0;
	currFrame = 0;
}

PandZ_Texture::~PandZ_Texture()
{
	free();
}

void PandZ_Texture::free()
{
	if (!mTexture.empty())
	{
		DestroyTexture(mTexture);
		mWidth = 0;
		mHeight = 0;
		sumFrame = 0;
		currFrame = 0;
	}
}

void PandZ_Texture::DestroyTexture(Vector<SDL_Texture *>tex)
{
	while (!tex.empty())
	{
		SDL_DestroyTexture(tex.pop());
	}
	tex.clear();
}

bool PandZ_Texture::TextureloadFromFile(string path, SDL_Renderer *renderer)
{
	free();
	//	SDL_Renderer *tempRenderer;// 临时的渲染器，函数调用结束后应该销毁，可能会出错
	int num = AG_LoadGIF(path.c_str(), NULL, 0);
	AG_Frame *frames = new AG_Frame[num];
	sumFrame = num;
	AG_LoadGIF(path.c_str(), frames, num);
	mWidth = frames[0].surface->w;
	mHeight = frames[0].surface->h;
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
		mTexture.push_back(texture);
	}
	//	SDL_DestroyRenderer(tempRenderer);
	AG_FreeSurfaces(frames, num);
	//SDL_FreeSurface(&texture);
	return true;
}

void PandZ_Texture::render(int x, int y , SDL_Rect *clip, SDL_Renderer *renderer)
{
	SDL_Rect renderQuad = { x,y,mWidth,mHeight };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy(renderer, mTexture.at(currFrame++%sumFrame) , clip, &renderQuad);
}

void PandZ_Texture::render(SDL_Rect renderQ, SDL_Renderer *renderer)
{
	SDL_Rect renderQuad = renderQ;
	renderQuad.x -= 20;
	renderQuad.y -= 20;
	SDL_RenderCopy(renderer, mTexture.at(currFrame%mTexture.size()), NULL, &renderQuad);
}

int PandZ_Texture::getWidth()
{
	return mWidth;
}

int PandZ_Texture::getHeight()
{
	return mHeight;
}

void PandZ_Texture::nextFrame()
{
	currFrame++;
}
#pragma once
#include"Ground_Texture.h"

GroundTexture::GroundTexture()
{
	groundTexture = NULL;
	Width = 0;
	Height = 0;
}

GroundTexture::~GroundTexture()
{
	free();
}

void GroundTexture::Destroy()
{
	SDL_DestroyTexture(groundTexture);
}

void GroundTexture::free()
{
	if (groundTexture != NULL)
	{
		SDL_DestroyTexture(groundTexture);
		groundTexture = NULL;
		Width = 0;
		Height = 0;
	}
}

bool GroundTexture::loadFromFile(string path, SDL_Renderer *renderer)
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s,IMG_Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create Texture from %s, SDL_Error: %s\n", path.c_str(), SDL_GetError());
		}
		else {
			Width = loadedSurface->w;
			Height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	groundTexture = newTexture;
	return groundTexture != NULL;
}

void GroundTexture::render(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, groundTexture, NULL, NULL);
	//SDL_RenderPresent(renderer);
}

void GroundTexture::render(SDL_Rect renderQ, SDL_Renderer* renderer)
{
//	renderQ.x = x;
//	renderQ.y = y;
	SDL_RenderCopy(renderer, groundTexture, NULL, &renderQ);
}

void GroundTexture::render(int x, int y,SDL_Rect renderQ, SDL_Renderer* renderer)
{
		renderQ.x = x;
		renderQ.y = y;
	SDL_RenderCopy(renderer, groundTexture, NULL, &renderQ);
}

int GroundTexture::getHeight()
{
	return Height;
}

int GroundTexture::getWidth()
{
	return Width;
}

bool GroundTexture::loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font *gFont ,SDL_Renderer *gRenderer)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		groundTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (groundTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			Width = textSurface->w;
			Height = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return groundTexture != NULL;
}

void GroundTexture::render(int x, int y,SDL_Renderer *gRenderer)
{
	SDL_Rect renderQuad = { x, y,Width,Height };
	SDL_RenderCopy(gRenderer, groundTexture, NULL, &renderQuad);
}
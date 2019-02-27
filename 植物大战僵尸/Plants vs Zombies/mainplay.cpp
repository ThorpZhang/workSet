#pragma once
#include<cstdio>
#include"include\SDL.h"
#include"include\SDL_image.h"
#include<string>
#include"PandZ_Texture.h"
#include"Ground_Texture.h" 
#include"Button.h"
#include"Plants.h"
#include"Zombies.h"
#include"List.h"
#include"Pea.h"
#include"include\SDL_ttf.h"


using namespace std;

//******************种子结构*****************************
/*
enum planttype
{
	NONE = 0,
	SUNFLOWER = 1,
	PEASHOOTER = 2
};
*/
class  seedButton
{
public:
//	planttype flag;
	LButton button;
	GroundTexture back;
	GroundTexture plant;
	SDL_Rect backrenderQ;
	SDL_Rect plantrenderQ;
	seedButton() :button(), back(), plant() { waitseeded = false; }

	bool waitseeded;

	void setseed()
	{
		if (button.getState() == MOUSE_BUTTON_DOWN)
			waitseeded = true;
	//	if (waitseeded == true) printf("waitseeded true\n");
	}

	bool getseed()
	{
		return waitseeded;
	}
};
//******************地板按钮*****************************

//*******************************************************
class Game
{

public:
	Game():mWindow(NULL),mRenderer(NULL){}

	~Game(){}

	bool init();
	bool load();

	bool loadTexture();

	bool initBackAndButton();

	bool initSeedButton();

	void initScreen();

	void initPits();

	void initZombie();

	bool loadTTF();

	void backButtonHandleE(SDL_Event e);

	void seedButtonHandleE(SDL_Event e);

	void backButtonrenderCube();

	void seedButtonrender();

	void wakeplant();//唤醒植物

	void wakeZombies();

	void zombmove(bool & f);

	void killPlant();

	void makebullet();

	void makeSun();

	void killZombie();

	void initlogic();

	void dologic( bool & f);

	void setseeded();

	void renderTTF();

	void renderFail();

	void render();

	void close();

	int gettime() { return Timer.getTicks(); }

	SDL_Renderer* getRenderer() { return mRenderer; }

private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;

	//*****************************背景图片**********************************************
	GroundTexture groundTexture;
	GroundTexture colorCube;//颜色亮块；
	//******************************按钮*************************************************
	LButton button[5][9];
	//*****************************普遍僵尸的六种纹理************************************
	PandZ_Texture walkZom_Texture;
	PandZ_Texture attackZom_Texture;
	PandZ_Texture lostHeadZom_Texture;
	PandZ_Texture lostAttackZom_Texture;
	PandZ_Texture lostHead_Texture;
	PandZ_Texture dead_Texture;

	//*****************************向日葵************************************************
	PandZ_Texture sumFlower;

	//*****************************豌豆射手**********************************************
	PandZ_Texture peaShoot_nor_Texture;
	PandZ_Texture peaShoot_attack_Texture;
	List<Peabulletlogic> shooter;
	GroundTexture pea;

	//*****************************向日葵和豌豆射手的种子********************************
	seedButton SFseed;
	seedButton PSseed;
	TTF_Font* sunFont;
	GroundTexture sunTextTexture;
	TTF_Font* peaFont;
	GroundTexture peaTextTexture;
	//*****************************植物坑************************************************
	Plantlogic plantPits[5][9];
	//*****************************僵尸大军**********************************************
	Zombies zombie[5][102];
	//*****************************计时器************************************************
	LTimer Timer;
	//*****************************阳光显示器********************************************
	seedButton sunBank;
	TTF_Font *sFont = NULL;
	int sunValue;
	LTimer sunTimer;
	//*****************************failSrc***********************************************
	GroundTexture failTex;
};

bool Game::init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error:%s\n", SDL_GetError());
		success = false;
	}
	else {
		mWindow = SDL_CreateWindow(u8"植物大战僵尸", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 640, SDL_WINDOW_SHOWN);
		if (mWindow == NULL) {
			printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
			success = false;
		}
		else {
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == NULL) {
				printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlag = IMG_INIT_PNG;
				if (!IMG_Init(imgFlag)&imgFlag) {
					printf("PNG could not be initialized! IMG_Error: %s\n", IMG_GetError());
					success = false;
				}
				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool Game::loadTexture()
{
	bool success = true;
	if (!walkZom_Texture.TextureloadFromFile("Resources/Zombies/Zombie/Zombie.gif", mRenderer))
	{
		printf("fail to load walkZom_Texture!\n");
		success = false;
	}
	if (!attackZom_Texture.TextureloadFromFile("Resources/Zombies/Zombie/ZombieAttack.gif", mRenderer))
	{
		printf("fail to load attackZom_Texture!\n");
		success = false;
	}
	if (!lostHeadZom_Texture.TextureloadFromFile("Resources/Zombies/Zombie/ZombieLostHead.gif", mRenderer))
	{
		printf("fail to load lostHeadZom_Texture!\n");
		success = false;
	}
	if (!lostAttackZom_Texture.TextureloadFromFile("Resources/Zombies/Zombie/ZombieLostHeadAttack.gif", mRenderer))
	{
		printf("fail to load lostAttack_Texture!\n");
		success = false;
	}
	if (!lostHead_Texture.TextureloadFromFile("Resources/Zombies/Zombie/ZombieHead.gif", mRenderer))
	{
		printf("fail to load lostHead_Texture!\n");
		success = false;
	}
	if (!dead_Texture.TextureloadFromFile("Resources/Zombies/Zombie/ZombieDie.gif",mRenderer))
	{
		printf("fail to load dead_Texture!\n");
		success = false;
	}	
	if (!peaShoot_nor_Texture.TextureloadFromFile("Resources/Plants/PeaShooter/PeaShooter.gif", mRenderer))
	{
		printf("fail to load peaShooter_Texture!\n");
		success = false;
	}
	if (!sumFlower.TextureloadFromFile("Resources/Plants/SunFlower/SunFlower1.gif", mRenderer))
	{
		printf("fail to load sunFlower!\n");
		success = false;
	}
	if (!pea.loadFromFile("Resources/ProjectilePea.png", mRenderer))
	{
		printf("fail to load pea!\n");
		success = false;
	}
	if (!failTex.loadFromFile("Resources/ZombiesWon.jpg", mRenderer))
	{
		printf("fail to load failTex\n");
		success = false;
	}
	return success;
} 

bool Game::initBackAndButton()
{
	if (!groundTexture.loadFromFile("Resources/background.jpg",mRenderer))
	{
		printf("fail to load backgound!\n");
		return false;
	}
	if (!colorCube.loadFromFile("Resources/colorCube.png", mRenderer))
	{
		printf("fail to load colorCube!\n");
		return false;
	}
	//**********************************************************render?
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			button[i][j].setPosition(280 + 80 * j, 100 + 107 * i);
			button[i][j].setSize(79, 96);
		}
			
}

bool Game::initSeedButton()
{
	SFseed.button.setPosition(40, 40);
	SFseed.button.setSize(100, 150);
	SFseed.backrenderQ = { 40,40,100,150 };
	SFseed.plantrenderQ = { 43,55,99,95 };
	if (!SFseed.back.loadFromFile("Resources/SeedPacket.png", mRenderer))
	{
		printf("fail to load seedButon-backTexture!\n");
		return false;
	}
	if (!SFseed.plant.loadFromFile("Resources/SFseed.png", mRenderer))
	{
		printf("fail to load SFseed.png\n");
		return false;
	}
	PSseed.button.setPosition(40, 210);
	PSseed.button.setSize(100, 150);
	PSseed.backrenderQ = { 40,210,100,150 };
	PSseed.plantrenderQ = { 43,225,99,95 };
	if (!PSseed.back.loadFromFile("Resources/SeedPacket.png", mRenderer))
	{
		printf("fail to load seedButon-backTexture!\n");
		return false;
	}
	if (!PSseed.plant.loadFromFile("Resources/PSseed.png", mRenderer))
	{
		printf("fail to load PSseed.png\n");
		return false;
	}


	sunBank.button.setPosition(40, 390);
	sunBank.button.setSize(0, 0);//没有按钮作用
	sunBank.backrenderQ = { 40,390,90,90 };
	sunBank.plantrenderQ = { 60,444,20,37 };
	//Font renderQ
	if (!sunBank.back.loadFromFile("Resources/SunBank.png", mRenderer))
	{
		printf("fail to load SunBank.png\n");
		return false;
	}
	return true;
}

bool Game::load()
{
	bool success = true;
	if (!loadTexture())
	{
		printf("fail to loadPlants&Zombie Texture!\n");
		success = false;
	}
	else if (!initBackAndButton())
	{
		printf("fail to initBackAndButton !\n");
		success = false;
	}
	else if (!initSeedButton())
	{
		printf("fail to initSeedButton!\n");
		success = false;
	}
	else if (!loadTTF())
	{
		printf("fail to loadTTF!\n");
		success = false;
	}
//	success = loadTexture();
	return success;
}

void Game::initScreen()
{
	groundTexture.render(mRenderer);
	SFseed.back.render(SFseed.backrenderQ, mRenderer);
	SFseed.plant.render(SFseed.plantrenderQ, mRenderer);
	PSseed.back.render(PSseed.backrenderQ, mRenderer);
	PSseed.plant.render(PSseed.plantrenderQ, mRenderer);
	sunBank.back.render(sunBank.backrenderQ, mRenderer);
}

void Game::initPits()
{
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			plantPits[i][j].plantColli.setPos(280 + 80 * j, 100 + 107 * i);
		}
}

void Game::initZombie()
{
	for(int i=0;i<5;i++)
		for (int j = 0; j < 101; j++)
		{
			zombie[i][j].zCAM.setPos(1100 + j * 100, 100 + 107 * i);
		}
}

bool Game::loadTTF()
{
	bool success = true;

	//Open the font
	sFont = TTF_OpenFont("Resources/FreeMonoBold.ttf", 25);
	if (sFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	sunFont = TTF_OpenFont("Resources/FreeMonoBold.ttf", 25);
	if (sunFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	peaFont = TTF_OpenFont("Resources/FreeMonoBold.ttf", 25);
	if (peaFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	return success;
}

void Game::backButtonHandleE(SDL_Event e)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
			button[i][j].handleEvent(&e);
}

void Game::seedButtonHandleE(SDL_Event e)
{
	SFseed.button.handleEvent(&e);
	PSseed.button.handleEvent(&e);
}

void Game::backButtonrenderCube()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			if (button[i][j].getState() == MOUSE_OVERMOTION)
			{
				SDL_Rect renderQ = { button[i][j].getPos().x,button[i][j].getPos().y,55,70 };
				colorCube.render(renderQ, mRenderer);
			}
		}
}

void Game::seedButtonrender()
{
	if (SFseed.button.getState() == MOUSE_OVERMOTION)
		sumFlower.render(SFseed.plantrenderQ, mRenderer);
	if (PSseed.button.getState() == MOUSE_OVERMOTION)
		peaShoot_nor_Texture.render(PSseed.plantrenderQ, mRenderer);

}

void Game::wakeplant()
{
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			if (button[i][j].getState() == MOUSE_BUTTON_DOWN)
			{
//				if (plantPits[i][j].plantColli.getflag() == SunFlower)printf("Sunflower true\n");
//				else printf("Sunflower false\n");
				if (SFseed.waitseeded == true && sunValue>=50)
				{
					plantPits[i][j].plantColli.changeplantflag() = SunFlower;
					sunValue -= 50;
//					if (plantPits[i][j].plantColli.getflag() == SunFlower)printf("Sunflower true\n");
//					else printf("Sunflower false\n");
					SFseed.waitseeded = false;
				}
				else if (PSseed.waitseeded == true && sunValue>=100)
				{
					plantPits[i][j].plantColli.changeplantflag() = PeaShooter;
					sunValue -= 100;
					PSseed.waitseeded = false;
				}
				else{/* do nothing */}
			}
		}
}

void Game::wakeZombies()
{
	if (Timer.getTicks()>=5000  && Timer.getTicks()<=5100)
	{
		zombie[2][0].zCAM.setVel(1); //zombie[2][0].HP = 6;
	}
	if (Timer.getTicks() >= 20000 && Timer.getTicks() <= 20100)
	{
		zombie[1][0].zCAM.setVel(1); //zombie[1][0].HP = 6;
		zombie[0][0].zCAM.setVel(1); //zombie[0][0].HP = 6;
	}
	if (Timer.getTicks() >= 30000 && Timer.getTicks() <= 30100)
	{
		zombie[3][0].zCAM.setVel(1); //zombie[3][0].HP = 6;
		zombie[4][0].zCAM.setVel(1); //zombie[4][0].HP = 6;
	}
	if (Timer.getTicks() >= 33000 && Timer.getTicks() < 33100)
	{
		zombie[0][1].zCAM.setVel(1); //zombie[0][1].HP = 6;
		zombie[0][2].zCAM.setVel(1); //zombie[0][2].HP = 6;
	}
	if (Timer.getTicks() >= 38000 && Timer.getTicks() < 38100)
	{
		zombie[3][1].zCAM.setVel(1); //zombie[3][1].HP = 6;
		zombie[3][2].zCAM.setVel(1); //zombie[3][2].HP = 6;
		zombie[3][3].zCAM.setVel(1);// zombie[3][3].HP = 6;
	}
	if (Timer.getTicks() >= 45000 && Timer.getTicks() < 45100)
	{
		zombie[1][1].zCAM.setVel(1);// zombie[1][1].HP = 6;
		zombie[1][2].zCAM.setVel(1); //zombie[1][2].HP = 6;
		zombie[1][3].zCAM.setVel(1);// zombie[1][3].HP = 6;
		zombie[2][1].zCAM.setVel(1);// zombie[2][1].HP = 6;
		zombie[2][2].zCAM.setVel(1); //zombie[2][2].HP = 6;
		zombie[4][1].zCAM.setVel(1);// zombie[4][1].HP = 6;
		zombie[4][2].zCAM.setVel(1);// zombie[4][2].HP = 6;
		zombie[4][3].zCAM.setVel(1);// zombie[4][3].HP = 6;
	}
	for(int i=1;i<5;i++)
		if (Timer.getTicks() >= 48000 + i * 1000)
		{
			for(int rank=0;rank<5;rank++)
				for (int j = 5+(i-1)*10; j < i * 10 + 5; j++)
				{
					zombie[rank][j].zCAM.setVel(2);
					//zombie[rank][j].HP = 6;
				}
		}
	for (int i = 1; i<5; i++)
		if (Timer.getTicks() >= 82000 + i * 1000)
		{
			for (int rank = 0; rank<5; rank++)
				for (int j = 5 + (i - 1) * 10; j < i * 10 + 5; j++)
				{
					zombie[rank][j].zCAM.setVel(3);
					//zombie[rank][j].HP = 6;
				}
		}
		
}

void Game::zombmove( bool & f)
{
	for(int i=0;i<5;i++)
		for (int j = 0; j < 101; j++)
		{
				if (zombie[i][j].HP > 0 ) 
				{
					int tempk = 0, s = 9999, temps = 0;
					for (int k = 0; k < 9; k++)//获取最近植物
					{
						temps = zombie[i][j].zCAM.getPosX() - plantPits[i][k].plantColli.getPosX();
						if (temps < s &&  temps>0) { s = temps; tempk = k; }
					}
					if (zombie[i][j].zCAM.move(plantPits[i][tempk].plantColli.getColli(),plantPits[i][tempk].plantColli.getflag()) == meetPlant )
					{
						plantPits[i][tempk].meetZombie = true;
						zombie[i][j].attackflag = true;
//						printf("111111111111111111111111111111\n");
					}
					else {
						if (zombie[i][j].zCAM.getPosX() < 1050) {
						zombie[i][j].attackflag = false;
						if (tempk == 0 && tempk == 8) {}
						else
						{
							plantPits[i][tempk].meetZombie = false;
						}
					}
					}
					if (zombie[i][j].zCAM.getPosX() < 150) f = true;
//					else printf(" %s \n",)
				}
		}
}

void Game::killPlant()
{
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			if (plantPits[i][j].plantColli.getflag() != Nothing)
			{
				if (plantPits[i][j].timer.getTicks() >= 5000)
				{
					plantPits[i][j].plantColli.changeplantflag() = Nothing;
					plantPits[i][j].timer.stop();
					plantPits[i][j].meetZombie = false;
				}
				if (plantPits[i][j].meetZombie == true)
				{
//					printf("meetzombie true %d %d\n", i, j);
					if (plantPits[i][j].timer.isPaused() == true)
						plantPits[i][j].timer.unpause();
					if (plantPits[i][j].timer.isStarted() == false)
						plantPits[i][j].timer.start();
				}
				if (plantPits[i][j].meetZombie == false)
				{
					if (plantPits[i][j].timer.isPaused() == false)
						plantPits[i][j].timer.pause();
				}
//				printf("%d  %d		%d		%d		 \n", i,j,plantPits[i][j].plantColli.getflag(), plantPits[i][j].timer.getTicks());
			}
		}
	
}

void Game::makebullet()
{
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			
				if (plantPits[i][j].plantColli.getflag() == PeaShooter)
				{
					int finalk = 0, temps=0, s=9999;//获取最近僵尸的距离
					for (int k = 0; k < 101; k++)
					{
						if (zombie[i][k].HP > 0)
						{
							temps = zombie[i][k].zCAM.getPosX() - plantPits[i][j].plantColli.getPosX();
							if (temps<s  && temps>0)
							{
								s = temps;
								finalk = k;
							}
						}
					}
					plantPits[i][j].plantColli.checkZombie(zombie[i][finalk].zCAM.getColli());
					if (plantPits[i][j].plantColli.getAttackFlag() == true &&zombie[i][finalk].HP>0)
					{
						if (plantPits[i][j].attackTimer.isStarted() == false) {
							plantPits[i][j].attackTimer.start();
						}
						else {}
					}
					else if (plantPits[i][j].plantColli.getAttackFlag() == false || zombie[i][finalk].HP<=0)
					{
						if (plantPits[i][j].attackTimer.isStarted())
							plantPits[i][j].attackTimer.stop();
					}
					if (plantPits[i][j].attackTimer.getTicks() >= 1000)
					{
						Peabulletlogic bullet;
						bullet.setPos(plantPits[i][j].plantColli.getPosX(), plantPits[i][j].plantColli.getPosY());
						bullet.setRow(i);
						shooter.push_back(bullet);
						plantPits[i][j].attackTimer.stop();
					}
				}
			
		}
}

void Game::makeSun()
{
	if (!sunTimer.isStarted())
	{
		sunTimer.start();
	}
	else if (sunTimer.isStarted())
	{
		if (sunTimer.getTicks() >= 5000)
		{
			sunValue += 25;
			sunTimer.stop();
		}
	}
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			if (plantPits[i][j].plantColli.getflag() == SunFlower)
			{
				if (!plantPits[i][j].makeSTimer.isStarted())
				{
					plantPits[i][j].makeSTimer.start();
				}
				else if(plantPits[i][j].makeSTimer.isStarted())
				{
					if (plantPits[i][j].makeSTimer.getTicks() >= 5000)
					{
						sunValue += 25;
						plantPits[i][j].makeSTimer.stop();
					}
				}
			}
		}
}

void Game::killZombie()
{
	List<Peabulletlogic>::iterator &itr = shooter.begin();
	if (!shooter.empty()) {
		if ((*itr).getBroken() == false && !shooter.empty())
		{
			int fk = 0, s = 9999, temps = 0;
			for (int k = 0; k < 101; k++)
			{
				if (zombie[(*itr).getRow()][k].HP > 0)
				{
					temps = zombie[(*itr).getRow()][k].zCAM.getPosX() - (*itr).getPosX();
					if (temps < s && temps>0)
					{
						s = temps;
						fk = k;
					}
				}
				/*
				(*itr).move(zombie[(*itr).getRow()][k].zCAM.getColli(), zombie[(*itr).getRow()][k].HP);
				if ((*itr).getBroken() == true && zombie[(*itr).getRow()][k].HP > 0)
				{
					zombie[(*itr).getRow()][k].HP--;
				}*/
			}
			(*itr).move(zombie[(*itr).getRow()][fk].zCAM.getColli(), zombie[(*itr).getRow()][fk].HP);
			if ((*itr).getBroken() == true && zombie[(*itr).getRow()][fk].HP > 0)
			{
				zombie[(*itr).getRow()][fk].HP--;
			}
		}
	
	while ((itr++)!=shooter.end())
	{
//		itr++;
		int fk = 0, s = 9999, temps = 0;
		if ((*itr).getBroken() == false)
		{
			for (int k = 0; k < 101; k++)
			{
				if (zombie[(*itr).getRow()][k].HP > 0)
				{
					temps = zombie[(*itr).getRow()][k].zCAM.getPosX() - (*itr).getPosX();
					if (temps < s && temps>0)
					{
						s = temps;
						fk = k;
					}
				}/*
				(*itr).move(zombie[(*itr).getRow()][k].zCAM.getColli(), zombie[(*itr).getRow()][k].HP);
				if ((*itr).getBroken() == true && zombie[(*itr).getRow()][k].HP > 0)
				{
					zombie[(*itr).getRow()][k].HP--;
				}*/
			}
			(*itr).move(zombie[(*itr).getRow()][fk].zCAM.getColli(), zombie[(*itr).getRow()][fk].HP);
			if ((*itr).getBroken() == true && zombie[(*itr).getRow()][fk].HP > 0)
			{
				zombie[(*itr).getRow()][fk].HP--;
			}
		}
	}
}
}

void Game::initlogic()
{
	sunValue = 0;
	initPits();
	initZombie();
	Timer.start();
}

void Game::dologic(bool & f)
{
	wakeplant();
	wakeZombies();
	zombmove(f);
	makebullet();
	killPlant();
	killZombie();
	makeSun();
}

void Game::renderTTF()
{
	SDL_Color textColor = { 0, 0, 0 };
	if (!sunBank.plant.loadFromRenderedText(to_string(sunValue), textColor, sFont, mRenderer))
	{
//		printf("Failed to render text texture!\n");
	}
	sunBank.plant.render(sunBank.plantrenderQ.x,sunBank.plantrenderQ.y, mRenderer);
	if (!sunTextTexture.loadFromRenderedText(to_string(50), textColor, sFont, mRenderer)){}
	sunTextTexture.render(69, 150, mRenderer);
	if (!peaTextTexture.loadFromRenderedText(to_string(100), textColor, sFont, mRenderer)) {}
	peaTextTexture.render(55, 320, mRenderer);
}

void Game::renderFail()
{
	failTex.render(mRenderer);
}

void Game::render()
{
	renderTTF();
	sumFlower.nextFrame();
	peaShoot_nor_Texture.nextFrame();
	walkZom_Texture.nextFrame();
	attackZom_Texture.nextFrame();
	lostHeadZom_Texture.nextFrame();
	lostAttackZom_Texture.nextFrame();
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			if (plantPits[i][j].plantColli.getflag() == SunFlower)
			{
				sumFlower.render(plantPits[i][j].plantColli.getColli(), mRenderer);
			}
			if (plantPits[i][j].plantColli.getflag() == PeaShooter)
			{
				peaShoot_nor_Texture.render(plantPits[i][j].plantColli.getColli(), mRenderer);
			}
		}
	for(int i=0;i<5;i++)
		for (int j = 0; j < 101; j++)
		{
			if (zombie[i][j].HP > 3 && zombie[i][j].attackflag == false)
				walkZom_Texture.render(zombie[i][j].zCAM.getColli(), mRenderer);
			else if (zombie[i][j].HP > 3 && zombie[i][j].attackflag == true)
				attackZom_Texture.render(zombie[i][j].zCAM.getColli(), mRenderer);
			else if (zombie[i][j].HP <= 3 && zombie[i][j].HP > 0 && zombie[i][j].attackflag == false)
				lostHeadZom_Texture.render(zombie[i][j].zCAM.getColli(), mRenderer);
			else if (zombie[i][j].HP <= 3 && zombie[i][j].HP > 0 && zombie[i][j].attackflag == true)
				lostAttackZom_Texture.render(zombie[i][j].zCAM.getColli(), mRenderer);
			else {}
		}
	if (!shooter.empty())
	{
		int num = 1;
		List<Peabulletlogic>::iterator &itr = shooter.begin();
		if ((*itr).getBroken() == false)
		{
			pea.render((*itr).getColli(), mRenderer);
//			printf("%d\n", num);
		}
		while ((itr++)!=shooter.end())
		{
			num++;
			if ((*itr).getBroken() == false)
			{
//				printf("%d\n", num);
				pea.render((*itr).getColli(), mRenderer);
			}
		}
	}
}

void Game::setseeded()
{
	SFseed.setseed();
	PSseed.setseed();
}

void Game::close()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
}


int main(int argc, char *args[])
{
	Game game;
	SDL_Event e;//事件	
	bool quit = false;
	bool quit2 = false;
	bool failFlag = false;
	if (!game.init())
	{
		printf("fail to init in main!\n");
	}
	else if (!game.load())
	{
		printf("fail to load resources!\n");
	}
	else
	{
		game.initlogic();
	//	game.initScreen();
	//	SDL_RenderPresent(game.getRenderer());
		while (!quit)
		{
			while (SDL_PollEvent(&e)!=0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				game.backButtonHandleE(e);
				game.seedButtonHandleE(e);
				game.setseeded();
				game.wakeplant();
			}
			
			game.dologic(failFlag);
			SDL_RenderClear(game.getRenderer());
			game.initScreen();
			game.backButtonrenderCube();
			game.seedButtonrender();
			game.render();
			SDL_RenderPresent(game.getRenderer());
			SDL_Delay(50);
			if (failFlag == true) quit = true;
			
		}
		if(failFlag==true)
		while (!quit2)
		{
			while (SDL_PollEvent(&e)!=0)
			{
				if (e.type == SDL_QUIT)
				{
					quit2 = true;
				}
			}
			SDL_RenderClear(game.getRenderer());
			game.renderFail();
			SDL_RenderPresent(game.getRenderer());
		}
	}
//	system("pause");
	game.close();
	return 0;
}
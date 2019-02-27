//cleanmines.h
#pragma once
#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<ctime>
#include"user.h"
#include"Storage.h"
#include"memberService.h"
#include"typeDefinition.h"

#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define ORANGE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define PURPLE FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY

using namespace std;
namespace ManagementSystemV5 {
	const int STARTX = 30;
	const int STARTY = 6;
	const int MAXX = 9;//雷区的宽
	const int MAXY = 9;//雷区的高
	const int BOMBNUMBER = 10;//地雷数量
//	time_t  time0;//记录时间

	class Cube {
	private:
		bool ifHaveBomb;//该方块是否含有炸弹
		bool ifOpen;//该方块有无被玩家翻开
		int nearBombNumber;//该区块周围8格的含有炸弹的方块的数量
	public:
		void setOpen() {
			//将Open的值改为true
			ifOpen = true;
		}
		bool getOpen() {
			//获取ifOpen的值
			return ifOpen;
		}
		void setNearBombNumber(int number) {
			//给nearBombNumber赋值
			nearBombNumber = number;
		}
		void haveBomb() {
			//给方块放置地雷
			ifHaveBomb = true;
		}
		bool getIfHaveBomb() {
			//获取ifHaveBomb的值
			return ifHaveBomb;
		}
		int getNearBombNumber() {
			//获取nearBombNumber的值
			return nearBombNumber;
		}
		void resetCube(bool ifhavebomb = false, bool ifopen = false, int nearbombnumber = 0) {
			//初始化成员数据
			ifHaveBomb = ifhavebomb;
			ifOpen = ifopen;
			nearBombNumber = nearbombnumber;
		}
	};//类定义结束
	//Cube cube[MAXX][MAXY];

	void GoTo(int x, int y);//定位光标
	void setBomb(int bombNumber);//生成bombNumber个炸弹并且放进随机的方块中
	void show();//显示地雷阵
	int checkAndSetNearBombNumber(int x, int y);//检查当前方块周围的雷数量
	void gameStart();//初始化游戏
	void showXY();//显示雷区坐标
	bool Splayers(bool &life);//玩家输入坐标翻开方块
	void ch_message(bool life,childplayer*p);//未成年玩家游戏结束后输出的信息
	void ad_message(bool life, adplayer*p);//成年人玩家游戏结束后输出信息
	void autoOpen(int x, int y);//玩家翻开的方块为不含雷且周围无雷的方块时，自动翻开周围无雷的方块
	bool ifWin();//判断玩家是否扫雷成功
	void showBomb();//游戏结束后显示地雷位置
	void adult_play_cleanmines(adplayer*ap);//成年人玩家启动游戏函数
	void child_play_cleanmines(childplayer*cp);//未成年人玩家启动游戏函数
}
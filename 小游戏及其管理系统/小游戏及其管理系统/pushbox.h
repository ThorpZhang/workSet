#pragma once
#include <stdio.h>  
#include <stdlib.h>
#include <conio.h>
#include<iostream>
#include"user.h"
#include"Storage.h"
#include"memberService.h"
#include"typeDefinition.h"
#define GameScreen_Height 10
#define GameScreen_Width  20
using namespace std;
//定义命名空间ManagementSystemV5
namespace ManagementSystemV5 {
	//int GameScreen[GameScreen_Height][GameScreen_Width] = {}; //定义游戏屏幕
	//char key;//定义用户按键
	struct people
	{
		int x;
		int y;
	};
	struct box
	{
		int x;
		int y;
	};
	struct goal
	{
		int x;
		int y;
	};
	//static people gamer;//定义玩家
	//char control;//定义按键
	void drawWall();//画墙
	void refreshScreen();//清屏
	void printfMassage();//输出游戏规则
	void drawScreen(int *x);//打印屏幕
	void CheckBoxGamerStatus();//监控全局箱子 玩家的状态 一旦重叠就改显示
	void gamerMove();//玩家移动的时候刷新
	void initGamer();//初始化游戏玩家位置
	void refreshGamer();//将游戏玩家加入游戏
	char getDirection();//获取用户当前按键
	void gameControl(char x);//用户移动事件
	bool detectionWin();//检测胜利条件
	void CheckBoxGamerStatus();
	void useMap(int x);
	void useMap1();
	void useMap2();
	void useMap3();
	void initGameScreen();
	//void putBoxStatus(); //测试方法  输出箱子位置
	void putGamerStatus();//测试方法 输出人物位置
	//void putGoalStatus();//测试方法  输出目的地位置
	/*
	0    空地
	1 ○ 人
	2 ⊙ 目的地
	3 □ 箱子
	4 ■ 墙壁
	5 ◎  人和目的地重叠
	6 ◇ 箱子和目的地重叠
	*/
	void play1(childplayer*p);
	void play2(adplayer*p);
}
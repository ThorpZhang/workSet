#include"pushbox.h"
namespace ManagementSystemV5 {
	int GameScreen[GameScreen_Height][GameScreen_Width] = {}; //定义游戏屏幕
	char key;//定义用户按键
	box gameBox[4];
	goal gameGoal[4];
	static people gamer;//定义玩家
	char control;//定义按键
	void drawWall()//创建墙壁
	{   //上墙壁 (0,0) --(0,19)
		//下墙壁 (9,0) --(9,19)
		//左墙壁 (1,0) --(8,0)
		//右墙壁 (1,19) --(8,19)
		int a = 0;
		for (a; a < GameScreen_Width; a++)
		{
			GameScreen[0][a] = 4;
		}//上边
		for (a = 0; a < GameScreen_Width; a++)
		{
			GameScreen[GameScreen_Height - 1][a] = 4;
		}//下边
		for (a = 1; a < GameScreen_Height - 1; a++)
		{
			GameScreen[a][0] = 4;
		}//左边
		for (a = 1; a < GameScreen_Height - 1; a++)
		{
			GameScreen[a][GameScreen_Width - 1] = 4;
		}//右边
	}
	void refreshScreen()//屏幕刷新 
	{
		system("cls");       //刷新屏幕
							 //输出新屏幕
	}
	void drawScreen(int *x)//打印屏幕
	{
		int a;
		CheckBoxGamerStatus();
		for (a = 0; a < GameScreen_Height*GameScreen_Width; a++)
		{


			if (a % 20 == 0) printf("\n");
			switch (*x)
			{
			case 0:printf("  "); break;
			case 1:printf("○"); break;
			case 2:printf("⊙"); break;
			case 3:printf("□"); break;
			case 4:printf("■"); break;
			case 5:printf("◎"); break;
			case 6:printf("◇"); break;
			}
			x++;
		}
		printf("\n");
	}//打印屏幕
	void initGamer()
	{
		gamer.x = 3;
		gamer.y = 5;
		GameScreen[gamer.x][gamer.y] = 1;
	}//初始化玩家位置	 
	void refreshGamer()
	{
		GameScreen[gamer.x][gamer.y] = 1;
	}
	char getDirection()
	{
		return control;
	}

	void useMap(int x)//跳关
	{
		switch (x)
		{
		case 1:useMap1(); break;
		case 2:useMap2(); break;
		case 3:useMap3(); break;
		}
	}
	void useMap1() //地图1
	{
		initGameScreen();
		drawWall();
		initGamer();
		int a = 3;
		int b = 9;
		for (int x = 0; x < 4; x++)
		{
			gameBox[x].x = a;
			gameBox[x].y = b += 2;
			GameScreen[a][b] = 3;
		}
		//生成箱子
		b = 9;
		a = 5;
		for (int y = 0; y < 4; y++)
		{
			gameGoal[y].x = a;
			gameGoal[y].y = b += 2;
			GameScreen[a][b] = 2;
		}
		//生成目标地


	}
	void useMap2() //地图2
	{
		initGameScreen();
		drawWall();
		//	initGamer();
		int a = 3;
		int b = 14;
		for (int x = 0; x < 4; x++)
		{
			gameBox[x].x = a;
			gameBox[x].y = b;
			GameScreen[a][14] = 3;
			a++;
		}//生成箱子
		int y;
		a = 1;
		for (y = 0; y < 2; y++)
		{
			gameGoal[y].x = a += 2;
			gameGoal[y].y = 16;
			GameScreen[a][16] = 2;
		}
		a = 4;
		b = 13;
		for (y = 2; y < 4; y++)
		{
			gameGoal[y].x = a;
			gameGoal[y].y = b += 2;
			GameScreen[a][b] = 2;
		}
		//生成目标地
		GameScreen[3][15] = 4;
		GameScreen[3][17] = 4;
		GameScreen[5][17] = 4;
		GameScreen[5][15] = 4;
		//生成石头
		initGamer();
	}
	void useMap3()
	{
		initGameScreen();
		drawWall();
		//画墙
		for (int a = 4; a < 9; a++) {
			GameScreen[a][3] = 4;
		}
		for (int a = 1; a < 5; a++) {
			GameScreen[a][4] = 4;
		}
		for (int b = 5; b < 9; b++) {
			GameScreen[1][b] = 4;
		}
		for (int a = 2; a < 5; a++) {
			GameScreen[a][9] = 4;
		}
		for (int a = 4; a < 9; a++) {
			GameScreen[a][10] = 4;
		}
		for (int a = 4; a < 6; a++) {
			GameScreen[a][7] = 4;
		}
		for (int b = 7; b < 9; b++) {
			GameScreen[2][b] = 4;
		}
		for (int a = 4; a < 6; a++) {
			GameScreen[a][5] = 4;
		}
		//生成目标地
		int a1 = 4;
		for (int num = 0; num < 4; num++) {
			gameGoal[num].x = a1 += 1;
			gameGoal[num].y = 4;
			GameScreen[a1][4] = 2;
		}
		//生成箱子
		gameBox[0].x = 3;   gameBox[0].y = 6;
		gameBox[1].x = 6;   gameBox[1].y = 5;
		gameBox[2].x = 7;   gameBox[2].y = 8;
		gameBox[3].x = 8;   gameBox[3].y = 8;
		GameScreen[3][6] = 3;
		GameScreen[6][5] = 3;
		GameScreen[7][8] = 3;
		GameScreen[8][8] = 3;
		initGamer();
		putGamerStatus();
	}
	bool detectionWin()
	{
		int flag = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (gameBox[i].x == gameGoal[x].x)
					if (gameBox[i].y == gameGoal[x].y)
					{
						flag++;
					}
			}

		}
		//遍历一次
		if (flag <= 3) return false;
		else return true;
		//获取目的地的坐标 并比较Screen的值是否为重叠值
		//检测箱子是否全部放好；
	}
	void initGameScreen()//初始化屏幕
	{
		int a, b;
		for (a = 0; a < GameScreen_Height; a++)
		{
			for (b = 0; b < GameScreen_Width; b++)
			{
				GameScreen[a][b] = 0;
			}     //初始化屏幕
		}
		drawWall();//画墙
	}
	void gamerMove()
	{
		refreshGamer();
		//玩家移动 就进行刷新位置
	}
	void printfMassage()
	{
		printf("游戏通关条件，当前所有的目的地都有箱子\n");
		printf("○ 代表玩家当前位置 \n ⊙ 代表目的地 \n □ 代表 箱子 \n ■ 代表 墙壁 \n ◎ 代表人和目的地重叠 \n◇代表 箱子和目的地重叠\n");
	}
	void gameControl(char x)
	{
		int i = 0;
		//获取玩家按键以后 进行移动
		switch (x)
		{
		case 'w':
			switch (GameScreen[gamer.x - 1][gamer.y]) {
			case 0:	GameScreen[gamer.x][gamer.y] = 0, gamer.x -= 1; break;	//空  则移动
			case 2: GameScreen[gamer.x][gamer.y] = 0, gamer.x -= 1; break;
			case 3: {																//箱子 找出箱子
				for (i = 0; i < 4; i++)
				{
					if (gameBox[i].x == gamer.x - 1)
					{
						if (gameBox[i].y == gamer.y)  break;
					}   //退出循环，此时的i就是碰撞的box的下标
				}
				switch (GameScreen[gameBox[i].x - 1][gameBox[i].y])//找出碰撞箱子后判断箱子情况 有三种 前面是墙，前面是目的地 前面是空；
				{
				case 0: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x -= 1, gameBox[i].x -= 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
				case 2: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x -= 1, gameBox[i].x -= 1; }; break; 	 //目的地 
				case 4:	refreshGamer();	break;	 //墙	
				case 6:	refreshGamer();	break;
				}}; break;
			case 4:refreshGamer(); break;	   			//人前方是墙
			case 5:gamer.x -= 1;										//目的地
			case 6: {																//箱子 找出箱子
				for (i = 0; i < 4; i++)
				{
					if (gameBox[i].x == gamer.x - 1)
					{
						if (gameBox[i].y == gamer.y)  break;
					}   //退出循环，此时的i就是碰撞的box的下标
				}
				switch (GameScreen[gameBox[i].x - 1][gameBox[i].y])//找出碰撞箱子后判断箱子情况 有三种 前面是墙，前面是目的地 前面是空；
				{
				case 0: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x -= 1, gameBox[i].x -= 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
				case 2: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x -= 1, gameBox[i].x -= 1; }; break; 	 //目的地 
				case 4:	refreshGamer();	break;	 //墙	
				case 6:	refreshGamer();	break;
				}}; break;                                              //前方为有箱子的目的地 检测箱子前方碰撞 并计算
			}; break;
			//目的地
			/*
			人前四种情况
			空      墙   箱子	目的地
			人  	人	  人	 人
			人前箱子 三种情况
			墙      目的地	  空
			箱子     箱子     箱子
			人        人	  人
			*/
			//移动，如果空地就走， 如果石头就不走，如果是箱子就判断哪个箱子，然后传入相同方向的键值
			//箱子 找出要碰撞的箱子，并检测箱子的相同方向为空或者为目的地或者为石头4
			//如果是石头就停止，如果是目的地，则重合
			//上 判断为空地则直接移动， 且刷新人物如果不为空则计算不为空的计算 
		case 's':switch (GameScreen[gamer.x + 1][gamer.y]) {
		case 0:	GameScreen[gamer.x][gamer.y] = 0, gamer.x += 1; break;	//空  则移动
		case 2: GameScreen[gamer.x][gamer.y] = 0, gamer.x += 1; break;
		case 3: {																//箱子 找出箱子
			for (i = 0; i < 4; i++)
			{
				if (gameBox[i].x == gamer.x + 1)
					if (gameBox[i].y == gamer.y)  break;    //退出循环，此时的i就是碰撞的box的下标
			}
			switch (GameScreen[gameBox[i].x + 1][gameBox[i].y])//找出碰撞箱子后判断箱子情况 有三种 前面是墙，前面是目的地 前面是空；
			{
			case 0: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x += 1, gameBox[i].x += 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
			case 2: { GameScreen[gameBox[i].x + 1][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x += 1, gameBox[i].x += 1; }; break; 	 //目的地 
			case 4:	refreshGamer()/*,refreshBox(gameBox[i])*/;	break;	 //墙	
			case 6:	refreshGamer();	break;
			}}; break;
		case 4:refreshGamer(); break;	   			//人前方是墙
		case 5:gamer.x += 1;	//目的地
		case 6: {																//箱子 找出箱子
			for (i = 0; i < 4; i++)
			{
				if (gameBox[i].x == gamer.x + 1)
					if (gameBox[i].y == gamer.y)  break;    //退出循环，此时的i就是碰撞的box的下标
			}
			switch (GameScreen[gameBox[i].x + 1][gameBox[i].y])//找出碰撞箱子后判断箱子情况 有三种 前面是墙，前面是目的地 前面是空；
			{
			case 0: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x += 1, gameBox[i].x += 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
			case 2: { GameScreen[gameBox[i].x + 1][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.x += 1, gameBox[i].x += 1; }; break; 	 //目的地 
			case 4:	refreshGamer();	break;	 //墙	
			case 6:	refreshGamer();	break;
			}}; break;

		}; break; 			//下
		case 'a':switch (GameScreen[gamer.x][gamer.y - 1]) {
		case 0:	GameScreen[gamer.x][gamer.y] = 0, gamer.y -= 1; break;	//空  则移动
		case 2: GameScreen[gamer.x][gamer.y] = 0, gamer.y -= 1; break;
		case 3: {																//箱子 找出箱子
			for (i = 0; i < 4; i++)
			{
				if (gameBox[i].x == gamer.x)
					if (gameBox[i].y == gamer.y - 1)  break;    //退出循环，此时的i就是碰撞的box的下标
			}
			switch (GameScreen[gameBox[i].x][gameBox[i].y - 1])//找出碰撞箱子后判断箱子情况 有三种 前面是墙，前面是目的地 前面是空；
			{
			case 0: { GameScreen[gamer.x][gamer.y] = 0, GameScreen[gameBox[i].x][gameBox[i].y] = 0, gamer.y -= 1, gameBox[i].y -= 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
			case 2: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.y -= 1, gameBox[i].y -= 1; }; break; 	 //目的地 
			case 4:	refreshGamer();	break;	 //墙	
			case 6:	refreshGamer();	break;
			}}; break;
		case 4:refreshGamer(); break;	//人前方是墙
		case 5:gamer.y -= 1;				//目的地
		case 6: {						//箱子 找出箱子
			for (i = 0; i < 4; i++)
			{
				if (gameBox[i].x == gamer.x)
					if (gameBox[i].y == gamer.y - 1)  break;    //退出循环，此时的i就是碰撞的box的下标
			}
			switch (GameScreen[gameBox[i].x][gameBox[i].y - 1])//找出碰撞箱子后判断箱子情况 有三种 前面是墙，前面是目的地 前面是空；
			{
			case 0: { GameScreen[gamer.x][gamer.y] = 0, GameScreen[gameBox[i].x][gameBox[i].y] = 0, gamer.y -= 1, gameBox[i].y -= 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
			case 2: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.y -= 1, gameBox[i].y -= 1; }; break; 	 //目的地 
			case 4:	refreshGamer();	break;	 //墙	
			case 6:	refreshGamer();	break;
			}}; break;

		}; break; 			//左
		case 'd':switch (GameScreen[gamer.x][gamer.y + 1]) {
		case 0:	GameScreen[gamer.x][gamer.y] = 0, gamer.y += 1; break;	//空  则移动
		case 2: GameScreen[gamer.x][gamer.y] = 0, gamer.y += 1; break;      //目的地
		case 3: {																//箱子 找出箱子
			for (i = 0; i < 4; i++)
			{
				if (gameBox[i].x == gamer.x)
					if (gameBox[i].y == gamer.y + 1)  break;    //退出循环，此时的i就是碰撞的box的下标
			}
			switch (GameScreen[gameBox[i].x][gameBox[i].y + 1])//找出碰撞箱子后判断箱子情况 有四种 前面是墙，前面是目的地 前面是空 前面是和目的地重合的箱子；
			{
			case 0: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.y += 1, gameBox[i].y += 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
			case 2: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.y += 1, gameBox[i].y += 1; }; break; 	 //目的地 
			case 4:	refreshGamer();	break;	 //墙	
			case 6:	refreshGamer();	break;
			}}; break;
		case 4:refreshGamer(); break;	   			//人前方是墙
		case 5:gamer.y += 1; break; //目的地
		case 6: {																//箱子 找出箱子
			for (i = 0; i < 4; i++)
			{
				if (gameBox[i].x == gamer.x)
					if (gameBox[i].y == gamer.y + 1)  break;    //退出循环，此时的i就是碰撞的box的下标
			}
			switch (GameScreen[gameBox[i].x][gameBox[i].y + 1])//找出碰撞箱子后判断箱子情况 有四种 前面是墙，前面是目的地 前面是空 前面是和目的地重合的箱子；
			{
			case 0: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.y += 1, gameBox[i].y += 1; }; break;  	  //写一个函数来监控全图箱子 人 与目的地重叠，而不进行单独的替换				     //空 人移动 箱子移动
			case 2: { GameScreen[gameBox[i].x][gameBox[i].y] = 0, GameScreen[gamer.x][gamer.y] = 0, gamer.y += 1, gameBox[i].y += 1; }; break; 	 //目的地 
			case 4:	refreshGamer();	break;	 //墙	
			case 6:	refreshGamer();	break;
			}};
		} break;

		}
	}
	void CheckBoxGamerStatus()
	{
		//检测箱子、玩家、目的地三者两两重合问题 玩家和箱子不可能重合
		GameScreen[gamer.x][gamer.y] = 1;
		for (int a = 0; a < 4; a++)
		{
			GameScreen[gameBox[a].x][gameBox[a].y] = 3;
		}
		for (int a = 0; a < 4; a++)
		{
			GameScreen[gameGoal[a].x][gameGoal[a].y] = 2;
		}
		for (int i = 0; i < 4; i++)
		{
			if (gamer.x == gameGoal[i].x)
			{
				if (gamer.y == gameGoal[i].y)
				{
					GameScreen[gamer.x][gamer.y] = 5;
					break;
					//结束循环
				}
			}  //玩家和箱子X重合 则判断Y 若Y也重合 则显示重合的状态
			else if (GameScreen[gameGoal[i].x][gameGoal[i].y] != 5) GameScreen[gameGoal[i].x][gameGoal[i].y] = 2;              //否则 画出玩家 画出箱子
		}
		int i = 0;
		int f = 0;
		for (i = 0; i < 4; i++)
		{
			for (f = 0; f < 4; f++)
			{
				if (gameGoal[i].x == gameBox[f].x)
				{
					if (gameGoal[i].y == gameBox[f].y)
					{
						GameScreen[gameGoal[i].x][gameGoal[i].y] = 6;
					}
				}
				else {
					if (GameScreen[gameGoal[i].x][gameGoal[i].y] != 6)GameScreen[gameGoal[i].x][gameGoal[i].y] = 2;
					if (GameScreen[gameBox[f].x][gameBox[f].y] != 6)GameScreen[gameBox[f].x][gameBox[f].y] = 3;
				}
			}

		}
	}
	void play1(childplayer*p)
	{
		
		printfMassage();
		system("pause");
		refreshScreen();
		int  map = 1; //定义游戏关卡 当为3时无地图 游戏结束
		int sorce = 0;//分数
		char work;//标志
		useMap(map); //使用地图
		drawScreen(*GameScreen);
		while ((control = _getch()) != 'r') {
			if (map == 3) putGamerStatus();
			gameControl(control);
			refreshScreen();
			drawScreen(*GameScreen);
			if (detectionWin()) {
				//childplayer*temp = p;
				sorce = 5;//通一关加五分
				Fchildplayer*child = new Fchildplayer();
				if (!child->writeaddSforchild(p, sorce)) cout << "加分失败！" << endl;
				//else  continue;
				if (map < 3) {
					printf("是否要进入下一关：Y/N");
					cin >> work;
					if (work == 'Y' || work == 'y') {
						printf("请按任意键继续！");
						map++, useMap(map);
					}
					else {
						//	printf("你通关了！请按任意键退出游戏！");
						//return ; 
						break;
					}
				}
				else
				{
					map++; useMap(map);
				}
			}
			if (map > 4) break;
			//putBoxStatus();
			//putGamerStatus();
			//putGoalStatus();

			//checkWin(map);
		}

		printf("你通关了！请按任意键退出游戏！");
		system("pause");
		//return ;
	}

	void play2(adplayer*p)
	{
		printfMassage();
		system("pause");
		refreshScreen();
		int  map = 1; //定义游戏关卡 当为3时无地图 游戏结束
		int sorce = 0;//分数
		char work;//标志
		useMap(map); //使用地图
		drawScreen(*GameScreen);
		while ((control = _getch()) != 'r') {
			gameControl(control);
			refreshScreen();
			drawScreen(*GameScreen);
			if (detectionWin()) {
				sorce = 5;//通一关加五分
				Fadplayer*adult = new Fadplayer();
				if (!adult->writeaddSforadult(p, sorce)) cout << "加分失败！" << endl;
//				else continue;
				if (map < 2) {
					printf("是否要进入下一关：Y/N");
					cin >> work;
					if (work == 'Y' || work == 'y') {
						printf("请按任意键继续！");
						map++, useMap(map);
					}
					else {
						//	printf("你通关了！请按任意键退出游戏！");
						//return ; 
						break;
					}
				}
				else
				{
					map++; useMap(map);
				}
			}
			if (map > 3) break;
			//putBoxStatus();
			//putGamerStatus();
			//putGoalStatus();

			//checkWin(map);
		}

		printf("你通关了！请按任意键退出游戏！");
		system("pause");
		//return ;
	}
	void putBoxStatus()
	{
		for (int x = 0; x < 4; x++)
		{
			printf("Box %d  x = %d y= %d \n", x, gameBox[x].x, gameBox[x].y);
		}//测试类 输出箱子位置
	}
	void putGamerStatus()
	{
		printf("gamer x = %d  y =  %d  \n", gamer.x, gamer.y);
	}
	void putGoalStatus()
	{
		for (int a = 0; a < 4; a++)
		{
			printf("Goal %d  x = %d  y=%d \n", a, gameGoal[a].x, gameGoal[a].y);
		}
	}

}
//cleanmines.cpp
#include"cleanmines.h"

namespace ManagementSystemV5 {
	Cube cube[MAXX][MAXY];
	time_t  time0;//记录时间
	void GoTo(int x, int y) {
		//定位光标
		COORD coord = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void setBomb(int bombNumber = BOMBNUMBER) {
		//生成bombNumber个炸弹并且放进随机的方块中
		srand((unsigned)GetCurrentTime());
		while (bombNumber--) {
			int x = MAXX + 1, y = MAXY + 1;
			while ((x >= MAXX || y >= MAXY) || cube[x][y].getIfHaveBomb() == true) {
				x = rand() % MAXX;
				y = rand() % MAXY;
			}
			cube[x][y].haveBomb();
		}
	}

	void show() {
		//显示地雷阵
		system("cls");
		showXY();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
		for (int i = 0; i < MAXY; i++) {
			GoTo(STARTX, STARTY + i);
			for (int j = 0; j < MAXX; j++) {
				if (cube[j][i].getOpen() == true) {
					if (cube[j][i].getIfHaveBomb() == false) {
						if (cube[j][i].getNearBombNumber() == 0) { //挖开无雷的方块显示该方块周围多少个方块含雷，若为0则显示空格
							printf("  ");
						}
						else {
							printf(" %d", cube[j][i].getNearBombNumber());
						}
					}
					else {
						printf("×");//有雷的方块被挖开后显示×
					}
				}
				else {
					printf("■");//未翻开的方块用■显示
				}
			}
		}
	}

	void showXY() {
		//显示坐标轴
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
		GoTo(STARTX - 3, STARTY + MAXY / 2);
		printf("Y");
		GoTo(STARTX + MAXX, STARTY - 2);
		printf("X");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
		for (int i = 0; i < MAXY; i++) {
			GoTo(STARTX - 1, STARTY + i);
			printf("%d ", i);
		}
		for (int i = 0; i < 2 * MAXX; i += 2) {
			GoTo(STARTX + i + 1, STARTY - 1);
			printf("%d ", i / 2);
		}
	}

	int checkAndSetNearBombNumber(int x, int y) {
		//检查当前方块周围的雷数量
		int num = 0;

		if (cube[x][y].getIfHaveBomb() == true) {
			//若该方块有地雷，则不用判断它周围有几个雷
			return 0;
		}
		else {
			//用两个循环当前方块周围8格扫一遍
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					int nx = x + i;
					int ny = y + j;
					if (!(ny == y && nx == x) && (nx >= 0 && nx <= MAXX - 1) &&
						(ny >= 0 && ny <= MAXY - 1)) {
						if (cube[nx][ny].getIfHaveBomb()) {
							num++;
						}
					}
				}
			}
			cube[x][y].setNearBombNumber(num);//设置该方块附近的地雷的数量
			return 0;
		}
	}

	void gameStart() {
		//初始化游戏
		for (int i = 0; i < MAXY; i++) {
			for (int j = 0; j < MAXX; j++) {
				cube[j][i].resetCube();
			}
		}
		setBomb();
		for (int i = 0; i < MAXY; i++) {
			for (int j = 0; j < MAXX; j++) {
				checkAndSetNearBombNumber(j, i);
			}
		}

		time0 = time(NULL);
	}

	bool Splayers(bool &life) {
		//玩家输入坐标翻开方块
		int x, y;
		GoTo(STARTX - 3, STARTY + MAXY + 1);
		printf("请输入坐标(x,y),x和y用空格隔开");
		GoTo(STARTX + MAXX / 2, STARTY + MAXY + 2);
		scanf_s("%d%d", &x, &y);
		if ((x < 0) || (x > MAXX - 1) || (y < 0) || (y > MAXY - 1)) {
			//当玩家输入的坐标超出范围时
			show();
			GoTo(STARTX - 3, STARTY + MAXY + 3);
			printf("该坐标不存在，请重新输入坐标");
			GoTo(STARTX + MAXX / 2, STARTY + MAXY + 2);
		}
		else if (cube[x][y].getIfHaveBomb() == true) {
			//当玩家翻开的方块有地雷时
			cube[x][y].setOpen();
			show();
			life = false;
			return false;
		}
		else if (cube[x][y].getOpen() == false) {
			//当玩家翻开的方块无雷时
			if (cube[x][y].getNearBombNumber() == 0) {
				autoOpen(x, y);
				cube[x][y].setOpen();
				show();
			}
			else {
				cube[x][y].setOpen();
				show();
			}
		}
		else if (cube[x][y].getOpen() == true) {
			//当玩家输入已翻开方块的坐标时
			show();
			GoTo(STARTX, STARTY + MAXY + 3);
			printf("该方块已被挖开，请再次输入坐标");
			GoTo(STARTX + MAXX / 2, STARTY + MAXY + 2);
		}
		ifWin();
		return true;
	}

	void ch_message(bool result,childplayer*cp) {
		if (result == true) {
			//玩家胜利时输出的信息
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("祝贺你，你胜利了！用时：");
			time_t time1;
			time1 = time(NULL) - time0;
			Fchildplayer *child = new Fchildplayer();
			if (!child->CMwriteaddSforchild(cp, time1)) cout << "加分失败！" << endl;
			cout << time1;
			printf("秒");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
		else {
			//玩家失败时输出的信息
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PURPLE);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("××你踩中地雷了××");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
	}

	void ad_message(bool result, adplayer*cp) {
		if (result == true) {
			//玩家胜利时输出的信息
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("祝贺你，你胜利了！用时：");
			time_t time1;
			time1 = time(NULL) - time0;
			Fadplayer *adult = new Fadplayer();
			if (!adult->CMwriteaddSforadult(cp, time1)) cout << "加分失败！" << endl;
			cout << time1;
			printf("秒");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
		else {
			//玩家失败时输出的信息
			showBomb();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PURPLE);
			GoTo(STARTX - 1, STARTY + MAXY + 1);
			printf("××你踩中地雷了××");
			GoTo(STARTX, STARTY + MAXY + 2);
		}
	}

	void autoOpen(int x, int y) {
		//玩家翻开的方块为不含雷且周围无雷的方块时，自动翻开周围无雷的方块
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int nx = x + i;
				int ny = y + j;
				if (!(ny == y && nx == x) && (nx >= 0 && nx <= MAXX - 1) &&
					(ny >= 0 && ny <= MAXY - 1) && cube[nx][ny].getOpen() == false) {
					if (cube[nx][ny].getNearBombNumber() == 0) {
						cube[nx][ny].setOpen();
						autoOpen(nx, ny);
					}
					else {
						cube[nx][ny].setOpen();
					}
				}
			}
		}
	}

	bool ifWin() {
		//判断玩家是否扫雷成功达到游戏结束条件
		int num = 0;
		for (int i = 0; i < MAXX; i++) {
			for (int j = 0; j < MAXY; j++) {
				if (cube[j][i].getOpen() == false) {
					num++;
				}
			}
		}
		if (num == BOMBNUMBER) {
			return true;
		}
		else {
			return false;
		}
	}

	void showBomb() {
		//游戏结束后显示地雷位置
		for (int i = 0; i < MAXY; i++) {
			for (int j = 0; j < MAXX; j++) {
				if (cube[j][i].getIfHaveBomb() == true) {
					cube[j][i].setOpen();
				}
			}
		}
		show();
	}


	void child_play_cleanmines(childplayer*cp) {

	P:gameStart();
		show();
		bool life = true, win = true;
		while (Splayers(life) && !ifWin()) {
		}
		ch_message(life && ifWin(),cp);
		cout << "是否重新开始游戏？（Y or N）";
		char ch;
		cin >> ch;
		if (ch == 'Y')
			goto P;
		//return 0;
	}

	void adult_play_cleanmines(adplayer*ap) {

	P:gameStart();
		show();
		bool life = true, win = true;
		while (Splayers(life) && !ifWin()) {
		}
		ad_message(life && ifWin(), ap);
		cout << "是否重新开始游戏？（Y or N）";
		char ch;
		cin >> ch;
		if (ch == 'Y')
			goto P;
		//return 0;
	}

}


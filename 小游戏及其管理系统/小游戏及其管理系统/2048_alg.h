#pragma once
#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>        //setw()
#include<conio.h>        //_getch()
#include<ctime>        //time()
using namespace std;
namespace ManagementSystemV5 {
	int rand0_n_1(int n);        //产生一个小于n的随机数
	int width(int n);        //数字宽度
	public ref class matrix        //矩阵类
	{
	public:
		int order;        //阶数
		int**block;        //方块
		int sum;
		matrix()
		{
			order = 0;
			block = 0;
			sum = 0;
		}
		~matrix() {};
		matrix(int a)
		{
			order = a;
			if (a)
			{
				block = new int*[a];
				for (int i = 0; i < a; i++)
					block[i] = new int[a];
			}
			else block = 0;
			sum = 0;
		}
		void input(int a)
		{
			order = a;
			if (a)
			{
				block = new int*[a];
				for (int i = 0; i < a; i++)
					block[i] = new int[a];
			}
			else block = 0;
			sum = 0;
		}
		string display()        //打印矩阵
		{
			calculate();
			ostringstream Output;
			Output << "\r\n" << setw(17 - order * 3) << "" << "GAME:2048" << setw(order * 6 - 17) << ""
				<< "SCORE:" << sum << "\r\n";
			Output << setw(16 - order * 3) << "" << "|";
			for (int j = 0; j < order; j++)
				Output << setw(6) << "-----|";
			Output << "\r\n";
			for (int i = 0; i < order; i++)
			{
				Output << setw(16 - order * 3) << "";
				for (int j = 0; j < order; j++)
				{
					if (block[i][j] == 0)
						Output << "|" << setw(5) << "";
					else
						Output << "|" << setw((width(block[i][j]) - 1) / 2 + 3)
						<< block[i][j] << setw(2 - (width(block[i][j]) - 1) / 2) << "";
				}
				Output << "|" << "\r\n" << setw(16 - order * 3) << "" << "|";
				for (int j = 0; j < order; j++)
					Output << setw(6) << "-----|";
				Output << "\r\n";
			}
			Output << setw(17 - order * 3) << "" << "KEYBOARD ↑←→↓" << "\r\n";
			return Output.str();
		}
		int zero_num()        //统计空位数目
		{
			int k = 0;
			for (int i = 0; i < order; i++)
			{
				for (int j = 0; j < order; j++)
					if (block[i][j] == 0)
						k++;
			}
			return k;
		}
		int insert_num()        //随机空位插入2或4
		{
			int k = zero_num();
			int n = rand0_n_1(k) + 1;
			k = 0;
			for (int i = 0; i < order; i++)
				for (int j = 0; j < order; j++)
				{
					if (block[i][j] == 0)
						k++;
					if (k == n)
					{
						block[i][j] = rand0_n_1(3) ? 2 : 4;
						return 0;
					}
				}
			return 0;
		}
		void block_to_left()        //左移
		{
			bool moved = 0;        //判断操作有效性
			for (int i = 0; i < order; i++)
			{
				int*temp = new int[order] { 0 }, k = 0;        //缩进
				for (int j = 0; j < order; j++)
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						if (k != j) moved = 1;
						k++;
					}
				for (int j = 0; j < order; j++)
					block[i][j] = temp[j];
				for (int j = 0; j < order - 1; j++)        //相同相加
					if (block[i][j] == block[i][j + 1] && block[i][j] != 0)
					{
						block[i][j] = block[i][j] * 2;
						block[i][j + 1] = 0;
						j++;
						moved = 1;
					}
				for (k = 0; k < order; k++)
					temp[k] = 0;
				k = 0;
				for (int j = 0; j < order; j++)        //缩进
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						k++;
					}
				for (int j = 0; j < order; j++)
					block[i][j] = temp[j];
			}
			if (moved)
				insert_num();
		}
		void block_to_right()        //右移
		{
			bool moved = 0;        //判断操作有效性
			for (int i = 0; i < order; i++)
			{
				int*temp = new int[order] { 0 }, k = order - 1;        //缩进
				for (int j = order - 1; j >= 0; j--)
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						if (k != j) moved = 1;
						k--;
					}
				for (int j = 0; j < order; j++)
					block[i][j] = temp[j];
				for (int j = order - 1; j > 0; j--)        //相同相加
					if (block[i][j] == block[i][j - 1] && block[i][j] != 0)
					{
						block[i][j] = block[i][j] * 2;
						block[i][j - 1] = 0;
						j--;
						moved = 1;
					}
				for (k = 0; k < order; k++)
					temp[k] = 0;
				k = order - 1;
				for (int j = order - 1; j >= 0; j--)        //缩进
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						k--;
					}
				for (int j = 0; j < order; j++)
					block[i][j] = temp[j];
			}
			if (moved)
				insert_num();
		}
		void block_up()        //上移
		{
			bool moved = 0;        //判断操作有效性
			for (int j = 0; j < order; j++)
			{
				int*temp = new int[order] { 0 }, k = 0;        //缩进
				for (int i = 0; i < order; i++)
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						if (k != i) moved = 1;
						k++;
					}
				for (int i = 0; i < order; i++)
					block[i][j] = temp[i];
				for (int i = 0; i < order - 1; i++)        //相同相加
					if (block[i][j] == block[i + 1][j] && block[i][j] != 0)
					{
						block[i][j] = block[i][j] * 2;
						block[i + 1][j] = 0;
						i++;
						moved = 1;
					}
				for (k = 0; k < order; k++)
					temp[k] = 0;
				k = 0;
				for (int i = 0; i < order; i++)        //缩进
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						k++;
					}
				for (int i = 0; i < order; i++)
					block[i][j] = temp[i];
			}
			if (moved)
				insert_num();
		}
		void block_down()        //下移
		{
			bool moved = 0;        //判断操作有效性
			for (int j = order - 1; j >= 0; j--)
			{
				int*temp = new int[order] { 0 }, k = order - 1;        //缩进
				for (int i = order - 1; i >= 0; i--)
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						if (k != i) moved = 1;
						k--;
					}
				for (int i = 0; i < order; i++)
					block[i][j] = temp[i];
				for (int i = order - 1; i > 0; i--)        //相同相加
					if (block[i][j] == block[i - 1][j] && block[i][j] != 0)
					{
						block[i][j] = block[i][j] * 2;
						block[i - 1][j] = 0;
						i--;
						moved = 1;
					}
				for (k = 0; k < order; k++)
					temp[k] = 0;
				k = order - 1;
				for (int i = order - 1; i >= 0; i--)        //缩进
					if (block[i][j] != 0)
					{
						temp[k] = block[i][j];
						k--;
					}
				for (int i = 0; i < order; i++)
					block[i][j] = temp[i];
			}
			if (moved)
				insert_num();
		}
		bool full()        //判断矩阵是否填满并无法移动
		{
			bool k = !zero_num();
			for (int i = 0; i < order; i++)
				for (int j = 0; j < order - 1; j++)
					if (block[i][j] == block[i][j + 1] && block[i][j] != 0)
					{
						k = 0; return k;
					}
			for (int j = 0; j < order; j++)
				for (int i = 0; i < order - 1; i++)
					if (block[i][j] == block[i + 1][j] && block[i][j] != 0)
					{
						k = 0; return k;
					}
			return k;
		}
		void calculate()        //计算总和
		{
			sum = 0;
			for (int i = 0; i < order; i++)
				for (int j = 0; j < order; j++)
					sum += block[i][j];
		}
	};
	public ref class game        //游戏类
	{
	public:
		matrix board;        //棋盘
		bool over;        //游戏结束判断符
		int score;        //得分
		game()
		{
			board.input(0);
			over = 0;
			score = 0;
		}
		game(int a)
		{
			board.input(a);
			over = 0;
			score = 0;
		}
		~game() {};
		void input(int a)
		{
			board.input(a);
			over = 0;
			score = 0;
		}
		void start()        //开始游戏
		{
			for (int i = 0; i < board.order; i++)
				for (int j = 0; j < board.order; j++)
					board.block[i][j] = 0;
			board.insert_num();
			board.insert_num();
			board.display();
		}
		void judge()        //判断游戏是否结束
		{
			over = board.full();
		}
		void calculate()
		{
			score = board.sum;
		}
	};
	//game _2048;
}
//outputRandS.cpp
#include"outputRandS.h"
using namespace std;
namespace ManagementSystemV5 {
	void doRandS()
	{
		int sum = 0;//获取玩家总数
		Fchildplayer*child = new Fchildplayer();
		sum = child->test();
		Player pa[11];//排行榜只显示10位玩家
		if (sum > 10) sum = 10;
		childplayer*p = new childplayer();//从文件读取用户信息
		fstream f;
		char path[100];
		sprintf(path, "D:\\小游戏管理系统存储\\RandS\\RandS.dat");
		f.open(path, ios::in | ios::binary);
		f.seekg(long(sizeof(int)), ios::beg);
		for (int i = 1; i <= sum&&i <= 10; i++)
		{
			f.read((char*)p, sizeof(childplayer));
			strcpy(pa[i].id, p->getid());
			strcpy(pa[i].name, p->getname());
			pa[i].sorce = p->getscore();
			pa[i].rank = p->getrank();
		}
		Player temp;//冒泡排序法排列排名
		for (int j = 1; j<sum; j++)
			for (int i = 1; i <= sum - j; i++)
				if (pa[i].sorce < pa[i + 1].sorce)
				{
					temp = pa[i];
					pa[i] = pa[i + 1];
					pa[i + 1] = temp;
				}
		for (int i = 1; i <= sum; i++) pa[i].rank = i;//对排名赋值
													  //测试
		for (int i = 1; i <= sum; i++)
			cout << pa[i].name << ' ' << pa[i].sorce << ' ' << pa[i].rank << endl;
	}
}
//Storage.h
#pragma once
#include"user.h"
#include"typeDefinition.h"
#include<fstream>
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
//定义命名空间 ManagementSystemV5
namespace ManagementSystemV5
{
	using namespace System;
	using namespace System::IO;
	//存储类Storage 开始
	public ref class Storage
	{
	public:
		/*login()是登陆函数
		        参数：登陆ID、登陆密码、登陆用户类型。登陆成功后，返回一个player类型指针，指向当前登陆的用户对象*/
		player* login(char*id, char*password, loginUsertype type)
		{
			char buffer[100];
			char loginInfo[100];
			ifstream input;
			char *path = "D:\\小游戏管理系统存储\\login\\admin.txt";
			player*p = new player();
			p = readLoginInfo(id);
			if (!p)return nullptr;//用户名不存在
			//校验用户名、密码是否一致
			if (strcmp(p->getpassword(), password) == 0 && (p->gettype() == (int)type)) { return p; }
			return nullptr;
		}//login函数结束
		//writeLogininfo()函数将用户信息写入文件
		bool writeLoginInfo(player*p)
		{
			ofstream output;//文件写入对象
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\login\\%s.dat", p->getid());
			output.open(path, ios::out | ios::binary);
			if (!output) { MessageBox::Show("文件写入异常!1"); output.close(); return false; }
			output.write((char*)p, sizeof(player));
			output.close();
			delete p;
			return true;
		}
		//readLoginInfo()函数从登陆数据文件读取用户信息
		player*readLoginInfo(char*id)
		{
			player*p = new player();
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\login\\%s.dat", id);
			f. open(path, ios::in | ios::binary);
			if (!f) { f.close(); return nullptr; }
			f.read((char*)p, sizeof(player));
			f.close();
			return p;
		}
		//updateInfo()函数修改密码
		bool updateInfo(int type, char*id, char*oldpw, char*passwd)
		{
			player*p = new player();
			p = readLoginInfo(id);//读取用户信息
			if(strcmp(oldpw,p->getpassword())==0&&p->gettype()==type)
			{//校验成功
				p->setpassword(passwd);
				writeLoginInfo(p);
				return true;
			}
			delete p;
			return false;
		}
		//writechild()函数将未成年人信息写入文件
		bool writechild(childplayer*p)
		{
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\childplayer\\%s.dat", p->getid());
			f.open(path, ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件写入异常！2"); return false; }
			f.write((char*)p, sizeof(childplayer));
			f.close();
			return true;
		}
		//writeadult()函数将成年人信息写入文件
		bool writeadult(adplayer*p)
		{
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\adplayer\\%s.dat", p->getid());
			f.open(path, ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件写入异常！3"); return false; }
			f.write((char*)p, sizeof(adplayer));
			f.close();
			return true;
		}
		//测试InitRandSforchild函数****（返回玩家总数）**********************
		int testRandSforchild()
		{
			int sum=9999999;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\RandS.dat");
			f.open(path, ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读取错误！3.4"); }
			f.read((char*)&sum, sizeof(int));
			f.close();
			return sum;
		}
		//函数用于注册时写入用户的排名和分数，首行为用户人数
		bool InitRandSforchild(childplayer*p)
		{
			int sum;
			int rank;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\RandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//第一次创建文件
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("文件读写异常！3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
			/*if (sum == NULL)// 第一次创建文件
			{
				sum = 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
			}*/
			//else
			//{
				sum += 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
			//}
			f.seekg(0, ios::beg);//在文件末尾添加一个记录
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
/*			f.seekp(long(sizeof(int)), ios::beg);
			f.seekp(long(sizeof(childplayer))*(sum-1), ios::cur);*/
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(childplayer));
			f.close();
			return true;
		}
		//函数用于注册时写入用户的排名和分数，首行为用户人数adult
		bool InitRandSforadult(adplayer*p)
		{
			int sum;
			int rank ;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\RandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//第一次创建文件
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("文件读写异常！3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
/*			if (sum == NULL)// 第一次创建文件
			{
				sum = 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
			}
			else
			{*/
				sum += 1;
				f.seekp(-long(sizeof(int)), ios::cur);
				f.write((char*)&sum, sizeof(int));
//			}
			f.seekg(0, ios::beg);
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(adplayer));
			f.close();
			return true;
		}
		//函数用于更改玩家分数
		bool writeRandSforadult(adplayer*p, int addsorce)
		{
			adplayer temp;
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\RandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(adplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "1" << endl;
					break;
				}
			}
			/*			do
						{
							//读一个adplayer记录
							f.read((char*)&temp, sizeof(adplayer));
						} while (temp.getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(adplayer)), ios::cur);
				f.write((char*)p, sizeof(adplayer));
			}
			else { cout << "not find！！" << endl; f.close(); return false; }
			f.close();
			return true;
		}
		
		//函数用于更改玩家分数
		bool writeRandSforchild(childplayer*p, int addsorce)
		{
			childplayer temp;
//			char tempp[30] = {0};
//			strcpy(tempp, p->getid());
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\RandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(childplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "1" << endl; 
					break;
				}
			}
/*			do
			{
				//读一个adplayer
				f.read((char*)&temp, sizeof(childplayer));
			} while (temp->getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(childplayer)), ios::cur);
				f.write((char*)p, sizeof(childplayer));
			}
			else { cout << "not find！！" << endl; f.close(); return false; }
			f.close();
			return true;
		}
//扫雷“cleanmines”游戏，注册时创建积分排行榜，游戏时更改分数***********************************************************
//*************************（返回玩家总数）**********************
		int testCMRandSforchild()
		{
			int sum = 9999999;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\CMRandS.dat");
			f.open(path, ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读取错误！3.4"); }
			f.read((char*)&sum, sizeof(int));
			f.close();
			return sum;
		}
		//函数用于注册时写入用户的排名和分数，首行为用户人数
		bool InitCMRandSforchild(childplayer*p)
		{
			int sum;
			int rank;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\CMRandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//第一次创建文件
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("文件读写异常！3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
											 /*if (sum == NULL)// 第一次创建文件
											 {
											 sum = 1;
											 f.seekp(-long(sizeof(int)), ios::cur);
											 f.write((char*)&sum, sizeof(int));
											 }*/
											 //else
											 //{
			sum += 1;
			f.seekp(-long(sizeof(int)), ios::cur);
			f.write((char*)&sum, sizeof(int));
			//}
			f.seekg(0, ios::beg);//在文件末尾添加一个记录
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
			/*			f.seekp(long(sizeof(int)), ios::beg);
			f.seekp(long(sizeof(childplayer))*(sum-1), ios::cur);*/
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(childplayer));
			f.close();
			return true;
		}
		//函数用于注册时写入用户的排名和分数，首行为用户人数adult
		bool InitCMRandSforadult(adplayer*p)
		{
			int sum;
			int rank;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\CMRandS.dat");
			f.open(path, ios::in | ios::out | ios::binary);
			if (!f)//第一次创建文件
			{
				f.close();
				sum = 0;
				f.open(path, ios::out | ios::binary);
				if (!f) { f.close(); MessageBox::Show("文件读写异常！3.5");	return false; }
				f.write((char*)&sum, sizeof(int));
				f.close();
			}
			else f.close();
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！4"); return false; }
			f.read((char*)&sum, sizeof(int));// write the sum of player
											 /*			if (sum == NULL)// 第一次创建文件
											 {
											 sum = 1;
											 f.seekp(-long(sizeof(int)), ios::cur);
											 f.write((char*)&sum, sizeof(int));
											 }
											 else
											 {*/
			sum += 1;
			f.seekp(-long(sizeof(int)), ios::cur);
			f.write((char*)&sum, sizeof(int));
			//			}
			f.seekg(0, ios::beg);
			f.read((char*)&rank, sizeof(int));
			p->setscore(0);
			p->setrank(sum);
			f.seekp(0, ios::end);
			f.write((char*)p, sizeof(adplayer));
			f.close();
			return true;
		}
		//函数用于更改玩家分数
		bool writeCMRandSforadult(adplayer*p, int addsorce)
		{
			adplayer temp;
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\CMRandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(adplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "1" << endl;
					break;
				}
			}
			/*			do
			{
			//读一个adplayer记录
			f.read((char*)&temp, sizeof(adplayer));
			} while (temp.getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(adplayer)), ios::cur);
				f.write((char*)p, sizeof(adplayer));
			}
			else { cout << "not find！！" << endl; f.close(); return false; }
			f.close();
			return true;
		}

		//函数用于更改玩家分数
		bool writeCMRandSforchild(childplayer*p, int addsorce)
		{
			childplayer temp;
			//			char tempp[30] = {0};
			//			strcpy(tempp, p->getid());
			int sum;
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\CMRandS.dat");
			f.open(path, ios::out | ios::in | ios::binary);
			if (!f) { f.close(); MessageBox::Show("文件读写异常！5"); return false; }
			f.read((char*)&sum, sizeof(int));
			f.seekg(long(sizeof(int)), ios::beg);
			for (int i = 0; i < sum; i++)
			{
				//f.seekg(long(sizeof(childplayer))*i, ios::cur);
				f.read((char*)&temp, sizeof(childplayer));
				if (strcmp(temp.getid(), p->getid()) == 0) {
					//cout << "：" ;
					break;
				}
			}
			/*			do
			{
			//读一个adplayer
			f.read((char*)&temp, sizeof(childplayer));
			} while (temp->getid() != p->getid());*/
			if (strcmp(temp.getid(), p->getid()) == 0)
			{
				int Sorce = temp.getscore() + addsorce;
				p->setscore(Sorce);
				f.seekp(-long(sizeof(childplayer)), ios::cur);
				f.write((char*)p, sizeof(childplayer));
			}
			else { cout << "not find！！" << endl; f.close(); return false; }
			f.close();
			return true;
		}


		//deleteLoginInfo()函数删除用户登陆信息
		bool deleteLoginInfo(char*id)
		{
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\login\\%s.dat",id);
			if (!remove(path)) {
				return true;
			}
			return false;
		}

		//deleteUserdata()函数删除用户数据
		bool deleteUserdata(char*id, int type)
		{
			char path[100];
			if (type == (int)userTypecode::user_adplayer)//删除成年人玩家
				sprintf(path, "D:\\小游戏管理系统存储\\adplayer\\%s.dat", id);
			else if (type == (int)userTypecode::user_childplayer)//删除未成年人玩家
				sprintf(path, "D:\\小游戏管理系统存储\\childplayer\\%s.dat", id);
			if (!remove(path)) {
				return true;
			}
			return false;
		}
	};
}
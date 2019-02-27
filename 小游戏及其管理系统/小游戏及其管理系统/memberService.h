//memberService.h
#pragma once
#include"user.h"
#include"typeDefinition.h"
#include"Storage.h"
#include<vector>
//定义命名空间 ManagementSystemV5
namespace ManagementSystemV5
{
	using namespace Runtime::InteropServices;
	//定义用户功能类User,实现登陆和修改密码
	public class User
	{
	public:
		//login()函数参数为  id，密码，类型
		player*login(char*id, char*passwd, loginUsertype type)
		{
			Storage storage;
			return storage.login(id, passwd, type);//调用登陆函数
		}
		//修改密码
		bool updatePasswd(int flag, char*idName, char*oldpw, char*passwd)
		{
			Storage storage;
			return storage.updateInfo(flag, idName, oldpw, passwd);
		}
	};//User类定义结束
	public class Fchildplayer :public User
	{
	public:
		//添加账号密码到登陆信息文件
		bool writeInitLoginInfo(char*id, char*passwd, int type) {
			Storage storage;
			player*p = new player();
			p->setid(id);
			p->setpassword(passwd);
			p->settype(type);
			return storage.writeLoginInfo(p);
		}
		//返回推箱子玩家总数**********************************
		int test()
		{
			Storage storage;
			return storage.testRandSforchild();
		}
		//返回扫雷玩家总数**************************************
		int CM_test()
		{
			Storage storage;
			return storage.testCMRandSforchild();
		}
		//添加未成年人用户信息到文件
		bool writechild(childplayer*p) {
			Storage storage;
			return storage.writechild(p);
		}
		//在游戏中更改用户分数功能函数
		bool writeaddSforchild(childplayer*p, int sorce)
		{
			//childplayer*pp = p;
			Storage storage;
			return storage.writeRandSforchild(p, sorce);
		}
		//添加用户时初始化游戏排名积分文件
		bool InitRandSforchildplayer(childplayer*p) {
			Storage storage;
			return storage.InitRandSforchild(p);
		}
//扫雷游戏积分排行功能块*******************************************************************
		//在游戏中更改用户分数功能函数
		bool CMwriteaddSforchild(childplayer*p, int sorce)
		{
			//childplayer*pp = p;
			Storage storage;
			return storage.writeCMRandSforchild(p, sorce);
		}
		//添加用户时初始化游戏排名积分文件
		bool InitCMRandSforchildplayer(childplayer*p) {
			Storage storage;
			return storage.InitCMRandSforchild(p);
		}

	};
	public class Fadplayer :public User
	{
	public:
		//添加账号密码到登陆信息文件
		bool writeInitLoginInfo(char*id, char*passwd, int type) {
			Storage storage;
			player*p = new player();
			p->setid(id);
			p->setpassword(passwd);
			p->settype(type);
			return storage.writeLoginInfo(p);
		}
		//成年人用户可以添加成年人和未成年人用户
		bool writeadult(adplayer*p) {
			Storage storage;
			return storage.writeadult(p);
		}
		bool writechild(childplayer*p) {
			Storage storage;
			return storage.writechild(p);
		}
		//添加用户时初始化游戏排名积分文件
		bool InitRandSforadplayer(adplayer*p) {
			Storage storage;
			return storage.InitRandSforadult(p);
		}
		//在游戏中更改用户分数功能函数
		bool writeaddSforadult(adplayer*p, int sorce)
		{
			Storage storage;
			return storage.writeRandSforadult(p, sorce);
		}
//扫雷游戏积分排行功能块*******************************************************************
       //添加用户时初始化游戏排名积分文件
		bool InitCMRandSforadplayer(adplayer*p) {
			Storage storage;
			return storage.InitCMRandSforadult(p);
		}
		//在游戏中更改用户分数功能函数
		bool CMwriteaddSforadult(adplayer*p, int sorce)
		{
			Storage storage;
			return storage.writeCMRandSforadult(p, sorce);
		}

		//删除指定ID账户
		bool deleteAccount(char*id) {
			Storage storage;
			player *p = storage.readLoginInfo(id);
			if (!storage.deleteLoginInfo(id)) return false;
			if (!storage.deleteUserdata(id, p->gettype())) return false;
			return true;
		}
	
		//读玩家登陆信息
		player *readplayerInfo(char *id) {
			Storage storage;
			return storage.readLoginInfo(id);
		}
	};
}
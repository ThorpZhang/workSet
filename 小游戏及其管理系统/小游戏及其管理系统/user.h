//user.h
#pragma once
#include<cstring>
using namespace std;
//定义命名空间  ManagementSystem V5
namespace ManagementSystemV5 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//用户基类
	public class player
	{
	public:
		void setid(char *id) { strcpy(this->id, id); }
		char* getid() { return id; }
		void settype(int type) { this->type = type; }
		int gettype() { return this->type; }
		void setpassword(char *password) { strcpy(this->password, password); }
		char* getpassword() { return this->password; }
	private:
		char id[30];
		char password[30];
		int type;
	};
	//成年游戏玩家
	public class adplayer :public player
	{
	public:
		void setname(char*name) { strcpy(this->name, name); }
		char*getname() { return this->name; }
		void setscore(int score) { this->score = score; }
		int getscore() { return this->score; }
		void setrank(int rank) { this->rank = rank; }
		int getrank() { return this->rank; }
	private:
		char name[30];
		int score;
		int rank;
	};
	//未成年游戏玩家
	public class childplayer :public player
	{
	public:
		void setname(char*name) { strcpy(this->name, name); }
		char*getname() { return this->name; }
		void setscore(int score) { this->score = score; }
		int getscore() { return this->score; }
		void setrank(int rank) { this->rank = rank; }
		int getrank() { return this->rank; }
	private:
		char name[30];
		int score;
		int rank;
	};
}
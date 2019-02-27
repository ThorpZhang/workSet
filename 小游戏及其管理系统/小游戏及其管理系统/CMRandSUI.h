#pragma once
#include <msclr\marshal.h>  
#include"user.h"
#include"Storage.h"
#include"memberService.h"
#include"typeDefinition.h"


namespace 小游戏及其管理系统 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ManagementSystemV5;
	using namespace msclr::interop;

	/// <summary>
	/// CMRandSUI 摘要
	/// </summary>
	struct Player_1
	{
		char name[30];
		int sorce;
		int rank;
		char id[30];
	};
	public ref class CMRandSUI : public System::Windows::Forms::Form
	{
	public:
		CMRandSUI(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~CMRandSUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Location = System::Drawing::Point(12, 25);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(972, 527);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// CMRandSUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(996, 573);
			this->Controls->Add(this->listView1);
			this->Name = L"CMRandSUI";
			this->Text = L"CMRandSUI";
			this->Load += gcnew System::EventHandler(this, &CMRandSUI::CMRandSUI_Load);
			this->ResumeLayout(false);

		}

//初始化扫雷游戏积分排行榜***********************************************
		void InitializeListView() {
			//**********************************排序*********************************************************
			int sum = 0;//获取玩家总数
			Fchildplayer*child = new Fchildplayer();
			sum = child->CM_test();
			Player_1 pa[11];//排行榜只显示10位玩家
			if (sum > 10) sum = 10;
			//用sorce来做后面的判断标志
			for (int i = 0; i < 11; i++) {
				pa[i].sorce = -1;
			}
			childplayer*p = new childplayer();//从文件读取用户信息
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\RandS\\CMRandS.dat");
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
			Player_1 temp;//冒泡排序法排列排名
			for (int j = 1; j<sum; j++)
				for (int i = 1; i <= sum - j; i++)
					if (pa[i].sorce > pa[i + 1].sorce)
					{
						temp = pa[i];
						pa[i] = pa[i + 1];
						pa[i + 1] = temp;
					}
			for (int i = 1; i <= sum; i++) pa[i].rank = i;//对排名赋值
														  //测试
		  //*********************************************排序结束*********************************************************
			this->listView1->View = System::Windows::Forms::View::Details;
			ColumnHeader^columnHeader1 = gcnew ColumnHeader;
			columnHeader1->Text = "排名";
			columnHeader1->TextAlign = HorizontalAlignment::Left;
			columnHeader1->Width = 200;
			ColumnHeader^columnHeader2 = gcnew ColumnHeader;
			columnHeader2->Text = "姓名";
			columnHeader2->TextAlign = HorizontalAlignment::Center;
			columnHeader2->Width = 200;
			ColumnHeader^columnHeader3 = gcnew ColumnHeader;
			columnHeader3->Text = "游戏用时";
			columnHeader3->TextAlign = HorizontalAlignment::Right;
			columnHeader3->Width = 200;
			this->listView1->Columns->Add(columnHeader1);
			this->listView1->Columns->Add(columnHeader2);
			this->listView1->Columns->Add(columnHeader3);
			cli::array<String^>^rankList = { "第一名","第二名","第三名","第四名","第五名","第六名","第七名","第八名","第九名","第十名" };
			cli::array<String^>^namelist = gcnew cli::array<String^, 1>(rankList->Length);
			cli::array<String^>^sorce = gcnew	cli::array<String^>(rankList->Length);
			for (int count = 0; count < rankList->Length; count++) {
				if (pa[(count + 1)].sorce != -1) {
					namelist[count] = marshal_as<String^>(pa[(count + 1)].name);
				}
				else namelist[count] = "  ";
			}
			for (int count = 0; count < rankList->Length; count++) {
				//				int a = -1;
				if (pa[(count + 1)].sorce != -1) {
					sorce[count] = pa[(count + 1)].sorce.ToString();
					//					sorce[count] = marshal_as<String^>(pa[(count+1)].sorce.ToString());
				}
				else sorce[count] = "   ";
			}
			for (int count = 0; count < rankList->Length; count++) {
				ListViewItem^listItem = gcnew ListViewItem(rankList[count]);
				listItem->SubItems->Add(namelist[count]);
				listItem->SubItems->Add(sorce[count]);
				this->listView1->Items->Add(listItem);
			}
		}
#pragma endregion
	private: System::Void CMRandSUI_Load(System::Object^  sender, System::EventArgs^  e) {
		InitializeListView();
	}
};
}

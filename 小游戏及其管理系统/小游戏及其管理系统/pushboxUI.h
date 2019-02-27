#pragma once
#include"level.h"
#include"cube.h"
#include"user.h"
#include"typeDefinition.h"
#include"memberService.h"
#include"Storage.h"

namespace 小游戏及其管理系统 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ManagementSystemV5;

	/// <summary>
	/// pushboxUI 摘要
	/// </summary>
	public ref class pushboxUI : public System::Windows::Forms::Form
	{
	private:
		childplayer*now;
	public:
		pushboxUI(childplayer*p)
		{
			now = p;
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}
/*		pushboxUI(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}*/

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~pushboxUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 16));
			this->button1->Location = System::Drawing::Point(690, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 145);
			this->button1->TabIndex = 0;
			this->button1->Text = L"重玩本关";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &pushboxUI::button1_Click);
			// 
			// pushboxUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(821, 741);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"pushboxUI";
			this->Text = L"推箱子";
			this->Load += gcnew System::EventHandler(this, &pushboxUI::pushboxUI_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &pushboxUI::pushboxUI_KeyDown);
			this->ResumeLayout(false);

		}
		//非系统打码区************************************************
		Point *curpoint;
		cli::array<cube^, 2>^cubee;
		cli::array<int, 2>^data;
		int curlvl = 0;
		//******************
#pragma endregion
	private: System::Void pushboxUI_Load(System::Object^  sender, System::EventArgs^  e) {
		if (cubee == nullptr)
			cubee = gcnew cli::array<cube^, 2>(16, 16);
		data = gcnew cli::array<int, 2>(16, 16);
		cli::array<String^>^lvl = Config::level[curlvl]->Split(',');
		for (int i = 0; i < lvl->Length; i++)
		{
			String^ temp = lvl[i];
			for (int j = 0; j < temp->Length; j++)
			{
				cube ^cubeee = nullptr;
				if (cubee[i, j] == nullptr)
				{
					cubeee = gcnew cube();
					cubee[i, j] = cubeee;
				}
				else cubeee = cubee[i, j];

				data[i, j] = int::Parse(temp[j].ToString());
				cubeee->Tag = data[i, j].ToString();
				cubeee->OldValue = data[i, j];
				cubeee->Left = j*cubeee->Width + 5;
				cubeee->Top = i*cubeee->Height + 5;
				this->Controls->Add(cubeee);
				cubeee->RefImage();
				if (data[i, j] >= 6)
				{
					curpoint = new Point();
					curpoint->X = j;
					curpoint->Y = i;
				}
			}
		}
	}
			 //*****************************************************************
	private:
		void RefImg(Point *p)//画****************************
		{

			cubee[p->Y, p->X]->Tag = data[p->Y, p->X].ToString();
			cubee[p->Y, p->X]->RefImage();
		}
		void CheckFinshed()//判断胜利
		{

			for (int i = 0; i < cubee->GetUpperBound(0); i++)
			{
				for (int j = 0; j < cubee->GetUpperBound(1); j++)
				{
					if (data[i, j] == 5)
					{
						return;
					}
				}
			}
			int sorce = 5;
			Fchildplayer*child = new Fchildplayer();
			if (!child->writeaddSforchild(now, sorce))  MessageBox::Show("加分失败！");
			MessageBox::Show("即将进入下一关！");
			curlvl++;//通关数增加
			if (curlvl >= Config::level->Length)
			{
				MessageBox::Show("通关!");
				return;
			}
			pushboxUI_Load(nullptr, nullptr);
		}
		void GoNewPoint(Point *newPoint1, Point *newPoint2)//人走
		{

			bool isFinshed = false;
			if (newPoint1->X<0 || newPoint1->Y<0) return;//走到边缘
			int n1 = data[newPoint1->Y, newPoint1->X];
			int n2 = data[newPoint2->Y, newPoint2->X];
			if (n1 <= 1) return;//碰墙
			if (n1 == 2 || n1 == 3)//人下一步到空格或者洞
			{
				data[newPoint1->Y, newPoint1->X] = data[curpoint->Y, curpoint->X];//对人重新赋值
				RefImg(newPoint1);//画人
				data[curpoint->Y, curpoint->X] = cubee[curpoint->Y, curpoint->X]->OldValue;//原来人的位置变成空白
				RefImg(curpoint);//画空白
				curpoint = newPoint1;
				return;
			}
			if (n1 == 5)//人面对箱子
			{

				if (n2 == 1 || n2 == 5) return;//箱子邻墙||箱子邻箱子
				if (n2 == 2)//箱子下步为空白
				{
					data[newPoint2->Y, newPoint2->X] = 5;
				}
				if (n2 == 3)//箱子入坑
				{
					data[newPoint2->Y, newPoint2->X] = 4;
					isFinshed = true;
				}
				RefImg(newPoint2);
				data[newPoint1->Y, newPoint1->X] = data[curpoint->Y, curpoint->X];//画人
				RefImg(newPoint1);
				data[curpoint->Y, curpoint->X] = cubee[curpoint->Y, curpoint->X]->OldValue;//原人变成空白
				RefImg(curpoint);
				curpoint = newPoint1;
				CheckFinshed();//判断胜利
			}

			if (n1 == 4)//已有箱子到达目的地
			{
				if (n2 == 2 || n2 == 3)//空白||目的地
				{
					if (n2 == 2)
					{
						data[newPoint2->Y, newPoint2->X] = 5;//出目的地
					}
					if (n2 == 3)
					{
						data[newPoint2->Y, newPoint2->X] = 4;//入他目的地              
					}

					RefImg(newPoint2);
					data[newPoint1->Y, newPoint1->X] = data[curpoint->Y, curpoint->X];//画人
					RefImg(newPoint1);
					data[curpoint->Y, curpoint->X] = cubee[curpoint->Y, curpoint->X]->OldValue;//原人归空白
					RefImg(curpoint);
					curpoint = newPoint1;
					CheckFinshed();
				}
			}
		}
		//***************************************************************************
	private: System::Void pushboxUI_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		Point *newPoint1 = new Point(curpoint->X, curpoint->Y);
		//Point *newPoint2 = curpoint;
		Point *newPoint2 = new Point(curpoint->X, curpoint->Y);
		int key = e->KeyValue;
		switch (key)
		{
		case 87://上38
			newPoint1->Y--;//人动
			newPoint2->Y -= 2;//箱子动
			data[curpoint->Y, curpoint->X] = 6;
			GoNewPoint(newPoint1, newPoint2);
			break;
		case 68://右39
			newPoint1->X++;
			newPoint2->X += 2;
			data[curpoint->Y, curpoint->X] = 9;
			GoNewPoint(newPoint1, newPoint2);
			break;
		case 83://下40
			newPoint1->Y++;
			newPoint2->Y += 2;
			data[curpoint->Y, curpoint->X] = 7;
			GoNewPoint(newPoint1, newPoint2);
			break;
		case 65://左37
			newPoint1->X--;
			newPoint2->X -= 2;
			data[curpoint->Y, curpoint->X] = 8;
			GoNewPoint(newPoint1, newPoint2);
			break;
		}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	pushboxUI_Load(nullptr, nullptr);
}
};
}

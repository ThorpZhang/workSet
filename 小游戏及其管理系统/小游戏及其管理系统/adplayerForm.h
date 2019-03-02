#pragma once
#include"user.h"
#include"Storage.h"
#include"typeDefinition.h"
#include"memberService.h"
#include"accmanager.h"
#include"pushbox.h"
#include"RandSUI.h"
#include<stdlib.h>
#include"pushboxUI.h"
#include<ctime>
#include"G2048.h"
#include"cleanmines.h"
#include"CMRandSUI.h"

namespace 小游戏及其管理系统 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace ManagementSystemV5;
	/// <summary>
	/// adplayerForm 摘要
	/// </summary>
/*	public  ref class mythread1
	{
	public:
		adplayer* theadult;
		mythread1(adplayer * ad1) { theadult = ad1; }
		void playgame()
		{
			play2(this->theadult);
		}
	};*/
	public  ref class mythread1
	{
	public:
		adplayer* theadult;
		mythread1(adplayer * ad1) { theadult = ad1; }
		void playgame()
		{
			adult_play_cleanmines(this->theadult);
		}
	};
	public ref class adplayerForm : public System::Windows::Forms::Form
	{
	public:
		adplayerForm(player *a)
		{
			//把player类型转化为childplayer类型
			adplayer*p = new adplayer();
			fstream f;
			char path[100];
			sprintf(path, "D:\\小游戏管理系统存储\\adplayer\\%s.dat", a->getid());
			f.open(path, ios::in | ios::binary);
			if (!f) { f.close(); Now = (adplayer*)a; }
			f.read((char*)p, sizeof(adplayer));
			f.close();
			Now = p;
			now = (childplayer*)p;
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~adplayerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
			 adplayer*Now;
			 childplayer*now;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  accmanage;
	private: System::Windows::Forms::Button^  RandSbutton;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(adplayerForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->accmanage = (gcnew System::Windows::Forms::Button());
			this->RandSbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(353, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"扫雷";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &adplayerForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(353, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(151, 69);
			this->button2->TabIndex = 1;
			this->button2->Text = L"推箱子";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &adplayerForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(351, 257);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(153, 61);
			this->button3->TabIndex = 2;
			this->button3->Text = L"2048";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &adplayerForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Control;
			this->button4->Location = System::Drawing::Point(31, 132);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 86);
			this->button4->TabIndex = 3;
			this->button4->Text = L"查看扫雷排名";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &adplayerForm::button4_Click);
			// 
			// accmanage
			// 
			this->accmanage->BackColor = System::Drawing::SystemColors::Control;
			this->accmanage->Location = System::Drawing::Point(31, 27);
			this->accmanage->Name = L"accmanage";
			this->accmanage->Size = System::Drawing::Size(140, 86);
			this->accmanage->TabIndex = 4;
			this->accmanage->Text = L"账户管理";
			this->accmanage->UseVisualStyleBackColor = false;
			this->accmanage->Click += gcnew System::EventHandler(this, &adplayerForm::accmanage_Click);
			// 
			// RandSbutton
			// 
			this->RandSbutton->Location = System::Drawing::Point(31, 242);
			this->RandSbutton->Name = L"RandSbutton";
			this->RandSbutton->Size = System::Drawing::Size(140, 76);
			this->RandSbutton->TabIndex = 5;
			this->RandSbutton->Text = L"推箱子积分和排名";
			this->RandSbutton->UseVisualStyleBackColor = true;
			this->RandSbutton->Click += gcnew System::EventHandler(this, &adplayerForm::RandSbutton_Click);
			// 
			// adplayerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(551, 344);
			this->Controls->Add(this->RandSbutton);
			this->Controls->Add(this->accmanage);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"adplayerForm";
			this->Text = L"成年人窗口端";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void accmanage_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Application::OpenForms["accmanager"] == nullptr) {
			//首次显示，生成新窗口
			accmanager^adone = gcnew accmanager();
			adone->Show();//显示
		}
		else {
			Application::OpenForms["accmanager"]->Show();//直接显示
		}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	mythread1 ^t = gcnew mythread1((adplayer*)now);
	ThreadStart ^ts = gcnew ThreadStart(t, &mythread1::playgame);
	Thread ^thread = gcnew Thread(ts);
	thread->Start();
}
private: System::Void RandSbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Application::OpenForms["RandSUI"] == nullptr) {
		RandSUI^adone = gcnew RandSUI();
		adone->Show();
	}
	else {
		Application::OpenForms["RandSUI"]->Show();
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Application::OpenForms["pushboxUI"] == nullptr) {
		pushboxUI^adone = gcnew pushboxUI(now);
		adone->Show();
	}
	else {
		Application::OpenForms["pushboxUI"]->Show();
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	srand((unsigned int)time(0));        //置时间种子
	if (Application::OpenForms["G2048"] == nullptr) {
		G2048^adone = gcnew G2048();
		adone->Show();
	}
	else {
		Application::OpenForms["G2048"]->Show();
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Application::OpenForms["CMRandSUI"] == nullptr) {
		CMRandSUI^adone = gcnew CMRandSUI();
		adone->Show();
	}
	else {
		Application::OpenForms["CMRandSUI"]->Show();
	}
}
};
}

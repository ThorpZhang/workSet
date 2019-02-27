#pragma once
#include"user.h"
#include"Storage.h"
#include"typeDefinition.h"
#include"memberService.h"

namespace 小游戏及其管理系统 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ManagementSystemV5;
	/// <summary>
	/// addadplayer 摘要
	/// </summary>
	public ref class addadplayer : public System::Windows::Forms::Form
	{
	public:
		addadplayer(void)
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
		~addadplayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  adnametbox;

	private: System::Windows::Forms::TextBox^  adpstbox;

	private: System::Windows::Forms::TextBox^  adIDtbox;

	private: System::Windows::Forms::Label^  adnamelabel;

	private: System::Windows::Forms::Label^  adpslabel;

	private: System::Windows::Forms::Label^  adIDlabel;


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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->adIDlabel = (gcnew System::Windows::Forms::Label());
			this->adpslabel = (gcnew System::Windows::Forms::Label());
			this->adnamelabel = (gcnew System::Windows::Forms::Label());
			this->adIDtbox = (gcnew System::Windows::Forms::TextBox());
			this->adpstbox = (gcnew System::Windows::Forms::TextBox());
			this->adnametbox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->adnametbox);
			this->groupBox1->Controls->Add(this->adpstbox);
			this->groupBox1->Controls->Add(this->adIDtbox);
			this->groupBox1->Controls->Add(this->adnamelabel);
			this->groupBox1->Controls->Add(this->adpslabel);
			this->groupBox1->Controls->Add(this->adIDlabel);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"宋体", 16));
			this->groupBox1->Location = System::Drawing::Point(29, 47);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(450, 333);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"请输入注册信息";
			// 
			// adIDlabel
			// 
			this->adIDlabel->AutoSize = true;
			this->adIDlabel->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->adIDlabel->Location = System::Drawing::Point(28, 83);
			this->adIDlabel->Name = L"adIDlabel";
			this->adIDlabel->Size = System::Drawing::Size(98, 18);
			this->adIDlabel->TabIndex = 0;
			this->adIDlabel->Text = L"请输入账号";
			// 
			// adpslabel
			// 
			this->adpslabel->AutoSize = true;
			this->adpslabel->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->adpslabel->Location = System::Drawing::Point(28, 148);
			this->adpslabel->Name = L"adpslabel";
			this->adpslabel->Size = System::Drawing::Size(98, 18);
			this->adpslabel->TabIndex = 1;
			this->adpslabel->Text = L"请输入密码";
			this->adpslabel->Click += gcnew System::EventHandler(this, &addadplayer::label2_Click);
			// 
			// adnamelabel
			// 
			this->adnamelabel->AutoSize = true;
			this->adnamelabel->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->adnamelabel->Location = System::Drawing::Point(28, 212);
			this->adnamelabel->Name = L"adnamelabel";
			this->adnamelabel->Size = System::Drawing::Size(98, 18);
			this->adnamelabel->TabIndex = 2;
			this->adnamelabel->Text = L"请输入姓名";
			// 
			// adIDtbox
			// 
			this->adIDtbox->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->adIDtbox->Location = System::Drawing::Point(136, 83);
			this->adIDtbox->Name = L"adIDtbox";
			this->adIDtbox->Size = System::Drawing::Size(231, 28);
			this->adIDtbox->TabIndex = 3;
			// 
			// adpstbox
			// 
			this->adpstbox->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->adpstbox->Location = System::Drawing::Point(136, 148);
			this->adpstbox->Name = L"adpstbox";
			this->adpstbox->Size = System::Drawing::Size(231, 28);
			this->adpstbox->TabIndex = 4;
			// 
			// adnametbox
			// 
			this->adnametbox->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->adnametbox->Location = System::Drawing::Point(136, 209);
			this->adnametbox->Name = L"adnametbox";
			this->adnametbox->Size = System::Drawing::Size(141, 28);
			this->adnametbox->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->button1->Location = System::Drawing::Point(47, 266);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 43);
			this->button1->TabIndex = 6;
			this->button1->Text = L"确定";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &addadplayer::button1_Click);
			// 
			// addadplayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 392);
			this->Controls->Add(this->groupBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"addadplayer";
			this->Text = L"家长注册";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^name = adnametbox->Text;
	String^IDstr = adIDtbox->Text;
	String^Psstr = adpstbox->Text;
	//用成年人用户功能类添加成年人用户
	Fadplayer*adult = new Fadplayer();
	//成年人玩家类
	adplayer*pm1 = new adplayer();
	//赋值
	pm1->setid((char*)(Marshal::StringToHGlobalAnsi(IDstr)).ToPointer());
	pm1->setname((char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer());
	pm1->setpassword((char*)(Marshal::StringToHGlobalAnsi(Psstr)).ToPointer());
	pm1->settype((int)userTypecode::user_adplayer);
	//存储对象到文件
	if (adult->writeadult(pm1) && adult->writeInitLoginInfo(pm1->getid(), pm1->getpassword(), 0)&&adult->InitRandSforadplayer(pm1)&&adult->InitCMRandSforadplayer(pm1)) {
		MessageBox::Show("注册成功！");
	}
}
};
}

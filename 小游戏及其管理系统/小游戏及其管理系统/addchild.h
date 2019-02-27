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
	/// addchild 摘要
	/// </summary>
	public ref class addchild : public System::Windows::Forms::Form
	{
	public:
		addchild(void)
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
		~addchild()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  IDpslabel;
	protected:


	private: System::Windows::Forms::Label^  IDlabel;


	private: System::Windows::Forms::TextBox^  IDpstbox;



	private: System::Windows::Forms::TextBox^  IDtbox;


	private: System::Windows::Forms::Button^  submitchildInfo;
	private: System::Windows::Forms::TextBox^  nametbox;
	private: System::Windows::Forms::Label^  childnamelabel;



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
			this->nametbox = (gcnew System::Windows::Forms::TextBox());
			this->childnamelabel = (gcnew System::Windows::Forms::Label());
			this->submitchildInfo = (gcnew System::Windows::Forms::Button());
			this->IDpstbox = (gcnew System::Windows::Forms::TextBox());
			this->IDtbox = (gcnew System::Windows::Forms::TextBox());
			this->IDpslabel = (gcnew System::Windows::Forms::Label());
			this->IDlabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->nametbox);
			this->groupBox1->Controls->Add(this->childnamelabel);
			this->groupBox1->Controls->Add(this->submitchildInfo);
			this->groupBox1->Controls->Add(this->IDpstbox);
			this->groupBox1->Controls->Add(this->IDtbox);
			this->groupBox1->Controls->Add(this->IDpslabel);
			this->groupBox1->Controls->Add(this->IDlabel);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"宋体", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(36, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(425, 349);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"请输入注册信息";
			// 
			// nametbox
			// 
			this->nametbox->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->nametbox->Location = System::Drawing::Point(127, 212);
			this->nametbox->Name = L"nametbox";
			this->nametbox->Size = System::Drawing::Size(163, 28);
			this->nametbox->TabIndex = 8;
			// 
			// childnamelabel
			// 
			this->childnamelabel->AutoSize = true;
			this->childnamelabel->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->childnamelabel->Location = System::Drawing::Point(32, 222);
			this->childnamelabel->Name = L"childnamelabel";
			this->childnamelabel->Size = System::Drawing::Size(98, 18);
			this->childnamelabel->TabIndex = 7;
			this->childnamelabel->Text = L"请输入姓名";
			// 
			// submitchildInfo
			// 
			this->submitchildInfo->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->submitchildInfo->Location = System::Drawing::Point(54, 287);
			this->submitchildInfo->Name = L"submitchildInfo";
			this->submitchildInfo->Size = System::Drawing::Size(131, 42);
			this->submitchildInfo->TabIndex = 6;
			this->submitchildInfo->Text = L"确定";
			this->submitchildInfo->UseVisualStyleBackColor = true;
			this->submitchildInfo->Click += gcnew System::EventHandler(this, &addchild::submitchildInfo_Click);
			// 
			// IDpstbox
			// 
			this->IDpstbox->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->IDpstbox->Location = System::Drawing::Point(127, 155);
			this->IDpstbox->Name = L"IDpstbox";
			this->IDpstbox->Size = System::Drawing::Size(266, 28);
			this->IDpstbox->TabIndex = 4;
			this->IDpstbox->TextChanged += gcnew System::EventHandler(this, &addchild::textBox2_TextChanged);
			// 
			// IDtbox
			// 
			this->IDtbox->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->IDtbox->Location = System::Drawing::Point(127, 81);
			this->IDtbox->Name = L"IDtbox";
			this->IDtbox->Size = System::Drawing::Size(266, 28);
			this->IDtbox->TabIndex = 3;
			// 
			// IDpslabel
			// 
			this->IDpslabel->AutoSize = true;
			this->IDpslabel->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->IDpslabel->Location = System::Drawing::Point(29, 165);
			this->IDpslabel->Name = L"IDpslabel";
			this->IDpslabel->Size = System::Drawing::Size(98, 18);
			this->IDpslabel->TabIndex = 1;
			this->IDpslabel->Text = L"请输入密码";
			this->IDpslabel->Click += gcnew System::EventHandler(this, &addchild::label2_Click);
			// 
			// IDlabel
			// 
			this->IDlabel->AutoSize = true;
			this->IDlabel->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->IDlabel->Location = System::Drawing::Point(29, 92);
			this->IDlabel->Name = L"IDlabel";
			this->IDlabel->Size = System::Drawing::Size(98, 18);
			this->IDlabel->TabIndex = 0;
			this->IDlabel->Text = L"请输入账号";
			// 
			// addchild
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 390);
			this->Controls->Add(this->groupBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"addchild";
			this->Text = L"未成年人用户注册";
			this->Load += gcnew System::EventHandler(this, &addchild::addchild_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void addchild_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void submitchildInfo_Click(System::Object^  sender, System::EventArgs^  e) {
	String^name = nametbox->Text;
	String^IDstr = IDtbox->Text;
	String^IDpsstr = IDpstbox->Text;
	//用未成年用户功能类添加用户
	Fchildplayer*child = new Fchildplayer();
	//未成年人玩家类
	childplayer*pm1 = new childplayer();
	//将用户输入的值赋给对象各属性，然后保存
	pm1->setid((char*)(Marshal::StringToHGlobalAnsi(IDstr)).ToPointer());
	pm1->setname((char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer());
	pm1->setpassword((char*)(Marshal::StringToHGlobalAnsi(IDpsstr)).ToPointer());
	pm1->settype((int)userTypecode::user_childplayer);
	//存储对象到文件
	if (child->writechild(pm1) && child->writeInitLoginInfo(pm1->getid(), pm1->getpassword(), 1)&&child->InitRandSforchildplayer(pm1)&&child->InitCMRandSforchildplayer(pm1)) {
		MessageBox::Show("注册成功！");
	}
	delete pm1;
}
};
}

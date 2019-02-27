#pragma once
#include"user.h"
#include"typeDefinition.h"
#include"Storage.h"
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
	/// deleteplayer 摘要
	/// </summary>
	public ref class deleteplayer : public System::Windows::Forms::Form
	{
	public:
		deleteplayer(void)
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
		~deleteplayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  acclabel;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  acctbox;


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
			this->acclabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->acctbox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// acclabel
			// 
			this->acclabel->AutoSize = true;
			this->acclabel->Location = System::Drawing::Point(18, 61);
			this->acclabel->Name = L"acclabel";
			this->acclabel->Size = System::Drawing::Size(44, 18);
			this->acclabel->TabIndex = 0;
			this->acclabel->Text = L"账号";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->acctbox);
			this->groupBox1->Controls->Add(this->acclabel);
			this->groupBox1->Location = System::Drawing::Point(12, 35);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(254, 197);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"请输入用户账号";
			// 
			// acctbox
			// 
			this->acctbox->Location = System::Drawing::Point(80, 58);
			this->acctbox->Name = L"acctbox";
			this->acctbox->Size = System::Drawing::Size(143, 28);
			this->acctbox->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(54, 132);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"确定";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &deleteplayer::button1_Click);
			// 
			// deleteplayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(278, 244);
			this->Controls->Add(this->groupBox1);
			this->Name = L"deleteplayer";
			this->Text = L"deleteplayer";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^idstr = acctbox->Text;
		//char id[30];
		//id = (char*)(Marshal::StringToHGlobalAnsi(idstr).ToPointer());
		//sprintf(id, "%s", idstr);
		//Fadplayer功能类实现调用删除函数
		Fadplayer *adult = new Fadplayer();
		//先获取此id的类型
		//Fadplayer*ad1 = new Fadplayer();
	//	if ((ad1->readplayerInfo((char*)(Marshal::StringToHGlobalAnsi(idstr)).ToPointer()))->gettype == (int)userTypecode::user_adplayer) {
			//如果是成年人玩
	//	}
		if (adult->deleteAccount((char*)(Marshal::StringToHGlobalAnsi(idstr).ToPointer()))) {
			MessageBox::Show("删除成功！");
		}
		else {
			MessageBox::Show("删除失败！"); 
		}
	}
};
}

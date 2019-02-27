#pragma once
#include"user.h"
#include"typeDefinition.h"
#include"Storage.h"
#include"memberService.h"
#include"addadplayer.h"
#include"deleteplayer.h"

namespace 小游戏及其管理系统 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ManagementSystemV5;
	/// <summary>
	/// accmanager 摘要
	/// </summary>
	public ref class accmanager : public System::Windows::Forms::Form
	{
	public:
		accmanager(void)
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
		~accmanager()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  createadplayer;
	private: System::Windows::Forms::Button^  deleteacc;
	protected:

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
			this->createadplayer = (gcnew System::Windows::Forms::Button());
			this->deleteacc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// createadplayer
			// 
			this->createadplayer->Location = System::Drawing::Point(56, 48);
			this->createadplayer->Name = L"createadplayer";
			this->createadplayer->Size = System::Drawing::Size(134, 63);
			this->createadplayer->TabIndex = 0;
			this->createadplayer->Text = L"注册成年人玩家";
			this->createadplayer->UseVisualStyleBackColor = true;
			this->createadplayer->Click += gcnew System::EventHandler(this, &accmanager::createadplayer_Click);
			// 
			// deleteacc
			// 
			this->deleteacc->Location = System::Drawing::Point(56, 152);
			this->deleteacc->Name = L"deleteacc";
			this->deleteacc->Size = System::Drawing::Size(134, 64);
			this->deleteacc->TabIndex = 1;
			this->deleteacc->Text = L"删除用户";
			this->deleteacc->UseVisualStyleBackColor = true;
			this->deleteacc->Click += gcnew System::EventHandler(this, &accmanager::deleteacc_Click);
			// 
			// accmanager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(247, 267);
			this->Controls->Add(this->deleteacc);
			this->Controls->Add(this->createadplayer);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"accmanager";
			this->Text = L"accmanager";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void createadplayer_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Application::OpenForms["addadplayer"] == nullptr) {
			//窗体首次显示，创建新窗体
			addadplayer^adone = gcnew addadplayer();
			adone->Show();//显示
		}
		else {
			Application::OpenForms["addadplayer"]->Show();//直接显示
		}
	}
	private: System::Void deleteacc_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Application::OpenForms["deleteplayer"] == nullptr) {
			//首次，生成新窗口
			deleteplayer^adone = gcnew deleteplayer();
			adone->Show();//显示
		}
		else {
			Application::OpenForms["deleteplayer"]->Show();//直接显示
		}
	}
	};
}

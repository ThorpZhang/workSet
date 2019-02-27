#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace 小游戏及其管理系统 {

	/// <summary>
	/// cube 摘要
	/// </summary>
	public ref class cube : public System::Windows::Forms::UserControl
	{
	public:
		cube(void)
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
		~cube()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ImageList^  imageList1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(cube::typeid));
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->SuspendLayout();
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"pict0.png");
			this->imageList1->Images->SetKeyName(1, L"pict1.png");
			this->imageList1->Images->SetKeyName(2, L"pict2.png");
			this->imageList1->Images->SetKeyName(3, L"pict3.png");
			this->imageList1->Images->SetKeyName(4, L"pict4.png");
			this->imageList1->Images->SetKeyName(5, L"pict5.png");
			this->imageList1->Images->SetKeyName(6, L"pict6.png");
			this->imageList1->Images->SetKeyName(7, L"pict7.png");
			this->imageList1->Images->SetKeyName(8, L"pict8.png");
			this->imageList1->Images->SetKeyName(9, L"pict9.png");
			// 
			// cube
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->Name = L"cube";
			this->Size = System::Drawing::Size(50, 50);
			this->Load += gcnew System::EventHandler(this, &cube::cube_Load);
			this->ResumeLayout(false);

		}

	private:
		int oldvalue;
	public:
		property int OldValue
		{
			int get()
			{
				if (oldvalue == 3) return 3;
				return 2;
			}
			void set(int value)
			{
				oldvalue = value;
			}
		}
		void RefImage()
		{
			Bitmap^bmp = gcnew Bitmap(imageList1->Images[int::Parse(this->Tag->ToString())]);
			this->BackgroundImage = ((System::Drawing::Bitmap^)(bmp));
			//Graphics^g1 = Graphics::FromImage(bmp);
			//g1->
		}
#pragma endregion
	private: System::Void cube_Load(System::Object^  sender, System::EventArgs^  e) {
		RefImage();
	}
	};
}

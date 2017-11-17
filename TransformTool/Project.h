#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TransformTool {

	/// <summary>
	/// Project の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Project : public System::Windows::Forms::Form
	{
	public:
		Project(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Project()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  P_OKbtn;
	protected: 
	protected: 








	private: System::Windows::Forms::Button^  P_Cancelbtn;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panel1;










	protected: 

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->P_OKbtn = (gcnew System::Windows::Forms::Button());
			this->P_Cancelbtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// P_OKbtn
			// 
			this->P_OKbtn->Location = System::Drawing::Point(405, 338);
			this->P_OKbtn->Name = L"P_OKbtn";
			this->P_OKbtn->Size = System::Drawing::Size(75, 23);
			this->P_OKbtn->TabIndex = 0;
			this->P_OKbtn->Text = L"OK";
			this->P_OKbtn->UseVisualStyleBackColor = true;
			this->P_OKbtn->Click += gcnew System::EventHandler(this, &Project::P_OKbtn_Click);
			// 
			// P_Cancelbtn
			// 
			this->P_Cancelbtn->Location = System::Drawing::Point(405, 309);
			this->P_Cancelbtn->Name = L"P_Cancelbtn";
			this->P_Cancelbtn->Size = System::Drawing::Size(75, 23);
			this->P_Cancelbtn->TabIndex = 3;
			this->P_Cancelbtn->Text = L"Cancel";
			this->P_Cancelbtn->UseVisualStyleBackColor = true;
			this->P_Cancelbtn->Click += gcnew System::EventHandler(this, &Project::P_Cancelbtn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(353, 339);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(24, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(353, 339);
			this->panel1->TabIndex = 5;
			// 
			// Project
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(492, 373);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->P_Cancelbtn);
			this->Controls->Add(this->P_OKbtn);
			this->Name = L"Project";
			this->Text = L"Project";
			this->Load += gcnew System::EventHandler(this, &Project::Project_Load);
			this->Resize += gcnew System::EventHandler(this, &Project::Project_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: void WindowToCenter() {
				 // フォームを中央に配置
				 System::Drawing::Rectangle ^ rect = Screen::PrimaryScreen->Bounds;
				 int sx = rect->Width;
				 int sy = rect->Height;
				 this->Left = (sx - this->Width) / 2;
				 this->Top = (sy - this->Height) / 2;
			 }

	private: System::Void Project_Load(System::Object^  sender, System::EventArgs^  e) {
				 // ウィンドウを開いた時
				 this->Width = 500;		// サイズの指定(横)
				 this->Height = 400;	// サイズの指定(縦)
				 WindowToCenter();		// 画像中心
				 this->TopMost = true;	// 最前面
			 }
	private: System::Void Project_Resize(System::Object^  sender, System::EventArgs^  e) {
				 // ウィンドウをリサイズした時
				 if(this->Width < 500) this->Width = 500;	// 最小の幅
				 if(this->Height < 400) this->Height = 400;	// 最小の高さ
				 if(this->Width > 500) this->Width = 500;	// 最大の幅
				 if(this->Height > 400) this->Height = 400;	// 最大の高さ
				 WindowToCenter();		// 画像中心
			 }
	private: System::Void P_OKbtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 // OKボタン実行
				 this->Hide();
			 }
	private: System::Void P_Cancelbtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 // キャンセルボタン実行
				 this->Hide();
			 }
};
}

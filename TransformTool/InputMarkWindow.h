#pragma once
#include "ImageHeader.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TransformTool {

	/// <summary>
	/// InputMarkWindow の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class InputMarkWindow : public System::Windows::Forms::Form
	{
	public:
		InputMarkWindow(void)
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
		~InputMarkWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  PictureBox;
	private: System::Windows::Forms::Button^  OKBtn;
	private: System::Windows::Forms::Button^  CancelBtn;
	private: System::Windows::Forms::Panel^  Panel;
	private: System::Windows::Forms::ListBox^  ListBox;
	private: System::Windows::Forms::Panel^  SubPanel;
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
			this->OKBtn = (gcnew System::Windows::Forms::Button());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			this->PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Panel = (gcnew System::Windows::Forms::Panel());
			this->ListBox = (gcnew System::Windows::Forms::ListBox());
			this->SubPanel = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox))->BeginInit();
			this->Panel->SuspendLayout();
			this->SubPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// OKBtn
			// 
			this->OKBtn->Location = System::Drawing::Point(72, 623);
			this->OKBtn->Name = L"OKBtn";
			this->OKBtn->Size = System::Drawing::Size(75, 23);
			this->OKBtn->TabIndex = 0;
			this->OKBtn->Text = L"OK";
			this->OKBtn->UseVisualStyleBackColor = true;
			this->OKBtn->Click += gcnew System::EventHandler(this, &InputMarkWindow::OKBtn_Click);
			// 
			// CancelBtn
			// 
			this->CancelBtn->Location = System::Drawing::Point(72, 594);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(75, 23);
			this->CancelBtn->TabIndex = 3;
			this->CancelBtn->Text = L"Cancel";
			this->CancelBtn->UseVisualStyleBackColor = true;
			this->CancelBtn->Click += gcnew System::EventHandler(this, &InputMarkWindow::CancelBtn_Click);
			// 
			// PictureBox
			// 
			this->PictureBox->BackColor = System::Drawing::Color::Black;
			this->PictureBox->Location = System::Drawing::Point(0, 0);
			this->PictureBox->Name = L"PictureBox";
			this->PictureBox->Size = System::Drawing::Size(500, 400);
			this->PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PictureBox->TabIndex = 4;
			this->PictureBox->TabStop = false;
			this->PictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &InputMarkWindow::PictureBox_MouseDown);
			// 
			// Panel
			// 
			this->Panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->Panel->AutoScroll = true;
			this->Panel->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Panel->Controls->Add(this->PictureBox);
			this->Panel->Location = System::Drawing::Point(12, 12);
			this->Panel->Name = L"Panel";
			this->Panel->Size = System::Drawing::Size(800, 650);
			this->Panel->TabIndex = 5;
			// 
			// ListBox
			// 
			this->ListBox->FormattingEnabled = true;
			this->ListBox->ItemHeight = 12;
			this->ListBox->Location = System::Drawing::Point(3, 500);
			this->ListBox->Name = L"ListBox";
			this->ListBox->Size = System::Drawing::Size(144, 88);
			this->ListBox->TabIndex = 6;
			// 
			// SubPanel
			// 
			this->SubPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->SubPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->SubPanel->Controls->Add(this->ListBox);
			this->SubPanel->Controls->Add(this->OKBtn);
			this->SubPanel->Controls->Add(this->CancelBtn);
			this->SubPanel->Location = System::Drawing::Point(830, 12);
			this->SubPanel->Name = L"SubPanel";
			this->SubPanel->Size = System::Drawing::Size(150, 649);
			this->SubPanel->TabIndex = 7;
			// 
			// InputMarkWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 673);
			this->Controls->Add(this->SubPanel);
			this->Controls->Add(this->Panel);
			this->Name = L"InputMarkWindow";
			this->ShowIcon = false;
			this->Text = L"InputMarkWindow";
			this->Load += gcnew System::EventHandler(this, &InputMarkWindow::InputMarkWindow_Load);
			this->Resize += gcnew System::EventHandler(this, &InputMarkWindow::InputMarkWindow_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox))->EndInit();
			this->Panel->ResumeLayout(false);
			this->Panel->PerformLayout();
			this->SubPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		//===================//
		//  InputMarkWindow  //
		//===================//
	private:
		//- Coordinate -//
		array <Point, 1> ^in_pt, ^in_pt_tmp;	// 入力点(座標)の領域確保
		array <Point, 1> ^out_pt, ^out_pt_tmp;	// 出力点(座標)の領域確保

	private:
		void WindowToCenter() {
			// フォームを中央に配置
			System::Drawing::Rectangle ^window_rect = Screen::PrimaryScreen->Bounds;
			int sx = window_rect->Width;
			int sy = window_rect->Height;
			this->Left = (sx - this->Width) / 2;
			this->Top = (sy - this->Height) / 2;
		}
	private:
		System::Void InputMarkWindow_Load(System::Object^  sender, System::EventArgs^  e) {
			// ウィンドウを開いた時
			WindowToCenter();		// 画像中心
			this->TopMost = true;	// 最前面
			//PictureBox->Image
		}
	private: 
		System::Void InputMarkWindow_Resize(System::Object^  sender, System::EventArgs^  e) {
			// ウィンドウをリサイズした時
			//Point pt = Panel->Location;
			//Panel->Width = this->Width - (SubPanel->Width+50);
			//Panel->Height = this->Height - 50;
			//SubPanel->Location = Point(Panel->Width + 30, pt.Y);
			//SubPanel->Height = Panel->Height;
			//this->Refresh();
		}
	private:
		System::Void OKBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			// OKボタン実行
			this->Hide();
		}
	private: 
		System::Void CancelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			// キャンセルボタン実行
			this->Hide();
		}
		//
		System::Void PictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			this->Refresh();
		}
	};
}

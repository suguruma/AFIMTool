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
	/// InputMarkWindow �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public ref class InputMarkWindow : public System::Windows::Forms::Form
	{
	public:
		InputMarkWindow(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^ �R�[�h��ǉ����܂�
			//
		}
	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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
		/// �K�v�ȃf�U�C�i�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�ŕύX���Ȃ��ł��������B
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
		array <Point, 1> ^in_pt, ^in_pt_tmp;	// ���͓_(���W)�̗̈�m��
		array <Point, 1> ^out_pt, ^out_pt_tmp;	// �o�͓_(���W)�̗̈�m��

	private:
		void WindowToCenter() {
			// �t�H�[���𒆉��ɔz�u
			System::Drawing::Rectangle ^window_rect = Screen::PrimaryScreen->Bounds;
			int sx = window_rect->Width;
			int sy = window_rect->Height;
			this->Left = (sx - this->Width) / 2;
			this->Top = (sy - this->Height) / 2;
		}
	private:
		System::Void InputMarkWindow_Load(System::Object^  sender, System::EventArgs^  e) {
			// �E�B���h�E���J������
			WindowToCenter();		// �摜���S
			this->TopMost = true;	// �őO��
			//PictureBox->Image
		}
	private: 
		System::Void InputMarkWindow_Resize(System::Object^  sender, System::EventArgs^  e) {
			// �E�B���h�E�����T�C�Y������
			//Point pt = Panel->Location;
			//Panel->Width = this->Width - (SubPanel->Width+50);
			//Panel->Height = this->Height - 50;
			//SubPanel->Location = Point(Panel->Width + 30, pt.Y);
			//SubPanel->Height = Panel->Height;
			//this->Refresh();
		}
	private:
		System::Void OKBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			// OK�{�^�����s
			this->Hide();
		}
	private: 
		System::Void CancelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			// �L�����Z���{�^�����s
			this->Hide();
		}
		//
		System::Void PictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			this->Refresh();
		}
	};
}

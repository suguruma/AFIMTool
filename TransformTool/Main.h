#pragma once
#include <iostream>
#include <math.h>
#include "InputMarkWindow.h"
#include "TransformTool.h"

namespace TransformTool {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::IO;
	using namespace System::Diagnostics;

	/// <summary>
	/// Main の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
			in_mark_form = gcnew InputMarkWindow();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  MenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  fileMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  windowMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  CenterMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  AAspectMenuItem;
	private: System::Windows::Forms::StatusStrip^  StatusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^  StatusLabel;
	private: System::Windows::Forms::ToolStripProgressBar^  ProgressBar;
	private: System::Windows::Forms::GroupBox^  SettingBox;
	private: System::Windows::Forms::ListBox^  OutputListBox;
	private: System::Windows::Forms::ListBox^  InputListBox;
	private: System::Windows::Forms::Button^  RunBtn;
	private: System::Windows::Forms::PictureBox^  InputImage1;
	private: System::Windows::Forms::PictureBox^  InputImage2;
	private: System::Windows::Forms::TrackBar^  ImageTrackBar;
	private: System::Windows::Forms::Button^  InputZoom;
	private: System::Windows::Forms::Button^  OutputZoom;
	private: System::Windows::Forms::PictureBox^  InterlevelImage;
	private: System::Windows::Forms::PictureBox^  FirstImage;
	private: System::Windows::Forms::PictureBox^  SecondImage;
	private: System::Windows::Forms::Button^  StartBtn;
	private: System::Windows::Forms::Button^  StopBtn;
	private: System::Windows::Forms::Button^  InterlevelZoom;
	private: System::Windows::Forms::Button^  OriginZoom;
	private: System::Windows::Forms::Button^  ProcessedZoom;
	private: System::Windows::Forms::Button^  ReadInputImage1;
	private: System::Windows::Forms::Button^  ReadInputImage2;
	private: System::Windows::Forms::OpenFileDialog^  OpenFileDialog;
	private: System::Windows::Forms::Label^  ResultLabel;
	private: System::Windows::Forms::Label^  OriginalLabel;
	private: System::Windows::Forms::GroupBox^  ProjectType;
	private: System::Windows::Forms::RadioButton^  NormalizationSelect;
	private: System::Windows::Forms::RadioButton^  WarpingSelect;
	private: System::Windows::Forms::NumericUpDown^  Franenumeric;
	private: System::Windows::Forms::Label^  LabelFrame;
	private: System::Windows::Forms::NumericUpDown^  Latticenumeric;
	private: System::Windows::Forms::NumericUpDown^  PartitionNumeric;
	private: System::Windows::Forms::NumericUpDown^  PointNumeric;
	private: System::Windows::Forms::Label^  LabelLatticeStep;
	private: System::Windows::Forms::Label^  LabelPartition;
	private: System::Windows::Forms::Label^  LabelPoint;
	private: System::Windows::Forms::GroupBox^  Interpolation;
	private: System::Windows::Forms::RadioButton^  NNBtn;
	private: System::Windows::Forms::RadioButton^  BiLinearBtn;
	private: System::Windows::Forms::CheckBox^  AnimationCk;
	private: System::Windows::Forms::ToolStripStatusLabel^  FrameRemainder;
	private: System::Windows::Forms::ToolStripStatusLabel^  Per;
	private: System::Windows::Forms::ToolStripStatusLabel^  FrameAll;
	private: System::Windows::Forms::Label^  AboutInPoint;
	private: System::Windows::Forms::NumericUpDown^  InPointSize;
	private: System::Windows::Forms::NumericUpDown^  OutPointSize;
	private: System::Windows::Forms::Label^  AboutOutPoint;
	private: System::Windows::Forms::Button^  InputInit;
	private: System::Windows::Forms::Button^  OutputInit;
	private: System::Windows::Forms::Timer^  AnimateTimer;
	private: System::Windows::Forms::Button^  InputCoordinateWrite;
	private: System::Windows::Forms::Button^  InputCoordinateRead;
	private: System::Windows::Forms::Button^  OutputCoordinateWrite;
	private: System::Windows::Forms::Button^  OutputCoordinateRead;
	private: System::Windows::Forms::Button^  InputNumberDisplay;
	private: System::Windows::Forms::Button^  OutputNumberDisplay;
	private: System::Windows::Forms::SaveFileDialog^  SaveFileDialog;
	private: System::Windows::Forms::Button^  InputMesh;
	private: System::Windows::Forms::Button^  OutputMesh;
	private: System::Windows::Forms::Button^  SaveImageBtn;
	private: System::Windows::Forms::Button^  SaveAnimate;
	private: System::Windows::Forms::TableLayoutPanel^  TableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  TableLayoutPanel2;
	private: System::Windows::Forms::Panel^  PanelOriginalImage;
	private: System::Windows::Forms::Panel^  PanelAnimateImage;
	private: System::Windows::Forms::Panel^  PanelResultImage;
	private: System::Windows::Forms::TableLayoutPanel^  TableLayoutPanel3;
	private: System::Windows::Forms::Panel^  PanelInputImage1;
	private: System::Windows::Forms::Panel^  PanelInputImage2;
	private: System::Windows::Forms::TableLayoutPanel^  TableLayoutPanel4;
	private: System::Windows::Forms::Panel^  PanelInputBtn;
	private: System::Windows::Forms::Panel^  PanelOutputBtn;
	private: System::Windows::Forms::TableLayoutPanel^  TableLayoutPanel5;
	private: System::Windows::Forms::Panel^  PanelOriginalBtn;
	private: System::Windows::Forms::Panel^  PanelAnimateBtn;
	private: System::Windows::Forms::Panel^  PanelResultBtn;
	private: System::Windows::Forms::TableLayoutPanel^  TableLayoutPanel6;
	private: System::Windows::Forms::Panel^  PanelImage1Info;
	private: System::Windows::Forms::Panel^  PanelImage2Info;
	private: System::Windows::Forms::RadioButton^  MorphingSelect;
	private: System::Windows::Forms::CheckBox^  EyebrowParts;
	private: System::Windows::Forms::CheckBox^  MouthParts;
	private: System::Windows::Forms::CheckBox^  EyeParts;
	private: System::Windows::Forms::Label^  BackgroundLabel;
	private: System::Windows::Forms::PictureBox^  BackgroundImage;
	private: System::Windows::Forms::ToolStripMenuItem^  ActiveShapeModelToolStripMenuItem;
	private: System::Windows::Forms::Button^  AssociationBtn;
	private: System::Windows::Forms::TableLayoutPanel^  TableLayoutPanel7;
	private: System::Windows::Forms::CheckBox^  NoseParts;
	private: System::Windows::Forms::Button^  BackgroundReadColor;
	private: System::Windows::Forms::ColorDialog^  ColorDialog;
	private: System::Windows::Forms::Button^  BackgroundReadImage;
	private: System::Windows::Forms::OpenFileDialog^  OpenBGImageDialog;
	private: System::Windows::Forms::Panel^  NormalizationPanel;
	private: System::Windows::Forms::Panel^  MorphPanel;
	private: System::Windows::Forms::Button^  DisplayChange1;
	private: System::Windows::Forms::Button^  DisplayChange2;
	private: System::Windows::Forms::CheckBox^  Image1SpeedingUp;
	private: System::Windows::Forms::CheckBox^  Image2SpeedingUp;
	private: System::Windows::Forms::Label^  Image1Label;
	private: System::Windows::Forms::Label^  Image2Label;
	private: System::Windows::Forms::Label^  Image1Name;
	private: System::Windows::Forms::Label^  Image2Name;
	private: System::Windows::Forms::Panel^  Image1NamePanel;
	private: System::Windows::Forms::Panel^  Image2NamePanel;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->MenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ActiveShapeModelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->windowMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CenterMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AAspectMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StatusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->StatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->ProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->FrameRemainder = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->Per = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->FrameAll = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->SettingBox = (gcnew System::Windows::Forms::GroupBox());
			this->TableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->OutputListBox = (gcnew System::Windows::Forms::ListBox());
			this->InputListBox = (gcnew System::Windows::Forms::ListBox());
			this->AssociationBtn = (gcnew System::Windows::Forms::Button());
			this->Interpolation = (gcnew System::Windows::Forms::GroupBox());
			this->NNBtn = (gcnew System::Windows::Forms::RadioButton());
			this->BiLinearBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ProjectType = (gcnew System::Windows::Forms::GroupBox());
			this->MorphPanel = (gcnew System::Windows::Forms::Panel());
			this->LabelLatticeStep = (gcnew System::Windows::Forms::Label());
			this->Latticenumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->Franenumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->AnimationCk = (gcnew System::Windows::Forms::CheckBox());
			this->LabelFrame = (gcnew System::Windows::Forms::Label());
			this->NormalizationPanel = (gcnew System::Windows::Forms::Panel());
			this->LabelPoint = (gcnew System::Windows::Forms::Label());
			this->BackgroundReadImage = (gcnew System::Windows::Forms::Button());
			this->LabelPartition = (gcnew System::Windows::Forms::Label());
			this->BackgroundReadColor = (gcnew System::Windows::Forms::Button());
			this->PointNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->NoseParts = (gcnew System::Windows::Forms::CheckBox());
			this->PartitionNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->BackgroundLabel = (gcnew System::Windows::Forms::Label());
			this->EyeParts = (gcnew System::Windows::Forms::CheckBox());
			this->BackgroundImage = (gcnew System::Windows::Forms::PictureBox());
			this->MouthParts = (gcnew System::Windows::Forms::CheckBox());
			this->EyebrowParts = (gcnew System::Windows::Forms::CheckBox());
			this->MorphingSelect = (gcnew System::Windows::Forms::RadioButton());
			this->NormalizationSelect = (gcnew System::Windows::Forms::RadioButton());
			this->WarpingSelect = (gcnew System::Windows::Forms::RadioButton());
			this->RunBtn = (gcnew System::Windows::Forms::Button());
			this->InputImage1 = (gcnew System::Windows::Forms::PictureBox());
			this->InputMesh = (gcnew System::Windows::Forms::Button());
			this->InputNumberDisplay = (gcnew System::Windows::Forms::Button());
			this->InputCoordinateWrite = (gcnew System::Windows::Forms::Button());
			this->InputCoordinateRead = (gcnew System::Windows::Forms::Button());
			this->InputInit = (gcnew System::Windows::Forms::Button());
			this->InPointSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->AboutInPoint = (gcnew System::Windows::Forms::Label());
			this->ReadInputImage1 = (gcnew System::Windows::Forms::Button());
			this->InputZoom = (gcnew System::Windows::Forms::Button());
			this->OutputMesh = (gcnew System::Windows::Forms::Button());
			this->OutputNumberDisplay = (gcnew System::Windows::Forms::Button());
			this->OutputCoordinateWrite = (gcnew System::Windows::Forms::Button());
			this->OutputCoordinateRead = (gcnew System::Windows::Forms::Button());
			this->OutputInit = (gcnew System::Windows::Forms::Button());
			this->OutPointSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->AboutOutPoint = (gcnew System::Windows::Forms::Label());
			this->ReadInputImage2 = (gcnew System::Windows::Forms::Button());
			this->OutputZoom = (gcnew System::Windows::Forms::Button());
			this->InputImage2 = (gcnew System::Windows::Forms::PictureBox());
			this->ImageTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->InterlevelImage = (gcnew System::Windows::Forms::PictureBox());
			this->FirstImage = (gcnew System::Windows::Forms::PictureBox());
			this->SecondImage = (gcnew System::Windows::Forms::PictureBox());
			this->StartBtn = (gcnew System::Windows::Forms::Button());
			this->StopBtn = (gcnew System::Windows::Forms::Button());
			this->InterlevelZoom = (gcnew System::Windows::Forms::Button());
			this->OriginZoom = (gcnew System::Windows::Forms::Button());
			this->ProcessedZoom = (gcnew System::Windows::Forms::Button());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->OriginalLabel = (gcnew System::Windows::Forms::Label());
			this->AnimateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SaveAnimate = (gcnew System::Windows::Forms::Button());
			this->SaveImageBtn = (gcnew System::Windows::Forms::Button());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->TableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->TableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PanelOriginalImage = (gcnew System::Windows::Forms::Panel());
			this->PanelAnimateImage = (gcnew System::Windows::Forms::Panel());
			this->PanelResultImage = (gcnew System::Windows::Forms::Panel());
			this->TableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PanelInputImage1 = (gcnew System::Windows::Forms::Panel());
			this->PanelInputImage2 = (gcnew System::Windows::Forms::Panel());
			this->TableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PanelInputBtn = (gcnew System::Windows::Forms::Panel());
			this->Image1NamePanel = (gcnew System::Windows::Forms::Panel());
			this->Image1Name = (gcnew System::Windows::Forms::Label());
			this->Image1Label = (gcnew System::Windows::Forms::Label());
			this->PanelOutputBtn = (gcnew System::Windows::Forms::Panel());
			this->Image2NamePanel = (gcnew System::Windows::Forms::Panel());
			this->Image2Name = (gcnew System::Windows::Forms::Label());
			this->Image2Label = (gcnew System::Windows::Forms::Label());
			this->TableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PanelOriginalBtn = (gcnew System::Windows::Forms::Panel());
			this->PanelAnimateBtn = (gcnew System::Windows::Forms::Panel());
			this->PanelResultBtn = (gcnew System::Windows::Forms::Panel());
			this->TableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PanelImage1Info = (gcnew System::Windows::Forms::Panel());
			this->Image1SpeedingUp = (gcnew System::Windows::Forms::CheckBox());
			this->DisplayChange1 = (gcnew System::Windows::Forms::Button());
			this->PanelImage2Info = (gcnew System::Windows::Forms::Panel());
			this->Image2SpeedingUp = (gcnew System::Windows::Forms::CheckBox());
			this->DisplayChange2 = (gcnew System::Windows::Forms::Button());
			this->ColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->OpenBGImageDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->MenuStrip->SuspendLayout();
			this->StatusStrip->SuspendLayout();
			this->SettingBox->SuspendLayout();
			this->TableLayoutPanel7->SuspendLayout();
			this->Interpolation->SuspendLayout();
			this->ProjectType->SuspendLayout();
			this->MorphPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Latticenumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Franenumeric))->BeginInit();
			this->NormalizationPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PointNumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PartitionNumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BackgroundImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputImage1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InPointSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OutPointSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputImage2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ImageTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InterlevelImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FirstImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SecondImage))->BeginInit();
			this->TableLayoutPanel1->SuspendLayout();
			this->TableLayoutPanel2->SuspendLayout();
			this->PanelOriginalImage->SuspendLayout();
			this->PanelAnimateImage->SuspendLayout();
			this->PanelResultImage->SuspendLayout();
			this->TableLayoutPanel3->SuspendLayout();
			this->PanelInputImage1->SuspendLayout();
			this->PanelInputImage2->SuspendLayout();
			this->TableLayoutPanel4->SuspendLayout();
			this->PanelInputBtn->SuspendLayout();
			this->Image1NamePanel->SuspendLayout();
			this->PanelOutputBtn->SuspendLayout();
			this->Image2NamePanel->SuspendLayout();
			this->TableLayoutPanel5->SuspendLayout();
			this->PanelOriginalBtn->SuspendLayout();
			this->PanelAnimateBtn->SuspendLayout();
			this->PanelResultBtn->SuspendLayout();
			this->TableLayoutPanel6->SuspendLayout();
			this->PanelImage1Info->SuspendLayout();
			this->PanelImage2Info->SuspendLayout();
			this->SuspendLayout();
			// 
			// MenuStrip
			// 
			this->MenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->fileMenuItem, this->editMenuItem, 
				this->viewMenuItem, this->toolsMenuItem, this->windowMenuItem, this->helpMenuItem});
			this->MenuStrip->Location = System::Drawing::Point(0, 0);
			this->MenuStrip->Name = L"MenuStrip";
			this->MenuStrip->Size = System::Drawing::Size(1016, 26);
			this->MenuStrip->TabIndex = 1;
			this->MenuStrip->Text = L"ToolBar";
			// 
			// fileMenuItem
			// 
			this->fileMenuItem->Name = L"fileMenuItem";
			this->fileMenuItem->Size = System::Drawing::Size(40, 22);
			this->fileMenuItem->Text = L"&File";
			// 
			// editMenuItem
			// 
			this->editMenuItem->Name = L"editMenuItem";
			this->editMenuItem->Size = System::Drawing::Size(42, 22);
			this->editMenuItem->Text = L"&Edit";
			// 
			// viewMenuItem
			// 
			this->viewMenuItem->Name = L"viewMenuItem";
			this->viewMenuItem->Size = System::Drawing::Size(48, 22);
			this->viewMenuItem->Text = L"&View";
			// 
			// toolsMenuItem
			// 
			this->toolsMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ActiveShapeModelToolStripMenuItem});
			this->toolsMenuItem->Name = L"toolsMenuItem";
			this->toolsMenuItem->Size = System::Drawing::Size(50, 22);
			this->toolsMenuItem->Text = L"&Tools";
			// 
			// ActiveShapeModelToolStripMenuItem
			// 
			this->ActiveShapeModelToolStripMenuItem->Name = L"ActiveShapeModelToolStripMenuItem";
			this->ActiveShapeModelToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->ActiveShapeModelToolStripMenuItem->Text = L"Active Shape Model";
			this->ActiveShapeModelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::ActiveShapeModelToolStripMenuItem_Click);
			// 
			// windowMenuItem
			// 
			this->windowMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->CenterMenuItem, 
				this->AAspectMenuItem});
			this->windowMenuItem->Name = L"windowMenuItem";
			this->windowMenuItem->Size = System::Drawing::Size(66, 22);
			this->windowMenuItem->Text = L"&Window";
			// 
			// CenterMenuItem
			// 
			this->CenterMenuItem->Name = L"CenterMenuItem";
			this->CenterMenuItem->Size = System::Drawing::Size(166, 22);
			this->CenterMenuItem->Text = L"Center";
			this->CenterMenuItem->Click += gcnew System::EventHandler(this, &Main::CenterMenuItem_Click);
			// 
			// AAspectMenuItem
			// 
			this->AAspectMenuItem->Name = L"AAspectMenuItem";
			this->AAspectMenuItem->Size = System::Drawing::Size(166, 22);
			this->AAspectMenuItem->Text = L"Anterior Aspect";
			this->AAspectMenuItem->Click += gcnew System::EventHandler(this, &Main::AAspectMenuItem_Click);
			// 
			// helpMenuItem
			// 
			this->helpMenuItem->Name = L"helpMenuItem";
			this->helpMenuItem->Size = System::Drawing::Size(46, 22);
			this->helpMenuItem->Text = L"&Help";
			// 
			// StatusStrip
			// 
			this->StatusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->StatusLabel, this->ProgressBar, 
				this->FrameRemainder, this->Per, this->FrameAll});
			this->StatusStrip->Location = System::Drawing::Point(0, 710);
			this->StatusStrip->Name = L"StatusStrip";
			this->StatusStrip->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StatusStrip->Size = System::Drawing::Size(1016, 23);
			this->StatusStrip->TabIndex = 2;
			this->StatusStrip->Text = L"StatusBar";
			// 
			// StatusLabel
			// 
			this->StatusLabel->Name = L"StatusLabel";
			this->StatusLabel->Size = System::Drawing::Size(46, 18);
			this->StatusLabel->Text = L"Status";
			// 
			// ProgressBar
			// 
			this->ProgressBar->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->ProgressBar->Name = L"ProgressBar";
			this->ProgressBar->Size = System::Drawing::Size(100, 17);
			// 
			// FrameRemainder
			// 
			this->FrameRemainder->Margin = System::Windows::Forms::Padding(5, 3, 0, 2);
			this->FrameRemainder->Name = L"FrameRemainder";
			this->FrameRemainder->Size = System::Drawing::Size(14, 18);
			this->FrameRemainder->Text = L"\?";
			// 
			// Per
			// 
			this->Per->Name = L"Per";
			this->Per->Size = System::Drawing::Size(13, 18);
			this->Per->Text = L"/";
			// 
			// FrameAll
			// 
			this->FrameAll->Name = L"FrameAll";
			this->FrameAll->Size = System::Drawing::Size(14, 18);
			this->FrameAll->Text = L"\?";
			// 
			// SettingBox
			// 
			this->SettingBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->SettingBox->Controls->Add(this->TableLayoutPanel7);
			this->SettingBox->Controls->Add(this->AssociationBtn);
			this->SettingBox->Controls->Add(this->Interpolation);
			this->SettingBox->Controls->Add(this->ProjectType);
			this->SettingBox->Controls->Add(this->RunBtn);
			this->SettingBox->Enabled = false;
			this->SettingBox->Location = System::Drawing::Point(12, 27);
			this->SettingBox->Name = L"SettingBox";
			this->SettingBox->Size = System::Drawing::Size(189, 675);
			this->SettingBox->TabIndex = 3;
			this->SettingBox->TabStop = false;
			this->SettingBox->Text = L"Setting";
			// 
			// TableLayoutPanel7
			// 
			this->TableLayoutPanel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableLayoutPanel7->ColumnCount = 1;
			this->TableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->TableLayoutPanel7->Controls->Add(this->OutputListBox, 0, 1);
			this->TableLayoutPanel7->Controls->Add(this->InputListBox, 0, 0);
			this->TableLayoutPanel7->Location = System::Drawing::Point(6, 493);
			this->TableLayoutPanel7->Name = L"TableLayoutPanel7";
			this->TableLayoutPanel7->RowCount = 2;
			this->TableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->TableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->TableLayoutPanel7->Size = System::Drawing::Size(177, 176);
			this->TableLayoutPanel7->TabIndex = 21;
			// 
			// OutputListBox
			// 
			this->OutputListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->OutputListBox->FormattingEnabled = true;
			this->OutputListBox->ItemHeight = 12;
			this->OutputListBox->Location = System::Drawing::Point(3, 91);
			this->OutputListBox->Name = L"OutputListBox";
			this->OutputListBox->Size = System::Drawing::Size(171, 76);
			this->OutputListBox->TabIndex = 2;
			// 
			// InputListBox
			// 
			this->InputListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->InputListBox->FormattingEnabled = true;
			this->InputListBox->ItemHeight = 12;
			this->InputListBox->Location = System::Drawing::Point(3, 3);
			this->InputListBox->Name = L"InputListBox";
			this->InputListBox->Size = System::Drawing::Size(171, 76);
			this->InputListBox->TabIndex = 1;
			// 
			// AssociationBtn
			// 
			this->AssociationBtn->Location = System::Drawing::Point(15, 458);
			this->AssociationBtn->Name = L"AssociationBtn";
			this->AssociationBtn->Size = System::Drawing::Size(77, 29);
			this->AssociationBtn->TabIndex = 20;
			this->AssociationBtn->Text = L"Association";
			this->AssociationBtn->UseVisualStyleBackColor = true;
			this->AssociationBtn->Click += gcnew System::EventHandler(this, &Main::AssociationBtn_Click);
			// 
			// Interpolation
			// 
			this->Interpolation->Controls->Add(this->NNBtn);
			this->Interpolation->Controls->Add(this->BiLinearBtn);
			this->Interpolation->Location = System::Drawing::Point(9, 392);
			this->Interpolation->Name = L"Interpolation";
			this->Interpolation->Size = System::Drawing::Size(171, 60);
			this->Interpolation->TabIndex = 18;
			this->Interpolation->TabStop = false;
			this->Interpolation->Text = L"Interpolation";
			// 
			// NNBtn
			// 
			this->NNBtn->AutoSize = true;
			this->NNBtn->Checked = true;
			this->NNBtn->Location = System::Drawing::Point(6, 18);
			this->NNBtn->Name = L"NNBtn";
			this->NNBtn->Size = System::Drawing::Size(112, 16);
			this->NNBtn->TabIndex = 1;
			this->NNBtn->TabStop = true;
			this->NNBtn->Text = L"Nearest Neighbor";
			this->NNBtn->UseVisualStyleBackColor = true;
			// 
			// BiLinearBtn
			// 
			this->BiLinearBtn->AutoSize = true;
			this->BiLinearBtn->Location = System::Drawing::Point(6, 40);
			this->BiLinearBtn->Name = L"BiLinearBtn";
			this->BiLinearBtn->Size = System::Drawing::Size(71, 16);
			this->BiLinearBtn->TabIndex = 0;
			this->BiLinearBtn->TabStop = true;
			this->BiLinearBtn->Text = L"Bi-Linear";
			this->BiLinearBtn->UseVisualStyleBackColor = true;
			// 
			// ProjectType
			// 
			this->ProjectType->Controls->Add(this->MorphPanel);
			this->ProjectType->Controls->Add(this->NormalizationPanel);
			this->ProjectType->Controls->Add(this->MorphingSelect);
			this->ProjectType->Controls->Add(this->NormalizationSelect);
			this->ProjectType->Controls->Add(this->WarpingSelect);
			this->ProjectType->Location = System::Drawing::Point(9, 18);
			this->ProjectType->Name = L"ProjectType";
			this->ProjectType->Size = System::Drawing::Size(171, 368);
			this->ProjectType->TabIndex = 18;
			this->ProjectType->TabStop = false;
			this->ProjectType->Text = L"Project Type";
			// 
			// MorphPanel
			// 
			this->MorphPanel->Controls->Add(this->LabelLatticeStep);
			this->MorphPanel->Controls->Add(this->Latticenumeric);
			this->MorphPanel->Controls->Add(this->Franenumeric);
			this->MorphPanel->Controls->Add(this->AnimationCk);
			this->MorphPanel->Controls->Add(this->LabelFrame);
			this->MorphPanel->Enabled = false;
			this->MorphPanel->Location = System::Drawing::Point(6, 295);
			this->MorphPanel->Name = L"MorphPanel";
			this->MorphPanel->Size = System::Drawing::Size(160, 67);
			this->MorphPanel->TabIndex = 23;
			// 
			// LabelLatticeStep
			// 
			this->LabelLatticeStep->AutoSize = true;
			this->LabelLatticeStep->Location = System::Drawing::Point(19, 5);
			this->LabelLatticeStep->Name = L"LabelLatticeStep";
			this->LabelLatticeStep->Size = System::Drawing::Size(40, 12);
			this->LabelLatticeStep->TabIndex = 6;
			this->LabelLatticeStep->Text = L"Lattice";
			// 
			// Latticenumeric
			// 
			this->Latticenumeric->Location = System::Drawing::Point(21, 20);
			this->Latticenumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->Latticenumeric->Name = L"Latticenumeric";
			this->Latticenumeric->Size = System::Drawing::Size(50, 19);
			this->Latticenumeric->TabIndex = 11;
			this->Latticenumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			// 
			// Franenumeric
			// 
			this->Franenumeric->Location = System::Drawing::Point(81, 20);
			this->Franenumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->Franenumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->Franenumeric->Name = L"Franenumeric";
			this->Franenumeric->Size = System::Drawing::Size(50, 19);
			this->Franenumeric->TabIndex = 13;
			this->Franenumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// AnimationCk
			// 
			this->AnimationCk->AutoSize = true;
			this->AnimationCk->Location = System::Drawing::Point(21, 45);
			this->AnimationCk->Name = L"AnimationCk";
			this->AnimationCk->Size = System::Drawing::Size(75, 16);
			this->AnimationCk->TabIndex = 2;
			this->AnimationCk->Text = L"Animation";
			this->AnimationCk->UseVisualStyleBackColor = true;
			// 
			// LabelFrame
			// 
			this->LabelFrame->AutoSize = true;
			this->LabelFrame->Location = System::Drawing::Point(79, 5);
			this->LabelFrame->Name = L"LabelFrame";
			this->LabelFrame->Size = System::Drawing::Size(37, 12);
			this->LabelFrame->TabIndex = 12;
			this->LabelFrame->Text = L"Frame";
			// 
			// NormalizationPanel
			// 
			this->NormalizationPanel->Controls->Add(this->LabelPoint);
			this->NormalizationPanel->Controls->Add(this->BackgroundReadImage);
			this->NormalizationPanel->Controls->Add(this->LabelPartition);
			this->NormalizationPanel->Controls->Add(this->BackgroundReadColor);
			this->NormalizationPanel->Controls->Add(this->PointNumeric);
			this->NormalizationPanel->Controls->Add(this->NoseParts);
			this->NormalizationPanel->Controls->Add(this->PartitionNumeric);
			this->NormalizationPanel->Controls->Add(this->BackgroundLabel);
			this->NormalizationPanel->Controls->Add(this->EyeParts);
			this->NormalizationPanel->Controls->Add(this->BackgroundImage);
			this->NormalizationPanel->Controls->Add(this->MouthParts);
			this->NormalizationPanel->Controls->Add(this->EyebrowParts);
			this->NormalizationPanel->Location = System::Drawing::Point(6, 34);
			this->NormalizationPanel->Name = L"NormalizationPanel";
			this->NormalizationPanel->Size = System::Drawing::Size(160, 214);
			this->NormalizationPanel->TabIndex = 22;
			// 
			// LabelPoint
			// 
			this->LabelPoint->AutoSize = true;
			this->LabelPoint->Location = System::Drawing::Point(19, 4);
			this->LabelPoint->Name = L"LabelPoint";
			this->LabelPoint->Size = System::Drawing::Size(31, 12);
			this->LabelPoint->TabIndex = 0;
			this->LabelPoint->Text = L"Point";
			// 
			// BackgroundReadImage
			// 
			this->BackgroundReadImage->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->BackgroundReadImage->Location = System::Drawing::Point(112, 86);
			this->BackgroundReadImage->Name = L"BackgroundReadImage";
			this->BackgroundReadImage->Size = System::Drawing::Size(45, 17);
			this->BackgroundReadImage->TabIndex = 21;
			this->BackgroundReadImage->Text = L"Image";
			this->BackgroundReadImage->UseVisualStyleBackColor = true;
			this->BackgroundReadImage->Click += gcnew System::EventHandler(this, &Main::BackgroundReadImage_Click);
			// 
			// LabelPartition
			// 
			this->LabelPartition->AutoSize = true;
			this->LabelPartition->Location = System::Drawing::Point(79, 4);
			this->LabelPartition->Name = L"LabelPartition";
			this->LabelPartition->Size = System::Drawing::Size(48, 12);
			this->LabelPartition->TabIndex = 3;
			this->LabelPartition->Text = L"Partition";
			// 
			// BackgroundReadColor
			// 
			this->BackgroundReadColor->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->BackgroundReadColor->Location = System::Drawing::Point(81, 86);
			this->BackgroundReadColor->Name = L"BackgroundReadColor";
			this->BackgroundReadColor->Size = System::Drawing::Size(25, 17);
			this->BackgroundReadColor->TabIndex = 20;
			this->BackgroundReadColor->Text = L"Color";
			this->BackgroundReadColor->UseVisualStyleBackColor = true;
			this->BackgroundReadColor->Click += gcnew System::EventHandler(this, &Main::BackgroundReadBtn_Click);
			// 
			// PointNumeric
			// 
			this->PointNumeric->Location = System::Drawing::Point(21, 19);
			this->PointNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {150, 0, 0, 0});
			this->PointNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->PointNumeric->Name = L"PointNumeric";
			this->PointNumeric->Size = System::Drawing::Size(50, 19);
			this->PointNumeric->TabIndex = 9;
			this->PointNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {103, 0, 0, 0});
			this->PointNumeric->ValueChanged += gcnew System::EventHandler(this, &Main::PointNumeric_ValueChanged);
			// 
			// NoseParts
			// 
			this->NoseParts->AutoSize = true;
			this->NoseParts->Checked = true;
			this->NoseParts->CheckState = System::Windows::Forms::CheckState::Checked;
			this->NoseParts->Location = System::Drawing::Point(21, 64);
			this->NoseParts->Name = L"NoseParts";
			this->NoseParts->Size = System::Drawing::Size(50, 16);
			this->NoseParts->TabIndex = 19;
			this->NoseParts->Text = L"Nose";
			this->NoseParts->UseVisualStyleBackColor = true;
			this->NoseParts->CheckedChanged += gcnew System::EventHandler(this, &Main::NoseParts_CheckedChanged);
			// 
			// PartitionNumeric
			// 
			this->PartitionNumeric->Location = System::Drawing::Point(81, 19);
			this->PartitionNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {200, 0, 0, 0});
			this->PartitionNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->PartitionNumeric->Name = L"PartitionNumeric";
			this->PartitionNumeric->Size = System::Drawing::Size(50, 19);
			this->PartitionNumeric->TabIndex = 10;
			this->PartitionNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {96, 0, 0, 0});
			// 
			// BackgroundLabel
			// 
			this->BackgroundLabel->AutoSize = true;
			this->BackgroundLabel->Location = System::Drawing::Point(10, 88);
			this->BackgroundLabel->Name = L"BackgroundLabel";
			this->BackgroundLabel->Size = System::Drawing::Size(65, 12);
			this->BackgroundLabel->TabIndex = 18;
			this->BackgroundLabel->Text = L"Background";
			// 
			// EyeParts
			// 
			this->EyeParts->AutoSize = true;
			this->EyeParts->Checked = true;
			this->EyeParts->CheckState = System::Windows::Forms::CheckState::Checked;
			this->EyeParts->Location = System::Drawing::Point(21, 44);
			this->EyeParts->Name = L"EyeParts";
			this->EyeParts->Size = System::Drawing::Size(43, 16);
			this->EyeParts->TabIndex = 14;
			this->EyeParts->Text = L"Eye";
			this->EyeParts->UseVisualStyleBackColor = true;
			this->EyeParts->CheckedChanged += gcnew System::EventHandler(this, &Main::EyeParts_CheckedChanged);
			// 
			// BackgroundImage
			// 
			this->BackgroundImage->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage->Location = System::Drawing::Point(3, 107);
			this->BackgroundImage->Name = L"BackgroundImage";
			this->BackgroundImage->Size = System::Drawing::Size(154, 95);
			this->BackgroundImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->BackgroundImage->TabIndex = 17;
			this->BackgroundImage->TabStop = false;
			// 
			// MouthParts
			// 
			this->MouthParts->AutoSize = true;
			this->MouthParts->Checked = true;
			this->MouthParts->CheckState = System::Windows::Forms::CheckState::Checked;
			this->MouthParts->Location = System::Drawing::Point(81, 64);
			this->MouthParts->Name = L"MouthParts";
			this->MouthParts->Size = System::Drawing::Size(55, 16);
			this->MouthParts->TabIndex = 15;
			this->MouthParts->Text = L"Mouth";
			this->MouthParts->UseVisualStyleBackColor = true;
			this->MouthParts->CheckedChanged += gcnew System::EventHandler(this, &Main::MouthParts_CheckedChanged);
			// 
			// EyebrowParts
			// 
			this->EyebrowParts->AutoSize = true;
			this->EyebrowParts->Checked = true;
			this->EyebrowParts->CheckState = System::Windows::Forms::CheckState::Checked;
			this->EyebrowParts->Location = System::Drawing::Point(81, 44);
			this->EyebrowParts->Name = L"EyebrowParts";
			this->EyebrowParts->Size = System::Drawing::Size(67, 16);
			this->EyebrowParts->TabIndex = 16;
			this->EyebrowParts->Text = L"Eyebrow";
			this->EyebrowParts->UseVisualStyleBackColor = true;
			this->EyebrowParts->CheckedChanged += gcnew System::EventHandler(this, &Main::EyebrowParts_CheckedChanged);
			// 
			// MorphingSelect
			// 
			this->MorphingSelect->AutoSize = true;
			this->MorphingSelect->Location = System::Drawing::Point(6, 273);
			this->MorphingSelect->Name = L"MorphingSelect";
			this->MorphingSelect->Size = System::Drawing::Size(69, 16);
			this->MorphingSelect->TabIndex = 3;
			this->MorphingSelect->Text = L"Morphing";
			this->MorphingSelect->UseVisualStyleBackColor = true;
			this->MorphingSelect->CheckedChanged += gcnew System::EventHandler(this, &Main::Morphing_CheckedChanged);
			// 
			// NormalizationSelect
			// 
			this->NormalizationSelect->AutoSize = true;
			this->NormalizationSelect->Checked = true;
			this->NormalizationSelect->Location = System::Drawing::Point(6, 18);
			this->NormalizationSelect->Name = L"NormalizationSelect";
			this->NormalizationSelect->Size = System::Drawing::Size(127, 16);
			this->NormalizationSelect->TabIndex = 0;
			this->NormalizationSelect->TabStop = true;
			this->NormalizationSelect->Text = L"Facial Normalization";
			this->NormalizationSelect->UseVisualStyleBackColor = true;
			this->NormalizationSelect->CheckedChanged += gcnew System::EventHandler(this, &Main::Normalization_CheckedChanged);
			// 
			// WarpingSelect
			// 
			this->WarpingSelect->AutoSize = true;
			this->WarpingSelect->Location = System::Drawing::Point(6, 254);
			this->WarpingSelect->Name = L"WarpingSelect";
			this->WarpingSelect->Size = System::Drawing::Size(63, 16);
			this->WarpingSelect->TabIndex = 1;
			this->WarpingSelect->Text = L"Warping";
			this->WarpingSelect->UseVisualStyleBackColor = true;
			this->WarpingSelect->CheckedChanged += gcnew System::EventHandler(this, &Main::Warping_CheckedChanged);
			// 
			// RunBtn
			// 
			this->RunBtn->Enabled = false;
			this->RunBtn->Location = System::Drawing::Point(101, 458);
			this->RunBtn->Name = L"RunBtn";
			this->RunBtn->Size = System::Drawing::Size(74, 29);
			this->RunBtn->TabIndex = 4;
			this->RunBtn->Text = L"Run";
			this->RunBtn->UseVisualStyleBackColor = true;
			this->RunBtn->Click += gcnew System::EventHandler(this, &Main::RunBtn_Click);
			// 
			// InputImage1
			// 
			this->InputImage1->BackColor = System::Drawing::Color::Black;
			this->InputImage1->Enabled = false;
			this->InputImage1->Location = System::Drawing::Point(0, 0);
			this->InputImage1->Margin = System::Windows::Forms::Padding(0);
			this->InputImage1->Name = L"InputImage1";
			this->InputImage1->Size = System::Drawing::Size(300, 300);
			this->InputImage1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InputImage1->TabIndex = 4;
			this->InputImage1->TabStop = false;
			this->InputImage1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::InputImage1_MouseDown);
			this->InputImage1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::InputImage1_Paint);
			// 
			// InputMesh
			// 
			this->InputMesh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InputMesh->Enabled = false;
			this->InputMesh->Location = System::Drawing::Point(318, 7);
			this->InputMesh->Name = L"InputMesh";
			this->InputMesh->Size = System::Drawing::Size(20, 20);
			this->InputMesh->TabIndex = 12;
			this->InputMesh->Text = L"Mesh";
			this->InputMesh->UseVisualStyleBackColor = true;
			this->InputMesh->Click += gcnew System::EventHandler(this, &Main::InputMesh_Click);
			// 
			// InputNumberDisplay
			// 
			this->InputNumberDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InputNumberDisplay->Enabled = false;
			this->InputNumberDisplay->Location = System::Drawing::Point(292, 7);
			this->InputNumberDisplay->Name = L"InputNumberDisplay";
			this->InputNumberDisplay->Size = System::Drawing::Size(20, 20);
			this->InputNumberDisplay->TabIndex = 11;
			this->InputNumberDisplay->Text = L"Number";
			this->InputNumberDisplay->UseVisualStyleBackColor = true;
			this->InputNumberDisplay->Click += gcnew System::EventHandler(this, &Main::InputNumberDisplay_Click);
			// 
			// InputCoordinateWrite
			// 
			this->InputCoordinateWrite->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InputCoordinateWrite->Enabled = false;
			this->InputCoordinateWrite->Location = System::Drawing::Point(344, 4);
			this->InputCoordinateWrite->Name = L"InputCoordinateWrite";
			this->InputCoordinateWrite->Size = System::Drawing::Size(20, 20);
			this->InputCoordinateWrite->TabIndex = 10;
			this->InputCoordinateWrite->Text = L"WriteCoordinate";
			this->InputCoordinateWrite->UseVisualStyleBackColor = true;
			this->InputCoordinateWrite->Click += gcnew System::EventHandler(this, &Main::InputCoordinateWrite_Click);
			// 
			// InputCoordinateRead
			// 
			this->InputCoordinateRead->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InputCoordinateRead->Enabled = false;
			this->InputCoordinateRead->Location = System::Drawing::Point(230, 4);
			this->InputCoordinateRead->Name = L"InputCoordinateRead";
			this->InputCoordinateRead->Size = System::Drawing::Size(20, 20);
			this->InputCoordinateRead->TabIndex = 9;
			this->InputCoordinateRead->Text = L"ReadCoordinate";
			this->InputCoordinateRead->UseVisualStyleBackColor = true;
			this->InputCoordinateRead->Click += gcnew System::EventHandler(this, &Main::InputCoordinateRead_Click);
			// 
			// InputInit
			// 
			this->InputInit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InputInit->Enabled = false;
			this->InputInit->Location = System::Drawing::Point(204, 4);
			this->InputInit->Name = L"InputInit";
			this->InputInit->Size = System::Drawing::Size(20, 20);
			this->InputInit->TabIndex = 8;
			this->InputInit->Text = L"Init";
			this->InputInit->UseVisualStyleBackColor = true;
			this->InputInit->Click += gcnew System::EventHandler(this, &Main::InputInit_Click);
			// 
			// InPointSize
			// 
			this->InPointSize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InPointSize->Location = System::Drawing::Point(148, 6);
			this->InPointSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {25, 0, 0, 0});
			this->InPointSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->InPointSize->Name = L"InPointSize";
			this->InPointSize->Size = System::Drawing::Size(50, 19);
			this->InPointSize->TabIndex = 7;
			this->InPointSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->InPointSize->ValueChanged += gcnew System::EventHandler(this, &Main::InPointSize_ValueChanged);
			// 
			// AboutInPoint
			// 
			this->AboutInPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->AboutInPoint->AutoSize = true;
			this->AboutInPoint->Location = System::Drawing::Point(86, 8);
			this->AboutInPoint->Name = L"AboutInPoint";
			this->AboutInPoint->Size = System::Drawing::Size(56, 12);
			this->AboutInPoint->TabIndex = 6;
			this->AboutInPoint->Text = L"Point Size";
			// 
			// ReadInputImage1
			// 
			this->ReadInputImage1->Location = System::Drawing::Point(70, 7);
			this->ReadInputImage1->Name = L"ReadInputImage1";
			this->ReadInputImage1->Size = System::Drawing::Size(20, 20);
			this->ReadInputImage1->TabIndex = 5;
			this->ReadInputImage1->Text = L"Read";
			this->ReadInputImage1->UseVisualStyleBackColor = true;
			this->ReadInputImage1->Click += gcnew System::EventHandler(this, &Main::ReadInputImage1_Click);
			// 
			// InputZoom
			// 
			this->InputZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InputZoom->Enabled = false;
			this->InputZoom->Location = System::Drawing::Point(344, 7);
			this->InputZoom->Name = L"InputZoom";
			this->InputZoom->Size = System::Drawing::Size(20, 20);
			this->InputZoom->TabIndex = 1;
			this->InputZoom->Text = L"Zoom";
			this->InputZoom->UseVisualStyleBackColor = true;
			this->InputZoom->Click += gcnew System::EventHandler(this, &Main::InputZoom_Click);
			// 
			// OutputMesh
			// 
			this->OutputMesh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutputMesh->Enabled = false;
			this->OutputMesh->Location = System::Drawing::Point(318, 7);
			this->OutputMesh->Name = L"OutputMesh";
			this->OutputMesh->Size = System::Drawing::Size(20, 20);
			this->OutputMesh->TabIndex = 9;
			this->OutputMesh->Text = L"Mesh";
			this->OutputMesh->UseVisualStyleBackColor = true;
			this->OutputMesh->Click += gcnew System::EventHandler(this, &Main::OutputMesh_Click);
			// 
			// OutputNumberDisplay
			// 
			this->OutputNumberDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutputNumberDisplay->Enabled = false;
			this->OutputNumberDisplay->Location = System::Drawing::Point(292, 7);
			this->OutputNumberDisplay->Name = L"OutputNumberDisplay";
			this->OutputNumberDisplay->Size = System::Drawing::Size(20, 20);
			this->OutputNumberDisplay->TabIndex = 8;
			this->OutputNumberDisplay->Text = L"Number";
			this->OutputNumberDisplay->UseVisualStyleBackColor = true;
			this->OutputNumberDisplay->Click += gcnew System::EventHandler(this, &Main::OutputNumberDisplay_Click);
			// 
			// OutputCoordinateWrite
			// 
			this->OutputCoordinateWrite->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutputCoordinateWrite->Enabled = false;
			this->OutputCoordinateWrite->Location = System::Drawing::Point(344, 4);
			this->OutputCoordinateWrite->Name = L"OutputCoordinateWrite";
			this->OutputCoordinateWrite->Size = System::Drawing::Size(20, 20);
			this->OutputCoordinateWrite->TabIndex = 7;
			this->OutputCoordinateWrite->Text = L"WriteCoordinate";
			this->OutputCoordinateWrite->UseVisualStyleBackColor = true;
			this->OutputCoordinateWrite->Click += gcnew System::EventHandler(this, &Main::OutputCoordinateWrite_Click);
			// 
			// OutputCoordinateRead
			// 
			this->OutputCoordinateRead->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutputCoordinateRead->Enabled = false;
			this->OutputCoordinateRead->Location = System::Drawing::Point(228, 4);
			this->OutputCoordinateRead->Name = L"OutputCoordinateRead";
			this->OutputCoordinateRead->Size = System::Drawing::Size(20, 20);
			this->OutputCoordinateRead->TabIndex = 6;
			this->OutputCoordinateRead->Text = L"ReadCoodinate";
			this->OutputCoordinateRead->UseVisualStyleBackColor = true;
			this->OutputCoordinateRead->Click += gcnew System::EventHandler(this, &Main::OutputCoordinateRead_Click);
			// 
			// OutputInit
			// 
			this->OutputInit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutputInit->Enabled = false;
			this->OutputInit->Location = System::Drawing::Point(202, 4);
			this->OutputInit->Name = L"OutputInit";
			this->OutputInit->Size = System::Drawing::Size(20, 20);
			this->OutputInit->TabIndex = 5;
			this->OutputInit->Text = L"Init";
			this->OutputInit->UseVisualStyleBackColor = true;
			this->OutputInit->Click += gcnew System::EventHandler(this, &Main::OutputInit_Click);
			// 
			// OutPointSize
			// 
			this->OutPointSize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutPointSize->Location = System::Drawing::Point(146, 6);
			this->OutPointSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {25, 0, 0, 0});
			this->OutPointSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->OutPointSize->Name = L"OutPointSize";
			this->OutPointSize->Size = System::Drawing::Size(50, 19);
			this->OutPointSize->TabIndex = 4;
			this->OutPointSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->OutPointSize->ValueChanged += gcnew System::EventHandler(this, &Main::OutPointSize_ValueChanged);
			// 
			// AboutOutPoint
			// 
			this->AboutOutPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->AboutOutPoint->AutoSize = true;
			this->AboutOutPoint->Location = System::Drawing::Point(82, 8);
			this->AboutOutPoint->Name = L"AboutOutPoint";
			this->AboutOutPoint->Size = System::Drawing::Size(56, 12);
			this->AboutOutPoint->TabIndex = 3;
			this->AboutOutPoint->Text = L"Point Size";
			// 
			// ReadInputImage2
			// 
			this->ReadInputImage2->Enabled = false;
			this->ReadInputImage2->Location = System::Drawing::Point(67, 7);
			this->ReadInputImage2->Name = L"ReadInputImage2";
			this->ReadInputImage2->Size = System::Drawing::Size(20, 20);
			this->ReadInputImage2->TabIndex = 2;
			this->ReadInputImage2->Text = L"Read";
			this->ReadInputImage2->UseVisualStyleBackColor = true;
			this->ReadInputImage2->Click += gcnew System::EventHandler(this, &Main::ReadInputImage2_Click);
			// 
			// OutputZoom
			// 
			this->OutputZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OutputZoom->Enabled = false;
			this->OutputZoom->Location = System::Drawing::Point(344, 7);
			this->OutputZoom->Name = L"OutputZoom";
			this->OutputZoom->Size = System::Drawing::Size(20, 20);
			this->OutputZoom->TabIndex = 1;
			this->OutputZoom->Text = L"Zoom";
			this->OutputZoom->UseVisualStyleBackColor = true;
			// 
			// InputImage2
			// 
			this->InputImage2->BackColor = System::Drawing::Color::Black;
			this->InputImage2->Enabled = false;
			this->InputImage2->Location = System::Drawing::Point(0, 0);
			this->InputImage2->Margin = System::Windows::Forms::Padding(0);
			this->InputImage2->Name = L"InputImage2";
			this->InputImage2->Size = System::Drawing::Size(300, 300);
			this->InputImage2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->InputImage2->TabIndex = 0;
			this->InputImage2->TabStop = false;
			this->InputImage2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::InputImage2_MouseDown);
			this->InputImage2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::InputImage2_Paint);
			// 
			// ImageTrackBar
			// 
			this->ImageTrackBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ImageTrackBar->Enabled = false;
			this->ImageTrackBar->Location = System::Drawing::Point(81, 3);
			this->ImageTrackBar->Margin = System::Windows::Forms::Padding(0);
			this->ImageTrackBar->Maximum = 1;
			this->ImageTrackBar->Name = L"ImageTrackBar";
			this->ImageTrackBar->Size = System::Drawing::Size(71, 45);
			this->ImageTrackBar->TabIndex = 7;
			this->ImageTrackBar->Scroll += gcnew System::EventHandler(this, &Main::ImageTrackBar_Scroll);
			// 
			// InterlevelImage
			// 
			this->InterlevelImage->BackColor = System::Drawing::Color::Black;
			this->InterlevelImage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InterlevelImage->Location = System::Drawing::Point(0, 0);
			this->InterlevelImage->Margin = System::Windows::Forms::Padding(0);
			this->InterlevelImage->Name = L"InterlevelImage";
			this->InterlevelImage->Size = System::Drawing::Size(221, 208);
			this->InterlevelImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->InterlevelImage->TabIndex = 8;
			this->InterlevelImage->TabStop = false;
			// 
			// FirstImage
			// 
			this->FirstImage->BackColor = System::Drawing::Color::Black;
			this->FirstImage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FirstImage->Location = System::Drawing::Point(0, 0);
			this->FirstImage->Margin = System::Windows::Forms::Padding(0);
			this->FirstImage->Name = L"FirstImage";
			this->FirstImage->Size = System::Drawing::Size(221, 208);
			this->FirstImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->FirstImage->TabIndex = 9;
			this->FirstImage->TabStop = false;
			// 
			// SecondImage
			// 
			this->SecondImage->BackColor = System::Drawing::Color::Black;
			this->SecondImage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SecondImage->Location = System::Drawing::Point(0, 0);
			this->SecondImage->Margin = System::Windows::Forms::Padding(0);
			this->SecondImage->Name = L"SecondImage";
			this->SecondImage->Size = System::Drawing::Size(221, 208);
			this->SecondImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->SecondImage->TabIndex = 10;
			this->SecondImage->TabStop = false;
			// 
			// StartBtn
			// 
			this->StartBtn->Enabled = false;
			this->StartBtn->Location = System::Drawing::Point(10, 15);
			this->StartBtn->Name = L"StartBtn";
			this->StartBtn->Size = System::Drawing::Size(25, 25);
			this->StartBtn->TabIndex = 11;
			this->StartBtn->Text = L">";
			this->StartBtn->UseVisualStyleBackColor = true;
			this->StartBtn->Click += gcnew System::EventHandler(this, &Main::StartBtn_Click);
			// 
			// StopBtn
			// 
			this->StopBtn->Enabled = false;
			this->StopBtn->Location = System::Drawing::Point(43, 15);
			this->StopBtn->Name = L"StopBtn";
			this->StopBtn->Size = System::Drawing::Size(25, 25);
			this->StopBtn->TabIndex = 12;
			this->StopBtn->Text = L"ll";
			this->StopBtn->UseVisualStyleBackColor = true;
			this->StopBtn->Click += gcnew System::EventHandler(this, &Main::StopBtn_Click);
			// 
			// InterlevelZoom
			// 
			this->InterlevelZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->InterlevelZoom->Enabled = false;
			this->InterlevelZoom->Location = System::Drawing::Point(201, 20);
			this->InterlevelZoom->Name = L"InterlevelZoom";
			this->InterlevelZoom->Size = System::Drawing::Size(20, 20);
			this->InterlevelZoom->TabIndex = 13;
			this->InterlevelZoom->Text = L"Zoom";
			this->InterlevelZoom->UseVisualStyleBackColor = true;
			// 
			// OriginZoom
			// 
			this->OriginZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->OriginZoom->Enabled = false;
			this->OriginZoom->Location = System::Drawing::Point(201, 20);
			this->OriginZoom->Name = L"OriginZoom";
			this->OriginZoom->Size = System::Drawing::Size(20, 20);
			this->OriginZoom->TabIndex = 14;
			this->OriginZoom->Text = L"Zoom";
			this->OriginZoom->UseVisualStyleBackColor = true;
			// 
			// ProcessedZoom
			// 
			this->ProcessedZoom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ProcessedZoom->Enabled = false;
			this->ProcessedZoom->Location = System::Drawing::Point(199, 20);
			this->ProcessedZoom->Name = L"ProcessedZoom";
			this->ProcessedZoom->Size = System::Drawing::Size(20, 20);
			this->ProcessedZoom->TabIndex = 15;
			this->ProcessedZoom->Text = L"Zoom";
			this->ProcessedZoom->UseVisualStyleBackColor = true;
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->FileName = L"OpenFileDialog";
			// 
			// ResultLabel
			// 
			this->ResultLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->ResultLabel->Location = System::Drawing::Point(50, 25);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(101, 15);
			this->ResultLabel->TabIndex = 17;
			this->ResultLabel->Text = L"Result Image";
			// 
			// OriginalLabel
			// 
			this->OriginalLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->OriginalLabel->AutoSize = true;
			this->OriginalLabel->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->OriginalLabel->Location = System::Drawing::Point(56, 25);
			this->OriginalLabel->Name = L"OriginalLabel";
			this->OriginalLabel->Size = System::Drawing::Size(110, 15);
			this->OriginalLabel->TabIndex = 16;
			this->OriginalLabel->Text = L"Original Image";
			// 
			// AnimateTimer
			// 
			this->AnimateTimer->Tick += gcnew System::EventHandler(this, &Main::AnimateTimer_Tick);
			// 
			// SaveAnimate
			// 
			this->SaveAnimate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SaveAnimate->Enabled = false;
			this->SaveAnimate->Location = System::Drawing::Point(175, 20);
			this->SaveAnimate->Name = L"SaveAnimate";
			this->SaveAnimate->Size = System::Drawing::Size(20, 20);
			this->SaveAnimate->TabIndex = 19;
			this->SaveAnimate->Text = L"Save";
			this->SaveAnimate->UseVisualStyleBackColor = true;
			this->SaveAnimate->Click += gcnew System::EventHandler(this, &Main::SaveAnimate_Click);
			// 
			// SaveImageBtn
			// 
			this->SaveImageBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SaveImageBtn->Enabled = false;
			this->SaveImageBtn->Location = System::Drawing::Point(173, 20);
			this->SaveImageBtn->Name = L"SaveImageBtn";
			this->SaveImageBtn->Size = System::Drawing::Size(20, 20);
			this->SaveImageBtn->TabIndex = 18;
			this->SaveImageBtn->Text = L"Save";
			this->SaveImageBtn->UseVisualStyleBackColor = true;
			this->SaveImageBtn->Click += gcnew System::EventHandler(this, &Main::SaveImageBtn_Click);
			// 
			// TableLayoutPanel1
			// 
			this->TableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableLayoutPanel1->ColumnCount = 1;
			this->TableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->TableLayoutPanel1->Controls->Add(this->TableLayoutPanel2, 0, 4);
			this->TableLayoutPanel1->Controls->Add(this->TableLayoutPanel3, 0, 1);
			this->TableLayoutPanel1->Controls->Add(this->TableLayoutPanel4, 0, 0);
			this->TableLayoutPanel1->Controls->Add(this->TableLayoutPanel5, 0, 3);
			this->TableLayoutPanel1->Controls->Add(this->TableLayoutPanel6, 0, 2);
			this->TableLayoutPanel1->Location = System::Drawing::Point(210, 34);
			this->TableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->TableLayoutPanel1->Name = L"TableLayoutPanel1";
			this->TableLayoutPanel1->RowCount = 5;
			this->TableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->TableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			this->TableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->TableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->TableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40)));
			this->TableLayoutPanel1->Size = System::Drawing::Size(794, 668);
			this->TableLayoutPanel1->TabIndex = 0;
			// 
			// TableLayoutPanel2
			// 
			this->TableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableLayoutPanel2->ColumnCount = 7;
			this->TableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33332F)));
			this->TableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				10)));
			this->TableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33334F)));
			this->TableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				10)));
			this->TableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33334F)));
			this->TableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				71)));
			this->TableLayoutPanel2->Controls->Add(this->PanelOriginalImage, 1, 0);
			this->TableLayoutPanel2->Controls->Add(this->PanelAnimateImage, 3, 0);
			this->TableLayoutPanel2->Controls->Add(this->PanelResultImage, 5, 0);
			this->TableLayoutPanel2->Location = System::Drawing::Point(0, 444);
			this->TableLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
			this->TableLayoutPanel2->Name = L"TableLayoutPanel2";
			this->TableLayoutPanel2->RowCount = 2;
			this->TableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->TableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 10)));
			this->TableLayoutPanel2->Size = System::Drawing::Size(794, 224);
			this->TableLayoutPanel2->TabIndex = 0;
			// 
			// PanelOriginalImage
			// 
			this->PanelOriginalImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->PanelOriginalImage->Controls->Add(this->FirstImage);
			this->PanelOriginalImage->Location = System::Drawing::Point(23, 3);
			this->PanelOriginalImage->Name = L"PanelOriginalImage";
			this->PanelOriginalImage->Size = System::Drawing::Size(221, 208);
			this->PanelOriginalImage->TabIndex = 0;
			// 
			// PanelAnimateImage
			// 
			this->PanelAnimateImage->Controls->Add(this->InterlevelImage);
			this->PanelAnimateImage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelAnimateImage->Location = System::Drawing::Point(260, 3);
			this->PanelAnimateImage->Name = L"PanelAnimateImage";
			this->PanelAnimateImage->Size = System::Drawing::Size(221, 208);
			this->PanelAnimateImage->TabIndex = 1;
			// 
			// PanelResultImage
			// 
			this->PanelResultImage->Controls->Add(this->SecondImage);
			this->PanelResultImage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelResultImage->Location = System::Drawing::Point(497, 3);
			this->PanelResultImage->Name = L"PanelResultImage";
			this->PanelResultImage->Size = System::Drawing::Size(221, 208);
			this->PanelResultImage->TabIndex = 2;
			// 
			// TableLayoutPanel3
			// 
			this->TableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableLayoutPanel3->ColumnCount = 5;
			this->TableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->TableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->TableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel3->Controls->Add(this->PanelInputImage1, 1, 0);
			this->TableLayoutPanel3->Controls->Add(this->PanelInputImage2, 3, 0);
			this->TableLayoutPanel3->Location = System::Drawing::Point(0, 30);
			this->TableLayoutPanel3->Margin = System::Windows::Forms::Padding(0);
			this->TableLayoutPanel3->Name = L"TableLayoutPanel3";
			this->TableLayoutPanel3->RowCount = 1;
			this->TableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->TableLayoutPanel3->Size = System::Drawing::Size(794, 334);
			this->TableLayoutPanel3->TabIndex = 1;
			// 
			// PanelInputImage1
			// 
			this->PanelInputImage1->AutoScroll = true;
			this->PanelInputImage1->BackColor = System::Drawing::Color::Black;
			this->PanelInputImage1->Controls->Add(this->InputImage1);
			this->PanelInputImage1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelInputImage1->Location = System::Drawing::Point(23, 3);
			this->PanelInputImage1->Name = L"PanelInputImage1";
			this->PanelInputImage1->Size = System::Drawing::Size(361, 328);
			this->PanelInputImage1->TabIndex = 0;
			// 
			// PanelInputImage2
			// 
			this->PanelInputImage2->AutoScroll = true;
			this->PanelInputImage2->BackColor = System::Drawing::Color::Black;
			this->PanelInputImage2->Controls->Add(this->InputImage2);
			this->PanelInputImage2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelInputImage2->Location = System::Drawing::Point(410, 3);
			this->PanelInputImage2->Name = L"PanelInputImage2";
			this->PanelInputImage2->Size = System::Drawing::Size(361, 328);
			this->PanelInputImage2->TabIndex = 1;
			// 
			// TableLayoutPanel4
			// 
			this->TableLayoutPanel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableLayoutPanel4->ColumnCount = 5;
			this->TableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->TableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->TableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel4->Controls->Add(this->PanelInputBtn, 1, 0);
			this->TableLayoutPanel4->Controls->Add(this->PanelOutputBtn, 3, 0);
			this->TableLayoutPanel4->Location = System::Drawing::Point(0, 0);
			this->TableLayoutPanel4->Margin = System::Windows::Forms::Padding(0);
			this->TableLayoutPanel4->Name = L"TableLayoutPanel4";
			this->TableLayoutPanel4->RowCount = 1;
			this->TableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->TableLayoutPanel4->Size = System::Drawing::Size(794, 30);
			this->TableLayoutPanel4->TabIndex = 2;
			// 
			// PanelInputBtn
			// 
			this->PanelInputBtn->Controls->Add(this->Image1NamePanel);
			this->PanelInputBtn->Controls->Add(this->Image1Label);
			this->PanelInputBtn->Controls->Add(this->ReadInputImage1);
			this->PanelInputBtn->Controls->Add(this->InputMesh);
			this->PanelInputBtn->Controls->Add(this->InputNumberDisplay);
			this->PanelInputBtn->Controls->Add(this->InputZoom);
			this->PanelInputBtn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelInputBtn->Location = System::Drawing::Point(20, 0);
			this->PanelInputBtn->Margin = System::Windows::Forms::Padding(0);
			this->PanelInputBtn->Name = L"PanelInputBtn";
			this->PanelInputBtn->Size = System::Drawing::Size(367, 30);
			this->PanelInputBtn->TabIndex = 0;
			// 
			// Image1NamePanel
			// 
			this->Image1NamePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->Image1NamePanel->Controls->Add(this->Image1Name);
			this->Image1NamePanel->Location = System::Drawing::Point(93, 0);
			this->Image1NamePanel->Margin = System::Windows::Forms::Padding(0);
			this->Image1NamePanel->Name = L"Image1NamePanel";
			this->Image1NamePanel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->Image1NamePanel->Size = System::Drawing::Size(196, 30);
			this->Image1NamePanel->TabIndex = 14;
			// 
			// Image1Name
			// 
			this->Image1Name->AutoSize = true;
			this->Image1Name->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->Image1Name->Location = System::Drawing::Point(3, 11);
			this->Image1Name->Name = L"Image1Name";
			this->Image1Name->Size = System::Drawing::Size(81, 13);
			this->Image1Name->TabIndex = 0;
			this->Image1Name->Text = L"Image1 Name";
			// 
			// Image1Label
			// 
			this->Image1Label->AutoSize = true;
			this->Image1Label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->Image1Label->Location = System::Drawing::Point(3, 7);
			this->Image1Label->Name = L"Image1Label";
			this->Image1Label->Size = System::Drawing::Size(61, 16);
			this->Image1Label->TabIndex = 13;
			this->Image1Label->Text = L"Image1";
			// 
			// PanelOutputBtn
			// 
			this->PanelOutputBtn->Controls->Add(this->Image2NamePanel);
			this->PanelOutputBtn->Controls->Add(this->Image2Label);
			this->PanelOutputBtn->Controls->Add(this->ReadInputImage2);
			this->PanelOutputBtn->Controls->Add(this->OutputMesh);
			this->PanelOutputBtn->Controls->Add(this->OutputNumberDisplay);
			this->PanelOutputBtn->Controls->Add(this->OutputZoom);
			this->PanelOutputBtn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelOutputBtn->Location = System::Drawing::Point(407, 0);
			this->PanelOutputBtn->Margin = System::Windows::Forms::Padding(0);
			this->PanelOutputBtn->Name = L"PanelOutputBtn";
			this->PanelOutputBtn->Size = System::Drawing::Size(367, 30);
			this->PanelOutputBtn->TabIndex = 1;
			// 
			// Image2NamePanel
			// 
			this->Image2NamePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->Image2NamePanel->Controls->Add(this->Image2Name);
			this->Image2NamePanel->Location = System::Drawing::Point(92, 0);
			this->Image2NamePanel->Margin = System::Windows::Forms::Padding(0);
			this->Image2NamePanel->Name = L"Image2NamePanel";
			this->Image2NamePanel->Size = System::Drawing::Size(197, 30);
			this->Image2NamePanel->TabIndex = 11;
			// 
			// Image2Name
			// 
			this->Image2Name->AutoSize = true;
			this->Image2Name->Enabled = false;
			this->Image2Name->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->Image2Name->Location = System::Drawing::Point(3, 11);
			this->Image2Name->Name = L"Image2Name";
			this->Image2Name->Size = System::Drawing::Size(81, 13);
			this->Image2Name->TabIndex = 11;
			this->Image2Name->Text = L"Image2 Name";
			// 
			// Image2Label
			// 
			this->Image2Label->AutoSize = true;
			this->Image2Label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->Image2Label->Location = System::Drawing::Point(3, 7);
			this->Image2Label->Name = L"Image2Label";
			this->Image2Label->Size = System::Drawing::Size(58, 15);
			this->Image2Label->TabIndex = 10;
			this->Image2Label->Text = L"Image2";
			// 
			// TableLayoutPanel5
			// 
			this->TableLayoutPanel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableLayoutPanel5->ColumnCount = 7;
			this->TableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->TableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				10)));
			this->TableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33334F)));
			this->TableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				10)));
			this->TableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->TableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				72)));
			this->TableLayoutPanel5->Controls->Add(this->PanelOriginalBtn, 1, 0);
			this->TableLayoutPanel5->Controls->Add(this->PanelAnimateBtn, 3, 0);
			this->TableLayoutPanel5->Controls->Add(this->PanelResultBtn, 5, 0);
			this->TableLayoutPanel5->Location = System::Drawing::Point(0, 394);
			this->TableLayoutPanel5->Margin = System::Windows::Forms::Padding(0);
			this->TableLayoutPanel5->Name = L"TableLayoutPanel5";
			this->TableLayoutPanel5->RowCount = 1;
			this->TableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->TableLayoutPanel5->Size = System::Drawing::Size(794, 50);
			this->TableLayoutPanel5->TabIndex = 3;
			// 
			// PanelOriginalBtn
			// 
			this->PanelOriginalBtn->Controls->Add(this->OriginZoom);
			this->PanelOriginalBtn->Controls->Add(this->OriginalLabel);
			this->PanelOriginalBtn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelOriginalBtn->Location = System::Drawing::Point(20, 0);
			this->PanelOriginalBtn->Margin = System::Windows::Forms::Padding(0);
			this->PanelOriginalBtn->Name = L"PanelOriginalBtn";
			this->PanelOriginalBtn->Size = System::Drawing::Size(227, 50);
			this->PanelOriginalBtn->TabIndex = 0;
			// 
			// PanelAnimateBtn
			// 
			this->PanelAnimateBtn->Controls->Add(this->SaveAnimate);
			this->PanelAnimateBtn->Controls->Add(this->InterlevelZoom);
			this->PanelAnimateBtn->Controls->Add(this->ImageTrackBar);
			this->PanelAnimateBtn->Controls->Add(this->StartBtn);
			this->PanelAnimateBtn->Controls->Add(this->StopBtn);
			this->PanelAnimateBtn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelAnimateBtn->Location = System::Drawing::Point(257, 0);
			this->PanelAnimateBtn->Margin = System::Windows::Forms::Padding(0);
			this->PanelAnimateBtn->Name = L"PanelAnimateBtn";
			this->PanelAnimateBtn->Size = System::Drawing::Size(227, 50);
			this->PanelAnimateBtn->TabIndex = 1;
			// 
			// PanelResultBtn
			// 
			this->PanelResultBtn->Controls->Add(this->ProcessedZoom);
			this->PanelResultBtn->Controls->Add(this->SaveImageBtn);
			this->PanelResultBtn->Controls->Add(this->ResultLabel);
			this->PanelResultBtn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelResultBtn->Location = System::Drawing::Point(494, 0);
			this->PanelResultBtn->Margin = System::Windows::Forms::Padding(0);
			this->PanelResultBtn->Name = L"PanelResultBtn";
			this->PanelResultBtn->Size = System::Drawing::Size(227, 50);
			this->PanelResultBtn->TabIndex = 2;
			// 
			// TableLayoutPanel6
			// 
			this->TableLayoutPanel6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableLayoutPanel6->ColumnCount = 5;
			this->TableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->TableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->TableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->TableLayoutPanel6->Controls->Add(this->PanelImage1Info, 1, 0);
			this->TableLayoutPanel6->Controls->Add(this->PanelImage2Info, 3, 0);
			this->TableLayoutPanel6->Location = System::Drawing::Point(0, 364);
			this->TableLayoutPanel6->Margin = System::Windows::Forms::Padding(0);
			this->TableLayoutPanel6->Name = L"TableLayoutPanel6";
			this->TableLayoutPanel6->RowCount = 1;
			this->TableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->TableLayoutPanel6->Size = System::Drawing::Size(794, 30);
			this->TableLayoutPanel6->TabIndex = 4;
			// 
			// PanelImage1Info
			// 
			this->PanelImage1Info->Controls->Add(this->Image1SpeedingUp);
			this->PanelImage1Info->Controls->Add(this->InPointSize);
			this->PanelImage1Info->Controls->Add(this->InputCoordinateRead);
			this->PanelImage1Info->Controls->Add(this->InputCoordinateWrite);
			this->PanelImage1Info->Controls->Add(this->InputInit);
			this->PanelImage1Info->Controls->Add(this->AboutInPoint);
			this->PanelImage1Info->Controls->Add(this->DisplayChange1);
			this->PanelImage1Info->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelImage1Info->Location = System::Drawing::Point(20, 0);
			this->PanelImage1Info->Margin = System::Windows::Forms::Padding(0);
			this->PanelImage1Info->Name = L"PanelImage1Info";
			this->PanelImage1Info->Size = System::Drawing::Size(367, 30);
			this->PanelImage1Info->TabIndex = 0;
			// 
			// Image1SpeedingUp
			// 
			this->Image1SpeedingUp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Image1SpeedingUp->AutoSize = true;
			this->Image1SpeedingUp->Checked = true;
			this->Image1SpeedingUp->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Image1SpeedingUp->Location = System::Drawing::Point(308, 7);
			this->Image1SpeedingUp->Name = L"Image1SpeedingUp";
			this->Image1SpeedingUp->Size = System::Drawing::Size(32, 16);
			this->Image1SpeedingUp->TabIndex = 1;
			this->Image1SpeedingUp->Text = L"C";
			this->Image1SpeedingUp->UseVisualStyleBackColor = true;
			// 
			// DisplayChange1
			// 
			this->DisplayChange1->Enabled = false;
			this->DisplayChange1->Location = System::Drawing::Point(3, 4);
			this->DisplayChange1->Name = L"DisplayChange1";
			this->DisplayChange1->Size = System::Drawing::Size(60, 20);
			this->DisplayChange1->TabIndex = 0;
			this->DisplayChange1->Text = L"All";
			this->DisplayChange1->UseVisualStyleBackColor = true;
			this->DisplayChange1->Click += gcnew System::EventHandler(this, &Main::DisplayChange1_Click);
			// 
			// PanelImage2Info
			// 
			this->PanelImage2Info->Controls->Add(this->Image2SpeedingUp);
			this->PanelImage2Info->Controls->Add(this->OutputCoordinateRead);
			this->PanelImage2Info->Controls->Add(this->OutputCoordinateWrite);
			this->PanelImage2Info->Controls->Add(this->OutPointSize);
			this->PanelImage2Info->Controls->Add(this->OutputInit);
			this->PanelImage2Info->Controls->Add(this->DisplayChange2);
			this->PanelImage2Info->Controls->Add(this->AboutOutPoint);
			this->PanelImage2Info->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PanelImage2Info->Location = System::Drawing::Point(407, 0);
			this->PanelImage2Info->Margin = System::Windows::Forms::Padding(0);
			this->PanelImage2Info->Name = L"PanelImage2Info";
			this->PanelImage2Info->Size = System::Drawing::Size(367, 30);
			this->PanelImage2Info->TabIndex = 1;
			// 
			// Image2SpeedingUp
			// 
			this->Image2SpeedingUp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Image2SpeedingUp->AutoSize = true;
			this->Image2SpeedingUp->Checked = true;
			this->Image2SpeedingUp->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Image2SpeedingUp->Location = System::Drawing::Point(306, 7);
			this->Image2SpeedingUp->Name = L"Image2SpeedingUp";
			this->Image2SpeedingUp->Size = System::Drawing::Size(32, 16);
			this->Image2SpeedingUp->TabIndex = 1;
			this->Image2SpeedingUp->Text = L"C";
			this->Image2SpeedingUp->UseVisualStyleBackColor = true;
			// 
			// DisplayChange2
			// 
			this->DisplayChange2->Enabled = false;
			this->DisplayChange2->Location = System::Drawing::Point(3, 4);
			this->DisplayChange2->Name = L"DisplayChange2";
			this->DisplayChange2->Size = System::Drawing::Size(60, 20);
			this->DisplayChange2->TabIndex = 0;
			this->DisplayChange2->Text = L"All";
			this->DisplayChange2->UseVisualStyleBackColor = true;
			this->DisplayChange2->Click += gcnew System::EventHandler(this, &Main::DisplayChange2_Click);
			// 
			// OpenBGImageDialog
			// 
			this->OpenBGImageDialog->FileName = L"OpenBGImageDialog";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 733);
			this->Controls->Add(this->TableLayoutPanel1);
			this->Controls->Add(this->SettingBox);
			this->Controls->Add(this->StatusStrip);
			this->Controls->Add(this->MenuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->MenuStrip;
			this->Name = L"Main";
			this->Text = L"Transform Tool";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->Resize += gcnew System::EventHandler(this, &Main::Main_Resize);
			this->MenuStrip->ResumeLayout(false);
			this->MenuStrip->PerformLayout();
			this->StatusStrip->ResumeLayout(false);
			this->StatusStrip->PerformLayout();
			this->SettingBox->ResumeLayout(false);
			this->TableLayoutPanel7->ResumeLayout(false);
			this->Interpolation->ResumeLayout(false);
			this->Interpolation->PerformLayout();
			this->ProjectType->ResumeLayout(false);
			this->ProjectType->PerformLayout();
			this->MorphPanel->ResumeLayout(false);
			this->MorphPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Latticenumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Franenumeric))->EndInit();
			this->NormalizationPanel->ResumeLayout(false);
			this->NormalizationPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PointNumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PartitionNumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BackgroundImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputImage1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InPointSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->OutPointSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InputImage2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ImageTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->InterlevelImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->FirstImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SecondImage))->EndInit();
			this->TableLayoutPanel1->ResumeLayout(false);
			this->TableLayoutPanel2->ResumeLayout(false);
			this->PanelOriginalImage->ResumeLayout(false);
			this->PanelAnimateImage->ResumeLayout(false);
			this->PanelResultImage->ResumeLayout(false);
			this->TableLayoutPanel3->ResumeLayout(false);
			this->PanelInputImage1->ResumeLayout(false);
			this->PanelInputImage1->PerformLayout();
			this->PanelInputImage2->ResumeLayout(false);
			this->PanelInputImage2->PerformLayout();
			this->TableLayoutPanel4->ResumeLayout(false);
			this->PanelInputBtn->ResumeLayout(false);
			this->PanelInputBtn->PerformLayout();
			this->Image1NamePanel->ResumeLayout(false);
			this->Image1NamePanel->PerformLayout();
			this->PanelOutputBtn->ResumeLayout(false);
			this->PanelOutputBtn->PerformLayout();
			this->Image2NamePanel->ResumeLayout(false);
			this->Image2NamePanel->PerformLayout();
			this->TableLayoutPanel5->ResumeLayout(false);
			this->PanelOriginalBtn->ResumeLayout(false);
			this->PanelOriginalBtn->PerformLayout();
			this->PanelAnimateBtn->ResumeLayout(false);
			this->PanelAnimateBtn->PerformLayout();
			this->PanelResultBtn->ResumeLayout(false);
			this->PanelResultBtn->PerformLayout();
			this->TableLayoutPanel6->ResumeLayout(false);
			this->PanelImage1Info->ResumeLayout(false);
			this->PanelImage1Info->PerformLayout();
			this->PanelImage2Info->ResumeLayout(false);
			this->PanelImage2Info->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//==============================================================//
		//  ファイル名	: Main.h (TransformTool)                        //
		//  作成者		: 寺田 卓馬 (Intelligent Image Processing Lab.) //
		//  更新日		: 2008/12/10                                    //
		//==============================================================//
	private:
		//--------------//
		//   変数宣言   //
		//--------------//

		//- BitMap -//
		Bitmap ^src_img, ^dst_img;				// オリジナル画像,ワープ画像
		Bitmap ^in_mark_img, ^out_mark_img;		// ペイント画像
		array <Bitmap ^> ^amt_img;				// アニメーション
		array <Bitmap ^> ^first_img, ^second_img;
		Bitmap ^tmp1_img;						// 一時保存
		Bitmap ^src_morph_img;					// モーフィング用オリジナル画像
		Bitmap ^background_img;					// 正規化時の背景画像
		Bitmap ^indst_img;						// 逆ワープ画像
		//- Coordinate -//
		array <Point, 1> ^in_pt, ^in_pt_tmp;	// 入力点(座標)の領域確保
		array <Point, 1> ^out_pt, ^out_pt_tmp;	// 出力点(座標)の領域確保
		//- String -//
		static String ^filename;				// 画像ファイル名
		static array <String ^> ^ sip = gcnew array<String ^>(150);	// 入力数字表示
		static array <String ^> ^ sop = gcnew array<String ^>(150);	// 出力数字表示
		static array <String ^> ^in_read_str_tmp, ^out_read_str_tmp;
		static String ^in_r_str, ^in_w_str;		// 入力座標読み込み
		static String ^out_r_str, ^out_w_str;	// 出力座標読み込み
		//- Form -//
		InputMarkWindow ^in_mark_form, ^out_mark_form;
		//- Transform Flag -//
		int in_num_display_flag;
		int out_num_display_flag;
		int in_mesh_display_flag;
		int out_mesh_display_flag;
		int display1_flag;
		int display2_flag;
		static int read_image1_flag = 1;
		static int read_image2_flag = 1;
		int morphing_flag;
		//- Animate -//
		int animate_bar, animate_flag;
		//- Color - //
		Color image_back_color;

	private:
		//==============//
		//  初期化関数  //
		//==============//

		//-- 処理初期化 --//
		void Initialization() {
			point_max = (int)PointNumeric->Value;
			moph_counter = 0;		// 変形の回数
			in_moph_counter = 0;
			out_moph_counter = 0;
			InputInitialization();
			if(MorphingSelect->Checked == false)
				OutputInitialization();
			// 画像の表示
			FirstImage->Image = src_img;
			InputImage1->Image = in_mark_img;
			if(MorphingSelect->Checked == false)
				InputImage2->Image = out_mark_img;
			// ステータス
			ProgressBar->Value = 0;
			FrameRemainder->Text = "?";
			FrameAll->Text = "?";
			// フラッグ
			in_num_display_flag = 0;
			out_num_display_flag = 0;
			in_mesh_display_flag = 0;
			out_mesh_display_flag = 0;
			display1_flag = 0;
			display2_flag = 0;
			morphing_flag = 0;
			// 背景色
			image_back_color = Color::Black;
			BackgroundImage->BackColor = Color::Black;
		}
		//-- 入力画像の初期化1 --//
		void InputInitialization() {
			InputListBox->Items->Clear();		// リストボックスを空にする
			in_pt_counter=0;					// 点の数を初期化
			Array::Resize(in_pt, point_max);	// 領域のリサイズ
			Array::Resize(in_pt_tmp, point_max);
			in_point_size = (int)InPointSize->Value;	// 点の大きさ
			in_r_str = "", in_w_str = "";				// 座標の初期化
			if(NormalizationSelect->Checked == true)
				RunBtn->Enabled = false;
			// フラッグ
			in_num_display_flag = 0;
			in_mesh_display_flag = 0;
		}
		//-- 入力画像の初期化2 --//
		void OutputInitialization() {
			OutputListBox->Items->Clear();
			out_pt_counter=0;
			Array::Resize(out_pt, point_max);
			Array::Resize(out_pt_tmp, point_max);
			out_point_size = (int)OutPointSize->Value;
			out_r_str = "", out_w_str = "";
			if(NormalizationSelect->Checked == true)
				RunBtn->Enabled = false;
			// フラッグ
			out_num_display_flag = 0;
			out_mesh_display_flag = 0;
		}
		//-- 初期ボタンのチェック --//
		void ButtonInitialization(){
			InputInit->Enabled = true;
			OutputInit->Enabled = true;
			InputZoom->Enabled = true;
			OutputZoom->Enabled = true;
			OriginZoom->Enabled = true;
			SettingBox->Enabled = true;
			InputImage1->Enabled = true;
			InputImage2->Enabled = true;
			InputCoordinateRead->Enabled = true;
			OutputCoordinateRead->Enabled = true;
			InputNumberDisplay->Enabled = true;
			OutputNumberDisplay->Enabled = true;
			InputCoordinateWrite->Enabled = true;
			OutputCoordinateWrite->Enabled = true;
			InputMesh->Enabled = true;
			OutputMesh->Enabled = true;
			DisplayChange1->Enabled = true;
			DisplayChange2->Enabled = true;
		}
		//-- Runボタン実行時のチェック --//
		void RunButtonInitialization(){
			ProgressBar->Value = 0;
			StartBtn->Enabled = true;
			StopBtn->Enabled = true;
			InterlevelZoom->Enabled = true;
			ImageTrackBar->Enabled = true;
			ProcessedZoom->Enabled = true;
			SaveImageBtn->Enabled = true;
			SaveAnimate->Enabled = true;
		}
	private:
		//======================//
		//  ウィンドウ操作処理  //
		//======================//

		//--  フォームを中央に配置  --//
		void WindowToCenter() {
			System::Drawing::Rectangle ^ rect = Screen::PrimaryScreen->Bounds;
			int sx = rect->Width;
			int sy = rect->Height;
			this->Left = (sx - this->Width) / 2;
			this->Top = (sy - this->Height) / 2;
		}
		//-- ウィンドウを開いた時 --//
		System::Void Main_Load(System::Object^  sender, System::EventArgs^  e) {
			this->Width = 1024;	// サイズの指定(横)
			this->Height = 760;	// サイズの指定(縦)
			WindowToCenter();
			Initialization();
		}
		//-- ウィンドウをリサイズした時 --//
		System::Void Main_Resize(System::Object^  sender, System::EventArgs^  e) {
			if(this->Width < 1024) this->Width = 1024;	// 最小の幅
			if(this->Height < 760) this->Height = 760;	// 最小の高さ
			if(read_image1_flag == 0)
				Image1Name->Left = Image1NamePanel->Width - Image1Name->Width;
			if(read_image2_flag == 0)
				Image2Name->Left = Image2NamePanel->Width - Image2Name->Width;
		}
	private:
		//================//
		//  メニュー項目  //
		//================//

		//-- センターに移動 --//
		System::Void CenterMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			WindowToCenter();
		}
		//-- 最前面 --//
		System::Void AAspectMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if(AAspectMenuItem->Checked == false){
				this->TopMost = true;
				AAspectMenuItem->Checked= true;
				if(in_mark_form != nullptr) in_mark_form->TopMost = true;
			}
			else{
				this->TopMost = false;
				AAspectMenuItem->Checked = false;
			}
		}
		//-- Active Shape Modelの起動 --//
		System::Void ActiveShapeModelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Process^ proc = gcnew Process();
			proc->StartInfo->FileName = "C:/Warping/asm/iFace_ASM_ImageSearching.exe";
			try {
				proc->Start();
			}
			catch (Exception^) {
				MessageBox::Show("ASMを起動できません");
			}
		}
	private:
		//===============//
		//  GUI:Setting  //
		//===============//

		//-- Settingボタン --//
		void Checked_Initialization() {
			ReadInputImage2->Enabled = false;
			Image2Name->Enabled = false;
			InputImage2->Enabled = true;
			in_mark_img = gcnew Bitmap(src_img);
			InputImage1->Image = in_mark_img;
			out_mark_img = gcnew Bitmap(src_img);
			InputImage2->Image = out_mark_img;
			SecondImage->Image = nullptr;
			OriginalLabel->Text = "Original Image";
			ResultLabel->Text = "Result Image";
			Image2Name->Text = "Image2 Name";
			Image2Name->Left = 3;
			read_image2_flag = 1;
			InputInitialization();
			OutputInitialization();
			SaveImageBtn->Visible = true;
		}
		//-- Normalizationボタン押したとき --//
		System::Void Normalization_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			MorphPanel->Enabled = false;
			NormalizationPanel->Enabled = true;
			RunBtn->Enabled = false;
			AssociationBtn->Enabled = true;
			Checked_Initialization();
		}
		//-- Warpingボタン押したとき --//
		System::Void Warping_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			NormalizationPanel->Enabled = false;
			MorphPanel->Enabled = true;
			AssociationBtn->Enabled = false;
			RunBtn->Enabled = true;
			Checked_Initialization();
		}
		//-- Morphingボタン押したとき --//
		System::Void Morphing_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			NormalizationPanel->Enabled = false;
			MorphPanel->Enabled = true;
			AssociationBtn->Enabled = false;
			RunBtn->Enabled = true;
			ReadInputImage2->Enabled = true;
			Image2Name->Enabled = true;
			OriginalLabel->Text = "Input Image 1";
			ResultLabel->Text = "Input Image 2";
			InputImage2->Image = nullptr;
			InputImage2->Enabled = false;
			SaveImageBtn->Visible = false;
			AnimationCk->Checked = true;
			morphing_flag = 1;
		}
		//-- 特徴点の最大数 --//
		System::Void PointNumeric_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			point_max = (int)PointNumeric->Value;
			if(in_pt_counter < point_max){
				Array::Resize(in_pt, point_max);
				Array::Resize(in_pt_tmp, point_max);
			}
			if(out_pt_counter < point_max){
				Array::Resize(out_pt, point_max);
				Array::Resize(out_pt_tmp, point_max);
			}
		}
		//-- Eyeボタンの変更 --//
		System::Void EyeParts_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(EyeParts->Checked == false)
				PartitionNumeric->Value = PartitionNumeric->Value + 12;	// Eyes:12
			else
				PartitionNumeric->Value = PartitionNumeric->Value - 12;	// Eyes:12
			RunBtn->Enabled = false;
		}
		//-- Eyebrowボタンの変更 --//
		System::Void EyebrowParts_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(EyebrowParts->Checked == false)
				PartitionNumeric->Value = PartitionNumeric->Value + 12;	// Eyes:12
			else
				PartitionNumeric->Value = PartitionNumeric->Value - 12;	// Eyes:12
			RunBtn->Enabled = false;
		}
		//-- Noseボタンの変更 --//
		System::Void NoseParts_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(NoseParts->Checked == false)
				PartitionNumeric->Value = PartitionNumeric->Value + 6;	// Eyes:12
			else
				PartitionNumeric->Value = PartitionNumeric->Value - 6;	// Eyes:12
			RunBtn->Enabled = false;
		}
		//-- Mouthボタンの変更 --//
		System::Void MouthParts_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if(MouthParts->Checked == false)
				PartitionNumeric->Value = PartitionNumeric->Value + 34;	// Eyes:12
			else
				PartitionNumeric->Value = PartitionNumeric->Value - 34;	// Eyes:12
			RunBtn->Enabled = false;
		}
		//-- 背景色の選択(Default:Black) --//
		System::Void BackgroundReadBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			if (ColorDialog->ShowDialog() == Windows::Forms::DialogResult::OK){
				image_back_color = ColorDialog->Color;
				BackgroundImage->BackColor = image_back_color;
				BackgroundImage->Image = nullptr;
			}
		}
		//-- 背景画像の選択 --//
		System::Void BackgroundReadImage_Click(System::Object^  sender, System::EventArgs^  e) {
			OpenBGImageDialog->Filter = "Image File (*.bmp,*.jpg,*png)|*.bmp;*.jpg;*.png";
			if (OpenBGImageDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				filename = OpenBGImageDialog->FileName;
				background_img = gcnew Bitmap(filename);
				BackgroundImage->Image = background_img;
			}
		}
	private:
		//==================//
		//  GUI:InputImage1 //
		//==================//

		//-- 画像データ読み込み --//
		System::Void ReadInputImage1_Click(System::Object^  sender, System::EventArgs^  e) {
			// 入力ファイルの設定
			OpenFileDialog->Filter = "Image File (*.bmp,*.jpg,*png)|*.bmp;*.jpg;*.png";
			if (OpenFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				// 画像の格納
				filename = OpenFileDialog->FileName;
				read_image1_flag = 0;
				Image1Name->Text = filename; // テキスト表示右寄り
				Image1Name->Left = Image1NamePanel->Width - Image1Name->Width;
				src_img = gcnew Bitmap(filename);
				in_mark_img = gcnew Bitmap(filename);
				// モーフィング用処理
				if(MorphingSelect->Checked == false)
					out_mark_img = gcnew Bitmap(filename);
				else if(read_image2_flag == 1){
					out_mark_img = nullptr;
				}
				// 画像の表示
				FirstImage->Image = src_img;
				InputImage1->Image = in_mark_img;
				if(MorphingSelect->Checked == false)
					InputImage2->Image = out_mark_img;
				tmp1_img = gcnew Bitmap(filename);
				InputInitialization();
				if(MorphingSelect->Checked == false)
					OutputInitialization();
				ButtonInitialization();
				// 画像2を読み込んでいない場合
				if(out_mark_img == nullptr)
					InputImage2->Enabled = false;
				// 通常画像設定初期化
				iWidth = src_img->Width;	// 横幅取得
				iHeight = src_img->Height;	// 縦幅取得
				dst_img = gcnew Bitmap(iWidth, iHeight);
				indst_img = gcnew Bitmap(iWidth, iHeight);
				// 他のウィンドウ処理
				in_mark_form->PictureBox->Image = in_mark_img;
			}
		}
		//-- InputImage1の初期化 --//
		System::Void InputInit_Click(System::Object^  sender, System::EventArgs^  e) {
			InputInitialization();
			in_mark_img = gcnew Bitmap(src_img);
			InputImage1->Image = in_mark_img;
			// モーフィング用処理
			if(MorphingSelect->Checked == false){
				out_mark_img = gcnew Bitmap(tmp1_img);
				InputImage2->Image = out_mark_img;
			}
		}
		//-- フォームの表示 --//
		System::Void InputZoom_Click(System::Object^  sender, System::EventArgs^  e) {
			if(in_mark_form == nullptr) in_mark_form = gcnew InputMarkWindow();
			in_mark_form->Show();
		}
		//-- 点の大きさ --//
		System::Void InPointSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			in_point_size = (int)InPointSize->Value;
		}
		//-- 座標の読み込み --//
		System::Void InputCoordinateRead_Click(System::Object^  sender, System::EventArgs^  e) {
			StreamReader ^pr;
			String ^s;
			int len = 0, comentout = 12;
			// 入力ファイルの設定
			OpenFileDialog->DefaultExt = L"pts";
			OpenFileDialog->Filter = "Text File (*.pts,*.txt)|*.pts;*.txt";
			if (OpenFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				String ^fname = OpenFileDialog->FileName;
				pr = gcnew StreamReader(
					gcnew FileStream(fname, FileMode::Open, FileAccess::Read),
					System::Text::Encoding::Default);
				// 1行読み込み
				while ((s = pr->ReadLine()) != nullptr) {
					// 必要ない行をとばす
					if(len >= comentout) in_r_str = in_r_str + s + "\r\n";
					len++;
				}
				// 文字列の分割
				in_read_str_tmp = in_r_str->Split(L'\r');
				// 砂時計表示
				System::Windows::Forms::Cursor^ save_csr = this->Cursor;
				this->Cursor = Cursors::WaitCursor;
				InputCoordinateRead->Enabled = false;
				while(in_pt_counter < point_max)
					InputImage1_MouseDown(nullptr, nullptr);
				InputCoordinateRead->Enabled = true;
				this->Cursor = save_csr; // 元のカーソルに戻す
				pr->Close();
			}
		}
		//-- 特徴点をマーク --//
		System::Void InputImage1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int x, y;				// 入力(x,y)座標
			double dox, doy;		// 画像とボックスの比率を調整
			Graphics ^g = InputImage1->CreateGraphics();
			// 座標を取得(読み込み(自動) or 手動)
			if(InputCoordinateRead->Enabled == false){
				array<String ^> ^ixy = in_read_str_tmp[in_pt_counter]->Split(L' ');
				in_pt_counter = Convert::ToInt32(ixy[4]);
				x = Convert::ToInt32(ixy[5]);
				y = Convert::ToInt32(ixy[6]);
				// 座標を変換(From 画像座標 To ピクチャーボックス)
				dox = InputImage1->Size.Width / (double)iWidth;
				doy = InputImage1->Size.Height / (double)iHeight;
				x = (int)((double)x * dox + 0.5);
				y = (int)((double)y * doy + 0.5);
			}
			else x = e->X, y = e->Y;
			// 座標の処理
			if(in_pt_counter < point_max){
				in_pt_tmp[in_pt_counter].X = x;
				in_pt_tmp[in_pt_counter].Y = y;
				// 座標を変換(From ピクチャーボックス To 画像座標)
				dox = (double)iWidth / (double)InputImage1->Size.Width;
				doy = (double)iHeight/ (double)InputImage1->Size.Height;
				x = (int)((double)x * dox + 0.5);
				y = (int)((double)y * doy + 0.5);
				// 読み込み後 + 範囲内であれば，ペイントを行う		
				in_pt[in_pt_counter].X = x;
				in_pt[in_pt_counter].Y = y;
				for(int i = y-in_point_size; i<y+in_point_size; i++){
					for(int j = x-in_point_size; j<x+in_point_size; j++)
						if(j < in_mark_img->Width && j >= 0 && i < in_mark_img->Height && i >= 0)
							if( abs(x-j)+abs(y-i) < in_point_size-1 ){
								in_mark_img->SetPixel(j,i, Color::Red);
								// モーフィング以外用処理
								if(MorphingSelect->Checked == false)
									out_mark_img->SetPixel(j,i, Color::Red);
							}
				}
				// リストボックスへの座標表示
				String ^s = String::Format("P:{0}\tX:{1}\tY:{2}",in_pt_counter, in_pt_tmp[in_pt_counter].X, in_pt_tmp[in_pt_counter].Y);
				InputListBox->Items->Add(s);
				// 書き込み用テキスト
				String ^ss = String::Format("#  A I {0} {1} {2} CF CT \r\n",in_pt_counter, in_pt[in_pt_counter].X, in_pt[in_pt_counter].Y);
				in_w_str = in_w_str + ss;
				// 特徴点増加, 自動スクロール
				InputListBox->SelectedIndex = in_pt_counter;
				in_pt_counter++;
			}
			if(Image1SpeedingUp->Checked == false || InputCoordinateRead->Enabled == true)
				this->Refresh();
			if(in_pt_counter >= point_max)
				this->Refresh();
		}
		//-- 座標の書き出し --//
		System::Void InputCoordinateWrite_Click(System::Object^  sender, System::EventArgs^  e) {
			StreamWriter^ ps;
			String ^s = "";
			int len = 0, comentout = 12;
			SaveFileDialog->DefaultExt = L"pts";
			SaveFileDialog->Filter = "Text File (*.pts,*.txt)|*.pts;*.txt";
			if (SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				String ^fname = SaveFileDialog->FileName;
				ps = gcnew StreamWriter(
					gcnew FileStream(fname, FileMode::Create, FileAccess::Write),
					System::Text::Encoding::Default);
				// コメントアウト行を追加
				while(len < comentout){
					s = s + "# \r\n";
					len++;
				}
				s =  s + in_w_str;
				ps->Write(s);		// 文字列を保存
				ps->Close();
			}
		}
		//-- ペイント表示 --//
		System::Void InputImage1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Graphics ^ g = e->Graphics;
			Pen ^ p = gcnew Pen(Color::White);
			// 番号を表示 
			if(in_num_display_flag == 0){
				if(display1_flag == 0){	// 通常サイズの画像時
					for(int i=0; i<in_pt_counter; i++){
						g->DrawString(i.ToString(), gcnew System::Drawing::Font("Arial",8),
							gcnew System::Drawing::SolidBrush(Color::WhiteSmoke),(float)in_pt[i].X,(float)in_pt[i].Y);
					}
				}
				else{
					for(int i=0; i<in_pt_counter; i++){
						g->DrawString(i.ToString(), gcnew System::Drawing::Font("Arial",8),
							gcnew System::Drawing::SolidBrush(Color::WhiteSmoke),(float)in_pt_tmp[i].X,(float)in_pt_tmp[i].Y);
					}
				}
			}
			// メッシュ表示
			if(in_mesh_display_flag == 1 && in_moph_counter == moph_max && display1_flag == 0){
				for(int i = 0; i<moph_max; i++){
					g->DrawLine(p, ip[i].px[0],ip[i].py[0], ip[i].px[1],ip[i].py[1]);
					g->DrawLine(p, ip[i].px[1],ip[i].py[1], ip[i].px[2],ip[i].py[2]);
					g->DrawLine(p, ip[i].px[2],ip[i].py[2], ip[i].px[0],ip[i].py[0]);
				}
			}
		}
		//-- 番号の表示・非表示 --//
		System::Void InputNumberDisplay_Click(System::Object^  sender, System::EventArgs^  e) {
			if(in_num_display_flag == 0) in_num_display_flag = 1;
			else in_num_display_flag = 0;
			this->Refresh();
		}
		//-- メッシュの表示・非表示 --//
		System::Void InputMesh_Click(System::Object^  sender, System::EventArgs^  e) {
			if(in_mesh_display_flag == 0) in_mesh_display_flag = 1;
			else in_mesh_display_flag = 0;
			this->Refresh();
		}
		//-- 表示方法の変更 --//
		System::Void DisplayChange1_Click(System::Object^  sender, System::EventArgs^  e) {
			if(display1_flag == 0){
				InputImage1->SizeMode = PictureBoxSizeMode::StretchImage;
				InputImage1->Dock = DockStyle::Fill;
				display1_flag = 1;
				in_num_display_flag = 1;
				in_mesh_display_flag = 1;
				InputNumberDisplay->Enabled = false;
				InputMesh->Enabled = false;
			}
			else{
				InputImage1->SizeMode = PictureBoxSizeMode::AutoSize;
				InputImage1->Dock = DockStyle::None;
				display1_flag = 0;
				in_num_display_flag = 0;
				in_mesh_display_flag = 0;
				InputNumberDisplay->Enabled = true;
				InputMesh->Enabled = true;
			}
		}
	private:
		//===================//
		//  GUI:InputImage2  //
		//===================//
		
		//-- 画像読み込み --//
		System::Void ReadInputImage2_Click(System::Object^  sender, System::EventArgs^  e) {
			// 入力ファイルの設定
			OpenFileDialog->Filter = "Image File (*.bmp,*.jpg,*png)|*.bmp;*.jpg;*.png";
			if (OpenFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
				// 画像の格納
				filename = OpenFileDialog->FileName;
				read_image2_flag = 0;
				Image2Name->Text = filename; // テキスト表示右寄り
				Image2Name->Left = Image2NamePanel->Width - Image2Name->Width;
				out_mark_img = gcnew Bitmap(filename);
				InputImage2->Image = out_mark_img;
				src_morph_img = gcnew Bitmap(filename);
				SecondImage->Image = src_morph_img;
				InputImage2->Enabled = true;
				OutputInitialization();
				morphing_flag = 1;
			}
		}
		//-- 点の大きさ --//
		System::Void OutPointSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			out_point_size = (int)OutPointSize->Value;
		}
		//-- InputImage2の初期化 --//
		System::Void OutputInit_Click(System::Object^  sender, System::EventArgs^  e) {
			OutputInitialization();
			tmp1_img = gcnew Bitmap(src_img);
			out_mark_img = gcnew Bitmap(in_mark_img);
			if(MorphingSelect->Checked == true)
				out_mark_img = gcnew Bitmap(src_morph_img);
			InputImage2->Image = out_mark_img;
		}
		//-- 座標の読み込み --//
		System::Void OutputCoordinateRead_Click(System::Object^  sender, System::EventArgs^  e) {
			StreamReader ^pr;
			String ^s;
			int len = 0, comentout = 12;
			// 入力ファイルの設定
			OpenFileDialog->DefaultExt = L"pts";
			OpenFileDialog->Filter = "Text File (*.pts,*.txt)|*.pts;*.txt";
			if (OpenFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				String ^ fname = OpenFileDialog->FileName;
				pr = gcnew StreamReader(
					gcnew FileStream(fname, FileMode::Open, FileAccess::Read),
					System::Text::Encoding::Default);
				// 1行読み込み
				while ((s = pr->ReadLine()) != nullptr) {
					// 必要ない行をとばす
					if(len >= comentout) out_r_str = out_r_str + s + "\r\n";
					len++;
				}
				// 文字列の分割
				out_read_str_tmp = out_r_str->Split(L'\r');
				// 砂時計表示
				System::Windows::Forms::Cursor^ save_csr = this->Cursor;
				this->Cursor = Cursors::WaitCursor;
				OutputCoordinateRead->Enabled = false;
				while(out_pt_counter<point_max)
					InputImage2_MouseDown(nullptr, nullptr);
				OutputCoordinateRead->Enabled = true;
				this->Cursor = save_csr; // 元のカーソルに戻す
				pr->Close();
			}
		}
		//-- 特徴点をマーク --//
		System::Void InputImage2_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int u, v;				// 出力(u,v)座標
			double dox, doy;		// 画像とボックスの比率を調整
			Graphics ^ g = InputImage2->CreateGraphics();
			// 座標を取得(読み込み(自動) or 手動)
			if(OutputCoordinateRead->Enabled == false){				 		 
				array<String ^> ^oxy = out_read_str_tmp[out_pt_counter]->Split(L' ');
				out_pt_counter = Convert::ToInt32(oxy[4]);
				u = Convert::ToInt32(oxy[5]);
				v = Convert::ToInt32(oxy[6]);
				// 座標を変換(From 画像座標 To ピクチャーボックス)
				dox = (double)InputImage2->Size.Width / (double)iWidth;
				doy = (double)InputImage2->Size.Height / (double)iHeight;
				u = (int)((double)u * dox + 0.5);
				v = (int)((double)v * doy + 0.5);
			} else u = e->X, v = e->Y;
			// 座標の処理
			if(out_pt_counter < point_max){
				out_pt_tmp[out_pt_counter].X = u;
				out_pt_tmp[out_pt_counter].Y = v;

				// 座標を変換(From ピクチャーボックス To 画像座標)
				dox = (double)iWidth / (double)InputImage2->Size.Width;
				doy = (double)iHeight / (double)InputImage2->Size.Height;
				u = (int)((double)u * dox + 0.5);
				v = (int)((double)v * doy + 0.5);

				// 読み込み後 + 範囲内であれば，ペイントを行う
				out_pt[out_pt_counter].X = u;
				out_pt[out_pt_counter].Y = v;
				for(int i = v-out_point_size; i<v+out_point_size; i++){
					for(int j = u-out_point_size; j<u+out_point_size; j++)
						if(j < in_mark_img->Width && j >= 0 && i < in_mark_img->Height && i >= 0)
							if( abs(u-j) + abs(v-i) < out_point_size-1 ){
								out_mark_img->SetPixel(j,i, Color::Blue);
								tmp1_img->SetPixel(j,i, Color::Blue);
							}
				}
				// リストボックスへの座標表示
				String ^ s = String::Format("P:{0}\tX:{1}\tY:{2}",out_pt_counter, out_pt_tmp[out_pt_counter].X, out_pt_tmp[out_pt_counter].Y);
				OutputListBox->Items->Add(s);
				// 書き込み用テキスト
				String ^ ss = String::Format("#  A I {0} {1} {2} CF CT \r\n",out_pt_counter, out_pt[out_pt_counter].X, out_pt[out_pt_counter].Y);
				out_w_str = out_w_str + ss;
				// 特徴点増加, 自動スクロール
				OutputListBox->SelectedIndex = out_pt_counter;
				out_pt_counter++;
			}
			if(Image2SpeedingUp->Checked == false || OutputCoordinateRead->Enabled == true)
				this->Refresh();
			if(out_pt_counter >= point_max)
				this->Refresh();
		}
		//-- 座標の書き出し --//
		System::Void OutputCoordinateWrite_Click(System::Object^  sender, System::EventArgs^  e) {
			StreamWriter^ ps;
			String ^s = "";
			int len = 0, comentout = 12;
			SaveFileDialog->DefaultExt = L"pts";
			SaveFileDialog->Filter = "Text File (*.pts,*.txt)|*.pts;*.txt";
			if(SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				String ^ fname = SaveFileDialog->FileName;
				ps = gcnew StreamWriter(
					gcnew FileStream(fname, FileMode::Create, FileAccess::Write),
					System::Text::Encoding::Default);
				// コメントアウト行を追加
				while(len < comentout){ 
					s = s + "# \r\n";
					len++;
				}
				s = s + out_w_str;
				ps->Write(s);		// 文字列を保存
				ps->Close();
			}
		}
		//-- ペイント表示 --//
		System::Void InputImage2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Graphics ^ g = e->Graphics;
			Pen ^ p = gcnew Pen(Color::BlueViolet);
			// 番号を表示 
			if(out_num_display_flag == 0){
				if(display2_flag == 0){	// 通常サイズの画像時
					for(int i=0; i<out_pt_counter; i++){
						g->DrawString(i.ToString(), gcnew System::Drawing::Font("Arial",8),
							gcnew System::Drawing::SolidBrush(Color::WhiteSmoke),(float)out_pt[i].X,(float)out_pt[i].Y);
					}
				}
				else{
					for(int i=0; i<out_pt_counter; i++){
						g->DrawString(i.ToString(), gcnew System::Drawing::Font("Arial",8),
							gcnew System::Drawing::SolidBrush(Color::WhiteSmoke),(float)out_pt_tmp[i].X,(float)out_pt_tmp[i].Y);
					}
				}
			}
			// メッシュ表示
			if(out_mesh_display_flag == 1 && out_moph_counter == moph_max && display2_flag == 0){
				for(int i = 0; i<moph_max; i++){
					g->DrawLine(p, op[i].px[0],op[i].py[0], op[i].px[1],op[i].py[1]);
					g->DrawLine(p, op[i].px[1],op[i].py[1], op[i].px[2],op[i].py[2]);
					g->DrawLine(p, op[i].px[2],op[i].py[2], op[i].px[0],op[i].py[0]);
				}
			}
		}
		//-- 番号の表示・非表示 --//
		System::Void OutputNumberDisplay_Click(System::Object^  sender, System::EventArgs^  e) {
			if(out_num_display_flag == 0) out_num_display_flag = 1;
			else out_num_display_flag = 0;
			this->Refresh();
		}
		//-- メッシュの表示・非表示 --//
		System::Void OutputMesh_Click(System::Object^  sender, System::EventArgs^  e) {
			if(out_mesh_display_flag == 0) out_mesh_display_flag = 1;
			else out_mesh_display_flag = 0;
			this->Refresh();
		}
		//-- 表示方法の変更 --//
		System::Void DisplayChange2_Click(System::Object^  sender, System::EventArgs^  e) {
			if(display2_flag == 0){
				InputImage2->SizeMode = PictureBoxSizeMode::StretchImage;
				InputImage2->Dock = DockStyle::Fill;
				display2_flag = 1;
				out_num_display_flag = 1;
				out_mesh_display_flag = 1;
				OutputNumberDisplay->Enabled = false;
				OutputMesh->Enabled = false;
			}
			else{
				InputImage2->SizeMode = PictureBoxSizeMode::AutoSize;
				InputImage2->Dock = DockStyle::None;
				display2_flag = 0;
				out_num_display_flag = 0;
				out_mesh_display_flag = 0;
				OutputNumberDisplay->Enabled = true;
				OutputMesh->Enabled = true;
			}
		}
	private :
		//===================//
		//  ImageProcessing  //
		//===================//

		//-- バイリニア補間 --//
		void BilinearInterpolation(double inx, double iny, int outx, int outy) {
			int bx,by;			// 四捨五入の値
			double tmpX1,tmpX2;	// 一時保存:X
			double tmpY1,tmpY2;	// 一時保存:Y
			double S1,S2,S3,S4;	// 4点

			// 4点カラー
			array<Color ^> ^pixel = gcnew array<Color ^>(4);
			array<String ^> ^ARGB, ^tmpStr;
			double dR[4],dG[4],dB[4];
			int R,G,B;				// 出力RGB

			bx = (int)(inx),	by = (int)(iny);
			tmpX1 = bx+1-inx, tmpY1 = by+1-iny;
			tmpX2 = inx-bx, tmpY2 = iny-by;

			S1 = tmpX2 * tmpY1, S2 = tmpX1 * tmpY1;
			S3 = tmpX1 * tmpY2, S4 = tmpX2 * tmpY2;

			// 座標のデータを取得
			if(bx+1 < iWidth && by+1 < iHeight){
				pixel[0] = src_img->GetPixel(bx+1,by);
				pixel[1] = src_img->GetPixel(bx,by);
				pixel[2] = src_img->GetPixel(bx,by+1);
				pixel[3] = src_img->GetPixel(bx+1,by+1);
			}
			else{
				pixel[0] = src_img->GetPixel(bx,by);
				pixel[1] = src_img->GetPixel(bx,by);
				pixel[2] = src_img->GetPixel(bx,by);
				pixel[3] = src_img->GetPixel(bx,by);
			}

			// RGB値の取得
			for(int c=0; c<4; c++){
				tmpStr = pixel[c]->ToString()->Split(L']');
				ARGB = tmpStr[0]->ToString()->Split(L',');
				dR[c] = Convert::ToDouble(ARGB[1]->Substring(3));
				dG[c] = Convert::ToDouble(ARGB[2]->Substring(3));
				dB[c] = Convert::ToDouble(ARGB[3]->Substring(3));
			}

			R = (int)(S1*dR[0] + S2*dR[1] + S3*dR[2] + S4*dR[3] + 0.5);
			G = (int)(S1*dG[0] + S2*dG[1] + S3*dG[2] + S4*dG[3] + 0.5);
			B = (int)(S1*dB[0] + S2*dB[1] + S3*dB[2] + S4*dB[3] + 0.5);
			if(R < 0) R = 0; if(R > 255) R = 255;
			if(G < 0) G = 0; if(G > 255) G = 255;
			if(B < 0) B = 0; if(B > 255) B = 255;

			dst_img->SetPixel(outx, outy, Color::FromArgb(R, G, B));
		}
	private :
		//============//
		//  変形処理  //
		//============//

		//-- 関連付けボタン --//
		System::Void AssociationBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			if(in_pt_counter >= PointNumeric->Value && out_pt_counter >= PointNumeric->Value){
				InitAffine();
				Association();
				RunBtn->Enabled = true;
			}
		}
		//-- 処理の実行 --//
		System::Void RunBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			// 砂時計表示
			System::Windows::Forms::Cursor^ save_csr = this->Cursor;
			this->Cursor = Cursors::WaitCursor;
			// 初期化
			RunButtonInitialization();
			// Affine
			if(NormalizationSelect->Checked == true){
				// 処理進捗
				amt_img[0] = gcnew Bitmap(src_img);
				ImageTrackBar->Maximum = 1;
				FrameRemainder->Text = "0";
				FrameAll->Text = "1"; this->Refresh();
				// 背景色・背景画像
				for(int j=0; j<iHeight; j++){
					for(int i=0; i<iWidth; i++){
						dst_img->SetPixel(i,j,image_back_color);
						if(BackgroundImage->Image != nullptr)
							dst_img->SetPixel(i,j,background_img->GetPixel(i,j));
					}
				}
				// アフィン変換ループ
				for(moph_counter=0 ; moph_counter<moph_max; moph_counter++){
					StartEndPoint();		// モーフィング処理位置の取得
					TriAffine();			// 三角パッチ内処理
					ProgressBar->Value = (int)(moph_counter*100 / moph_max);
				}
				// 出力
				SecondImage->Image = dst_img;
				amt_img[1] = gcnew Bitmap(dst_img);
				FrameRemainder->Text = "1"; this->Refresh();
			}
			// Warping(B-Spline)
			else if(WarpingSelect->Checked == true){
				InitSpline();
				ObtainWeight();
				// アニメーション処理
				if(AnimationCk->Checked == true){
					amt_img[0] = gcnew Bitmap(src_img);
					InterlevelImage->Image = amt_img[0];
					FrameRemainder->Text = "0";
					FrameAll->Text = transform_frame.ToString();
					ImageTrackBar->Maximum = transform_frame;
					this->Refresh();
					for(int i=1; i<=transform_frame; i++){
						BSplineOutput(i);
						SecondImage->Image = dst_img;
						amt_img[i] = gcnew Bitmap(dst_img);
						FrameRemainder->Text = i.ToString();
						this->Refresh();
					}
				}
				else{
					amt_img[0] = gcnew Bitmap(src_img);
					ImageTrackBar->Maximum = 1;
					FrameRemainder->Text = "0";
					FrameAll->Text = "1"; this->Refresh();
					BSplineOutput(transform_frame);
					SecondImage->Image = dst_img;
					amt_img[1] = gcnew Bitmap(dst_img);
					FrameRemainder->Text = "1"; this->Refresh();
				}
			}
			// Morphing(B-Spline)
			else if(MorphingSelect->Checked == true){
				// 初期化処理
				MorpingInitialization();
				ObtainWeight();
				// ステータス表示
				FrameRemainder->Text = "0";
				FrameAll->Text = (transform_frame*2).ToString();
				ImageTrackBar->Maximum = transform_frame;
				// FirstImage処理
				first_img[0] = gcnew Bitmap(src_img);
				InterlevelImage->Image = first_img[0];
				for(int i=1; i<=transform_frame; i++){
					BSplineOutput(i);		// Image1 -> Image2
					first_img[i] = gcnew Bitmap(dst_img);
					FrameRemainder->Text = i.ToString();
					this->Refresh();
				}
				// 初期化処理
				MorpingInitialization();	// latticeの初期化
				ObtainWeightInverse();		// 逆の重みを求める
				// SecondImage処理
				second_img[0] = gcnew Bitmap(src_morph_img);
				for(int i=1; i<=transform_frame; i++){
					InvBSplineOutput(i); //BSplineOutputと変更なし(出力だけdst)
					second_img[i] = gcnew Bitmap(dst_img);
					FrameRemainder->Text = (i +transform_frame).ToString();
					this->Refresh();
				}
				// アニメーション処理
				amt_img[0] = gcnew Bitmap(src_img);
				amt_img[transform_frame] = gcnew Bitmap(src_morph_img);
				for(int i=1; i<transform_frame; i++){
					MorphingProcessing(i);
					amt_img[i] = gcnew Bitmap(dst_img);
				}
			}
			this->Cursor = save_csr; // 元のカーソルに戻す
		}
	private :
		//==============//
		//  Affine変換  //
		//==============//

		//-- アフィン変換初期化 --//
		void InitAffine(){
			moph_max = (int)PartitionNumeric->Value;
			ip = new struct ThreePoint [moph_max];
			op = new struct ThreePoint [moph_max];
			tmpip = new struct ThreePoint [moph_max];
			tmpop = new struct ThreePoint [moph_max];
			transform_frame = (int)(this->Franenumeric->Value)-1;
			Array::Resize(amt_img, transform_frame+1);
			in_moph_counter = 0;
			out_moph_counter = 0;
		}
		//-- 入力点の代入 --//
		void inSubstitution(int p1, int p2, int p3) {
			// 画像上の座標
			ip[in_moph_counter].px[0]=in_pt[p1].X;
			ip[in_moph_counter].py[0]=in_pt[p1].Y;
			ip[in_moph_counter].px[1]=in_pt[p2].X;
			ip[in_moph_counter].py[1]=in_pt[p2].Y;
			ip[in_moph_counter].px[2]=in_pt[p3].X;
			ip[in_moph_counter].py[2]=in_pt[p3].Y;

			// ピクチャーボックス上の座標
			tmpip[in_moph_counter].px[0]=in_pt_tmp[p1].X;
			tmpip[in_moph_counter].py[0]=in_pt_tmp[p1].Y;
			tmpip[in_moph_counter].px[1]=in_pt_tmp[p2].X;
			tmpip[in_moph_counter].py[1]=in_pt_tmp[p2].Y;
			tmpip[in_moph_counter].px[2]=in_pt_tmp[p3].X;
			tmpip[in_moph_counter].py[2]=in_pt_tmp[p3].Y;
			in_moph_counter++;
		}
		//-- 出力点の代入 --//
		void outSubstitution(int p1, int p2, int p3){
			// 画像上の座標
			op[out_moph_counter].px[0]=out_pt[p1].X;
			op[out_moph_counter].py[0]=out_pt[p1].Y;
			op[out_moph_counter].px[1]=out_pt[p2].X;
			op[out_moph_counter].py[1]=out_pt[p2].Y;
			op[out_moph_counter].px[2]=out_pt[p3].X;
			op[out_moph_counter].py[2]=out_pt[p3].Y;

			// ピクチャーボックス上の座標
			tmpop[out_moph_counter].px[0]=out_pt_tmp[p1].X;
			tmpop[out_moph_counter].py[0]=out_pt_tmp[p1].Y;
			tmpop[out_moph_counter].px[1]=out_pt_tmp[p2].X;
			tmpop[out_moph_counter].py[1]=out_pt_tmp[p2].Y;
			tmpop[out_moph_counter].px[2]=out_pt_tmp[p3].X;
			tmpop[out_moph_counter].py[2]=out_pt_tmp[p3].Y;
			out_moph_counter++;
		}
		//-- 点の関連付け --//
		void Association(){				 
			// 入力点の関連付け
			inSubstitution(14, 84, 18);
			inSubstitution(14, 101, 84);
			inSubstitution(18, 84, 85);
			inSubstitution(14, 13, 101);
			inSubstitution(18, 85, 19);
			inSubstitution(13, 12, 101);
			inSubstitution(19, 85, 20);
			inSubstitution(12, 11, 101);
			inSubstitution(20, 85, 21);
			inSubstitution(11, 100, 101);
			inSubstitution(21, 85, 86);
			inSubstitution(11, 10, 100);
			inSubstitution(21, 86, 22);
			inSubstitution(10, 99, 100);
			inSubstitution(22, 86, 87);
			inSubstitution(10, 98, 99);
			inSubstitution(22, 87, 88);
			inSubstitution(10, 27, 98);
			inSubstitution(22, 88, 40);
			if(EyebrowParts->Checked == false){
				inSubstitution(11, 17, 10); //右眉1
				inSubstitution(12, 17, 11); //右眉2
				inSubstitution(12, 16, 17); //右眉3
				inSubstitution(13, 16, 12); //右眉4
				inSubstitution(13, 15, 16); //右眉5
				inSubstitution(14, 15, 13); //右眉6
				inSubstitution(21, 22, 23); //左眉1
				inSubstitution(20, 21, 23); //左眉2
				inSubstitution(20, 23, 24); //左眉3
				inSubstitution(19, 20, 24); //左眉4
				inSubstitution(19, 24, 25); //左眉5
				inSubstitution(18, 19, 25); //左眉6
			}
			inSubstitution(10, 17, 27);
			inSubstitution(17, 28, 27);
			inSubstitution(17, 16, 28);
			inSubstitution(16, 29, 28);
			inSubstitution(16, 15, 29);
			inSubstitution(15, 30, 29);
			inSubstitution(14, 30, 15);
			inSubstitution(14, 31, 30);
			inSubstitution(22, 40, 23);
			inSubstitution(23, 40, 39);
			inSubstitution(23, 39, 24);
			inSubstitution(24, 39, 38);
			inSubstitution(24, 38, 25);
			inSubstitution(25, 38, 37);
			inSubstitution(18, 25, 37);
			inSubstitution(18, 37, 36);
			if(EyeParts->Checked == false){
				inSubstitution(28, 34, 27); //右目1
				inSubstitution(29, 34, 28); //右目2
				inSubstitution(29, 33, 34); //右目3
				inSubstitution(30, 33, 29); //右目4
				inSubstitution(30, 32, 33); //右目5
				inSubstitution(31, 32, 30); //右目6
				inSubstitution(39, 40, 41); //左目1
				inSubstitution(38, 39, 41); //左目2
				inSubstitution(38, 41, 42); //左目3
				inSubstitution(37, 38, 42); //左目4
				inSubstitution(37, 42, 43); //左目5
				inSubstitution(36, 37, 43); //左目6
			}
			inSubstitution(56, 57, 59);
			inSubstitution(45, 46, 59);
			inSubstitution(51, 52, 59);
			inSubstitution(49, 51, 59);
			inSubstitution(60, 96, 97);
			inSubstitution(60, 95, 96);
			inSubstitution(66, 89, 90);
			inSubstitution(66, 90, 91);
			inSubstitution(60, 71, 95);
			inSubstitution(71, 94, 95);
			inSubstitution(70, 94, 71);
			inSubstitution(69, 94, 70);
			inSubstitution(69, 93, 94);
			inSubstitution(69, 92, 93);
			inSubstitution(68, 92, 69);
			inSubstitution(67, 92, 68);
			inSubstitution(67, 91, 92);
			inSubstitution(66, 91, 67);
			inSubstitution(54, 60, 55);
			inSubstitution(54, 61, 60);
			inSubstitution(54, 62, 61);
			inSubstitution(54, 53, 62);
			inSubstitution(51, 62, 53);
			inSubstitution(51, 63, 62);
			inSubstitution(51, 64, 63);
			inSubstitution(50, 64, 51);
			inSubstitution(48, 64, 50);
			inSubstitution(48, 65, 64);
			inSubstitution(48, 66, 65);
			inSubstitution(47, 66, 48);
			if(NoseParts->Checked == false){
				inSubstitution(52, 53, 54); // 鼻1
				inSubstitution(51, 53, 52); // 鼻2
				inSubstitution(49, 50, 51); // 鼻3
				inSubstitution(48, 50, 49); // 鼻4
				inSubstitution(48, 49, 47); // 鼻5
				inSubstitution(54, 55, 52); // 鼻6
			}
			if(MouthParts->Checked == false){
				inSubstitution(60, 61, 72); // 口1
				inSubstitution(60, 72, 71); // 口2
				inSubstitution(61, 73, 72); // 口3
				inSubstitution(71, 72, 83); // 口4
				inSubstitution(61, 74, 73); // 口5
				inSubstitution(70, 71, 83); // 口6
				inSubstitution(61, 62, 74); // 口7
				inSubstitution(70, 83, 82); // 口8
				inSubstitution(62, 75, 74); // 口9
				inSubstitution(69, 70, 82); // 口10
				inSubstitution(62, 63, 75); // 口11
				inSubstitution(69, 82, 81); // 口12
				inSubstitution(63, 64, 75); // 口13
				inSubstitution(69, 81, 80); // 口14
				inSubstitution(75, 64, 76); // 口15
				inSubstitution(69, 80, 68); // 口16
				inSubstitution(64, 65, 76); // 口17
				inSubstitution(68, 80, 79); // 口18
				inSubstitution(65, 77, 76); // 口19
				inSubstitution(67, 68, 79); // 口20
				inSubstitution(65, 78, 77); // 口21
				inSubstitution(67, 79, 78); // 口22
				inSubstitution(65, 66, 78); // 口23
				inSubstitution(66, 67, 78); // 口24
				inSubstitution(72, 73, 83); // 口25
				inSubstitution(73, 74, 83); // 口26
				inSubstitution(82, 83, 74); // 口27
				inSubstitution(74, 75, 82); // 口28
				inSubstitution(82, 75, 81); // 口29
				inSubstitution(75, 80, 81); // 口30
				inSubstitution(75, 76, 80); // 口31
				inSubstitution(76, 79, 80); // 口32
				inSubstitution(76, 77, 79); // 口33
				inSubstitution(78, 79, 77); // 口34
			}
			inSubstitution(59, 44, 45);
			inSubstitution(59, 57, 58);
			inSubstitution(58, 44, 59);
			inSubstitution(14, 18, 58);
			inSubstitution(44, 58, 18);
			inSubstitution(44, 18, 36);
			inSubstitution(58, 31, 14);
			inSubstitution(59, 46, 47);
			inSubstitution(55, 56, 59);
			inSubstitution(45, 41, 40);
			inSubstitution(42, 41, 45);
			inSubstitution(43, 42, 45);
			inSubstitution(45, 36, 43);
			inSubstitution(45, 44, 36);
			inSubstitution(57, 27, 34);
			inSubstitution(34, 33, 57);
			inSubstitution(57, 33, 32);
			inSubstitution(57, 32, 31);
			inSubstitution(57, 31, 58);
			inSubstitution(46, 45, 40);
			inSubstitution(56, 27, 57);
			inSubstitution(40, 89, 66);
			inSubstitution(40, 88, 89);
			inSubstitution(46, 40, 47);
			inSubstitution(47, 40, 66);
			inSubstitution(55, 27, 56);
			inSubstitution(60, 27, 55);
			inSubstitution(97, 27, 60);
			inSubstitution(98, 27, 97);
			inSubstitution(55, 59, 52);
			inSubstitution(47, 49, 59);

			// 出力点の関連付け
			outSubstitution(14, 84, 18);
			outSubstitution(14, 101, 84);
			outSubstitution(18, 84, 85);
			outSubstitution(14, 13, 101);
			outSubstitution(18, 85, 19);
			outSubstitution(13, 12, 101);
			outSubstitution(19, 85, 20);
			outSubstitution(12, 11, 101);
			outSubstitution(20, 85, 21);
			outSubstitution(11, 100, 101);
			outSubstitution(21, 85, 86);
			outSubstitution(11, 10, 100);
			outSubstitution(21, 86, 22);
			outSubstitution(10, 99, 100);
			outSubstitution(22, 86, 87);
			outSubstitution(10, 98, 99);
			outSubstitution(22, 87, 88);
			outSubstitution(10, 27, 98);
			outSubstitution(22, 88, 40);
			if(EyebrowParts->Checked == false){
				outSubstitution(11, 17, 10); //右眉1
				outSubstitution(12, 17, 11); //右眉2
				outSubstitution(12, 16, 17); //右眉3
				outSubstitution(13, 16, 12); //右眉4
				outSubstitution(13, 15, 16); //右眉5
				outSubstitution(14, 15, 13); //右眉6
				outSubstitution(21, 22, 23); //左眉1
				outSubstitution(20, 21, 23); //左眉2
				outSubstitution(20, 23, 24); //左眉3
				outSubstitution(19, 20, 24); //左眉4
				outSubstitution(19, 24, 25); //左眉5
				outSubstitution(18, 19, 25); //左眉6
			}
			outSubstitution(10, 17, 27);
			outSubstitution(17, 28, 27);
			outSubstitution(17, 16, 28);
			outSubstitution(16, 29, 28);
			outSubstitution(16, 15, 29);
			outSubstitution(15, 30, 29);
			outSubstitution(14, 30, 15);
			outSubstitution(14, 31, 30);
			outSubstitution(22, 40, 23);
			outSubstitution(23, 40, 39);
			outSubstitution(23, 39, 24);
			outSubstitution(24, 39, 38);
			outSubstitution(24, 38, 25);
			outSubstitution(25, 38, 37);
			outSubstitution(18, 25, 37);
			outSubstitution(18, 37, 36);
			if(EyeParts->Checked == false){
				outSubstitution(28, 34, 27); //右目1
				outSubstitution(29, 34, 28); //右目2
				outSubstitution(29, 33, 34); //右目3
				outSubstitution(30, 33, 29); //右目4
				outSubstitution(30, 32, 33); //右目5
				outSubstitution(31, 32, 30); //右目6
				outSubstitution(39, 40, 41); //左目1
				outSubstitution(38, 39, 41); //左目2
				outSubstitution(38, 41, 42); //左目3
				outSubstitution(37, 38, 42); //左目4
				outSubstitution(37, 42, 43); //左目5
				outSubstitution(36, 37, 43); //左目6
			}
			outSubstitution(56, 57, 59);
			outSubstitution(45, 46, 59);
			outSubstitution(51, 52, 59);
			outSubstitution(49, 51, 59);
			outSubstitution(60, 96, 97);
			outSubstitution(60, 95, 96);
			outSubstitution(66, 89, 90);
			outSubstitution(66, 90, 91);
			outSubstitution(60, 71, 95);
			outSubstitution(71, 94, 95);
			outSubstitution(70, 94, 71);
			outSubstitution(69, 94, 70);
			outSubstitution(69, 93, 94);
			outSubstitution(69, 92, 93);
			outSubstitution(68, 92, 69);
			outSubstitution(67, 92, 68);
			outSubstitution(67, 91, 92);
			outSubstitution(66, 91, 67);
			outSubstitution(54, 60, 55);
			outSubstitution(54, 61, 60);
			outSubstitution(54, 62, 61);
			outSubstitution(54, 53, 62);
			outSubstitution(51, 62, 53);
			outSubstitution(51, 63, 62);
			outSubstitution(51, 64, 63);
			outSubstitution(50, 64, 51);
			outSubstitution(48, 64, 50);
			outSubstitution(48, 65, 64);
			outSubstitution(48, 66, 65);
			outSubstitution(47, 66, 48);
			if(NoseParts->Checked == false){		
				outSubstitution(52, 53, 54); // 鼻1
				outSubstitution(51, 53, 52); // 鼻2
				outSubstitution(49, 50, 51); // 鼻3
				outSubstitution(48, 50, 49); // 鼻4
				outSubstitution(48, 49, 47); // 鼻5
				outSubstitution(54, 55, 52); // 鼻6
			}
			if(MouthParts->Checked == false){
				outSubstitution(60, 61, 72); // 口1
				outSubstitution(60, 72, 71); // 口2
				outSubstitution(61, 73, 72); // 口3
				outSubstitution(71, 72, 83); // 口4
				outSubstitution(61, 74, 73); // 口5
				outSubstitution(70, 71, 83); // 口6
				outSubstitution(61, 62, 74); // 口7
				outSubstitution(70, 83, 82); // 口8
				outSubstitution(62, 75, 74); // 口9
				outSubstitution(69, 70, 82); // 口10
				outSubstitution(62, 63, 75); // 口11
				outSubstitution(69, 82, 81); // 口12
				outSubstitution(63, 64, 75); // 口13
				outSubstitution(69, 81, 80); // 口14
				outSubstitution(75, 64, 76); // 口15
				outSubstitution(69, 80, 68); // 口16
				outSubstitution(64, 65, 76); // 口17
				outSubstitution(68, 80, 79); // 口18
				outSubstitution(65, 77, 76); // 口19
				outSubstitution(67, 68, 79); // 口20
				outSubstitution(65, 78, 77); // 口21
				outSubstitution(67, 79, 78); // 口22
				outSubstitution(65, 66, 78); // 口23
				outSubstitution(66, 67, 78); // 口24
				outSubstitution(72, 73, 83); // 口25
				outSubstitution(73, 74, 83); // 口26
				outSubstitution(82, 83, 74); // 口27
				outSubstitution(74, 75, 82); // 口28
				outSubstitution(82, 75, 81); // 口29
				outSubstitution(75, 80, 81); // 口30
				outSubstitution(75, 76, 80); // 口31
				outSubstitution(76, 79, 80); // 口32
				outSubstitution(76, 77, 79); // 口33
				outSubstitution(78, 79, 77); // 口34
			}
			outSubstitution(59, 44, 45);
			outSubstitution(59, 57, 58);
			outSubstitution(58, 44, 59);
			outSubstitution(14, 18, 58);
			outSubstitution(44, 58, 18);
			outSubstitution(44, 18, 36);
			outSubstitution(58, 31, 14);
			outSubstitution(59, 46, 47);
			outSubstitution(55, 56, 59);
			outSubstitution(45, 41, 40);
			outSubstitution(42, 41, 45);
			outSubstitution(43, 42, 45);
			outSubstitution(45, 36, 43);
			outSubstitution(45, 44, 36);
			outSubstitution(57, 27, 34);
			outSubstitution(34, 33, 57);
			outSubstitution(57, 33, 32);
			outSubstitution(57, 32, 31);
			outSubstitution(57, 31, 58);
			outSubstitution(46, 45, 40);
			outSubstitution(56, 27, 57);
			outSubstitution(40, 89, 66);
			outSubstitution(40, 88, 89);
			outSubstitution(46, 40, 47);
			outSubstitution(47, 40, 66);
			outSubstitution(55, 27, 56);
			outSubstitution(60, 27, 55);
			outSubstitution(97, 27, 60);
			outSubstitution(98, 27, 97);
			outSubstitution(55, 59, 52);
			outSubstitution(47, 49, 59);
		}
		//-- モーフィング処理位置の取得 --//
		void StartEndPoint(){
			startX = iWidth;		// スキャン開始位置:x
			startY = iHeight;		// スキャン開始位置:y
			endX = 0;				// スキャン終了位置:x
			endY = 0;				// スキャン終了位置:y
			for(int i=0; i<3; i++){
				if(startX > op[moph_counter].px[i]) startX = op[moph_counter].px[i];
				if(startY > op[moph_counter].py[i]) startY = op[moph_counter].py[i];
				if(endX < op[moph_counter].px[i]) endX = op[moph_counter].px[i];
				if(endY < op[moph_counter].py[i]) endY = op[moph_counter].py[i];
			}
		}
		//-- 三角パッチ内処理 --//
		void TriAffine(){
			double x, y;
			double alpha, beta, gamma;	// ベクトルの係数
			double denominator;			// β,γの分母

			// β,γの分母の計算
			denominator = -op[moph_counter].px[1]*op[moph_counter].py[2] + 
				op[moph_counter].px[1]*op[moph_counter].py[0] + 
				op[moph_counter].px[0]*op[moph_counter].py[2] + 
				op[moph_counter].px[2]*op[moph_counter].py[1] - 
				op[moph_counter].px[2]*op[moph_counter].py[0] - 
				op[moph_counter].px[0]*op[moph_counter].py[1];

			// 画像左上(startX,startY)からスキャン
			for(int j = startY; j < endY; j++){		// for(;iHeight;)
				for(int i = startX; i < endX; i++){	// for(;iWidth;)
					// ベクトルの各係数を求める Eq:X = ax1 + bx2 + gx3
					beta = j*op[moph_counter].px[2] - op[moph_counter].px[0]*j - 
						op[moph_counter].px[2]*op[moph_counter].py[0] - op[moph_counter].py[2]*i + 
						op[moph_counter].px[0]*op[moph_counter].py[2] + i*op[moph_counter].py[0];
					beta = beta / denominator;
					gamma = i*op[moph_counter].py[1] - i*op[moph_counter].py[0] - 
						op[moph_counter].px[0]*op[moph_counter].py[1] - op[moph_counter].px[1]*j + 
						op[moph_counter].px[1]*op[moph_counter].py[0] + op[moph_counter].px[0]*j;
					gamma = gamma / denominator;
					alpha = 1 - (beta + gamma);
					// 指定した3点内を処理する	[0 <= a,b,g <= 1]
					if(alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1 && gamma >= 0 && gamma <= 1){
						// 式の適応
						x = alpha*ip[moph_counter].px[0] + beta*ip[moph_counter].px[1] + gamma*ip[moph_counter].px[2];
						y = alpha*ip[moph_counter].py[0] + beta*ip[moph_counter].py[1] + gamma*ip[moph_counter].py[2];
						// 補間 + 結果画像へ出力(画像外の座標の場合，処理は行わない)
						if(NNBtn->Checked == true){
							// ニアレストネイバー補間
							if((int)(x+0.5) >= 0 && (int)(x+0.5) < iWidth && (int)(y+0.5) >= 0 && (int)(y+0.5) < iHeight)
								dst_img->SetPixel(i,j, src_img->GetPixel((int)(x+0.5), (int)(y+0.5)));
							else
								dst_img->SetPixel(i,j, Color::Black);
						}
						else{
							// バイリニア補間
							if(x >= 0 && x < iWidth && y >= 0 && y < iHeight)
								BilinearInterpolation(x, y, i, j);
							else
								dst_img->SetPixel(i,j, Color::Black);
						}
					}
				} 
			} 
		}
	private :
		//----------------//
		//  B-Spline変換  //
		//----------------//

		//-- スプライン初期化 --//
		void InitSpline(){
			latbw = (int)this->Latticenumeric->Value;	// 格子間隔
			// 画像全体の格子の大きさ
			latw = (iWidth / latbw) + 4;
			lath = (iHeight / latbw) + 4;
			cl = new struct controlLattice[latw*lath];
			// 全格子の各座標を格納
			for(int j=0; j<lath; j++){
				for(int i=0; i<latw; i++){
					cl[j*latw + i].xdel = 0;
					cl[j*latw + i].ydel = 0;
					cl[j*latw + i].ome = 0;
					cl[j*latw + i].xfai = 0;
					cl[j*latw + i].yfai = 0;
				}
			}
			transform_frame = (int)(this->Franenumeric->Value)-1;
			Array::Resize(amt_img, transform_frame+1);
			// 現在の点の数
			if(in_pt_counter > out_pt_counter)
				current_pt = out_pt_counter;
			else
				current_pt = in_pt_counter;
		}
		//-- Bスプライン設定 --//
		double Basic(int num, double t) {
			if(num == 0)
				B[num] = ((1-t)*(1-t)*(1-t)) / 6;
			else if(num == 1)
				B[num] = (3*t*t*t - 6*t*t + 4) / 6;
			else if(num == 2)
				B[num] = (-3*t*t*t + 3*t*t + 3*t + 1) / 6;
			else if(num == 3)
				B[num] = (t*t*t) / 6;
			return (B[num]);
		}
		//-- 格子の大きさを求める --//
		void ObtainWeight() {
			// 各点からの格子の大きさ
			for(int p=0; p<current_pt; p++){
				x_dtmp = in_pt[p].X%latbw;	// 格子までの差:x
				y_dtmp = in_pt[p].Y%latbw;	// 格子までの差:y
				int i = ( (int)(in_pt[p].X-x_dtmp)  / latbw) - 1;	// [x]-1:格子上の点x
				int j = ( (int)(in_pt[p].Y-y_dtmp)  / latbw) - 1;	// [y]-1:格子上の点y
				s = (double)x_dtmp / (double)latbw;	// 格子までの差(0-1)
				t = (double)y_dtmp / (double)latbw;	// 格子までの差(0-1)
				Wab = 0;
				for(int b=0; b<=3; b++){		// row
					for(int a=0; a<=3; a++){	// col
						Wab = Wab + (Basic(a, s)*Basic(b, t)) * (Basic(a, s)*Basic(b, t));				
					}
				}
				for(int l=0; l<=3; l++){		// row
					for(int k=0; k<=3; k++){	// col
						W[l][k] = Basic(k, s) * Basic(l, t);
						x_fai[l][k] = (W[l][k] * (in_pt[p].X-out_pt[p].X) ) / Wab;
						y_fai[l][k] = (W[l][k] * (in_pt[p].Y-out_pt[p].Y) ) / Wab;
						itmp = (j+l+1)*latw + (i+k+1);
						cl[itmp].xdel = cl[itmp].xdel + W[l][k] * W[l][k] * x_fai[l][k];
						cl[itmp].ydel = cl[itmp].ydel + W[l][k] * W[l][k] * y_fai[l][k];
						cl[itmp].ome = cl[itmp].ome + W[l][k] * W[l][k];
					}
				}
			}
			// 範囲内のオーバーラップを考慮
			for(int j=0; j<lath; j++){
				for(int i=0; i<latw; i++){
					if(cl[j*latw + i].ome != 0){
						omega = 0;
						for(int l=0; l<=3; l++){		// row
							for(int k=0; k<=3; k++){	// col
								itmp = (j+l-1)*latw + i+k-1;
								if(itmp >= 0 && itmp <= lath*latw){
									cl[j*latw + i].xfai = cl[j*latw + i].xfai + cl[itmp].xdel;
									cl[j*latw + i].yfai = cl[j*latw + i].yfai + cl[itmp].ydel;
									omega = omega + cl[itmp].ome;
								}
							}
						}
						cl[j*latw + i].xfai = (cl[j*latw + i].xfai / omega);
						cl[j*latw + i].yfai = (cl[j*latw + i].yfai / omega);
					}
					else{
						cl[j*latw + i].xfai = 0;
						cl[j*latw + i].yfai = 0;
					}
				}
			}
		}
		//-- B-Splineの書き出し --//
		void BSplineOutput(int frameNum) {
			double x, y;
			for(int j=0; j<iHeight; j++){
				for(int i=0; i<iWidth; i++){
					inw = i/latbw;
					inh = j/latbw;
					x_dtmp = i%latbw;
					y_dtmp = j%latbw;
					s = (double)x_dtmp / (double)latbw;
					t = (double)y_dtmp / (double)latbw;
					fx = 0, fy = 0;
					for(int l=0; l<=3; l++){		// row
						for(int k=0; k<=3; k++){	// col
							itmp = (inh+l-1)*latw+(inw+k-1);
							if(itmp > 0 && itmp <= latw*lath){
								fx = fx + Basic(k, s) * Basic(l, t) * 
									(cl[itmp].xfai * ((double)frameNum / (double)transform_frame));
								fy = fy + Basic(k, s) * Basic(l, t) * 
									(cl[itmp].yfai * ((double)frameNum / (double)transform_frame));
							}
						}
					}
					// 補間 + 結果画像へ出力
					x = i+fx, y = j+fy;
					if(NNBtn->Checked == true){



						// ニアレストネイバー補間
						if((int)(x+0.5) >= 0 && (int)(x+0.5) < iWidth && (int)(y+0.5) >= 0 && (int)(y+0.5) < iHeight)
							dst_img->SetPixel(i,j, src_img->GetPixel((int)(x+0.5), (int)(y+0.5)));
						else
							dst_img->SetPixel(i,j, Color::Black);
					}
					else{
						// バイリニア補間
						if(x >= 0 && x < iWidth && y >= 0 && y < iHeight)
							BilinearInterpolation(x, y, i, j);
						else
							dst_img->SetPixel(i,j, Color::Black);
					}
					ProgressBar->Value = (int)((i+j*iWidth)*100 / (iWidth*iHeight));
				}
			}
		}
	private:
		//====================//
		//  入出力画像(結果)  //
		//====================//

		//-- フレーム間画像(トラックバー) --//
		System::Void ImageTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			animate_bar = ImageTrackBar->Value;
			InterlevelImage->Image = amt_img[ animate_bar ];
			this->Refresh();
		}
		//-- タイマー処理 --//
		System::Void AnimateTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			// '+'方向(進む)
			if(animate_bar <= ImageTrackBar->Maximum && animate_flag == 0){
				ImageTrackBar->Value = animate_bar;
				InterlevelImage->Image = amt_img[animate_bar];
				this->Refresh();
				animate_bar++; animate_flag = 0;
			}
			// '-'方向(戻る)
			else{
				animate_flag = 1;
				animate_bar--;
				ImageTrackBar->Value = animate_bar;
				InterlevelImage->Image = amt_img[animate_bar];
				this->Refresh();
				if(animate_bar == 0) animate_flag = 0;
			}
		}
		//-- 再生ボタン --//
		System::Void StartBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			animate_bar = 0;
			animate_flag = 0;
			AnimateTimer->Enabled = true;
		}
		//-- 停止ボタン --//
		System::Void StopBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			AnimateTimer->Enabled = false;
		}
		//-- アニメーション書き出し --//
		System::Void SaveAnimate_Click(System::Object^  sender, System::EventArgs^  e) {
			String ^s, ^ss, ^fname = "";
			if(amt_img[1] != nullptr){
				SaveFileDialog->DefaultExt = L".png";
				SaveFileDialog->Filter = "Image File (*.png)|*.png";
				if (SaveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK){
					fname = SaveFileDialog->FileName;
					for(int i=0; i<=ImageTrackBar->Maximum; i++){
						s = String::Format("_{0}.png", i);
						ss = fname->Replace(".png", s);
						amt_img[i]->Save(ss);
					}
				}
			}
		}
		//-- 画像書き出し --//
		System::Void SaveImageBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			if(dst_img != nullptr){
				SaveFileDialog->DefaultExt = L".png";
				SaveFileDialog->Filter = "Image File (*.png)|*.png";
				if (SaveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
					dst_img->Save(SaveFileDialog->FileName);
			}
		}
	private:
		//============//
		//  Morphing  //
		//============//

		//-- モーフィング初期化 --//
		void MorpingInitialization(){
			latbw = (int)this->Latticenumeric->Value;	// 格子間隔
			// 画像全体の格子の大きさ
			latw = (iWidth / latbw) + 4;
			lath = (iHeight / latbw) + 4;
			cl = new struct controlLattice[latw*lath];
			// 全格子の各座標を格納
			for(int j=0; j<lath; j++){
				for(int i=0; i<latw; i++){
					cl[j*latw + i].xdel = 0;
					cl[j*latw + i].ydel = 0;
					cl[j*latw + i].ome = 0;
					cl[j*latw + i].xfai = 0;
					cl[j*latw + i].yfai = 0;
				}
			}
			transform_frame = (int)(this->Franenumeric->Value)-1;
			Array::Resize(amt_img, transform_frame+1);
			Array::Resize(first_img, transform_frame+1);
			Array::Resize(second_img, transform_frame+1);
			// 現在の点の数
			if(in_pt_counter > out_pt_counter)
				current_pt = out_pt_counter;
			else
				current_pt = in_pt_counter;
		}
		//-- 格子の大きさを求める --//
		void ObtainWeightInverse(){
			// 各点からの格子の大きさ
			for(int p=0; p<current_pt; p++){
				x_dtmp = out_pt[p].X%latbw;	// 格子までの差:x
				y_dtmp = out_pt[p].Y%latbw;	// 格子までの差:y
				int i = ( (int)(out_pt[p].X-x_dtmp)  / latbw) - 1;	// [x]-1:格子上の点x
				int j = ( (int)(out_pt[p].Y-y_dtmp)  / latbw) - 1;	// [y]-1:格子上の点y
				s = (double)x_dtmp / (double)latbw;	// 格子までの差(0-1)
				t = (double)y_dtmp / (double)latbw;	// 格子までの差(0-1)
				Wab = 0;
				for(int b=0; b<=3; b++){		// row
					for(int a=0; a<=3; a++){	// col
						Wab = Wab + (Basic(a, s)*Basic(b, t)) * (Basic(a, s)*Basic(b, t));				
					}
				}
				for(int l=0; l<=3; l++){		// row
					for(int k=0; k<=3; k++){	// col
						W[l][k] = Basic(k, s) * Basic(l, t);
						x_fai[l][k] = (W[l][k] * (out_pt[p].X-in_pt[p].X) ) / Wab;
						y_fai[l][k] = (W[l][k] * (out_pt[p].Y-in_pt[p].Y) ) / Wab;
						itmp = (j+l+1)*latw + (i+k+1);
						cl[itmp].xdel = cl[itmp].xdel + W[l][k] * W[l][k] * x_fai[l][k];
						cl[itmp].ydel = cl[itmp].ydel + W[l][k] * W[l][k] * y_fai[l][k];
						cl[itmp].ome = cl[itmp].ome + W[l][k] * W[l][k];
					}
				}
			}
			// 範囲内のオーバーラップを考慮
			for(int j=0; j<lath; j++){
				for(int i=0; i<latw; i++){
					if(cl[j*latw + i].ome != 0){
						omega = 0;
						for(int l=0; l<=3; l++){		// row
							for(int k=0; k<=3; k++){	// col
								itmp = (j+l-1)*latw + i+k-1;
								if(itmp >= 0 && itmp <= lath*latw){
									cl[j*latw + i].xfai = cl[j*latw + i].xfai + cl[itmp].xdel;
									cl[j*latw + i].yfai = cl[j*latw + i].yfai + cl[itmp].ydel;
									omega = omega + cl[itmp].ome;
								}
							}
						}
						cl[j*latw + i].xfai = (cl[j*latw + i].xfai / omega);
						cl[j*latw + i].yfai = (cl[j*latw + i].yfai / omega);
					}
					else{
						cl[j*latw + i].xfai = 0;
						cl[j*latw + i].yfai = 0;
					}
				}
			}
		}
		//-- 変形画像の出力 --//
		void InvBSplineOutput(int frameNum) {
			double x, y;
			for(int j=0; j<iHeight; j++){
				for(int i=0; i<iWidth; i++){
					inw = i/latbw;
					inh = j/latbw;
					x_dtmp = i%latbw;
					y_dtmp = j%latbw;
					s = (double)x_dtmp / (double)latbw;
					t = (double)y_dtmp / (double)latbw;
					fx = 0, fy = 0;
					for(int l=0; l<=3; l++){		// row
						for(int k=0; k<=3; k++){	// col
							itmp = (inh+l-1)*latw+(inw+k-1);
							if(itmp > 0 && itmp <= latw*lath){
								fx = fx + Basic(k, s) * Basic(l, t) * 
									(cl[itmp].xfai * ((double)frameNum / (double)transform_frame));
								fy = fy + Basic(k, s) * Basic(l, t) * 
									(cl[itmp].yfai * ((double)frameNum / (double)transform_frame));
							}
						}
					}
					// 補間 + 結果画像へ出力
					x = i+fx, y = j+fy;
					if(NNBtn->Checked == true){
						// ニアレストネイバー補間
						if((int)(x+0.5) >= 0 && (int)(x+0.5) < iWidth && (int)(y+0.5) >= 0 && (int)(y+0.5) < iHeight)
							dst_img->SetPixel(i,j, src_morph_img->GetPixel((int)(x+0.5), (int)(y+0.5)));
						else
							dst_img->SetPixel(i,j, Color::Black);
					}
					else{
						// バイリニア補間
						if(x >= 0 && x < iWidth && y >= 0 && y < iHeight)
							InvBilinearInterpolation(x, y, i, j);
						else
							dst_img->SetPixel(i,j, Color::Black);
					}
					ProgressBar->Value = (int)((i+j*iWidth)*100 / (iWidth*iHeight));
				}
			}
		}
		//-- モーフィング --//
		void MorphingProcessing(int frame){
			double in_dmn = (double)frame / (double)transform_frame;
			double dmn = 1 - in_dmn;
			for(int j=0; j<iHeight; j++){
				for(int i=0; i<iWidth; i++){
					Color ^c1 = first_img[frame]->GetPixel(i,j);
					Color ^c2 = second_img[transform_frame-frame]->GetPixel(i,j);
					dst_img->SetPixel(i,j,
						Color::FromArgb( (int)(c1->R*dmn) + (int)(c2->R*in_dmn),
						(int)(c1->G*dmn) + (int)(c2->G*in_dmn), 
						(int)(c1->B*dmn) + (int)(c2->B*in_dmn)));
				}
			}
		}
		//-- バイリニア補間 --//
		void InvBilinearInterpolation(double inx, double iny, int outx, int outy) {
			int bx,by;			// 四捨五入の値
			double tmpX1,tmpX2;	// 一時保存:X
			double tmpY1,tmpY2;	// 一時保存:Y
			double S1,S2,S3,S4;	// 4点

			// 4点カラー
			array<Color ^> ^pixel = gcnew array<Color ^>(4);
			array<String ^> ^ARGB, ^tmpStr;
			double dR[4],dG[4],dB[4];
			int R,G,B;				// 出力RGB

			bx = (int)(inx),	by = (int)(iny);
			tmpX1 = bx+1-inx, tmpY1 = by+1-iny;
			tmpX2 = inx-bx, tmpY2 = iny-by;

			S1 = tmpX2 * tmpY1, S2 = tmpX1 * tmpY1;
			S3 = tmpX1 * tmpY2, S4 = tmpX2 * tmpY2;

			// 座標のデータを取得
			if(bx+1 < iWidth && by+1 < iHeight){
				pixel[0] = src_morph_img->GetPixel(bx+1,by);
				pixel[1] = src_morph_img->GetPixel(bx,by);
				pixel[2] = src_morph_img->GetPixel(bx,by+1);
				pixel[3] = src_morph_img->GetPixel(bx+1,by+1);
			}
			else{
				pixel[0] = src_morph_img->GetPixel(bx,by);
				pixel[1] = src_morph_img->GetPixel(bx,by);
				pixel[2] = src_morph_img->GetPixel(bx,by);
				pixel[3] = src_morph_img->GetPixel(bx,by);
			}

			// RGB値の取得
			for(int c=0; c<4; c++){
				tmpStr = pixel[c]->ToString()->Split(L']');
				ARGB = tmpStr[0]->ToString()->Split(L',');
				dR[c] = Convert::ToDouble(ARGB[1]->Substring(3));
				dG[c] = Convert::ToDouble(ARGB[2]->Substring(3));
				dB[c] = Convert::ToDouble(ARGB[3]->Substring(3));
			}

			R = (int)(S1*dR[0] + S2*dR[1] + S3*dR[2] + S4*dR[3] + 0.5);
			G = (int)(S1*dG[0] + S2*dG[1] + S3*dG[2] + S4*dG[3] + 0.5);
			B = (int)(S1*dB[0] + S2*dB[1] + S3*dB[2] + S4*dB[3] + 0.5);
			if(R < 0) R = 0; if(R > 255) R = 255;
			if(G < 0) G = 0; if(G > 255) G = 255;
			if(B < 0) B = 0; if(B > 255) B = 255;

			dst_img->SetPixel(outx, outy, Color::FromArgb(R, G, B));
		}
	};
	// 外部の関数を追加
}


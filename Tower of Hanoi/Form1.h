#pragma once

#include "towerDisplay.h"

namespace TowerofHanoi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			displayForm = gcnew towerDisplay(this);
			// display = gcnew towerDisplay(discsNo, steps, stepsNo, stepsTimer->Checked, t, this);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  noOfDiscs;
	private: System::Windows::Forms::CheckBox^  stepsTimer;
	private: System::Windows::Forms::NumericUpDown^  time;
	private: System::Windows::Forms::ComboBox^  timeType;
	private: System::Windows::Forms::Button^  start;
	private: int discsNo;
	private: int** steps;
	private: int stepsNo;
	private: int stepsTime;
	private: towerDisplay^ displayForm;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->noOfDiscs = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->start = (gcnew System::Windows::Forms::Button());
			this->stepsTimer = (gcnew System::Windows::Forms::CheckBox());
			this->time = (gcnew System::Windows::Forms::NumericUpDown());
			this->timeType = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->noOfDiscs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->time))->BeginInit();
			this->SuspendLayout();
			// 
			// noOfDiscs
			// 
			this->noOfDiscs->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->noOfDiscs->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->noOfDiscs->Location = System::Drawing::Point(185, 47);
			this->noOfDiscs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->noOfDiscs->Name = L"noOfDiscs";
			this->noOfDiscs->Size = System::Drawing::Size(120, 27);
			this->noOfDiscs->TabIndex = 1;
			this->noOfDiscs->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(79, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"No. of Discs:";
			// 
			// start
			// 
			this->start->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->start->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->start->Location = System::Drawing::Point(138, 150);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(108, 30);
			this->start->TabIndex = 5;
			this->start->Text = L"&Start";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &Form1::start_Click);
			// 
			// stepsTimer
			// 
			this->stepsTimer->AutoSize = true;
			this->stepsTimer->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->stepsTimer->Location = System::Drawing::Point(22, 97);
			this->stepsTimer->Name = L"stepsTimer";
			this->stepsTimer->Size = System::Drawing::Size(111, 23);
			this->stepsTimer->TabIndex = 2;
			this->stepsTimer->Text = L"Steps Timer";
			this->stepsTimer->UseVisualStyleBackColor = true;
			this->stepsTimer->CheckedChanged += gcnew System::EventHandler(this, &Form1::stepsTimer_CheckedChanged);
			// 
			// time
			// 
			this->time->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->time->Enabled = false;
			this->time->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->time->Location = System::Drawing::Point(139, 96);
			this->time->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {25000, 0, 0, 0});
			this->time->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(97, 27);
			this->time->TabIndex = 3;
			this->time->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// timeType
			// 
			this->timeType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->timeType->Enabled = false;
			this->timeType->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->timeType->FormattingEnabled = true;
			this->timeType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Second(s)", L"Millisecond(s)"});
			this->timeType->Location = System::Drawing::Point(242, 95);
			this->timeType->Name = L"timeType";
			this->timeType->Size = System::Drawing::Size(121, 27);
			this->timeType->TabIndex = 4;
			this->timeType->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::timeType_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AcceptButton = this->start;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 211);
			this->Controls->Add(this->timeType);
			this->Controls->Add(this->time);
			this->Controls->Add(this->stepsTimer);
			this->Controls->Add(this->start);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->noOfDiscs);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Tower of Hanoi";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->noOfDiscs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->time))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: void hanoi(int noOfDiscs, int a, int b, int c)
		{
			if (noOfDiscs > 0)
			{
				hanoi(noOfDiscs - 1, a, c, b);
				steps[stepsNo][0] = a;
				steps[stepsNo][1] = c;
				stepsNo++;
				hanoi(noOfDiscs - 1, b, a, c);
			}
		}

		private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) {
			discsNo = Convert::ToInt32(noOfDiscs->Value);
			stepsNo = 0;

			for (int x = 0; x < discsNo; x++)
				stepsNo = stepsNo * 2 + 1;

			steps = new int*[stepsNo];
			for (int x = 0; x < stepsNo; x++)
				steps[x] = new int[2];

			stepsNo = 0;
			hanoi(discsNo, 0, 1, 2);

			stepsTime = System::Convert::ToInt32(time->Text);
			if (timeType->SelectedIndex == 0)
				stepsTime *= 1000;

			displayForm->discsNo = discsNo;
			displayForm->steps = steps;
			displayForm->stepsNo = stepsNo;
			displayForm->stepsTimer = stepsTimer->Checked;
			displayForm->time = stepsTime;
			displayForm->towerDisplayShow();
			this->Hide();
		}

		private: System::Void stepsTimer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (stepsTimer->Checked) {
				time->Enabled = true;
				timeType->Enabled = true;
			} else {
				time->Enabled = false;
				timeType->Enabled = false;
			}
		}

		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			timeType->SelectedIndex = 0;
		}

		private: System::Void timeType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (timeType->SelectedIndex == 0) {
				time->Minimum = 1;
				time->Text = System::Convert::ToString(System::Convert::ToInt32(time->Text) / 1000);
				time->Maximum = 250;
			} else {
				time->Maximum = 25000;
				time->Text = System::Convert::ToString(System::Convert::ToInt32(time->Text) * 1000);
				time->Minimum = 1;
			}

		}
	};
}


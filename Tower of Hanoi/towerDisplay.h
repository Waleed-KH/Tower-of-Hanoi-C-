#pragma once

#include "stack.h"

System::String^ OrdinalNo(int n)
{
	int hunhundredRem = n % 100;
	int tenRem = n % 10;

	if (hunhundredRem >= 11 && hunhundredRem <= 13)
		return n + "th";

	switch (tenRem)
	{
	case 1:
		return n + "st";
	case 2:
		return n + "nd";
	case 3:
		return n + "rd";
	default:
		return n + "th";
	}
}

#include "tower.h"

namespace TowerofHanoi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for towerDisplay
	/// </summary>
	public ref class towerDisplay : public System::Windows::Forms::Form
	{
	public:
		towerDisplay(Form^ cf)
		{
			controlForm = cf;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~towerDisplay()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Form^ controlForm;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RichTextBox^  result;
	private: System::Windows::Forms::RichTextBox^  tower1;
	private: System::Windows::Forms::RichTextBox^  tower2;
	private: System::Windows::Forms::RichTextBox^  tower3;
	private: System::Windows::Forms::Button^  newSession;
	private: System::Windows::Forms::Button^  next;
	private: System::Windows::Forms::Button^  start;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  noOfDiscs;
	private: System::Windows::Forms::Label^  stepsLabel;
	private: System::ComponentModel::IContainer^  components;
	private: tower* t;
	private: int step;
	internal: int discsNo;
	internal: int** steps;
	internal: int stepsNo;
	internal: bool stepsTimer;
	internal: int time;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->result = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tower1 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tower2 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tower3 = (gcnew System::Windows::Forms::RichTextBox());
			this->newSession = (gcnew System::Windows::Forms::Button());
			this->next = (gcnew System::Windows::Forms::Button());
			this->start = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->noOfDiscs = (gcnew System::Windows::Forms::Label());
			this->stepsLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->result);
			this->groupBox1->Location = System::Drawing::Point(12, 263);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(860, 175);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Result:";
			// 
			// result
			// 
			this->result->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->result->BackColor = System::Drawing::SystemColors::Control;
			this->result->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->result->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->result->Location = System::Drawing::Point(6, 19);
			this->result->Name = L"result";
			this->result->ReadOnly = true;
			this->result->Size = System::Drawing::Size(848, 150);
			this->result->TabIndex = 3;
			this->result->Text = L"";
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox2->Controls->Add(this->tower1);
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(280, 245);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Tower A:";
			// 
			// tower1
			// 
			this->tower1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tower1->BackColor = System::Drawing::SystemColors::Control;
			this->tower1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tower1->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tower1->Location = System::Drawing::Point(6, 19);
			this->tower1->Name = L"tower1";
			this->tower1->ReadOnly = true;
			this->tower1->Size = System::Drawing::Size(268, 220);
			this->tower1->TabIndex = 0;
			this->tower1->Text = L"";
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox3->Controls->Add(this->tower2);
			this->groupBox3->Location = System::Drawing::Point(302, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(280, 245);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Tower B:";
			// 
			// tower2
			// 
			this->tower2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tower2->BackColor = System::Drawing::SystemColors::Control;
			this->tower2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tower2->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tower2->Location = System::Drawing::Point(6, 19);
			this->tower2->Name = L"tower2";
			this->tower2->ReadOnly = true;
			this->tower2->Size = System::Drawing::Size(268, 220);
			this->tower2->TabIndex = 1;
			this->tower2->Text = L"";
			// 
			// groupBox4
			// 
			this->groupBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox4->Controls->Add(this->tower3);
			this->groupBox4->Location = System::Drawing::Point(592, 12);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(280, 245);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Tower C:";
			// 
			// tower3
			// 
			this->tower3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tower3->BackColor = System::Drawing::SystemColors::Control;
			this->tower3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tower3->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tower3->Location = System::Drawing::Point(6, 19);
			this->tower3->Name = L"tower3";
			this->tower3->ReadOnly = true;
			this->tower3->Size = System::Drawing::Size(268, 220);
			this->tower3->TabIndex = 2;
			this->tower3->Text = L"";
			// 
			// newSession
			// 
			this->newSession->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->newSession->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->newSession->Location = System::Drawing::Point(12, 461);
			this->newSession->Name = L"newSession";
			this->newSession->Size = System::Drawing::Size(114, 30);
			this->newSession->TabIndex = 4;
			this->newSession->Text = L"N&ew Session";
			this->newSession->UseVisualStyleBackColor = true;
			this->newSession->Click += gcnew System::EventHandler(this, &towerDisplay::newSession_Click);
			// 
			// next
			// 
			this->next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->next->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->next->Location = System::Drawing::Point(764, 461);
			this->next->Name = L"next";
			this->next->Size = System::Drawing::Size(108, 30);
			this->next->TabIndex = 7;
			this->next->Text = L"&Next >";
			this->next->UseVisualStyleBackColor = true;
			this->next->Click += gcnew System::EventHandler(this, &towerDisplay::next_Click);
			// 
			// start
			// 
			this->start->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->start->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->start->Location = System::Drawing::Point(764, 461);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(108, 30);
			this->start->TabIndex = 7;
			this->start->Text = L"&Start";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &towerDisplay::start_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &towerDisplay::timer1_Tick);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(132, 467);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 19);
			this->label1->TabIndex = 5;
			this->label1->Text = L"No. of Discs:";
			// 
			// noOfDiscs
			// 
			this->noOfDiscs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->noOfDiscs->AutoSize = true;
			this->noOfDiscs->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->noOfDiscs->Location = System::Drawing::Point(232, 467);
			this->noOfDiscs->Name = L"noOfDiscs";
			this->noOfDiscs->Size = System::Drawing::Size(0, 19);
			this->noOfDiscs->TabIndex = 5;
			// 
			// stepsLabel
			// 
			this->stepsLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->stepsLabel->AutoSize = true;
			this->stepsLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->stepsLabel->Location = System::Drawing::Point(373, 467);
			this->stepsLabel->Name = L"stepsLabel";
			this->stepsLabel->Size = System::Drawing::Size(0, 19);
			this->stepsLabel->TabIndex = 6;
			this->stepsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// towerDisplay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 511);
			this->Controls->Add(this->start);
			this->Controls->Add(this->newSession);
			this->Controls->Add(this->stepsLabel);
			this->Controls->Add(this->noOfDiscs);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->next);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"towerDisplay";
			this->Text = L"Tower of Hanoi";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &towerDisplay::towerDisplay_FormClosing);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		internal: void towerDisplayShow() {
			this->Show();
			result->Text = "";
			step = 0;

			if (stepsTimer) {
				timer1->Interval = time;
				next->Visible = false;
				start->Visible = true;
				start->Enabled = true;
				AcceptButton = start;
			} else {
				next->Visible = true;
				next->Enabled = true;
				start->Visible = false;
				AcceptButton = next;
			}

			t = new tower[3];
			t[0] = tower(discsNo, discsNo, 'A');
			t[1] = tower(0, discsNo, 'B');
			t[2] = tower(0, discsNo, 'C');

			tower1->Text = t[0].display();
			tower2->Text = t[1].display();
			tower3->Text = t[2].display();

			noOfDiscs->Text = System::Convert::ToString(discsNo);
			stepsLabel->Text = "Step 0 of " + stepsNo;
		}

		private: void nextStep() {
			result->Text += t[steps[step][0]].move(t[steps[step][1]]) + "\n";
			tower1->Text = t[0].display();
			tower2->Text = t[1].display();
			tower3->Text = t[2].display();

			step++;
			stepsLabel->Text = "Step " + step + " of " + stepsNo;
		}

		private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e) {
			nextStep();
			if (step == stepsNo) {
				next->Enabled = false;
				MessageBox::Show("Done.. The Discs has moved from Tower A to Tower C.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

		private: System::Void towerDisplay_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			Application::Exit();
		}

		private: System::Void newSession_Click(System::Object^  sender, System::EventArgs^  e) {
			controlForm->Show();
			timer1->Enabled = false;
			this->Hide();
		}

		private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) {
			start->Enabled = false;
			timer1->Enabled = true;
		}

		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			nextStep();
			if (step == stepsNo) {
				timer1->Enabled = false;
				MessageBox::Show("Done.. The Discs has moved from Tower A to Tower C.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
	};
}

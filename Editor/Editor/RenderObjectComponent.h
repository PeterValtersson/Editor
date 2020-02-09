#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {

	/// <summary>
	/// Summary for RenderObjectComponent
	/// </summary>
	public ref class RenderObjectComponent : public System::Windows::Forms::UserControl
	{
	public:
		RenderObjectComponent(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RenderObjectComponent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox2;

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
			this->groupBox1 = ( gcnew System::Windows::Forms::GroupBox() );
			this->comboBox1 = ( gcnew System::Windows::Forms::ComboBox() );
			this->groupBox2 = ( gcnew System::Windows::Forms::GroupBox() );
			this->comboBox2 = ( gcnew System::Windows::Forms::ComboBox() );
			this->label1 = ( gcnew System::Windows::Forms::Label() );
			this->flowLayoutPanel1 = ( gcnew System::Windows::Forms::FlowLayoutPanel() );
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add( this->comboBox1 );
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point( 0, 0 );
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size( 250, 96 );
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Mesh";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point( 7, 18 );
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size( 150, 21 );
			this->comboBox1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add( this->flowLayoutPanel1 );
			this->groupBox2->Controls->Add( this->label1 );
			this->groupBox2->Controls->Add( this->comboBox2 );
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Location = System::Drawing::Point( 0, 96 );
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size( 250, 346 );
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Material";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point( 54, 17 );
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size( 184, 21 );
			this->comboBox2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point( 7, 20 );
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size( 41, 13 );
			this->label1->TabIndex = 1;
			this->label1->Text = L"Shader";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point( 0, 44 );
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size( 244, 100 );
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// RenderObjectComponent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->groupBox2 );
			this->Controls->Add( this->groupBox1 );
			this->Name = L"RenderObjectComponent";
			this->Size = System::Drawing::Size( 250, 626 );
			this->groupBox1->ResumeLayout( false );
			this->groupBox2->ResumeLayout( false );
			this->groupBox2->PerformLayout();
			this->ResumeLayout( false );

		}
#pragma endregion
	};
}

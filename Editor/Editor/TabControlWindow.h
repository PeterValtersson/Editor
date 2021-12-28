#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor
{

/// <summary>
/// Summary for TabControlWindow
/// </summary>
	public ref class TabControlWindow : public System::Windows::Forms::UserControl{
	public:

		System::Windows::Forms::MenuItem^ tabText2;
		TabControlWindow( void )
		{
			InitializeComponent();
		}
		property System::Windows::Forms::MenuStrip^ menu
		{
			System::Windows::Forms::MenuStrip^ get()
			{
				return menuStrip1;
			}
		}
		property System::Windows::Forms::TabControl^ tabs
		{
			System::Windows::Forms::TabControl^ get()
			{
				return tabControl1;
			}
		}
		void hide_tabs( bool hide );
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TabControlWindow()
		{
			if ( components )
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ tabText;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ aToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent( void )
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TabControlWindow::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->tabText = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tabText, this->aToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(387, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// tabText
			// 
			this->tabText->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tabText->ForeColor = System::Drawing::Color::White;
			this->tabText->Name = L"tabText";
			this->tabText->Size = System::Drawing::Size(39, 20);
			this->tabText->Text = L"Test";
			// 
			// aToolStripMenuItem
			// 
			this->aToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->aToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aToolStripMenuItem.Image")));
			this->aToolStripMenuItem->Name = L"aToolStripMenuItem";
			this->aToolStripMenuItem->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->aToolStripMenuItem->Size = System::Drawing::Size(28, 20);
			// 
			// tabControl1
			// 
			this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(387, 553);
			this->tabControl1->TabIndex = 1;
			this->tabControl1->TabIndexChanged += gcnew System::EventHandler(this, &TabControlWindow::tabControl1_TabIndexChanged);
			this->tabControl1->ControlAdded += gcnew System::Windows::Forms::ControlEventHandler(this, &TabControlWindow::tabControl1_ControlAdded);
			// 
			// TabControlWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"TabControlWindow";
			this->Size = System::Drawing::Size(387, 577);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tabControl1_TabIndexChanged( System::Object^ sender, System::EventArgs^ e );
	private: System::Void tabControl1_ControlAdded( System::Object^ sender, System::Windows::Forms::ControlEventArgs^ e );

	};
}

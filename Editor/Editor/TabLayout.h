#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {

	/// <summary>
	/// Summary for TabLayout
	/// </summary>
	public ref class TabLayout : public System::Windows::Forms::UserControl
	{
	public:
		TabLayout(void)
		{
			InitializeComponent();
		

			content_tabs = gcnew Generic::List<Control^>();
		}


		void add_view(Control^ control);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TabLayout()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ content_panel;

	private: System::Windows::Forms::FlowLayoutPanel^ tab_list;
	protected:

	private:
		Generic::List<Control^>^ content_tabs;
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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->content_panel = (gcnew System::Windows::Forms::Panel());
			this->tab_list = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->content_panel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tab_list, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 125)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(150, 150);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// content_panel
			// 
			this->content_panel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->content_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->content_panel->Location = System::Drawing::Point(0, 0);
			this->content_panel->Margin = System::Windows::Forms::Padding(0);
			this->content_panel->Name = L"content_panel";
			this->content_panel->Size = System::Drawing::Size(150, 125);
			this->content_panel->TabIndex = 0;
			// 
			// tab_list
			// 
			this->tab_list->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tab_list->Location = System::Drawing::Point(0, 125);
			this->tab_list->Margin = System::Windows::Forms::Padding(0);
			this->tab_list->Name = L"tab_list";
			this->tab_list->Size = System::Drawing::Size(150, 25);
			this->tab_list->TabIndex = 1;
			// 
			// TabLayout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"TabLayout";
			this->Resize += gcnew System::EventHandler(this, &TabLayout::TabLayout_Resize);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TabLayout_Resize(System::Object^ sender, System::EventArgs^ e);
		   void on_tab_button_click(System::Object^ sender, System::EventArgs^ e);
	};
}

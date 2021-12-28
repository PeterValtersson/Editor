#pragma once

#include "Events.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {
	/// <summary>
	/// Summary for AddComponentDialog
	/// </summary>
	public ref class AddComponentDialog : public System::Windows::Forms::UserControl
	{
	private:
		ref class Btn : public Button
		{
		public:
			std::shared_ptr<ECS::ComponentReflection>* component_ptr;
			Btn(std::shared_ptr<ECS::ComponentReflection> component)
			{
				Anchor = AnchorStyles::Left | AnchorStyles::Right;
				Size = Drawing::Size(100, 25);
				Text = gcnew String(component->get_name().c_str());
				Visible = true;
				component_ptr = new std::shared_ptr<ECS::ComponentReflection>(component);
			}
			~Btn()
			{
				delete component_ptr;
			}
		};
	public:
		AddComponentDialog()
		{
			InitializeComponent();
			
		}
		void clear_components()
		{
			component_list->Controls->Clear();
		}
		void add_component(std::shared_ptr<ECS::ComponentReflection> component)
		{
			auto btn = gcnew Btn(component);
			btn->Click += gcnew System::EventHandler(this, &Editor::AddComponentDialog::OnClick);
			component_list->Controls->Add(btn);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddComponentDialog()
		{
			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ component_panel;
	private: System::Windows::Forms::FlowLayoutPanel^ component_list;



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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->component_panel = (gcnew System::Windows::Forms::Panel());
			this->component_list = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->component_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->component_panel, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(411, 449);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(405, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Component";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// component_panel
			// 
			this->component_panel->Controls->Add(this->component_list);
			this->component_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->component_panel->Location = System::Drawing::Point(3, 78);
			this->component_panel->Name = L"component_panel";
			this->component_panel->Size = System::Drawing::Size(405, 368);
			this->component_panel->TabIndex = 1;
			// 
			// component_list
			// 
			this->component_list->BackColor = System::Drawing::SystemColors::ControlDark;
			this->component_list->Dock = System::Windows::Forms::DockStyle::Fill;
			this->component_list->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->component_list->Location = System::Drawing::Point(0, 0);
			this->component_list->Name = L"component_list";
			this->component_list->Size = System::Drawing::Size(405, 368);
			this->component_list->TabIndex = 0;
			// 
			// AddComponentDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AddComponentDialog";
			this->Size = System::Drawing::Size(411, 449);
			this->Leave += gcnew System::EventHandler(this, &AddComponentDialog::AddComponentDialog_Leave);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->component_panel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		void OnClick(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddComponentDialog_Leave(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	
}
};
}

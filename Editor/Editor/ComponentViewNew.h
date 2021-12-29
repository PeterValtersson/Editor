#pragma once
#include "Events.h"
#include "ComponentList.h"
#include "AddComponentDialog.h"
#include "PoperContainer.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Editor {

	/// <summary>
	/// Summary for ComponentViewNew
	/// </summary>
	public ref class ComponentViewNew : public System::Windows::Forms::UserControl
	{
	public:
		ComponentViewNew(EnginePtr* engine) : engine(engine)
		{
			InitializeComponent();
			add_component_dialog = gcnew AddComponentDialog();
			add_component_poper = gcnew PoperContainer(add_component_dialog);

			EditorEvents::on_selected_entity_changed += gcnew decltype(EditorEvents::on_selected_entity_changed)::Handler(this, &ComponentViewNew::set_entity);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentViewNew()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ component_list_panel;
	private: System::Windows::Forms::Button^ add_component;
	protected:


	private:
		EnginePtr* engine;
		ComponentList^ component_list;
		AddComponentDialog^ add_component_dialog;
		PoperContainer^ add_component_poper;

		void set_entity(Entity entity);

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
			this->component_list_panel = (gcnew System::Windows::Forms::Panel());
			this->add_component = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->component_list_panel, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->add_component, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 47)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(430, 680);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// component_list_panel
			// 
			this->component_list_panel->Location = System::Drawing::Point(0, 47);
			this->component_list_panel->Margin = System::Windows::Forms::Padding(0);
			this->component_list_panel->Name = L"component_list_panel";
			this->component_list_panel->Size = System::Drawing::Size(0, 0);
			this->component_list_panel->TabIndex = 0;
			// 
			// add_component
			// 
			this->add_component->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->add_component->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->add_component->Location = System::Drawing::Point(40, 50);
			this->add_component->Margin = System::Windows::Forms::Padding(40, 3, 40, 3);
			this->add_component->Name = L"add_component";
			this->add_component->Size = System::Drawing::Size(350, 23);
			this->add_component->TabIndex = 1;
			this->add_component->Text = L"Add Component";
			this->add_component->UseVisualStyleBackColor = true;
			this->add_component->Click += gcnew System::EventHandler(this, &ComponentViewNew::add_component_Click);
			// 
			// ComponentViewNew
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"ComponentViewNew";
			this->Size = System::Drawing::Size(430, 680);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void add_component_Click(System::Object^ sender, System::EventArgs^ e);
};
}


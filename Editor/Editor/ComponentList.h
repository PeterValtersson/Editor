#pragma once
#include "EnginePtr.h"
#include "ComponentDecorator.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {

	/// <summary>
	/// Summary for ComponentList
	/// </summary>
	public ref class ComponentList : public System::Windows::Forms::UserControl
	{
	public:
		ComponentList()
		{
			InitializeComponent();

		}

		void add_component(Control^ component_control)
		{
			auto deco = gcnew ComponentDecorator(component_control);
			deco->Anchor = AnchorStyles::Left | AnchorStyles::Right;
			component_list->Controls->Add(deco);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ component_list;
	private: System::Windows::Forms::Button^ button1;

	protected:

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
			this->component_list = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->component_list->SuspendLayout();
			this->SuspendLayout();
			// 
			// component_list
			// 
			this->component_list->AutoSize = true;
			this->component_list->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->component_list->BackColor = System::Drawing::SystemColors::ControlDark;
			this->component_list->Controls->Add(this->button1);
			this->component_list->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->component_list->Location = System::Drawing::Point(0, 0);
			this->component_list->Name = L"component_list";
			this->component_list->Size = System::Drawing::Size(81, 29);
			this->component_list->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// ComponentList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Controls->Add(this->component_list);
			this->Name = L"ComponentList";
			this->Size = System::Drawing::Size(84, 32);
			this->component_list->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {

	/// <summary>
	/// Summary for ComponentDecorator
	/// </summary>
	public ref class ComponentDecorator : public System::Windows::Forms::UserControl
	{
	public:
		ComponentDecorator(Control^ component_content_control)
		{
			InitializeComponent();
			component_content->Controls->Add(component_content_control);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentDecorator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ collapse;
	private: System::Windows::Forms::ToolStripMenuItem^ expand;
	private: System::Windows::Forms::ToolStripMenuItem^ remove;
	private: System::Windows::Forms::Panel^ component_content;
	private: System::Windows::Forms::ToolStripMenuItem^ name;

	protected:

	protected:


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
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ComponentDecorator::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->collapse = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->expand = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->remove = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->name = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->component_content = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->collapse, this->expand,
					this->remove, this->name
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(0, 24);
			this->menuStrip1->TabIndex = 0;
			// 
			// collapse
			// 
			this->collapse->ForeColor = System::Drawing::SystemColors::ControlText;
			this->collapse->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"collapse.Image")));
			this->collapse->Name = L"collapse";
			this->collapse->Size = System::Drawing::Size(28, 20);
			this->collapse->ToolTipText = L"Collapse";
			this->collapse->Click += gcnew System::EventHandler(this, &ComponentDecorator::collapse_Click);
			// 
			// expand
			// 
			this->expand->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"expand.Image")));
			this->expand->Name = L"expand";
			this->expand->Size = System::Drawing::Size(28, 20);
			this->expand->Visible = false;
			this->expand->Click += gcnew System::EventHandler(this, &ComponentDecorator::expand_Click);
			// 
			// remove
			// 
			this->remove->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->remove->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"remove.Image")));
			this->remove->Name = L"remove";
			this->remove->Size = System::Drawing::Size(28, 20);
			// 
			// name
			// 
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(51, 20);
			this->name->Text = L"Name";
			// 
			// component_content
			// 
			this->component_content->AutoSize = true;
			this->component_content->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->component_content->Dock = System::Windows::Forms::DockStyle::Fill;
			this->component_content->Location = System::Drawing::Point(0, 24);
			this->component_content->Name = L"component_content";
			this->component_content->Size = System::Drawing::Size(0, 0);
			this->component_content->TabIndex = 1;
			// 
			// ComponentDecorator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Controls->Add(this->component_content);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"ComponentDecorator";
			this->Size = System::Drawing::Size(0, 24);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void collapse_Click(System::Object^ sender, System::EventArgs^ e) {
		collapse->Visible = false;
		expand->Visible = true;
		component_content->Visible = false;
	}
	private: System::Void expand_Click(System::Object^ sender, System::EventArgs^ e) {
		collapse->Visible = true;
		expand->Visible = false;
		component_content->Visible = true;
	}
	};
}

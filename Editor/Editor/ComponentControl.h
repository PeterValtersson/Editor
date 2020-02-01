#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {

	public delegate void ComponenetSelected( Control^ component );

	/// <summary>
	/// Summary for ComponentControl
	/// </summary>
	public ref class ComponentControl : public System::Windows::Forms::UserControl
	{
	private:
		ComponenetSelected^ selected_callback;
	private: System::Windows::Forms::GroupBox^ groupBox1;
		   Control^ component;
	public:
		ComponentControl( ComponenetSelected^ selected_callback, Control^ component )
		{
			InitializeComponent();
			this->selected_callback = selected_callback;
			this->component = component;
			this->Click += gcnew System::EventHandler( this, &ComponentControl::clicked );
			this->groupBox1->Click += gcnew System::EventHandler( this, &ComponentControl::clicked );
			this->groupBox1->Text = component->Text;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentControl()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ removeBtn;
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
			this->removeBtn = ( gcnew System::Windows::Forms::Button() );
			this->groupBox1 = ( gcnew System::Windows::Forms::GroupBox() );
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// removeBtn
			// 
			this->removeBtn->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast< System::Byte >( 0 ) ) );
			this->removeBtn->Location = System::Drawing::Point( 3, 46 );
			this->removeBtn->Name = L"removeBtn";
			this->removeBtn->Size = System::Drawing::Size( 144, 23 );
			this->removeBtn->TabIndex = 1;
			this->removeBtn->Text = L"Remove";
			this->removeBtn->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add( this->removeBtn );
			this->groupBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox1->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																   static_cast< System::Byte >( 0 ) ) );
			this->groupBox1->Location = System::Drawing::Point( 0, 0 );
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size( 150, 75 );
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Component";
			// 
			// ComponentControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->groupBox1 );
			this->Name = L"ComponentControl";
			this->Size = System::Drawing::Size( 150, 75 );
			this->groupBox1->ResumeLayout( false );
			this->ResumeLayout( false );

		}
#pragma endregion
	private: System::Void clicked( System::Object^ sender, System::EventArgs^ e );
	};
}

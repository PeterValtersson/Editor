#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor
{
	public delegate void AddComponentCallback( Control^ component );

	/// <summary>
	/// Summary for AddNewComponent
	/// </summary>
	public ref class AddNewComponent : public System::Windows::Forms::UserControl {
	private:
		AddComponentCallback^ add_callback;
	public:
		AddNewComponent( AddComponentCallback^ add_callback ) : add_callback( add_callback )
		{
			InitializeComponent();
		}
		property ComboBox::ObjectCollection^ Components
		{
			ComboBox::ObjectCollection^ get()
			{
				return cmbComponents->Items;
			}
		}
		property String^ Text
		{
			String^ get()override
			{
				return groupBox1->Text;
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddNewComponent()
		{
			if ( components )
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cmbComponents;
	protected:

	protected:
	private: System::Windows::Forms::Button^ AddBtn;
	private: System::Windows::Forms::GroupBox^ groupBox1;

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
		void InitializeComponent( void )
		{
			this->cmbComponents = ( gcnew System::Windows::Forms::ComboBox() );
			this->AddBtn = ( gcnew System::Windows::Forms::Button() );
			this->groupBox1 = ( gcnew System::Windows::Forms::GroupBox() );
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// cmbComponents
			// 
			this->cmbComponents->Dock = System::Windows::Forms::DockStyle::Top;
			this->cmbComponents->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbComponents->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	   static_cast< System::Byte >( 0 ) ) );
			this->cmbComponents->Location = System::Drawing::Point( 3, 19 );
			this->cmbComponents->Name = L"cmbComponents";
			this->cmbComponents->Size = System::Drawing::Size( 144, 21 );
			this->cmbComponents->TabIndex = 0;
			// 
			// AddBtn
			// 
			this->AddBtn->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->AddBtn->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																static_cast< System::Byte >( 0 ) ) );
			this->AddBtn->Location = System::Drawing::Point( 3, 49 );
			this->AddBtn->Name = L"AddBtn";
			this->AddBtn->Size = System::Drawing::Size( 144, 23 );
			this->AddBtn->TabIndex = 1;
			this->AddBtn->Text = L"Add";
			this->AddBtn->UseVisualStyleBackColor = true;
			this->AddBtn->Click += gcnew System::EventHandler( this, &AddNewComponent::AddBtn_Click );
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add( this->cmbComponents );
			this->groupBox1->Controls->Add( this->AddBtn );
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																   static_cast< System::Byte >( 0 ) ) );
			this->groupBox1->Location = System::Drawing::Point( 0, 0 );
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size( 150, 75 );
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"New Component";
			// 
			// AddNewComponent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->groupBox1 );
			this->Name = L"AddNewComponent";
			this->Size = System::Drawing::Size( 150, 75 );
			this->groupBox1->ResumeLayout( false );
			this->ResumeLayout( false );

		}
#pragma endregion
	private: System::Void AddBtn_Click( System::Object^ sender, System::EventArgs^ e );
	};
}

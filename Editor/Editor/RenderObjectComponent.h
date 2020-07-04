#pragma once

#include "BaseComponent.h"
#include "EnginePtr.h"
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
	private:
		EnginePtr* engine;
		Entity entity;
	public:
		RenderObjectComponent( EnginePtr* engine, Entity entity )
		{
			InitializeComponent();

			this->engine = engine;
			this->entity = entity;
			this->Text = "Transform";
			Dock = DockStyle::Fill;
		}

		String^ ToString()override
		{
			return Text;
		}
		virtual void Create();
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
	private: System::Windows::Forms::ComboBox^ shaderDD;
	protected:






	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ meshDD;


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
			this->label2 = ( gcnew System::Windows::Forms::Label() );
			this->shaderDD = ( gcnew System::Windows::Forms::ComboBox() );
			this->label3 = ( gcnew System::Windows::Forms::Label() );
			this->meshDD = ( gcnew System::Windows::Forms::ComboBox() );
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add( this->label3 );
			this->groupBox1->Controls->Add( this->meshDD );
			this->groupBox1->Controls->Add( this->label2 );
			this->groupBox1->Controls->Add( this->shaderDD );
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Location = System::Drawing::Point( 0, 0 );
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size( 250, 96 );
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Mesh";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point( 7, 32 );
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size( 41, 13 );
			this->label2->TabIndex = 2;
			this->label2->Text = L"Shader";
			this->label2->Click += gcnew System::EventHandler( this, &RenderObjectComponent::label2_Click );
			// 
			// shaderDD
			// 
			this->shaderDD->FormattingEnabled = true;
			this->shaderDD->Location = System::Drawing::Point( 75, 29 );
			this->shaderDD->Name = L"shaderDD";
			this->shaderDD->Size = System::Drawing::Size( 169, 21 );
			this->shaderDD->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point( 7, 59 );
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size( 33, 13 );
			this->label3->TabIndex = 4;
			this->label3->Text = L"Mesh";
			// 
			// meshDD
			// 
			this->meshDD->FormattingEnabled = true;
			this->meshDD->Location = System::Drawing::Point( 75, 56 );
			this->meshDD->Name = L"meshDD";
			this->meshDD->Size = System::Drawing::Size( 169, 21 );
			this->meshDD->TabIndex = 3;
			// 
			// RenderObjectComponent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->groupBox1 );
			this->Name = L"RenderObjectComponent";
			this->Size = System::Drawing::Size( 250, 105 );
			this->groupBox1->ResumeLayout( false );
			this->groupBox1->PerformLayout();
			this->ResumeLayout( false );

		}
#pragma endregion
private: System::Void label2_Click( System::Object^ sender, System::EventArgs^ e )
{}
};
}

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
	/// Summary for TransformComponent
	/// </summary>
	public ref class TransformComponent : public System::Windows::Forms::UserControl, public BaseComponent
	{
	private:
		EnginePtr* engine;
		Entity entity;
	private: System::Windows::Forms::GroupBox^ rotationGroup;
	private: System::Windows::Forms::MaskedTextBox^ rotZ;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::MaskedTextBox^ rotY;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::MaskedTextBox^ rotX;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ scaleGroup;
	private: System::Windows::Forms::MaskedTextBox^ scaleZ;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::MaskedTextBox^ scaleY;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::MaskedTextBox^ scaleX;
	private: System::Windows::Forms::Label^ label9;
	public:
		TransformComponent( EnginePtr* engine, Entity entity)
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
		~TransformComponent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ positionGroup;








	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MaskedTextBox^ posZ;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::MaskedTextBox^ posY;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::MaskedTextBox^ posX;
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
			this->positionGroup = ( gcnew System::Windows::Forms::GroupBox() );
			this->posZ = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label3 = ( gcnew System::Windows::Forms::Label() );
			this->posY = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label2 = ( gcnew System::Windows::Forms::Label() );
			this->posX = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label1 = ( gcnew System::Windows::Forms::Label() );
			this->rotationGroup = ( gcnew System::Windows::Forms::GroupBox() );
			this->rotZ = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label4 = ( gcnew System::Windows::Forms::Label() );
			this->rotY = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label5 = ( gcnew System::Windows::Forms::Label() );
			this->rotX = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label6 = ( gcnew System::Windows::Forms::Label() );
			this->scaleGroup = ( gcnew System::Windows::Forms::GroupBox() );
			this->scaleZ = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label7 = ( gcnew System::Windows::Forms::Label() );
			this->scaleY = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label8 = ( gcnew System::Windows::Forms::Label() );
			this->scaleX = ( gcnew System::Windows::Forms::MaskedTextBox() );
			this->label9 = ( gcnew System::Windows::Forms::Label() );
			this->positionGroup->SuspendLayout();
			this->rotationGroup->SuspendLayout();
			this->scaleGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// positionGroup
			// 
			this->positionGroup->Controls->Add( this->posZ );
			this->positionGroup->Controls->Add( this->label3 );
			this->positionGroup->Controls->Add( this->posY );
			this->positionGroup->Controls->Add( this->label2 );
			this->positionGroup->Controls->Add( this->posX );
			this->positionGroup->Controls->Add( this->label1 );
			this->positionGroup->Location = System::Drawing::Point( 3, 3 );
			this->positionGroup->Name = L"positionGroup";
			this->positionGroup->Size = System::Drawing::Size( 244, 83 );
			this->positionGroup->TabIndex = 0;
			this->positionGroup->TabStop = false;
			this->positionGroup->Text = L"Position";
			// 
			// posZ
			// 
			this->posZ->Location = System::Drawing::Point( 155, 45 );
			this->posZ->Mask = L"#999.999";
			this->posZ->Name = L"posZ";
			this->posZ->Size = System::Drawing::Size( 55, 20 );
			this->posZ->TabIndex = 10;
			this->posZ->TextChanged += gcnew System::EventHandler( this, &TransformComponent::posChanged );
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point( 155, 29 );
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size( 14, 13 );
			this->label3->TabIndex = 9;
			this->label3->Text = L"Z";
			// 
			// posY
			// 
			this->posY->Location = System::Drawing::Point( 94, 45 );
			this->posY->Mask = L"#999.999";
			this->posY->Name = L"posY";
			this->posY->Size = System::Drawing::Size( 55, 20 );
			this->posY->TabIndex = 8;
			this->posY->TextChanged += gcnew System::EventHandler( this, &TransformComponent::posChanged );
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point( 94, 29 );
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size( 14, 13 );
			this->label2->TabIndex = 7;
			this->label2->Text = L"Y";
			// 
			// posX
			// 
			this->posX->Location = System::Drawing::Point( 33, 45 );
			this->posX->Mask = L"#999.999";
			this->posX->Name = L"posX";
			this->posX->Size = System::Drawing::Size( 55, 20 );
			this->posX->TabIndex = 6;
			this->posX->TextChanged += gcnew System::EventHandler( this, &TransformComponent::posChanged );
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point( 33, 29 );
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size( 14, 13 );
			this->label1->TabIndex = 1;
			this->label1->Text = L"X";
			// 
			// rotationGroup
			// 
			this->rotationGroup->Controls->Add( this->rotZ );
			this->rotationGroup->Controls->Add( this->label4 );
			this->rotationGroup->Controls->Add( this->rotY );
			this->rotationGroup->Controls->Add( this->label5 );
			this->rotationGroup->Controls->Add( this->rotX );
			this->rotationGroup->Controls->Add( this->label6 );
			this->rotationGroup->Location = System::Drawing::Point( 3, 92 );
			this->rotationGroup->Name = L"rotationGroup";
			this->rotationGroup->Size = System::Drawing::Size( 244, 83 );
			this->rotationGroup->TabIndex = 11;
			this->rotationGroup->TabStop = false;
			this->rotationGroup->Text = L"Rotation";
			// 
			// rotZ
			// 
			this->rotZ->Location = System::Drawing::Point( 155, 45 );
			this->rotZ->Mask = L"#999.999";
			this->rotZ->Name = L"rotZ";
			this->rotZ->Size = System::Drawing::Size( 55, 20 );
			this->rotZ->TabIndex = 10;
			this->rotZ->TextChanged += gcnew System::EventHandler( this, &TransformComponent::rotChanged );
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point( 155, 29 );
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size( 14, 13 );
			this->label4->TabIndex = 9;
			this->label4->Text = L"Z";
			// 
			// rotY
			// 
			this->rotY->Location = System::Drawing::Point( 94, 45 );
			this->rotY->Mask = L"#999.999";
			this->rotY->Name = L"rotY";
			this->rotY->Size = System::Drawing::Size( 55, 20 );
			this->rotY->TabIndex = 8;
			this->rotY->TextChanged += gcnew System::EventHandler( this, &TransformComponent::rotChanged );
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point( 94, 29 );
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size( 14, 13 );
			this->label5->TabIndex = 7;
			this->label5->Text = L"Y";
			// 
			// rotX
			// 
			this->rotX->Location = System::Drawing::Point( 33, 45 );
			this->rotX->Mask = L"#999.999";
			this->rotX->Name = L"rotX";
			this->rotX->Size = System::Drawing::Size( 55, 20 );
			this->rotX->TabIndex = 6;
			this->rotX->TextChanged += gcnew System::EventHandler( this, &TransformComponent::rotChanged );
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point( 33, 29 );
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size( 14, 13 );
			this->label6->TabIndex = 1;
			this->label6->Text = L"X";
			// 
			// scaleGroup
			// 
			this->scaleGroup->Controls->Add( this->scaleZ );
			this->scaleGroup->Controls->Add( this->label7 );
			this->scaleGroup->Controls->Add( this->scaleY );
			this->scaleGroup->Controls->Add( this->label8 );
			this->scaleGroup->Controls->Add( this->scaleX );
			this->scaleGroup->Controls->Add( this->label9 );
			this->scaleGroup->Location = System::Drawing::Point( 3, 181 );
			this->scaleGroup->Name = L"scaleGroup";
			this->scaleGroup->Size = System::Drawing::Size( 244, 83 );
			this->scaleGroup->TabIndex = 12;
			this->scaleGroup->TabStop = false;
			this->scaleGroup->Text = L"Scale";
			// 
			// scaleZ
			// 
			this->scaleZ->Location = System::Drawing::Point( 155, 45 );
			this->scaleZ->Mask = L"#999.999";
			this->scaleZ->Name = L"scaleZ";
			this->scaleZ->Size = System::Drawing::Size( 55, 20 );
			this->scaleZ->TabIndex = 10;
			this->scaleZ->TextChanged += gcnew System::EventHandler( this, &TransformComponent::scaleChanged );
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point( 155, 29 );
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size( 14, 13 );
			this->label7->TabIndex = 9;
			this->label7->Text = L"Z";
			// 
			// scaleY
			// 
			this->scaleY->Location = System::Drawing::Point( 94, 45 );
			this->scaleY->Mask = L"#999.999";
			this->scaleY->Name = L"scaleY";
			this->scaleY->Size = System::Drawing::Size( 55, 20 );
			this->scaleY->TabIndex = 8;
			this->scaleY->TextChanged += gcnew System::EventHandler( this, &TransformComponent::scaleChanged );
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point( 94, 29 );
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size( 14, 13 );
			this->label8->TabIndex = 7;
			this->label8->Text = L"Y";
			// 
			// scaleX
			// 
			this->scaleX->Location = System::Drawing::Point( 33, 45 );
			this->scaleX->Mask = L"#999.999";
			this->scaleX->Name = L"scaleX";
			this->scaleX->Size = System::Drawing::Size( 55, 20 );
			this->scaleX->TabIndex = 6;
			this->scaleX->TextChanged += gcnew System::EventHandler( this, &TransformComponent::scaleChanged );
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point( 33, 29 );
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size( 14, 13 );
			this->label9->TabIndex = 1;
			this->label9->Text = L"X";
			// 
			// TransformComponent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->scaleGroup );
			this->Controls->Add( this->rotationGroup );
			this->Controls->Add( this->positionGroup );
			this->Name = L"TransformComponent";
			this->Size = System::Drawing::Size( 250, 272 );
			this->positionGroup->ResumeLayout( false );
			this->positionGroup->PerformLayout();
			this->rotationGroup->ResumeLayout( false );
			this->rotationGroup->PerformLayout();
			this->scaleGroup->ResumeLayout( false );
			this->scaleGroup->PerformLayout();
			this->ResumeLayout( false );

		}
#pragma endregion
private: System::Void posChanged( System::Object^ sender, System::EventArgs^ e );
private: System::Void rotChanged( System::Object^ sender, System::EventArgs^ e );
private: System::Void scaleChanged( System::Object^ sender, System::EventArgs^ e );
};
}

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "EnginePtr.h"

namespace Editor {

	/// <summary>
	/// Summary for RenderView
	/// </summary>
	public ref class RenderView : public System::Windows::Forms::UserControl
	{
	public:
		RenderView(EnginePtr* engine)
		{
			InitializeComponent();
			
			this->engine = engine;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RenderView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ resize_delay;
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = ( gcnew System::ComponentModel::Container() );
			this->resize_delay = ( gcnew System::Windows::Forms::Timer( this->components ) );
			this->button1 = ( gcnew System::Windows::Forms::Button() );
			this->SuspendLayout();
			// 
			// resize_delay
			// 
			this->resize_delay->Interval = 1000;
			this->resize_delay->Tick += gcnew System::EventHandler( this, &RenderView::resize_delay_Tick );
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point( 4, 4 );
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size( 75, 23 );
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// RenderView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->button1 );
			this->Name = L"RenderView";
			this->Size = System::Drawing::Size( 547, 529 );
			this->Resize += gcnew System::EventHandler( this, &RenderView::RenderView_Resize );
			this->ResumeLayout( false );

		}
#pragma endregion
	private:
		EnginePtr* engine;
	
	private: 
		System::Void RenderView_Resize( System::Object^ sender, System::EventArgs^ e );
	private: System::Void resize_delay_Tick( System::Object^ sender, System::EventArgs^ e );
	};
}

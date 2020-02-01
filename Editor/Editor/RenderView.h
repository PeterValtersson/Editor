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
			this->SuspendLayout();
			// 
			// resize_delay
			// 
			this->resize_delay->Interval = 1000;
			this->resize_delay->Tick += gcnew System::EventHandler( this, &RenderView::resize_delay_Tick );
			// 
			// RenderView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
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

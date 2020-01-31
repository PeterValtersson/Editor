#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include <IEngine.h>

namespace Editor {

	/// <summary>
	/// Summary for RenderView
	/// </summary>
	public ref class RenderView : public System::Windows::Forms::UserControl
	{
	public:
		RenderView(Engine)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
			this->SuspendLayout();
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
	private: System::Void RenderView_Resize( System::Object^ sender, System::EventArgs^ e );
	};
}

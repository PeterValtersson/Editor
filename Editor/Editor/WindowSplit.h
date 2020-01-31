#pragma once
#include "TabControlWindow.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Editor {

	/// <summary>
	/// Summary for WindowSplit
	/// </summary>
	public ref class WindowSplit : public System::Windows::Forms::UserControl
	{
	public:
		enum class Location{
			Left,
			Right,
			Top,
			Bottom
		};

		WindowSplit(void)
		{
			InitializeComponent();
	

			left_views = gcnew TabControlWindow;
			left_views->Dock = DockStyle::Fill;
			split1->Panel1->Controls->Add( left_views );
			right_views = gcnew TabControlWindow;
			right_views->Dock = DockStyle::Fill;
			split2->Panel2->Controls->Add( right_views );
			top_views = gcnew TabControlWindow;
			top_views->Dock = DockStyle::Fill;
			top_views->menu->Visible = false;
			top_views->tabs->Alignment = TabAlignment::Top;
			top_views->Dock = DockStyle::Fill;
			split3->Panel1->Controls->Add( top_views );
			bottom_views = gcnew TabControlWindow;
			split3->Panel2->Controls->Add( bottom_views );

			views[Location::Left] = gcnew Generic::List<Control^>();
			views[Location::Right] = gcnew Generic::List<Control^>();
			views[Location::Top] = gcnew Generic::List<Control^>();
			views[Location::Bottom] = gcnew Generic::List<Control^>();
		}

		void add_view( Location location, Control^ control );
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WindowSplit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ split1;
	protected:

	protected:
	private: System::Windows::Forms::SplitContainer^ split2;
	private: System::Windows::Forms::SplitContainer^ split3;







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
			this->split1 = ( gcnew System::Windows::Forms::SplitContainer() );
			this->split2 = ( gcnew System::Windows::Forms::SplitContainer() );
			this->split3 = ( gcnew System::Windows::Forms::SplitContainer() );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->split1 ) )->BeginInit();
			this->split1->Panel2->SuspendLayout();
			this->split1->SuspendLayout();
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->split2 ) )->BeginInit();
			this->split2->Panel1->SuspendLayout();
			this->split2->SuspendLayout();
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->split3 ) )->BeginInit();
			this->split3->SuspendLayout();
			this->SuspendLayout();
			// 
			// split1
			// 
			this->split1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->split1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->split1->Location = System::Drawing::Point( 0, 0 );
			this->split1->Name = L"split1";
			// 
			// split1.Panel2
			// 
			this->split1->Panel2->Controls->Add( this->split2 );
			this->split1->Size = System::Drawing::Size( 555, 515 );
			this->split1->SplitterDistance = 185;
			this->split1->TabIndex = 0;
			// 
			// split2
			// 
			this->split2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->split2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->split2->Location = System::Drawing::Point( 0, 0 );
			this->split2->Name = L"split2";
			// 
			// split2.Panel1
			// 
			this->split2->Panel1->Controls->Add( this->split3 );
			this->split2->Size = System::Drawing::Size( 366, 515 );
			this->split2->SplitterDistance = 177;
			this->split2->TabIndex = 0;
			// 
			// split3
			// 
			this->split3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->split3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->split3->Location = System::Drawing::Point( 0, 0 );
			this->split3->Name = L"split3";
			this->split3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// split3.Panel1
			// 
			this->split3->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			// 
			// split3.Panel2
			// 
			this->split3->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->split3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->split3->Size = System::Drawing::Size( 177, 515 );
			this->split3->SplitterDistance = 271;
			this->split3->TabIndex = 0;
			// 
			// WindowSplit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->split1 );
			this->Name = L"WindowSplit";
			this->Size = System::Drawing::Size( 555, 515 );
			this->split1->Panel2->ResumeLayout( false );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->split1 ) )->EndInit();
			this->split1->ResumeLayout( false );
			this->split2->Panel1->ResumeLayout( false );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->split2 ) )->EndInit();
			this->split2->ResumeLayout( false );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->split3 ) )->EndInit();
			this->split3->ResumeLayout( false );
			this->ResumeLayout( false );

		}
#pragma endregion

	private:
		Generic::Dictionary<Location, Generic::List<Control^>^> views;
		TabControlWindow^ left_views;
		TabControlWindow^ right_views;
		TabControlWindow^ top_views;
		TabControlWindow^ bottom_views;
	private:
		void setup_spliters();
	};
}

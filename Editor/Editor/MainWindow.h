#pragma once
#include <IEngine.h>
#include "EngineWindowInterface.h"
#include "WindowSplit.h"
#include "SceneView.h"

namespace Editor {
	struct EnginePtr{
		std::shared_ptr<Engine::IEngine> engine;
		std::shared_ptr<EngineWindowInterface> window;
	};


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
		
	public:
		MainWindow( void );

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow();
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::StatusStrip^ statusStrip1;

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
			this->menuStrip1 = ( gcnew System::Windows::Forms::MenuStrip() );
			this->statusStrip1 = ( gcnew System::Windows::Forms::StatusStrip() );
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point( 0, 0 );
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size( 916, 24 );
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point( 0, 537 );
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size( 916, 22 );
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size( 916, 559 );
			this->Controls->Add( this->statusStrip1 );
			this->Controls->Add( this->menuStrip1 );
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->ResumeLayout( false );
			this->PerformLayout();

		}
#pragma endregion

	private:
		EnginePtr* engine;

		WindowSplit^ spliter;
		SceneView^ scene_view;
		Panel^ render_view;
	};
}

#pragma once
#include <IEngine.h>
#include "EngineWindowInterface.h"
#include "WindowSplit.h"
#include "SceneView.h"
#include "EnginePtr.h"
#include "RenderView.h"
#include "ComponentView.h"
#include "ComponentViewNew.h"


namespace Editor {



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

	private:
		EnginePtr* engine;

		WindowSplit^ spliter;
		SceneView^ scene_view;
		RenderView^ render_view;
		ComponentViewNew^ component_view;
	public:
		MainWindow( void );

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow();
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	protected:
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	protected:



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
			this->toolStripContainer1 = ( gcnew System::Windows::Forms::ToolStripContainer() );
			this->statusStrip1 = ( gcnew System::Windows::Forms::StatusStrip() );
			this->menuStrip1 = ( gcnew System::Windows::Forms::MenuStrip() );
			this->toolStripContainer1->BottomToolStripPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripContainer1
			// 
			// 
			// toolStripContainer1.BottomToolStripPanel
			// 
			this->toolStripContainer1->BottomToolStripPanel->Controls->Add( this->statusStrip1 );
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size( 1120, 513 );
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->Location = System::Drawing::Point( 0, 0 );
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size( 1120, 559 );
			this->toolStripContainer1->TabIndex = 2;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add( this->menuStrip1 );
			// 
			// statusStrip1
			// 
			this->statusStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->statusStrip1->Location = System::Drawing::Point( 0, 0 );
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size( 1120, 22 );
			this->statusStrip1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Location = System::Drawing::Point( 0, 0 );
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size( 1120, 24 );
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size( 1120, 559 );
			this->Controls->Add( this->toolStripContainer1 );
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->toolStripContainer1->BottomToolStripPanel->ResumeLayout( false );
			this->toolStripContainer1->BottomToolStripPanel->PerformLayout();
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout( false );
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout( false );
			this->toolStripContainer1->PerformLayout();
			this->ResumeLayout( false );

		}
#pragma endregion

	};
}

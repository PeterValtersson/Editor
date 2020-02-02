#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#include "EnginePtr.h"


namespace Editor
{

/// <summary>
/// Summary for ResourceView
/// </summary>
	public ref class ResourceView : public System::Windows::Forms::UserControl {
	private:
		EnginePtr* engine;
	public:
		ResourceView( EnginePtr* engine ) : engine( engine )
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		//	engine->engine->get_sub_systems().resource_archive->
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ResourceView()
		{
			if ( components )
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^ resourceTree;
	protected:

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
			this->resourceTree = ( gcnew System::Windows::Forms::TreeView() );
			this->SuspendLayout();
			// 
			// resourceTree
			// 
			this->resourceTree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->resourceTree->Location = System::Drawing::Point( 0, 0 );
			this->resourceTree->Name = L"resourceTree";
			this->resourceTree->Size = System::Drawing::Size( 283, 367 );
			this->resourceTree->TabIndex = 0;
			// 
			// ResourceView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->resourceTree );
			this->Name = L"ResourceView";
			this->Size = System::Drawing::Size( 283, 367 );
			this->ResumeLayout( false );

		}
#pragma endregion
	};
}

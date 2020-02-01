#pragma once
#include "EnginePtr.h"

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
/// Summary for ComponentView
/// </summary>
	public ref class ComponentView : public System::Windows::Forms::UserControl {
	private:
		EnginePtr* engine;

		   Entity _selectedEntity;
	public:
		ComponentView( EnginePtr* engine ) : engine( engine )
		{
			InitializeComponent();
			_selectedEntity = ~0;
		}
		property Entity selectedEntity
		{
			Entity get()
			{
				return _selectedEntity;
			}
			void set( Entity e )
			{
				auto temp = _selectedEntity;
				_selectedEntity = e;
				if ( temp != e )
					EntityChanged();
			}
		}
	private:
		void EntityChanged();
		void ComponentSelected( Control^ component );
		void AddComponent( Control^ component );
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentView()
		{
			if ( components )
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^ componentPanel;

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
			this->splitContainer1 = ( gcnew System::Windows::Forms::SplitContainer() );
			this->componentPanel = ( gcnew System::Windows::Forms::FlowLayoutPanel() );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->splitContainer1 ) )->BeginInit();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point( 0, 0 );
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->AutoScroll = true;
			this->splitContainer1->Panel1MinSize = 100;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add( this->componentPanel );
			this->splitContainer1->Panel2MinSize = 150;
			this->splitContainer1->Size = System::Drawing::Size( 404, 500 );
			this->splitContainer1->SplitterDistance = 250;
			this->splitContainer1->TabIndex = 0;
			// 
			// componentPanel
			// 
			this->componentPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->componentPanel->Location = System::Drawing::Point( 0, 0 );
			this->componentPanel->Name = L"componentPanel";
			this->componentPanel->Size = System::Drawing::Size( 150, 500 );
			this->componentPanel->TabIndex = 0;
			// 
			// ComponentView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->splitContainer1 );
			this->Name = L"ComponentView";
			this->Size = System::Drawing::Size( 404, 500 );
			this->splitContainer1->Panel2->ResumeLayout( false );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->splitContainer1 ) )->EndInit();
			this->splitContainer1->ResumeLayout( false );
			this->ResumeLayout( false );

		}
#pragma endregion
	};
}

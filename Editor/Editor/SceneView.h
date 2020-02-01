#pragma once
#include "EnginePtr.h"
#include "ComponentView.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor
{

/// <summary>
/// Summary for SceneView
/// </summary>
	public ref class SceneView : public System::Windows::Forms::UserControl {
	private:
		EnginePtr* engine;

		TreeNode^ cmSelectedNode;
		ComponentView^ component_view;
	public:
		SceneView( EnginePtr* engine, ComponentView^ component_view ) : engine( engine ), component_view( component_view )
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
		~SceneView()
		{
			if ( components )
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::TreeView^ scene_tree;
	private: System::Windows::Forms::TreeView^ entity_tree;
	private: System::Windows::Forms::ContextMenuStrip^ sceneTreeCM;
	private: System::Windows::Forms::ToolStripMenuItem^ newSceneCMBTN;
	private: System::Windows::Forms::ContextMenuStrip^ sceneTreeNodeCM;
	private: System::Windows::Forms::ToolStripMenuItem^ sceneTreeNodeNSCMBTN;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent( void )
		{
			this->components = ( gcnew System::ComponentModel::Container() );
			this->splitContainer1 = ( gcnew System::Windows::Forms::SplitContainer() );
			this->scene_tree = ( gcnew System::Windows::Forms::TreeView() );
			this->sceneTreeCM = ( gcnew System::Windows::Forms::ContextMenuStrip( this->components ) );
			this->newSceneCMBTN = ( gcnew System::Windows::Forms::ToolStripMenuItem() );
			this->entity_tree = ( gcnew System::Windows::Forms::TreeView() );
			this->sceneTreeNodeCM = ( gcnew System::Windows::Forms::ContextMenuStrip( this->components ) );
			this->sceneTreeNodeNSCMBTN = ( gcnew System::Windows::Forms::ToolStripMenuItem() );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->splitContainer1 ) )->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->sceneTreeCM->SuspendLayout();
			this->sceneTreeNodeCM->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point( 0, 0 );
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add( this->scene_tree );
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add( this->entity_tree );
			this->splitContainer1->Size = System::Drawing::Size( 361, 578 );
			this->splitContainer1->SplitterDistance = 173;
			this->splitContainer1->TabIndex = 0;
			// 
			// scene_tree
			// 
			this->scene_tree->ContextMenuStrip = this->sceneTreeCM;
			this->scene_tree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->scene_tree->Location = System::Drawing::Point( 0, 0 );
			this->scene_tree->Name = L"scene_tree";
			this->scene_tree->Size = System::Drawing::Size( 173, 578 );
			this->scene_tree->TabIndex = 0;
			this->scene_tree->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler( this, &SceneView::scene_tree_AfterSelect );
			// 
			// sceneTreeCM
			// 
			this->sceneTreeCM->Items->AddRange( gcnew cli::array< System::Windows::Forms::ToolStripItem^  >( 1 ) { this->newSceneCMBTN } );
			this->sceneTreeCM->Name = L"sceneTreeCM";
			this->sceneTreeCM->Size = System::Drawing::Size( 133, 26 );
			// 
			// newSceneCMBTN
			// 
			this->newSceneCMBTN->Name = L"newSceneCMBTN";
			this->newSceneCMBTN->Size = System::Drawing::Size( 132, 22 );
			this->newSceneCMBTN->Text = L"New Scene";
			this->newSceneCMBTN->Click += gcnew System::EventHandler( this, &SceneView::newSceneCMBTN_Click );
			// 
			// entity_tree
			// 
			this->entity_tree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->entity_tree->Location = System::Drawing::Point( 0, 0 );
			this->entity_tree->Name = L"entity_tree";
			this->entity_tree->Size = System::Drawing::Size( 184, 578 );
			this->entity_tree->TabIndex = 0;
			// 
			// sceneTreeNodeCM
			// 
			this->sceneTreeNodeCM->Items->AddRange( gcnew cli::array< System::Windows::Forms::ToolStripItem^  >( 1 ) { this->sceneTreeNodeNSCMBTN } );
			this->sceneTreeNodeCM->Name = L"sceneTreeNodeCM";
			this->sceneTreeNodeCM->Size = System::Drawing::Size( 133, 26 );
			this->sceneTreeNodeCM->Opening += gcnew System::ComponentModel::CancelEventHandler( this, &SceneView::sceneTreeNodeCM_Opening );
			// 
			// sceneTreeNodeNSCMBTN
			// 
			this->sceneTreeNodeNSCMBTN->Name = L"sceneTreeNodeNSCMBTN";
			this->sceneTreeNodeNSCMBTN->Size = System::Drawing::Size( 132, 22 );
			this->sceneTreeNodeNSCMBTN->Text = L"New Scene";
			this->sceneTreeNodeNSCMBTN->Click += gcnew System::EventHandler( this, &SceneView::newSceneCMBTN_Click );
			// 
			// SceneView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add( this->splitContainer1 );
			this->Name = L"SceneView";
			this->Size = System::Drawing::Size( 361, 578 );
			this->splitContainer1->Panel1->ResumeLayout( false );
			this->splitContainer1->Panel2->ResumeLayout( false );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->splitContainer1 ) )->EndInit();
			this->splitContainer1->ResumeLayout( false );
			this->sceneTreeCM->ResumeLayout( false );
			this->sceneTreeNodeCM->ResumeLayout( false );
			this->ResumeLayout( false );

		}
#pragma endregion
	private: System::Void newSceneCMBTN_Click( System::Object^ sender, System::EventArgs^ e );
	private: System::Void sceneTreeNodeCM_Opening( System::Object^ sender, System::ComponentModel::CancelEventArgs^ e );
	private: System::Void scene_tree_AfterSelect( System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e );
};
}

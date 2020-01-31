#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {

	/// <summary>
	/// Summary for SceneView
	/// </summary>
	public ref class SceneView : public System::Windows::Forms::UserControl
	{
	public:
		SceneView(void)
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
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::TreeView^ scene_tree;
	private: System::Windows::Forms::TreeView^ entity_tree;
	protected:

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
			this->splitContainer1 = ( gcnew System::Windows::Forms::SplitContainer() );
			this->scene_tree = ( gcnew System::Windows::Forms::TreeView() );
			this->entity_tree = ( gcnew System::Windows::Forms::TreeView() );
			( cli::safe_cast< System::ComponentModel::ISupportInitialize^ >( this->splitContainer1 ) )->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
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
			this->scene_tree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->scene_tree->Location = System::Drawing::Point( 0, 0 );
			this->scene_tree->Name = L"scene_tree";
			this->scene_tree->Size = System::Drawing::Size( 173, 578 );
			this->scene_tree->TabIndex = 0;
			// 
			// entity_tree
			// 
			this->entity_tree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->entity_tree->Location = System::Drawing::Point( 0, 0 );
			this->entity_tree->Name = L"entity_tree";
			this->entity_tree->Size = System::Drawing::Size( 184, 578 );
			this->entity_tree->TabIndex = 0;
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
			this->ResumeLayout( false );

		}
#pragma endregion
	};
}

#pragma once
#include <IEngine.h>

namespace Editor {
	struct EnginePtr{
		std::shared_ptr<Engine::IEngine> engine;
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
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size( 916, 559 );
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->ResumeLayout( false );

		}
#pragma endregion

	private:
		EnginePtr* engine;
	};
}

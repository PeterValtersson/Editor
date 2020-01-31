#include "MainWindow.h"
#include "EngineWindowInterface.h"
#include "StringHelpers.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main( array <String^>^ args )
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault( false );
	try
	{
		Editor::MainWindow form;
		Application::Run( % form );
	}
	catch ( Utilities::Exception & e )
	{
		MessageBox::Show( managedString( e.what() ), managedString( e.title ), MessageBoxButtons::OK );
	}
	return 0;
}

Editor::MainWindow::MainWindow( void )
{
	InitializeComponent();

	engine = new EnginePtr;

	Engine::Init_Info ii;
	ii.sub_systems.window = std::make_shared<EngineWindowInterface>();
	engine->engine = Engine::IEngine::create(ii);
}

Editor::MainWindow::~MainWindow()
{
	if ( components )
	{
		delete components;
	}
	if ( engine )
		delete engine;
}

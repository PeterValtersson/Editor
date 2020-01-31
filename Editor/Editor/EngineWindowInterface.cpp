#include "EngineWindowInterface.h"

void Editor::EngineWindowInterface::Frame() noexcept
{}

void* Editor::EngineWindowInterface::GetWindowHandle() noexcept
{
	return hwnd;
}

void* Editor::EngineWindowInterface::GetWindowImplementation() noexcept
{
	return nullptr;
}

bool Editor::EngineWindowInterface::ButtonDown( Window::ActionButton actionButton ) const noexcept
{
	return false;
}

bool Editor::EngineWindowInterface::ButtonPressed( Window::ActionButton actionButton ) const noexcept
{
	return false;
}

bool Editor::EngineWindowInterface::ButtonUp( Window::ActionButton actionButton ) const noexcept
{
	return false;
}

bool Editor::EngineWindowInterface::ButtonDouble( Window::ActionButton actionButton ) const noexcept
{
	return false;
}

void Editor::EngineWindowInterface::GetMousePos( int& x, int& y ) const noexcept
{}

void Editor::EngineWindowInterface::ToggleCursor( bool on ) noexcept
{}

void Editor::EngineWindowInterface::SetWindowTitle( const std::string & title ) noexcept
{}

Window::Resolution Editor::EngineWindowInterface::GetResolution() const noexcept
{
	return Window::Resolution();
}

void Editor::EngineWindowInterface::MapActionButton( Window::ActionButton actionButton, Window::KeyCode key )
{}

void Editor::EngineWindowInterface::SetWindowInfo( const Window::InitializationInfo & info )
{}

float Editor::EngineWindowInterface::GetDelta() const noexcept
{
	return 0.0f;
}

void Editor::EngineWindowInterface::BindMouseClickCallback( Window::ActionButton actionButton, const Window::MouseClickCallback& callback ) noexcept
{}

void Editor::EngineWindowInterface::UnbindMouseClickCallback( Window::ActionButton actionButton, const Window::MouseClickCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::BindMouseMotionCallback( const Window::MouseMotionCallback& callback ) noexcept
{}

void Editor::EngineWindowInterface::UnbindMouseMotionCallback( const Window::MouseMotionCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::BindKeyPressCallback( Window::ActionButton actionButton, const Window::KeyCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::UnbindKeyPressCallback( Window::ActionButton actionButton, const Window::KeyCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::BindKeyDownCallback( Window::ActionButton actionButton, const Window::KeyCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::UnbindKeyDownCallback( Window::ActionButton actionButton, const Window::KeyCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::BindKeyUpCallback( Window::ActionButton actionButton, const Window::KeyCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::UnbindKeyUpCallback( Window::ActionButton actionButton, const Window::KeyCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::UnbindAllCallbacks() noexcept
{}

void Editor::EngineWindowInterface::BindOnQuitEvent( const Window::QuitCallback & callback ) noexcept
{}

void Editor::EngineWindowInterface::UnbindOnQuitEvent( const Window::QuitCallback & callback ) noexcept
{}

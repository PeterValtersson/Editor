#include "pch.h"
#include "EngineWindow.h"

EngineWindow::EngineWindow(void* hwnd, ECSEngine::Resolution resolution) : hwnd(hwnd), resolution(resolution)
{

}


void EngineWindow::EngineWindow::Frame() noexcept
{}

void* EngineWindow::EngineWindow::GetWindowHandle() noexcept
{
	return hwnd;
}

void* EngineWindow::EngineWindow::GetWindowImplementation() noexcept
{
	return nullptr;
}

bool EngineWindow::EngineWindow::ButtonDown(ECSEngine::ActionButton actionButton) const noexcept
{
	return false;
}

bool EngineWindow::EngineWindow::ButtonPressed(ECSEngine::ActionButton actionButton) const noexcept
{
	return false;
}

bool EngineWindow::EngineWindow::ButtonUp(ECSEngine::ActionButton actionButton) const noexcept
{
	return false;
}

bool EngineWindow::EngineWindow::ButtonDouble(ECSEngine::ActionButton actionButton) const noexcept
{
	return false;
}

void EngineWindow::EngineWindow::GetMousePos(int& x, int& y) const noexcept
{}

void EngineWindow::EngineWindow::ToggleCursor(bool on) noexcept
{}

void EngineWindow::EngineWindow::SetWindowTitle(const std::string& title) noexcept
{}

ECSEngine::Resolution EngineWindow::EngineWindow::GetResolution() const noexcept
{
	return resolution;
}

void EngineWindow::EngineWindow::MapActionButton(ECSEngine::ActionButton actionButton, ECSEngine::KeyCode key)
{}

void EngineWindow::EngineWindow::SetWindowInfo(const ECSEngine::InitializationInfo& info)
{}

float EngineWindow::EngineWindow::GetDelta() const noexcept
{
	return 0.0f;
}

void EngineWindow::EngineWindow::BindMouseClickCallback(ECSEngine::ActionButton actionButton, const ECSEngine::MouseClickCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::UnbindMouseClickCallback(ECSEngine::ActionButton actionButton, const ECSEngine::MouseClickCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::BindMouseMotionCallback(const ECSEngine::MouseMotionCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::UnbindMouseMotionCallback(const ECSEngine::MouseMotionCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::BindKeyPressCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::UnbindKeyPressCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::BindKeyDownCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::UnbindKeyDownCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::BindKeyUpCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::UnbindKeyUpCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::UnbindAllCallbacks() noexcept
{}

void EngineWindow::EngineWindow::BindOnQuitEvent(const ECSEngine::QuitCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::UnbindOnQuitEvent(const ECSEngine::QuitCallback& callback) noexcept
{}

void EngineWindow::EngineWindow::SetHWND(void* hwnd)
{
	this->hwnd = hwnd;
}

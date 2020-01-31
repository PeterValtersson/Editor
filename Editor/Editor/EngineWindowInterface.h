#pragma once
#include <Window_Interface.h>

namespace Editor
{
	class EngineWindowInterface : public Window::Window_Interface{
	public:
		virtual void Frame()noexcept override;

		virtual void* GetWindowHandle()noexcept override;

		virtual void* GetWindowImplementation()noexcept override;

		virtual bool ButtonDown( Window::ActionButton actionButton ) const noexcept override;

		virtual bool ButtonPressed( Window::ActionButton actionButton ) const noexcept override;

		virtual bool ButtonUp( Window::ActionButton actionButton ) const noexcept override;

		virtual bool ButtonDouble( Window::ActionButton actionButton ) const noexcept override;

		virtual void GetMousePos( int& x, int& y ) const noexcept override;

		virtual void ToggleCursor( bool on ) noexcept override;

		virtual void SetWindowTitle( const std::string& title ) noexcept override;

		virtual Window::Resolution GetResolution() const noexcept override;

		virtual void MapActionButton( Window::ActionButton actionButton, Window::KeyCode key ) override;

		virtual void SetWindowInfo( const Window::InitializationInfo& info ) override;

		virtual float GetDelta() const noexcept override;


		virtual void BindMouseClickCallback( Window::ActionButton actionButton, const Window::MouseClickCallback& callback )noexcept override;
		virtual void UnbindMouseClickCallback( Window::ActionButton actionButton, const Window::MouseClickCallback& callback )noexcept override;

		virtual void BindMouseMotionCallback( const Window::MouseMotionCallback& callback )noexcept override;
		virtual void UnbindMouseMotionCallback( const Window::MouseMotionCallback& callback )noexcept override;

		virtual void BindKeyPressCallback( Window::ActionButton actionButton, const Window::KeyCallback& callback )noexcept override;
		virtual void UnbindKeyPressCallback( Window::ActionButton actionButton, const Window::KeyCallback& callback )noexcept override;

		virtual void BindKeyDownCallback( Window::ActionButton actionButton, const Window::KeyCallback& callback )noexcept override;
		virtual void UnbindKeyDownCallback( Window::ActionButton actionButton, const Window::KeyCallback& callback )noexcept override;

		virtual void BindKeyUpCallback( Window::ActionButton actionButton, const Window::KeyCallback& callback )noexcept override;
		virtual void UnbindKeyUpCallback( Window::ActionButton actionButton, const Window::KeyCallback& callback )noexcept override;

		virtual void UnbindAllCallbacks()noexcept override;

		virtual void BindOnQuitEvent( const Window::QuitCallback& callback )noexcept override;
		virtual void UnbindOnQuitEvent( const Window::QuitCallback& callback )noexcept override;
	};
}
#pragma once
#include <HMI.h>

class EngineWindow : public ECSEngine::HMI
{
public:
	EngineWindow(void* hwnd, ECSEngine::Resolution resolution);
	virtual void Frame()noexcept override;

	virtual void* GetWindowHandle()noexcept override;

	virtual void* GetWindowImplementation()noexcept override;

	virtual bool ButtonDown(ECSEngine::ActionButton actionButton) const noexcept override;

	virtual bool ButtonPressed(ECSEngine::ActionButton actionButton) const noexcept override;

	virtual bool ButtonUp(ECSEngine::ActionButton actionButton) const noexcept override;

	virtual bool ButtonDouble(ECSEngine::ActionButton actionButton) const noexcept override;

	virtual void GetMousePos(int& x, int& y) const noexcept override;

	virtual void ToggleCursor(bool on) noexcept override;

	virtual void SetWindowTitle(const std::string& title) noexcept override;

	virtual ECSEngine::Resolution GetResolution() const noexcept override;

	virtual void MapActionButton(ECSEngine::ActionButton actionButton, ECSEngine::KeyCode key) override;

	virtual void SetWindowInfo(const ECSEngine::InitializationInfo& info) override;

	virtual float GetDelta() const noexcept override;


	virtual void BindMouseClickCallback(ECSEngine::ActionButton actionButton, const ECSEngine::MouseClickCallback& callback)noexcept override;
	virtual void UnbindMouseClickCallback(ECSEngine::ActionButton actionButton, const ECSEngine::MouseClickCallback& callback)noexcept override;

	virtual void BindMouseMotionCallback(const ECSEngine::MouseMotionCallback& callback)noexcept override;
	virtual void UnbindMouseMotionCallback(const ECSEngine::MouseMotionCallback& callback)noexcept override;

	virtual void BindKeyPressCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback)noexcept override;
	virtual void UnbindKeyPressCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback)noexcept override;

	virtual void BindKeyDownCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback)noexcept override;
	virtual void UnbindKeyDownCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback)noexcept override;

	virtual void BindKeyUpCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback)noexcept override;
	virtual void UnbindKeyUpCallback(ECSEngine::ActionButton actionButton, const ECSEngine::KeyCallback& callback)noexcept override;

	virtual void UnbindAllCallbacks()noexcept override;

	virtual void BindOnQuitEvent(const ECSEngine::QuitCallback& callback)noexcept override;
	virtual void UnbindOnQuitEvent(const ECSEngine::QuitCallback& callback)noexcept override;

	void SetHWND(void* hwnd);

private:
	void* hwnd;
	ECSEngine::Resolution resolution;
};


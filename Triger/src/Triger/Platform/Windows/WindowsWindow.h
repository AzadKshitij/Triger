#pragma once

#include "Triger/Window.h"

#include <GLFW/glfw3.h>

namespace Triger
{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps &props);
		virtual ~WindowsWindow();

		/*
		* To update buffers, GLFW stuff etc. 
		* Will be called once per frame
		*/
		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps &props);
		virtual void Shutdown();

	private:
		GLFWwindow *m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

} // namespace Triger
#pragma once

#include "Core.h"
#include "Triger/Events/Event.h"
#include "Triger/Events/ApplicationEvent.h"
#include "Window.h"

namespace Triger
{
	class TRIGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	/*
	* This will be defined in the Client
	*/
	Application *CreateApplication();
} // namespace Triger

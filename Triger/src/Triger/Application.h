#pragma once

#include "Core.h"
#include "Window.h"
#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/Event.h"
#include "Triger/Layers/LayerStack.h"

namespace Triger
{
	class TRIGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	/*
	* This will be defined in the Client
	*/
	Application *CreateApplication();
} // namespace Triger

#pragma once

#include "Core.h"
#include "Window.h"
#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/Event.h"
#include "Triger/Layers/LayerStack.h"
#include "Triger/ImGui/ImGuiLayer.h"

#include "Triger/Core/Timestep.h"


namespace Triger
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
		bool m_Minimized = false;
		
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
		
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	/*
	* This will be defined in the Client
	*/

	Application *CreateApplication();
} // namespace Triger

/**
 *  @file   Application.h
 *  @brief  Applicatoin creation base
 *  @author Kshitij Azad
 *  @date   November 2, 2020
 ***********************************************/
#pragma once

#include "Triger/Core/Base.h"
#include "Triger/Core/Window.h"

#include "Triger/Layers/LayerStack.h"
#include "Triger/Events/Event.h"
#include "Triger/Events/ApplicationEvent.h"

#include "Triger/Core/Timestep.h"

#include "Triger/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Triger {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Triger

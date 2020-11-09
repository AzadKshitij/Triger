#pragma once

#include "Core.h"
#include "Window.h"
#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/Event.h"
#include "Triger/Layers/LayerStack.h"
#include "Triger/ImGui/ImGuiLayer.h"
#include "Triger/Renderer/Shader.h"
#include "Triger/Renderer/Buffer.h"

#include "Triger/Renderer/VertexArray.h"


namespace Triger
{
	class TRIGER_API Application
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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

	private:
		static Application* s_Instance;
	};

	/*
	* This will be defined in the Client
	*/
	Application *CreateApplication();
} // namespace Triger

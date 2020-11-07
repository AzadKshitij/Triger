#include "trpch.h"

 #include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Triger/Log.h"

#include <GLFW/glfw3.h>

namespace Triger
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		/*
		* Goes into window data
		*/
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		TR_CORE_TRACE("{0}",e);
	}



	void Application::Run()
	{
		
		while (m_Running)
		{
			// m_Window->OnUpdate();
			//TR_TRACE(e);
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}


} // namespace Triger

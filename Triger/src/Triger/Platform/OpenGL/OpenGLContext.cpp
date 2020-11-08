#include "trpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Triger {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TR_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TR_CORE_ASSERT(status, "Failed to initialize Glad!");

		TR_CORE_INFO("OpenGL Info:");
		TR_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		TR_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		TR_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
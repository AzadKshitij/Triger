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

		#ifdef TR_ENABLE_ASSERTS
				int versionMajor;
				int versionMinor;
				glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
				glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

				TR_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Triger requires at least OpenGL version 4.5!");
		#endif // TR_ENABLE_ASSERTS
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
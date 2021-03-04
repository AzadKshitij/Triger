/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : OpenGLContext.cpp
//   Created On  : 08/11/2020
//   Updated On  : 08/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "trpch.h"
#include "Triger/Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Triger
{

	OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TR_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		TR_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TR_CORE_ASSERT(status, "Failed to initialize Glad!");

		TR_CORE_INFO("OpenGL Info:");
		TR_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		TR_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		TR_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		TR_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Triger requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		TR_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}

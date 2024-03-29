/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : OpenGLRendererAPI.cpp
//   Created On  : 10/11/2020
//   Updated On  : 10/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "trpch.h"
#include "Triger/Platform/OpenGL/OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Triger
{

	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char *message,
		const void *userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:
			TR_CORE_CRITICAL(message);
			return;
		case GL_DEBUG_SEVERITY_MEDIUM:
			TR_CORE_ERROR(message);
			return;
		case GL_DEBUG_SEVERITY_LOW:
			TR_CORE_WARN(message);
			return;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			TR_CORE_TRACE(message);
			return;
		}

		TR_CORE_ASSERT(false, "Unknown severity level!");
	}

	void OpenGLRendererAPI::Init()
	{
		TR_PROFILE_FUNCTION();

#ifdef TR_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4 &color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray> &vertexArray, uint32_t indexCount)
	{
		uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr); 
		glBindTexture(GL_TEXTURE_2D, 0); 
	}
}

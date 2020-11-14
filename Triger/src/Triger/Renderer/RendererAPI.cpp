#include <trpch.h>

#include <glm/glm.hpp>

#include "RendererAPI.h"
#include "Triger/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Triger {

		RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

		Scope<RendererAPI> RendererAPI::Create()
		{
			switch (s_API)
			{
			case RendererAPI::API::None:    TR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
			}

			TR_CORE_ASSERT(false, "Unknown RendererAPI!");
			return nullptr;
		}
}
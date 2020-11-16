#include "trpch.h"
#include "Triger/Renderer/GraphicsContext.h"

#include "Triger/Renderer/Renderer.h"
#include "Triger/Platform/OpenGL/OpenGLContext.h"

namespace Triger {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    TR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		TR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
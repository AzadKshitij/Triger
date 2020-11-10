#include "trpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Triger/Platform/OpenGL/OpenGLVertexArray.h"

namespace Triger {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    TR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLVertexArray();
		}

		TR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
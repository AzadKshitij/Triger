#include "trpch.h"
#include "Triger/Renderer/Framebuffer.h"

#include "Triger/Renderer/Renderer.h"

#include "Triger/Platform/OpenGL/OpenGLFramebuffer.h"

namespace Triger {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    TR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		TR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}

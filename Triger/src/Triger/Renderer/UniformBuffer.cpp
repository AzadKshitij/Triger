#include "trpch.h"
#include "UniformBuffer.h"

#include "Triger/Renderer/Renderer.h"
#include "Triger/Platform/OpenGL/OpenGLUniformBuffer.h"

namespace Triger
{

    Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            TR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLUniformBuffer>(size, binding);
        }

        TR_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}

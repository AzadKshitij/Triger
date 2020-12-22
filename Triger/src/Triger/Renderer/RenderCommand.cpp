#include "trpch.h"

#include "Triger/Renderer/RenderCommand.h"

namespace Triger {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}

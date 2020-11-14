#include "trpch.h"

#include "RenderCommand.h"

namespace Triger {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
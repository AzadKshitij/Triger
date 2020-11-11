#include "trpch.h"
#include "RenderCommand.h"

#include "Triger/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Triger {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();

}
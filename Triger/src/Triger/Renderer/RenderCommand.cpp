#include "trpch.h"
#include "RenderCommand.h"

#include "Triger/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Triger {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
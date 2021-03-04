/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : VertexArray.cpp
//   Created On  : 09/11/2020
//   Updated On  : 09/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "trpch.h"
#include "Triger/Renderer/VertexArray.h"

#include "Triger/Renderer/Renderer.h"
#include "Triger/Platform/OpenGL/OpenGLVertexArray.h"

	namespace Triger
{

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			TR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexArray>();
		}

		TR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
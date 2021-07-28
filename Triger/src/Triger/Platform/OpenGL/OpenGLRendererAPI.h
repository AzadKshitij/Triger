/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : OpenGLRendererAPI.h
//   Created On  : 10/11/2020
//   Updated On  : 10/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger/Renderer/RendererAPI.h"

namespace Triger
{

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		virtual void SetClearColor(const glm::vec4 &color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Ref<VertexArray> &vertexArray, uint32_t indexCount = 0) override;
	};
}

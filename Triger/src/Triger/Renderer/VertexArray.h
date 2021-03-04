/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : VertexArray.h
//   Created On  : 09/11/2020
//   Updated On  : 29/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include <memory>
#include "Triger/Renderer/Buffer.h"

namespace Triger
{

	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const Ref<VertexBuffer> &vertexBuffer) = 0;
		virtual void SetIndexBuffer(const Ref<IndexBuffer> &indexBuffer) = 0;

		virtual const std::vector<Ref<VertexBuffer>> &GetVertexBuffers() const = 0;
		virtual const Ref<IndexBuffer> &GetIndexBuffer() const = 0;

		static Ref<VertexArray> Create();
	};
}

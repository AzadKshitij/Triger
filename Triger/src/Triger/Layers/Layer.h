/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Layer.h
//   Created On  : 07/11/2020
//   Updated On  : 08/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once
#include "Triger/Core/Base.h"
#include "Triger/Core/Timestep.h"
#include "Triger/Events/Event.h"

namespace Triger
{

	class Layer
	{
	public:
		Layer(const std::string &name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event &event) {}

		inline const std::string &GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

} // namespace Triger

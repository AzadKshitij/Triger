/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : ImGuiLayer.h
//   Created On  : 07/11/2020
//   Updated On  : 08/12/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger/Layers/Layer.h"

#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/KeyEvent.h"
#include "Triger/Events/MouseEvent.h"

namespace Triger
{

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event &e) override;

		void Begin();
		void End();
		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors(std::string theme);

	private:
		bool m_BlockEvents = true;
	};
}

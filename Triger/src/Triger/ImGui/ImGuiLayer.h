#pragma once

#include "Triger/Layers/Layer.h"

#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/KeyEvent.h"
#include "Triger/Events/MouseEvent.h"

namespace Triger {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}
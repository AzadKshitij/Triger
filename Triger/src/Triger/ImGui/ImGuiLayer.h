#pragma once

#include "Triger/Layers/Layer.h"

#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/KeyEvent.h"
#include "Triger/Events/MouseEvent.h"

namespace Triger {

	class TRIGER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}
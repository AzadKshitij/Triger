/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : LayerStack.h
//   Created On  : 07/11/2020
//   Updated On  : 08/12/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger/Core/Base.h"
#include "Triger/Layers/Layer.h"

#include <vector>

namespace Triger
{

	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *overlay);
		void PopLayer(Layer *layer);
		void PopOverlay(Layer *overlay);

		std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer *>::iterator end() { return m_Layers.end(); }
		std::vector<Layer *>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer *>::reverse_iterator rend() { return m_Layers.rend(); }

		std::vector<Layer *>::const_iterator begin() const { return m_Layers.begin(); }
		std::vector<Layer *>::const_iterator end() const { return m_Layers.end(); }
		std::vector<Layer *>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
		std::vector<Layer *>::const_reverse_iterator rend() const { return m_Layers.rend(); }

	private:
		std::vector<Layer *> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};

}
#pragma once

#include "Triger/Core/Core.h"
#include "Layer.h"

#include <vector>

namespace Triger {

	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();
		/**
		 * @brief 
		 * @param layer 
		*/
		void PushLayer(Layer* layer);

		/**
		 * @brief 
		 * @param overlay 
		*/
		void PushOverlay(Layer* overlay);

		/**
		 * @brief 
		 * @param layer 
		*/
		void PopLayer(Layer* layer);

		/**
		 * @brief 
		 * @param overlay 
		*/
		void PopOverlay(Layer* overlay);

		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }

		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }

		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }


		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }

		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::const_iterator end()	const { return m_Layers.end(); }

		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }

		/**
		 * @brief 
		 * @return 
		*/
		std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};

}
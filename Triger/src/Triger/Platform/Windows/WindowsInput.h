#pragma once

#include "Triger/Core/Input.h"

namespace Triger {

	class WindowsInput : public Input
	{
	protected:
		
		/**
		 * @brief 
		 * @param keycode 
		 * @return 
		*/
		virtual bool IsKeyPressedImpl(int keycode) override;
		
		/**
		 * @brief 
		 * @param button 
		 * @return 
		*/
		virtual bool IsMouseButtonPressedImpl(int button) override;
		
		/**
		 * @brief 
		 * @return 
		*/
		virtual std::pair<float, float> GetMousePositionImpl() override;
		
		/**
		 * @brief 
		 * @return 
		*/
		virtual float GetMouseXImpl() override;
		
		/**
		 * @brief 
		 * @return 
		*/
		virtual float GetMouseYImpl() override;
	};

}
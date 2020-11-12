/**
 *  @file   Input.h.h
 *  @brief  Different type of input to interect with app
 *  @author Kshitij Azad
 *  @date   November 6, 2020
 ***********************************************/
#pragma once

#include "Triger/Core/Core.h"

namespace Triger
{
	/**
	 * @brief
	*/
	class TRIGER_API Input
	{
	protected:
		/**
		 * @brief
		*/
		Input() = default;

	public:
		/**
		 * @brief
		 * @param
		*/
		Input(const Input&) = delete;
		
		/**
		 * @brief
		 * @param
		 * @return
		*/
		Input& operator=(const Input&) = delete;
		
		/**
		 * @brief
		 * @param keycode
		 * @return
		*/
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		/**
		 * @brief
		 * @param button
		 * @return
		*/
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		
		/**
		 * @brief
		 * @return
		*/
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		
		/**
		 * @brief
		 * @return
		*/
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		
		/**
		 * @brief
		 * @return
		*/
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:
		/**
		 * @brief 
		 * @param keycode 
		 * @return 
		*/
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		/**
		 * @brief 
		 * @param button 
		 * @return 
		*/
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		/**
		 * @brief 
		 * @return 
		*/
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		/**
		 * @brief 
		 * @return 
		*/
		virtual float GetMouseXImpl() = 0;
		/**
		 * @brief 
		 * @return 
		*/
		virtual float GetMouseYImpl() = 0;

	private:
		/**
		 * @brief 
		*/
		static Scope<Input> s_Instance;
	};

} // namespace Triger 
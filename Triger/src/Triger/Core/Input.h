/**
 *  @file   Input.h
 *  @brief  Different type of input to interect with app
 *  @author Kshitij Azad
 *  @date   November 6, 2020
 ***********************************************/
#pragma once

#include "Triger/Core/KeyCodes.h"
#include "Triger/Core/MouseCodes.h"
#include <glm/glm.hpp>

namespace Triger
{

	class Input
	{
	public:
		virtual ~Input() = default;
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

} // namespace Triger 

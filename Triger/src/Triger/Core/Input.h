/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Input.h
//   Created On  : 07/11/2020
//   Updated On  : 11/12/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
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
		static bool IsKeyPressedOnce(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

} // namespace Triger

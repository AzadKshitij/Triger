/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : WindowsInput.cpp
//   Created On  : 07/11/2020
//   Updated On  : 11/12/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "trpch.h"
#include "Triger/Core/Input.h"

#include "Triger/Core/Application.h"
#include <GLFW/glfw3.h>

namespace Triger
{

	bool Input::IsKeyPressed(const KeyCode key)
	{
		auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool Input::IsKeyPressedOnce(const KeyCode key)
	{
		auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS;
	}

	bool Input::IsMouseButtonPressed(MouseCode button)
	{
		auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePosition()
	{
		auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return {(float)xpos, (float)ypos};
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().y;
	}

} // namespace Triger

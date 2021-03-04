/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Camera.h
//   Created On  : 27/11/2020
//   Updated On  : 27/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/#pragma once

#include <glm/glm.hpp>

namespace Triger {

	class Camera
	{
	public:
		Camera() = default;

		Camera(const glm::mat4& projection)
			: m_Projection(projection) {}

		virtual ~Camera() = default;

		const glm::mat4& GetProjection() const { return m_Projection; }
	
	protected:
		glm::mat4 m_Projection = glm::mat4(1.0f);
	};

}
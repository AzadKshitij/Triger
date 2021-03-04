/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Sandbox2D.h
//   Created On  : 11/11/2020
//   Updated On  : 11/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger.h"

	class Sandbox2D : public Triger::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Triger::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Triger::Event &e) override;

private:
	Triger::OrthographicCameraController m_CameraController;

	// Temp
	Triger::Ref<Triger::VertexArray> m_SquareVA;
	Triger::Ref<Triger::Shader> m_FlatColorShader;

	Triger::Ref<Triger::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};
};
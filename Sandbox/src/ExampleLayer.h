/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : ExampleLayer.h
//   Created On  : 16/11/2020
//   Updated On  : 16/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger.h"

class ExampleLayer : public Triger::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Triger::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Triger::Event &e) override;

private:
	Triger::ShaderLibrary m_ShaderLibrary;
	Triger::Ref<Triger::Shader> m_Shader;
	Triger::Ref<Triger::VertexArray> m_VertexArray;

	Triger::Ref<Triger::Shader> m_FlatColorShader;
	Triger::Ref<Triger::VertexArray> m_SquareVA;

	Triger::Ref<Triger::Texture2D> m_Texture, m_ChernoLogoTexture;

	Triger::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = {0.2f, 0.3f, 0.8f};
};

#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = Triger::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Triger::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Triger::RenderCommand::SetClearColor({ 0.3f, 0.3f, 0.3f, 1 });
	Triger::RenderCommand::Clear();

	Triger::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Triger::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Triger::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	Triger::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
	Triger::Renderer2D::EndScene();
	// TODO: Add these functions - Shader::SetMat4, Shader::SetFloat4
	// std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->Bind();
	// std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Triger::Event& e)
{
	m_CameraController.OnEvent(e);
}
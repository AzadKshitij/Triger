#include <Triger.h>

#include "Triger/Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Triger::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Triger::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Triger::Ref<Triger::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Triger::VertexBuffer::Create(vertices, sizeof(vertices)));
		Triger::BufferLayout layout = {
			{ Triger::ShaderDataType::Float3, "a_Position" },
			{ Triger::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Triger::Ref<Triger::IndexBuffer> indexBuffer;
		indexBuffer.reset(Triger::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Triger::VertexArray::Create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Triger::Ref<Triger::VertexBuffer> squareVB;
		squareVB.reset(Triger::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Triger::ShaderDataType::Float3, "a_Position" },
			{ Triger::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Triger::Ref<Triger::IndexBuffer> squareIB;
		squareIB.reset(Triger::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(Triger::Shader::Create(vertexSrc, fragmentSrc));

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			
			uniform vec3 u_Color;
			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader.reset(Triger::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));

		m_TextureShader.reset(Triger::Shader::Create("assets/shaders/Texture.glsl"));

		m_Texture = Triger::Texture2D::Create("assets/textures/Checkerboard.png");
		m_TrigerLogoTexture = Triger::Texture2D::Create("assets/Logos/TrigerLogo.png");
		m_TriEditorLogoTexture = Triger::Texture2D::Create("assets/Logos/TriEditorLogo.png");


		std::dynamic_pointer_cast<Triger::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Triger::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Triger::Timestep ts) override
	{
		if (Triger::Input::IsKeyPressed(TR_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (Triger::Input::IsKeyPressed(TR_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Triger::Input::IsKeyPressed(TR_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (Triger::Input::IsKeyPressed(TR_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Triger::Input::IsKeyPressed(TR_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (Triger::Input::IsKeyPressed(TR_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		Triger::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Triger::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Triger::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Triger::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Triger::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Triger::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		m_Texture->Bind();
		Triger::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_TrigerLogoTexture->Bind();
		Triger::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		
		m_TriEditorLogoTexture->Bind();
		Triger::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(2.0f), glm::vec3(2.0f)));

		// Triangle
		// Triger::Renderer::Submit(m_Shader, m_VertexArray);

		Triger::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Triger::Event& event) override
	{
	}
private:
	Triger::Ref<Triger::Shader> m_Shader;
	Triger::Ref<Triger::VertexArray> m_VertexArray;

	Triger::Ref<Triger::Shader> m_FlatColorShader, m_TextureShader;
	Triger::Ref<Triger::VertexArray> m_SquareVA;

	Triger::Ref<Triger::Texture2D> m_Texture, m_TrigerLogoTexture, m_TriEditorLogoTexture;

	Triger::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Triger::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Triger::Application* Triger::CreateApplication()
{
	return new Sandbox();
}
#include "Triger.h"

#include "ImGui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>


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

		std::shared_ptr<Triger::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Triger::VertexBuffer::Create(vertices, sizeof(vertices)));
		Triger::BufferLayout layout = {
			{ Triger::ShaderDataType::Float3, "a_Position" },
			{ Triger::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Triger::IndexBuffer> indexBuffer;
		indexBuffer.reset(Triger::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Triger::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Triger::VertexBuffer> squareVB;
		squareVB.reset(Triger::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Triger::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Triger::IndexBuffer> squareIB;
		squareIB.reset(Triger::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
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

		m_Shader.reset(new Triger::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new Triger::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate(Triger::Timestep ts) override
	{
		//TR_INFO("ExampleLayer::Update");
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

		Triger::Renderer::Submit(m_BlueShader, m_SquareVA);
		Triger::Renderer::Submit(m_Shader, m_VertexArray);

		Triger::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		/*ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();*/
	}

	void OnEvent(Triger::Event& event) override
	{
		//TR_TRACE("{0}", event);
		/*if (event.GetEventType() == Triger::EventType::KeyPressed)
		{
			Triger::KeyPressedEvent& e = (Triger::KeyPressedEvent&)event;
			if (e.GetKeyCode() == TR_KEY_TAB)
				TR_TRACE("Tab key is pressed (event)!");
			TR_TRACE("{0}", (char)e.GetKeyCode());
		}*/
	}
private:
	std::shared_ptr<Triger::Shader> m_Shader;
	std::shared_ptr<Triger::VertexArray> m_VertexArray;

	std::shared_ptr<Triger::Shader> m_BlueShader;
	std::shared_ptr<Triger::VertexArray> m_SquareVA;

	Triger::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 45.0f;
	float m_CameraRotationSpeed = 180.0f;
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
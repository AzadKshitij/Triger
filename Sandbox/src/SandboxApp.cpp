#include "Triger.h"

#include "Triger/Platform/OpenGL/OpenGLShader.h"

#include "Triger/Core/EntryPoint.h"
#include "Sandbox2D.h"


#include "ExampleLayer.h"

class Sandbox : public Triger::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Triger::Application* Triger::CreateApplication()
{
	return new Sandbox();
}
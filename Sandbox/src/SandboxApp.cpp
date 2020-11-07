#include "Triger.h"


class ExampleLayer : public Triger::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		TR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Triger::Event& event) override
	{
		TR_TRACE("{0}", event);
	}
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
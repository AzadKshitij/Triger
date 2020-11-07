#include "Triger.h"

#include "ImGui/imgui.h"


class ExampleLayer : public Triger::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//TR_INFO("ExampleLayer::Update");
		if (Triger::Input::IsKeyPressed(TR_KEY_TAB))
			TR_TRACE("Tab key is pressed (poll)!");
	}
	
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Triger::Event& event) override
	{
		//TR_TRACE("{0}", event);
		if (event.GetEventType() == Triger::EventType::KeyPressed)
		{
			Triger::KeyPressedEvent& e = (Triger::KeyPressedEvent&)event;
			if (e.GetKeyCode() == TR_KEY_TAB)
				TR_TRACE("Tab key is pressed (event)!");
			TR_TRACE("{0}", (char)e.GetKeyCode());
		}
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
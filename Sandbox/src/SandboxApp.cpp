#include "Triger.h"

class Sandbox : public Triger::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Triger::Application* Triger::CreateApplication() 
{
	return new Sandbox();
}
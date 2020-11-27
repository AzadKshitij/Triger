#include <Triger.h>
#include <Triger/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Triger {

	class Tridor : public Application
	{
	public:
		Tridor()
			: Application("Tridor")
		{
			PushLayer(new EditorLayer());
		}

		~Tridor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Tridor();
	}

}
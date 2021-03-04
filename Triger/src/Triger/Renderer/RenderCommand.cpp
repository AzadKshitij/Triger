/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : RenderCommand.cpp
//   Created On  : 10/11/2020
//   Updated On  : 10/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "trpch.h"

#include "Triger/Renderer/RenderCommand.h"

	namespace Triger
{

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}

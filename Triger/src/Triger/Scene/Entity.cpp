/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Entity.cpp
//   Created On  : 27/11/2020
//   Updated On  : 27/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#include "trpch.h"
#include "Triger/Scene/Entity.h"

	namespace Triger
{

	Entity::Entity(entt::entity handle, Scene * scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}
}

#include "trpch.h"
#include "Entity.h"

namespace Triger {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}
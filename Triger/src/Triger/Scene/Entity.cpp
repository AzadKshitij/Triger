#include "trpch.h"
#include "Triger/Scene/Entity.h"

namespace Triger {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}

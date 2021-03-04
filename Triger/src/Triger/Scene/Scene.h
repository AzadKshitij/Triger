/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Scene.h
//   Created On  : 27/11/2020
//   Updated On  : 11/12/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "entt.hpp"

#include "Triger/Core/Timestep.h"
#include "Triger/Renderer/EditorCamera.h"

namespace Triger
{

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string &name = std::string());
		void DestroyEntity(Entity entity);

		void OnUpdateEditor(Timestep ts, EditorCamera &camera);
		void OnUpdateRuntime(Timestep ts);
		void OnViewportResize(uint32_t width, uint32_t height);

		Entity GetPrimaryCameraEntity();

	private:
		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;

	private:
		template <typename T>
		void OnComponentAdded(Entity entity, T &component);
	};
}

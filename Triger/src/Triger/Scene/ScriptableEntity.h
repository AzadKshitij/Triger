/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : ScriptableEntity.h
//   Created On  : 29/11/2020
//   Updated On  : 29/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger/Scene/Entity.h"

	namespace Triger
{

	class ScriptableEntity
	{
	public:
		virtual ~ScriptableEntity() {}

		template <typename T>
		T &GetComponent()
		{
			return m_Entity.GetComponent<T>();
		}

	protected:
		virtual void OnCreate() {}
		virtual void OnDestroy() {}
		virtual void OnUpdate(Timestep ts) {}
		
	private:
		Entity m_Entity;
		friend class Scene;
	};
}

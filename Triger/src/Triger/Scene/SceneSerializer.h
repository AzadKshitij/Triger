/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : SceneSerializer.h
//   Created On  : 29/11/2020
//   Updated On  : 29/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger/Scene/Scene.h"

	namespace Triger
{

	class SceneSerializer
	{
	public:
		SceneSerializer(const Ref<Scene> &scene);

		void Serialize(const std::string &filepath);
		void SerializeRuntime(const std::string &filepath);

		bool Deserialize(const std::string &filepath);
		bool DeserializeRuntime(const std::string &filepath);

	private:
		Ref<Scene> m_Scene;
	};
}

#pragma once

/*------------ Copyright � 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Tridor
//   License     : https://opensource.org/licenses/MIT
//   File        : SceneHierarchyPanel.cpp
//   Created On  : 25/07/2021
//   Updated On  : 25/07/2021
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/

#include <filesystem>

#include "Triger/Renderer/Texture.h"

namespace Triger {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
		Ref<Texture2D> m_FileIconPng;
	};

}

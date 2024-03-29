#include <trpch.h>
#include "ContentBrowserPanel.h"

#include <imgui/imgui.h>

namespace Triger {

	// Once we have projects, change this
	extern const std::filesystem::path g_AssetPath = "assets";
	std::filesystem::path m_lastVisitedPath = "assets";

	ContentBrowserPanel::ContentBrowserPanel()
		: m_CurrentDirectory(g_AssetPath)
	{
		m_DirectoryIcon = Texture2D::Create("Resources/Icons/ContentBrowser/DirectoryIcon.png");
		m_FileIcon = Texture2D::Create("Resources/Icons/ContentBrowser/FileIcon.png");
		m_FileIconPng = Texture2D::Create("Resources/Icons/ContentBrowser/FileIconPng.png");
	}

	void ContentBrowserPanel::OnImGuiRender()
	{
		ImGui::Begin("Content Browser"); 
		//if (m_CurrentDirectory != std::filesystem::path(s_AssetPath))
		//{ 
			if (ImGui::ArrowButton("Back", ImGuiDir_Left) && m_CurrentDirectory != std::filesystem::path(g_AssetPath))
			{
				m_CurrentDirectory = m_CurrentDirectory.parent_path();
				if (m_lastVisitedPath.parent_path() != m_CurrentDirectory)
				{
					m_lastVisitedPath = m_lastVisitedPath.parent_path();
				}
			}  
			ImGui::SameLine();
			if (ImGui::ArrowButton("Forward", ImGuiDir_Right))
			{
				m_CurrentDirectory = m_lastVisitedPath;
			} 
		//}

		static float padding = 10.0f;
		static float thumbnailSize = 128.0f;
		float cellSize = thumbnailSize + padding;

		float panelWidth = ImGui::GetContentRegionAvail().x;
		int columnCount = (int)(panelWidth / cellSize);
		if (columnCount < 1)
			columnCount = 1;

		ImGui::Columns(columnCount, 0, false);

		for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
		{
			const auto& path = directoryEntry.path();
			auto relativePath = std::filesystem::relative(path, g_AssetPath);
			std::string filenameString = relativePath.filename().string();

			ImGui::PushID(filenameString.c_str());
			Ref<Texture2D> icon = directoryEntry.is_directory() ? m_DirectoryIcon : path.extension() == ".png" ? m_FileIconPng : m_FileIcon;
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));

			ImGui::ImageButton((ImTextureID)icon->GetRendererID(), { thumbnailSize, thumbnailSize }, { 0, 1 }, { 1, 0 });
			

			if (ImGui::BeginDragDropSource())
			{
				const wchar_t* itemPath = relativePath.c_str();
				ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, (wcslen(itemPath) + 1) * sizeof(wchar_t));
				ImGui::EndDragDropSource();
			}

			ImGui::PopStyleColor();

			if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
			{
				if (directoryEntry.is_directory())
				{
					m_CurrentDirectory /= path.filename();
					m_lastVisitedPath = path;
				}
			}
			
			ImGui::TextWrapped(filenameString.c_str());

			ImGui::NextColumn();
			
			ImGui::PopID();
		} 


		ImGui::Columns(1);
		ImGui::SliderFloat("Thumbnail Size", &thumbnailSize, 60, 512);
		ImGui::SliderFloat("Padding", &padding, 0, 32); 
		ImGui::ShowDemoWindow();
		// TODO: status bar

		ImGui::End();
	}

}

/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Tridor
//   License     : https://opensource.org/licenses/MIT
//   File        : EditorLayer.h
//   Created On  : 27/11/2020
//   Updated On  : 27/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include "Triger.h"
#include "Panels/SceneHierarchyPanel.h"
#include "Triger/Renderer/EditorCamera.h"

	namespace Triger
{

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event &e) override;

	private:
		bool OnKeyPressed(KeyPressedEvent &e);
		bool OnMouseButtonPressed(MouseButtonEvent &e);

		void NewScene();
		void OpenScene();
		void SaveScene();
		void SaveSceneAs();

	private:
		Triger::OrthographicCameraController m_CameraController;

		// Temp
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondCamera;
		Entity m_HoveredEntity;

		std::string m_openedFilepath;

		bool m_PrimaryCamera = true;
		EditorCamera m_EditorCamera;

		Ref<Texture2D> m_CheckerboardTexture;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = {0.0f, 0.0f};
		glm::vec2 m_ViewportBounds[2];
		glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};

		int m_GizmoType = -1;
		bool m_AllowShortcuts = true;

		// View
		bool m_showConsole = true;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
	};
}

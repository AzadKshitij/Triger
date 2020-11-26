#pragma once

#include "Triger/Renderer/RenderCommand.h"

#include "Triger/Renderer/OrthographicCamera.h"
#include "Triger/Renderer/Shader.h"

namespace Triger {

	class Renderer
	{
	public:
		static void Init();

		static void BeginScene(OrthographicCamera& camera);
		static void OnWindowResize(uint32_t width, uint32_t height);
		static void EndScene();

		static void Shutdown();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Scope<SceneData> s_SceneData;
	};

}
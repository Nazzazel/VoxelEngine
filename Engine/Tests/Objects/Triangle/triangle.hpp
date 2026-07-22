#pragma once
#include "Engine/Assets/AssetManager/asset_manager.hpp"
#include "../../../Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Engine/RenderingAPI/Shader/game_shader.hpp"
#include "Engine/RenderingAPI/Buffers/vertex_array.hpp"
#include "Engine/RenderingAPI/Buffers/vertex_buffer.hpp"
#include "Engine/RenderingAPI/Buffers/index_buffer.hpp"

namespace engine
{
	class IRenderer;
	class AssetManager;
	class VertexBuffer;
	class IndexBuffer;
	class VertexArray;
	class Shader;

	class Triangle
	{
	public:
		Triangle() = default;
		~Triangle() = default;
		
		void Init(AssetManager& assets);

		void Draw(IRenderer& renderer);


	private:
		std::unique_ptr<VertexArray>  m_vao;
		//std::unique_ptr<VertexBuffer> m_vbo;
		//std::unique_ptr<IndexBuffer>  m_ibo;

		engine::GameShader* m_shader = nullptr;

		//ERASE LATER
		int location;

	};

}
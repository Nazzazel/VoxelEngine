#pragma once
#include "Engine/Assets/AssetManager/asset_manager.hpp"
#include "../../../Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Engine/RenderingAPI/Shader/game_shader.hpp"
#include "Engine/RenderingAPI/Buffers/vertex_array.hpp"
#include "Engine/RenderingAPI/Buffers/vertex_buffer.hpp"
#include "Engine/RenderingAPI/Buffers/index_buffer.hpp"
#include <vector>
#include <string>
#include <memory>

namespace engine
{
	class IRenderer;
	class AssetManager;
	class VertexBuffer;
	class IndexBuffer;
	class VertexArray;
	class Shader;


	struct ConsoleVertex {
		float x, y; // 2D Screen Position
		float u, v; // Texture Coordinates
	};

	class Console
	{
	public:
		Console() = default;
		~Console() = default;

		void Init(AssetManager& assets);

		void Draw(IRenderer& renderer);
		//void AdditionalData(float& i);

		void print(const std::string& message);

		const std::vector<std::string>& getLines() const;


	private:
		std::vector<std::string> m_buffer;
		const size_t maxLines = 100;

		// Font spacing metrics (Monospace example)
		const float m_charWidth = 10.0f;
		const float m_charHeight = 20.0f;
		const float m_lineHeight = 24.0f;

		std::unique_ptr<VertexArray>  m_vao;
		std::shared_ptr<VertexBuffer> m_vbo; // Kept as member to upload data every frame

		engine::GameShader* m_shader = nullptr;
		// unsigned int m_fontTextureID = 0; // Assign your loaded font texture sheet ID here
	};


}

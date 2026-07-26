#pragma once
#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Core/Systems/Assets/Shaders/IShader.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexArray.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexBuffer.hpp"
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"


namespace engine
{


	class Triangle
	{
	public:
		Triangle() = default;
		~Triangle() = default;

		void Init(AssetSystem& assets);

		void Draw(IRenderer& renderer);


	private:
		std::unique_ptr<IVertexArray>  m_vao;
		//std::unique_ptr<VertexBuffer> m_vbo;
		//std::unique_ptr<IndexBuffer>  m_ibo;

		engine::IShader* m_shader = nullptr;

		//ERASE LATER
		int location;

	};

}
#pragma once
//#include "Engine/Assets/AssetManager/asset_manager.hpp"

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexArray.hpp"
#include "Engine/Systems/Renderer/Buffers/IVertexBuffer.hpp"
#include "Engine/Systems/Renderer/Buffers/IIndexBuffer.hpp"

namespace engine
{
	//class IRenderer;
	//class AssetSystem;
	//class VertexBuffer;
	//class IndexBuffer;
	//class VertexArray;
	//class Shader;

	class Rot_Cube
	{
	public:
		Rot_Cube() = default;
		~Rot_Cube();

		void Init(AssetSystem& assets);


		void SetPosition(const glm::vec3& position) { m_Position = position; }
		void Translate(const glm::vec3& offset) { m_Position += offset; }

		void Draw(IRenderer& renderer);
		//void AdditionalData(float& i);


	private:
		//std::shared_ptr<IVertexArray>  m_vao;
		//std::unique_ptr<VertexBuffer> m_vbo;
		//std::unique_ptr<IndexBuffer>  m_ibo;
		std::shared_ptr<Mesh> m_Mesh;
		std::shared_ptr<Material> m_Material;

		engine::IShader* m_shader = nullptr;

		//ERASE LATER
		//int location;
		//float m_i;

		glm::vec3 m_Position = glm::vec3(0.0f);
	};

}
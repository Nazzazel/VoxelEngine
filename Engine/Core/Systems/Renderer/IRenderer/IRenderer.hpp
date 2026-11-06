#pragma once


#include <memory>
//#include <Engine/Res/Assets/Shaders/ShadersLib/shader_library.hpp>
#include "Engine/Systems/Renderer/Buffers/IVertexArray.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Core/Systems/Assets/Shaders/IShader.hpp"


namespace engine
{
	class Material;
	class Mesh;


	struct DrawCommand {
		//std::shared_ptr<Mesh>		mesh;
		std::shared_ptr<Mesh>		mesh;
		//std::shared_ptr<Material>	material;
		std::shared_ptr<Material>	material;

		glm::mat4 modelMatrix = glm::mat4(1.0f);
	};

	struct SceneData {
		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
		glm::vec3 cameraPosition;
	};





    class IRenderer
    {
    public:


        virtual ~IRenderer() = default;
        
        virtual Result Init() = 0;
        virtual void BeginFrame() = 0;
        virtual void EndFrame() = 0;

        virtual void OnResize(int width, int height) = 0;

    	// Add the Submit function
    	virtual void Submit(const DrawCommand& command) = 0;
    	virtual void SetSceneData(const SceneData& scene_data) = 0;

		//virtual void DrawTriangle() = 0; //TODO remove this later
        //virtual void DrawIndexed(const std::unique_ptr<VertexArray>& vao) = 0;
        virtual void DrawIndexed(uint32_t indexCount,int8_t mode) = 0;
    	void DrawMeshTasks(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ){};//TODO Later

    	virtual float GetAspectRatio() = 0;

        static std::unique_ptr<IRenderer> Create();

	protected:
    	float m_aspectRatio = 0.0f;

		//std::unique_ptr<engine::ShaderLibrary> m_ShaderLibrary; //TODO remove this later




    };
}

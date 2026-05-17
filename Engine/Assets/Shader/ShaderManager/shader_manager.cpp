#include "shader_manager.hpp"

#include "Backends/API/renderer_api.hpp"




#include "Backends/OpenGL/Shader/opengl_shader.hpp"
#include <stdexcept>



namespace engine
{
	ShaderManager::ShaderManager(IAssetProvider& provider)
		:m_provider(provider)
		,m_shader_loader()
	{
		
	}

	ShaderManager::~ShaderManager()
	{

	}

	void ShaderManager::Add(ShaderTypeID type)
	{
		backends::RendererAPIType api = backends::RendererAPI::GetAPI();

		//std::string basePath = "Res/Assets/Shaders/ShaderTypes/Basic/OpenGL/";//TODO change later
		
		std::string basePath = m_provider.GetAssetRoot() + "Engine/Res/Assets/Shaders/";//TODO change later

		std::unique_ptr<engine::GameShader> shader;

		switch (api)
		{
		case backends::RendererAPIType::OpenGL:

			basePath +=
				ShaderTypeIDToString(type) + // Conrerts the ShaderTypeID to a string to be used in the file path
				"/" + 
				backends::RendererAPI::RendererAPIToString(api) + // API to string aka OpelGL to "OpenGL"
				"/";


			shader = engine::GameShader::Create(
					m_shader_loader.OpenGLShaderLoader(basePath + "vert.shader"),
					m_shader_loader.OpenGLShaderLoader(basePath + "frag.shader")
				);

			//return std::make_unique
			//	<backends::OpenGLShader>(
			//	basePath + "vert.shader",
			//	basePath + "frag.shader"
			//);
			//std::cout << basePath + "vert.shader" << std::endl;
			break;
		case backends::RendererAPIType::Vulkan:
			break;
			//return std::make_shared<VulkanShader>(
			//	basePath + "vulkan/vert.spv",
			//	basePath + "vulkan/frag.spv"
			//);
		case backends::RendererAPIType::DirectX11:
			break;
			//return std::make_shared<DX11Shader>(
			//	basePath + "directx/vert.hlsl",
			//	basePath + "directx/frag.hlsl"
			//);
		default:
			throw std::runtime_error("Unsupported RendererAPIType");
			break;
		}

		
		m_Shaders[type] = std::move(shader);


	}

	GameShader* ShaderManager::Get(ShaderTypeID type)
	{
		auto it = m_Shaders.find(type);
		return (it != m_Shaders.end()) ? it->second.get() : nullptr;
	}

	std::string ShaderManager::ShaderTypeIDToString(ShaderTypeID type)
	{

		switch (type)
		{
		case ShaderTypeID::Basic:
			return "Basic";
		case ShaderTypeID::Lighting:
			return "Lighting";
		case ShaderTypeID::PBR:
			return "PBR";
		case ShaderTypeID::Shadow:
			return "Shadow";
		case ShaderTypeID::Skybox:
			return "Skybox";
		case ShaderTypeID::UI:
			return "UI";
		case ShaderTypeID::Particles:
			return "Particles";
		case ShaderTypeID::Debug:
			return "Debug";
		default:
			return "Unknown";
		}
	}

}
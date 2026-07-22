#include "IShader.hpp"
//#include <iostream>
//#include <memory>
//
//
#include <Backends/API/RendererApi.hpp>
#include <Backends/OpenGL/Shader/opengl_shader.hpp>
////
////
////#include <Engine/Res/Assets/Shaders/ShadersLib/shader_library.hpp>
////#include <DebugTools/Core/Logger/logger.hpp>
//#include "Engine/Assets/Shader/ShaderManager/Core/ShaderTypeID.h"

//
namespace engine
{

    //{
	//std::unique_ptr<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	//std::unique_ptr<engine::GameShader> engine::GameShader::Create()
    //}

    std::unique_ptr<engine::IShader> engine::IShader::Create(
    	const std::string& vertexSrc,
    	const std::string& fragmentSrc



    	)
	{
        backends::RendererAPIType api = backends::RendererAPI::GetAPI();

       // std::string basePath = "Res/Assets/Shaders/ShaderTypes/" + engine::ShaderLibrary::ShaderTypeToString(type) + "/" + backends::RendererAPI::RendererAPIToString(api) + "/";
        std::string basePath = "Res/Assets/Shaders/ShaderTypes/Basic/OpenGL/";

		//AssetManager::Loa dShader(basePath + "vert.shader");

        switch (api)
        {
        case backends::RendererAPIType::OpenGL:
            return std::make_unique
                <backends::OpenGLShader>( vertexSrc, fragmentSrc );

			//std::cout << basePath + "vert.shader" << std::endl;

        case backends::RendererAPIType::Vulkan:
            break;
            //return std::make_shared<VulkanShader>(
            //    basePath + "vulkan/vert.spv",
            //    basePath + "vulkan/frag.spv"
            //);

        case backends::RendererAPIType::DirectX11:
            break;
            //return std::make_shared<DX11Shader>(
            //    basePath + "directx/vert.hlsl",
            //    basePath + "directx/frag.hlsl"
            //);

        default:
            return nullptr;
        }
    	return nullptr;
	}






   // std::string GameShader::LoadShader(backends::RendererAPIType type, const std::string& filepath)
   // {
   //     switch (type)
   //     {
   //     case backends::RendererAPIType::Default:
   //     {
		 //   //TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Error, "Renderer API not set!"); //TODO add Logger
		 //   return "";
   //     }
   //     case backends::RendererAPIType::OpenGL:
   //     {
			////TODO DEAL WITH THIS debugtools::Logger::Log(debugtools::LogLevel::Info, "Loading shader from file: " + filepath);
			//return LoadShader(backends::RendererAPIType::OpenGL, filepath);
   //     }

   //         
   //     case backends::RendererAPIType::Vulkan:
   //         break;
   //     case backends::RendererAPIType::DirectX11:
   //         break;
   //     case backends::RendererAPIType::DirectX12:
   //         break;
   //     default:
   //         break;
   //     }


   //     std::ifstream stream(filepath);

   //     if (!stream.is_open())
   //     {
   //         std::cerr << "Nie mozna otworzyc pliku!\n";
   //         return "";
   //     }

   //     std::stringstream ss;
   //     ss << stream.rdbuf();
   //     return ss.str();

   //     return std::string();
   // }
}
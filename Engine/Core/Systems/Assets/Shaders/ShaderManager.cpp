//
// Created by nazzazel on 22.07.2026.
//

#include "ShaderManager.hpp"

#include "API/RendererApi.hpp"


namespace engine
{
    ShaderManager::ShaderManager(AssetProviderContext& provider)
        :m_AssetProvider(provider)
    {
        m_LoggerSystem = m_AssetProvider.GetLoggerSystem();


    }

    void ShaderManager::SetTraditionalPipeline(TraditionalPipelineShaderFlag flag)
    {

        if (Result result = EvaluateShaderByAPI(flag);result.IsFailure()){m_LoggerSystem->AddResult(result);}

    }

    void ShaderManager::SetTaskPipeline(TaskPipelineShaderFlag flag)
    {

        if (Result result = EvaluateShaderByAPI(flag);result.IsFailure()){m_LoggerSystem->AddResult(result);}

    }

    void ShaderManager::LoadEngineShader(ShaderTypeID type)
    {
        backends::RendererAPIType api = backends::RendererAPI::GetAPI();
        std::string basePath = m_AssetProvider.GetAssetRoot() + "Engine/Res/Assets/Shaders/";
        basePath +=
            ShaderTypeIDToString(type) + // Conrerts the ShaderTypeID to a string to be used in the file path
                "/" +
                    backends::RendererAPI::RendererAPIToString(api) + // API to string aka OpelGL to "OpenGL"
                        "/";
      // std::unique_ptr<engine::IShader> shader = engine::IShader::Create(
      //    // {ShaderStage::Vertex, basePath + "Shaders/Vertex.vert.glsl"}
      //     {ShaderStage::Vertex, GetSourceFromShader(basePath)}
      // );


        std::unique_ptr<engine::IShader> shader = engine::IShader::Create(
   // {ShaderStage::Vertex, basePath + "Shaders/Vertex.vert.glsl"}
    {ShaderStage::Vertex, GetSourceFromShader(basePath)}

        );

        //api specific filter for shaders



    }





	std::string ShaderManager::ShaderTypeIDToString(ShaderTypeID type)
    {
        switch (type)
        {
            case ShaderTypeID::Basic:       return "Basic";
            case ShaderTypeID::Lighting:    return "Lighting";
            case ShaderTypeID::PBR:         return "PBR";
            case ShaderTypeID::Shadow:      return "Shadow";
            case ShaderTypeID::Skybox:      return "Skybox";
            case ShaderTypeID::UI:          return "UI";
            case ShaderTypeID::Particles:   return "Particles";
            case ShaderTypeID::Debug:       return "Debug";
            default:                        return "Unknown";
        }
    }

    Result ShaderManager::EvaluateShaderByAPI(TraditionalPipelineShaderFlag flag)
    {
        backends::RendererAPIType api = backends::RendererAPI::GetAPI();
        switch (api)
        {
        case backends::RendererAPIType::OpenGL:
        case backends::RendererAPIType::Vulkan:
            {
                if (!flag.HasFragment() || !flag.HasVertex())
                {
                    return GRAPHIC_RESULT(ShaderObjectDoesNotPossessNessesaryShaderStages,Error);
                }
                return {};
            }
        //TODO ADD DIRECT X
        }

        return {};//Nothing means Success
    }

    Result ShaderManager::EvaluateShaderByAPI(TaskPipelineShaderFlag flag)
    {
        backends::RendererAPIType api = backends::RendererAPI::GetAPI();
        switch (api)
        {
        case backends::RendererAPIType::OpenGL:
            {
                if (!flag.HasFragment() || !flag.HasMesh() || !flag.HasTask()) //Pipeline Disabled due to OpenGL being a legacyAPI and support of this pipeline is very difficult to deal with just switch to Vulkan
                {
                    return GRAPHIC_RESULT(ShaderObjectAPINotSupportingElementsOfPipeline, Warning);
                }
                return {};
            }

        case backends::RendererAPIType::Vulkan:
            {
                if (!flag.HasFragment() || !flag.HasMesh())
                {
                    return GRAPHIC_RESULT(ShaderObjectDoesNotPossessNessesaryShaderStages,Error);
                }
                return {};
            }

        //TODO ADD DIRECT X
        }

        return {};//Nothing means Success

    }


    void ShaderManager::LoadCustomShader(ShaderTypeID type, const std::filesystem::path& path) //loadion custom way of load shaders from for example // maybe later a specification of api
    {

        //TODO LATER
    }


    IShader* ShaderManager::Get(ShaderTypeID type)
    {

    }

    const IShader* ShaderManager::Get(ShaderTypeID type) const
    {
    }

    void ShaderManager::Clear()
    {
        if (!m_Shaders.empty())
        {
            m_Shaders.clear();
        }
    }
} // engine
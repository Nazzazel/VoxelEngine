//
// Created by nazzazel on 22.07.2026.
//

#include "ShaderManager.hpp"

#include "ShaderData.hpp"
#include "API/RendererApi.hpp"


namespace engine
{
    ShaderManager::ShaderManager(AssetProviderContext* provider)
        :m_AssetProvider(provider)
    {
        m_Logger = m_AssetProvider->GetLoggerSystem();


    }

    void ShaderManager::SetTraditionalPipeline(TraditionalPipelineShaderFlag flag)
    {

        if (Result result = EvaluateShaderByAPI(flag);result.IsFailure()){m_Logger->AddResult(result);}else{m_TradFLag = flag;m_Logger->AddInfo("SetUp Traditional Pipeline ");}

    }

    void ShaderManager::SetTaskPipeline(TaskPipelineShaderFlag flag)
    {

        if (Result result = EvaluateShaderByAPI(flag);result.IsFailure()){m_Logger->AddResult(result);}else{m_TaskFlag = flag;m_Logger->AddInfo("SetUp Task Pipeline ");}

    }

    Result ShaderManager::LoadEngineShader(ShaderTypeID type)
    {
        if (Result result = EvaluateShaderByAPI(m_TradFLag);result.IsFailure())
        {
            m_Logger->AddResult(result);
            return result;
        }
        else
        {m_Logger->AddInfo("Loaded Shader Succesful - Traditional Shader");}


        backends::RendererAPIType api = backends::RendererAPI::GetAPI();
        std::string basePath = m_AssetProvider->GetAssetRoot();
        //std::string basePath = m_AssetProvider->GetAssetRoot() + "Engine/Res/Assets/Shaders/";
        basePath +=
            ShaderTypeIDToString(type) + // Conrerts the ShaderTypeID to a string to be used in the file path
                "/" +
                    backends::RendererAPI::RendererAPIToString(api) + // API to string aka OpelGL to "OpenGL"
                        "/";
        m_Logger->AddInfo(basePath);
       std::unique_ptr<engine::IShader> TraditionalPipelineShader = engine::IShader::Create({
          // {ShaderStage::Vertex, basePath + "Shaders/Vertex.vert.glsl"}
           LoadShaderFromFilePath(ShaderStage::Vertex,basePath),
           LoadShaderFromFilePath(ShaderStage::Fragment,basePath)
       });

        //{ShaderStage::Vertex, GetSourceFromShader(basePath)}

        // int a;
        // std::unique_ptr<engine::IShader> gggg = engine::IShader::CreateInt(
        //     {a,a}
        //
        // );

 //       std::unique_ptr<engine::IShader> shader = engine::IShader::Create(
 //  // {ShaderStage::Vertex, basePath + "Shaders/Vertex.vert.glsl"}
 //   {ShaderStage::Vertex, GetSourceFromShader(basePath)}
//
 //       );
        //todo dffdfgdfghhdfgfghfgh shader

        //api specific filter for shaders


        return {};
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

    ShaderData ShaderManager::LoadShaderFromFilePath(ShaderStage stage, const std::filesystem::path& path,ShaderLanguage language, const std::string& customFileName )
    {
        ShaderData data;
        data.stage = stage;

        std::string shaderName = customFileName.empty() ? "shader" : customFileName;

        std::string extension = "";

        switch (stage)
        {
            case ShaderStage::Vertex:                       {extension = ".vert"; break;}
            case ShaderStage::TessellationControl:          {extension = ".tesc"; break;}
            case ShaderStage::TessellationEvaluation:       {extension = ".tese"; break;}
            case ShaderStage::Geometry:                     {extension = ".geom"; break;}
            case ShaderStage::Task:                         {extension = ".task"; break;}
            case ShaderStage::Mesh:                         {extension = ".mesh"; break;}
            case ShaderStage::Fragment:                     {extension = ".frag"; break;}
            case ShaderStage::Compute:                      {extension = ".comp"; break;}
            case ShaderStage::RayGen:                       {extension = ".rgen"; break;}
            case ShaderStage::Intersection:                 {extension = ".rint"; break;}
            case ShaderStage::AnyHit:                       {extension = ".rahit"; break;}
            case ShaderStage::ClosestHit:                   {extension = ".rchit"; break;}
            case ShaderStage::Miss:                         {extension = ".rmiss"; break;}
            case ShaderStage::Callable:                     {extension = ".rcall"; break;}
        }

        switch (language)
        {
            case ShaderLanguage::GLSL:{extension += ".glsl"; break;}
            case ShaderLanguage::HLSL:{extension += ".hlsl"; break;}
        }


        std::filesystem::path shaderPath = path / (shaderName + extension);



    }


    Result ShaderManager::LoadCustomShader(ShaderTypeID type, const std::filesystem::path& path) //loadion custom way of load shaders from for example // maybe later a specification of api
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
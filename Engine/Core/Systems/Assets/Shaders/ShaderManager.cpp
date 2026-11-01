//
// Created by nazzazel on 22.07.2026.
//

#include "ShaderManager.hpp"

#include "ShaderData.hpp"
#include "API/RendererApi.hpp"
#include "Loader/ShaderLoader.hpp"


namespace engine
{
    ShaderManager::ShaderManager(AssetProviderContext* provider)
        :m_AssetProvider(provider)
    {
        m_Logger        = m_AssetProvider->GetLoggerSystem();
        m_FileSystem    = m_AssetProvider->GetFileSystem();


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
        //std::string basePath = m_AssetProvider->GetAssetRoot();
        std::string basePath = m_AssetProvider->GetAssetRoot() + "/Res/Assets/Shaders/";
        basePath +=
            ShaderTypeIDToString(type) + // Conrerts the ShaderTypeID to a string to be used in the file path
                "/" +
                    backends::RendererAPI::RendererAPIToString(api) + // API to string aka OpelGL to "OpenGL"
                        "/";
        m_Logger->AddInfo(basePath);

        //const std::initializer_list<ShaderData> TraditionalShaders{};
      //  TraditionalShaders.a//

        //TODO DEAL WITH PIPELINES HAVE AN IDEA THIS CLASS NEEDS RETHINKING RAYTHACIN PIPELINE TRADITIONAL PIPELINE TAST PIPELINE AND COMPUTE PIPELINE



        std::vector<ShaderData> traditionalShaderStages;
        if (m_TradFLag.HasVertex())                 {traditionalShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::Vertex                   ,basePath,ShaderLanguage::GLSL));}
        if (m_TradFLag.HasTessellationControl())    {traditionalShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::TessellationControl      ,basePath,ShaderLanguage::GLSL));}
        if (m_TradFLag.HasTessellationEvaluation()) {traditionalShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::TessellationEvaluation   ,basePath,ShaderLanguage::GLSL));}
        if (m_TradFLag.HasGeometry())               {traditionalShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::Geometry                 ,basePath,ShaderLanguage::GLSL));}
        if (m_TradFLag.HasFragment())               {traditionalShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::Fragment                 ,basePath,ShaderLanguage::GLSL));}

         std::unique_ptr<engine::IShader> f_TraditionalPipelineShader = engine::IShader::Create(traditionalShaderStages,ShaderTypeIDToString(type));
        if (f_TraditionalPipelineShader)
        {
            m_Logger->AddInfo("Shader wa successfully added to the list : -> ", ShaderTypeIDToString(type) );
            m_Shaders.emplace(type,std::move(f_TraditionalPipelineShader));
        }
        else
        {
            m_Logger->AddError("f_TraditionalPipelineShader was not initiated ShaderManager.cpp: ");
        }

        //TODO TASK BASED PIPELINE I NEED TO UNDERSTAND THIS , not now.
     //  std::vector<ShaderData> taskShaderStages;
     //  if (m_TradFLag.HasVertex())                 {taskShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::Vertex                   ,basePath,ShaderLanguage::GLSL));}
     //  if (m_TradFLag.HasTessellationControl())    {taskShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::TessellationControl      ,basePath,ShaderLanguage::GLSL));}
     //  if (m_TradFLag.HasTessellationEvaluation()) {taskShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::TessellationEvaluation   ,basePath,ShaderLanguage::GLSL));}
     //  if (m_TradFLag.HasGeometry())               {taskShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::Geometry                 ,basePath,ShaderLanguage::GLSL));}
     //  if (m_TradFLag.HasFragment())               {taskShaderStages.push_back(LoadShaderFromFilePath(ShaderStage::Fragment                 ,basePath,ShaderLanguage::GLSL));}

     //  std::unique_ptr<engine::IShader> f_TaskPipelineShader = engine::IShader::Create(taskShaderStages);


       // std::unique_ptr<engine::IShader> TraditionalPipelineShader = engine::IShader::Create({
       //    // {ShaderStage::Vertex, basePath + "Shaders/Vertex.vert.glsl"}
       //     LoadShaderFromFilePath(ShaderStage::Vertex,basePath,ShaderLanguage::GLSL),
       //     LoadShaderFromFilePath(ShaderStage::Fragment,basePath,ShaderLanguage::GLSL)
       // });

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
                    m_Logger->AddError("Traditional Shader Pipeline - Shader Object does not posses nessesary shader stages ( Fragment or Vertex ) )");
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

        //std::cout << shaderPath << std::endl;


        data.shaderSource = GetSourceFromShader(shaderPath,language);

      //  m_Logger->AddInfo("Shader Content: \n " , data.shaderSource);

        return data;
    }

    std::string ShaderManager::GetSourceFromShader(std::filesystem::path shaderPath,ShaderLanguage shaderLanguage)
    {
        // 1. Assuming m_FileSystem is available inside your ShaderManager
        // Pass the path as a string to your FileSystem virtual/native router
        auto file = m_FileSystem->OpenFile(shaderPath);

       // std::cerr << "hhhh: " << file << " \n";



        if (!file || !file->IsOpen())
        {
            m_Logger->AddError("File could not be opened via FileSystem: " , shaderPath);
            return "";
        }

        m_Logger->AddInfo("File opened via FileSystem:  " , shaderPath);

        // 2. Read the file contents as binary bytes using your IFile interface
        std::vector<uint8_t> data = file->ReadAsBinary();

        // 3. Convert the byte vector safely into a std::string text block
        return std::string(data.begin(), data.end());


        // std::ifstream stream(shaderPath);
        //
        // if (!stream.is_open())
        // {
        //     std::cerr << "File could not be opened\n";
        //     return "";
        // }
        //
        // std::stringstream ss;
        // ss << stream.rdbuf();
        // // std::cout << "  1454ghyghhdhg : \n ";
        // // std::cout << "  hgffgg : " << stream.rdbuf() << " \n";
        // return ss.str();
        // //return ""; //TODO

        return "";
    }


    Result ShaderManager::LoadCustomShader(ShaderTypeID type, const std::filesystem::path& path) //todo loadion custom way of load shaders from for example // maybe later a specification of api
    {

        //TODO LATER
    }


    IShader* ShaderManager::Get(ShaderTypeID type)
    {
        for (auto& shader : m_Shaders)
        {
            if (shader.first == type)
            {
             return shader.second.get();
            }
        }
        return nullptr;
    }

    const IShader* ShaderManager::Get(ShaderTypeID type) const
    {
        for (auto& shader : m_Shaders)
        {
            if (shader.first == type)
            {
                return shader.second.get();
            }
        }
        return nullptr;
    }

    void ShaderManager::Clear()
    {
        if (!m_Shaders.empty())
        {
            m_Shaders.clear();
        }
    }
} // engine
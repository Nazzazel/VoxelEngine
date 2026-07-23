//
// Created by nazzazel on 22.07.2026.
//


#pragma once
#include "IShader.hpp"
#include "Assets/Shader/ShaderTypeID.h"
#include "Core/Systems/Assets/AssetProviderContext.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"

namespace engine
{
    // Optional: Separate ID enum for compute shaders if they don't share the same IDs as graphics shaders

    struct TraditionalPipelineShaderFlag
    {
        void Reset(){m_TraditionalPipelineShaderFlag = 0;};

        void SetVertex                  (bool enable){if (enable){m_TraditionalPipelineShaderFlag |= (1 << 0);} else {m_TraditionalPipelineShaderFlag &= ~(1 << 0);}};
        void SetTessellationControl     (bool enable){if (enable){m_TraditionalPipelineShaderFlag |= (1 << 1);} else {m_TraditionalPipelineShaderFlag &= ~(1 << 1);}};
        void SetTessellationEvaluation  (bool enable){if (enable){m_TraditionalPipelineShaderFlag |= (1 << 2);} else {m_TraditionalPipelineShaderFlag &= ~(1 << 2);}};
        void SetGeometry                (bool enable){if (enable){m_TraditionalPipelineShaderFlag |= (1 << 3);} else {m_TraditionalPipelineShaderFlag &= ~(1 << 3);}};
        void SetFragment                (bool enable){if (enable){m_TraditionalPipelineShaderFlag |= (1 << 4);} else {m_TraditionalPipelineShaderFlag &= ~(1 << 4);}};

        [[nodiscard]] uint32_t GetTraditionalPipelineShaderFlag() const;


        [[nodiscard]] bool HasVertex() const                    { return (m_TraditionalPipelineShaderFlag & (1 << 0)) != 0; }
        [[nodiscard]] bool HasTessellationControl() const       { return (m_TraditionalPipelineShaderFlag & (1 << 1)) != 0; }
        [[nodiscard]] bool HasTessellationEvaluation() const    { return (m_TraditionalPipelineShaderFlag & (1 << 2)) != 0; }
        [[nodiscard]] bool HasGeometry() const                  { return (m_TraditionalPipelineShaderFlag & (1 << 3)) != 0; }
        [[nodiscard]] bool HasFragment() const                  { return (m_TraditionalPipelineShaderFlag & (1 << 4)) != 0; }

        [[nodiscard]] bool IsBitSet(uint32_t bitIndex) const { return (m_TraditionalPipelineShaderFlag & (1 << bitIndex)) != 0; }

        private:
        uint32_t m_TraditionalPipelineShaderFlag = 0;
    };

    struct TaskPipelineShaderFlag
    {
        void Reset(){m_TaskPipelineShaderFlag = 0;};

        void SetTask    (bool enable){if (enable){m_TaskPipelineShaderFlag |= (1 << 5);} else {m_TaskPipelineShaderFlag &= ~(1 << 5);}};
        void SetMesh    (bool enable){if (enable){m_TaskPipelineShaderFlag |= (1 << 6);} else {m_TaskPipelineShaderFlag &= ~(1 << 6);}};
        void SetFragment(bool enable){if (enable){m_TaskPipelineShaderFlag |= (1 << 7);} else {m_TaskPipelineShaderFlag &= ~(1 << 7);}};

        [[nodiscard]] uint32_t GetTaskPipelineShaderFlag() const;


        [[nodiscard]] bool HasTask() const     { return (m_TaskPipelineShaderFlag & (1 << 5)) != 0; }
        [[nodiscard]] bool HasMesh() const     { return (m_TaskPipelineShaderFlag & (1 << 6)) != 0; }
        [[nodiscard]] bool HasFragment() const { return (m_TaskPipelineShaderFlag & (1 << 7)) != 0; }


        [[nodiscard]] bool IsBitSet(uint32_t bitIndex) const { return (m_TaskPipelineShaderFlag & (1 << bitIndex)) != 0; }

    private:
        uint32_t m_TaskPipelineShaderFlag = 0;
    };

    class ShaderManager
    {
    public:
        explicit ShaderManager(AssetProviderContext& provider);//AssetProvider -> Specific instance that gives managers nessesary for propper work data ex. Root directory C:/.., /root/..
        ~ShaderManager() = default;

        ShaderManager(const ShaderManager&) = delete;
        ShaderManager& operator=(const ShaderManager&) = delete;
        ShaderManager(ShaderManager&&) noexcept = default;
        ShaderManager& operator=(ShaderManager&&) noexcept = default;//TODO I NEED T ODO THIS IN EVERY FILE AND CLASSS  h c cpp and hpp

        // Traditional Pipeline--- Graphics Shaders (Vertex + Fragment + ) ---
        //Mandatory -> Vertex + Fragment
        //Optional  -> TessellationControl + TessellationEvaluation + Geometry

        void SetTraditionalPipeline (TraditionalPipelineShaderFlag flag );
        void SetTaskPipeline        (TaskPipelineShaderFlag        flag );


        // Task Pipeline---        Graphics Shaders (Task + Mesh + Fragment ) ---

       void LoadEngineShader(ShaderTypeID type);
       void LoadCustomShader(ShaderTypeID type, const std::filesystem::path& path);



       IShader* Get(ShaderTypeID type);
       const IShader* Get(ShaderTypeID type) const;


        void Clear();

    private:
        std::string ShaderTypeIDToString(ShaderTypeID type);

        Result EvaluateShaderByAPI(TraditionalPipelineShaderFlag flag );
        Result EvaluateShaderByAPI(TaskPipelineShaderFlag        flag );


    private:
        AssetProviderContext& m_AssetProvider;

        LoggerSystem* m_LoggerSystem;

        // Separate storage for graphics vs compute pipelines

        //ShaderTypeID -> Type that determins overall Shader as a whole so full pipeline 1.Task/2.Traditional is represented by this Type
        std::unordered_map<ShaderTypeID, std::unique_ptr<IShader>> m_Shaders;



    };
} // engine

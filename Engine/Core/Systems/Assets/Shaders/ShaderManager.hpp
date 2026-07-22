//
// Created by nazzazel on 22.07.2026.
//


#pragma once
#include "IShader.hpp"
#include "Assets/Shader/ShaderTypeID.h"
#include "Core/Systems/Assets/IAssetProvider.hpp"


namespace engine
{
    // Optional: Separate ID enum for compute shaders if they don't share the same IDs as graphics shaders
    enum class ComputeShaderID
    {
        VoxelTerrainGenerator,
        FrustumCuller
    };

    class ShaderManager
    {
    public:
        explicit ShaderManager(IAssetProvider& provider);
        ~ShaderManager() = default;

        ShaderManager(const ShaderManager&) = delete;
        ShaderManager& operator=(const ShaderManager&) = delete;
        ShaderManager(ShaderManager&&) noexcept = default;
        ShaderManager& operator=(ShaderManager&&) noexcept = default;

        // --- Graphics Shaders (Vertex + Fragment) ---
        void LoadEngineShader(ShaderTypeID type);
        void LoadCustomShader(ShaderTypeID type, const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
        IShader* Get(ShaderTypeID type);
        const IShader* Get(ShaderTypeID type) const;

        // --- Compute Shaders (Single Compute Stage) ---
        void LoadComputeShader(ComputeShaderID id, const std::filesystem::path& computePath);
        ComputeShader* GetCompute(ComputeShaderID id);
        const ComputeShader* GetCompute(ComputeShaderID id) const;

        void Clear();

    private:
        std::string ReadFile(const std::filesystem::path& filepath) const;

    private:
        IAssetProvider& m_AssetProvider;

        // Separate storage for graphics vs compute pipelines
        std::unordered_map<ShaderTypeID, std::unique_ptr<IShader>> m_GraphicsShaders;
        std::unordered_map<ComputeShaderID, std::unique_ptr<ComputeShader>> m_ComputeShaders;




    };
} // engine

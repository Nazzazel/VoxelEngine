//
// Created by nazzazel on 24.07.2026.
//


#pragma once



namespace engine
{
    enum class ShaderStage;

    struct ShaderData
    {
        ShaderStage stage;
        std::string shaderCode;
    };

    enum struct ShaderLanguage
    {
        GLSL,
        HLSL
    };
}

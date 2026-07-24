//
// Created by nazzazel on 23.07.2026.
//


#pragma once
#include "Core/Systems/Assets/Shaders/IShader.hpp"


namespace engine
{
    class ShaderLoader
    {
        public:
        std::string GetSourceFromShader(ShaderStage stage,std::string shaderPath);
        


    };
} // engine

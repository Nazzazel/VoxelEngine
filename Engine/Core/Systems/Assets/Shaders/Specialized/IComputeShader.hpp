//
// Created by nazzazel on 22.07.2026.
//

#pragma once
#include <string>
#include <memory>
#include <glm/glm.hpp>

namespace engine
{
    class ComputeShader
    {
    public:
        virtual ~ComputeShader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        // Dispatch the compute shader (e.g., local work groups X, Y, Z)
        virtual void Dispatch(unsigned int x, unsigned int y, unsigned int z) = 0;

        // Uniform setters (same as your graphics shaders)
        virtual void SetInt(const std::string& name, int value) = 0;
        virtual void SetFloat(const std::string& name, float value) = 0;
        virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

        // Factory method (supports OpenGL .glsl compute and Vulkan .spv binary)
        static std::unique_ptr<ComputeShader> Create(const std::string& computePath);
    };
}
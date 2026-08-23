//
// Created by nazzazel on 21.08.2026.
//


#pragma once
#include "Texture.hpp"
#include "Core/Systems/Assets/Shaders/IShader.hpp"
#include "thirdparty/glfw/src/internal.h"


namespace engine
{
    class OpenGLTexture: public engine::Texture
    {
        public:
        //OpenGLTexture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
        OpenGLTexture();

        void SetUniforms(IShader* shader,const char* uniform,GLuint unit);

        void Bind() override;
        void UnBind() override;
        int GetWidth() const override;
        int GetHeight() const override;
        int Delete() const override;

        private:
        GLuint ID;
        GLenum type;
    };
}

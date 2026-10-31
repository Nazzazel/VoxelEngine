//
// Created by nazzazel on 31.10.2026.
//


#pragma once
#include <map>

#include "Core/Systems/Assets/AssetSystem.hpp"
#include "Core/Systems/Renderer/IRenderer/IRenderer.hpp"
#include "Systems/Renderer/Renderer/DrawComponents.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm/glm.hpp>
#include <map>

namespace engine
{
    class OpenGLTexture;
}


namespace opengltests
{

    struct Character {
        std::shared_ptr<engine::OpenGLTexture> Texture; // Your engine's texture class!

      //  std: // OpenGL texture handle for the glyph
        glm::ivec2   Size;      // Size of glyph
        glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
        unsigned int Advance;   // Offset to advance to next glyph
    };

    class Text
    {
    public:
       // Text(engine::AssetSystem& assets,engine::OpenGLTexture& texture);
        Text(engine::AssetSystem& assets, const std::string& fontPath,std::shared_ptr<engine::OpenGLTexture> texture);
        void TextRender(std::string text);
        void Draw(engine::IRenderer& renderer, const std::string& text, float x, float y, float scale, glm::vec3 color);

        ~Text() = default;
        //void BuildMesh();
    private:
        int InitFreeType(const std::string& fontPath);

        std::map<char, Character> m_Characters;



        std::shared_ptr<engine::Mesh> m_Mesh;
        std::shared_ptr<engine::Material> m_Material;

        engine::AssetSystem& m_assets;

        std::shared_ptr<engine::OpenGLTexture> m_texture;
        //std::shared_ptr<engine::IShader> m_Shader = nullptr;
        engine::IShader* m_Shader = nullptr;
        engine::LoggerSystem*   m_Logger;
        //engine::OpenGLTexture& m_Texture;

    };
} // opengltests

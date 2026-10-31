//
// Created by nazzazel on 31.10.2026.
//


#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm/glm.hpp>
#include <map>

namespace engine
{



    struct Character {
        unsigned int TextureID; // ID handle of the glyph texture
        glm::ivec2   Size;      // Size of glyph (width, height)
        glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
        unsigned int Advance;   // Offset to advance to next glyph (in 1/64th pixels)
    };

    class TextRenderer
    {
        public:
        TextRenderer();
        void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);

        private:
        int InitTextRenderer();

        std::map<char, Character> Characters;
    };
} // engine

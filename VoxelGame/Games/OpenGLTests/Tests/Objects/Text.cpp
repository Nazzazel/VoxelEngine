//
// Created by nazzazel on 31.10.2026.
//

#include "Text.hpp"

#include "glad/glad.h"
//#include "glad/glad.h"

namespace opengltests
{


    // Text::Text(engine::AssetSystem& assets,engine::OpenGLTexture& texture)
    // :
    // m_assets(assets)
    // //,m_Texture(texture)
    // {
    //
    //     BuildMesh();
    // }

    Text::Text(engine::AssetSystem& assets, const std::string& fontPath,std::shared_ptr<engine::OpenGLTexture> texture) : m_assets(assets)
    {
        m_texture = texture;
        m_Shader = m_assets.GetShaderManager().Get(engine::ShaderTypeID::UI);

        m_Logger = m_assets.GetSystemManager()->GetSystem<engine::LoggerSystem>();

        InitFreeType(fontPath);




        // const engine::BufferLayout layout =
        // {
        //     {engine::ShaderDataType::Float2, "a_Position"},
        //     {engine::ShaderDataType::Float2, "a_TexCoord"}
        // };

        //std::vector<float> emptyVertices(6 * 4 * 64, 0.0f); // e.g. 64 characters max per batch for now
        //std::vector<uint32_t> emptyIndices= { 0, 1, 2, 2, 3, 0 };
        //
        //m_Mesh = std::make_shared<engine::Mesh>(
        //    emptyVertices.data(),
        //    emptyVertices.size() * sizeof(float),
        //    layout,
        //    emptyIndices.data(),
        //    emptyIndices.size()
        //    );

    }

    int Text::InitFreeType(const std::string& fontPath)
    {
        FT_Library ft;
        if (FT_Init_FreeType(&ft))
        {
            std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
            return -1;
        }

        FT_Face face;
        if (FT_New_Face(ft, fontPath.c_str(), 0, &face))
        //if (FT_New_Face(ft, "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 0, &face))
        {
            std::cout << "ERROR::FREETYPE: Failed to load font at: " << fontPath << std::endl;
            return -1;
        }

        FT_Set_Pixel_Sizes(face, 0, 48); // Set font size
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction
       // glPixelStorei()

        for (unsigned char c = 0; c < 128; c++)
        {
            if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            {
                std::cout << "ERROR::FREETYPE: Failed to load Glyph " << c << std::endl;
                continue;
            }



            auto glyphTexture = std::make_shared<engine::OpenGLTexture>(
                face->glyph->bitmap.buffer,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows
            );

            Character character = {
                glyphTexture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                static_cast<unsigned int>(face->glyph->advance.x)
            };
            m_Characters.insert({c, character});
        }

        FT_Done_Face(face);
        FT_Done_FreeType(ft);
        return 0;
    }

    void Text::TestDrawSquare(engine::IRenderer& renderer)
    {
        // 1. Bind your test shader
        m_Shader->Bind();
        m_Shader->SetVec3("testColor", glm::vec3(1.0f, 0.0f, 0.0f)); // Bright Red Square

        // 2. Define a simple square right in the middle of Normalized Device Coordinates (-0.5 to 0.5)
      // float quadVertices[] = {
      //         -0.5f,  0.5f,  0.0f, 1.0f, // Top-left
      //         -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
      //          0.5f, -0.5f,  1.0f, 0.0f, // Bottom-right

      //         -0.5f,  0.5f,  0.0f, 1.0f, // Top-left
      //          0.5f, -0.5f,  1.0f, 0.0f, // Bottom-right
      //          0.5f,  0.5f,  1.0f, 1.0f  // Top-right
      //     };

        float quadVertices[6][2] = {
            { -0.5f,  0.5f }, // Top-left
            { -0.5f, -0.5f }, // Bottom-left
            {  0.5f, -0.5f }, // Bottom-right

            { -0.5f,  0.5f }, // Top-left
            {  0.5f, -0.5f }, // Bottom-right
            {  0.5f,  0.5f }  // Top-right
        };

        //const engine::BufferLayout layout2D = {
        //    {engine::ShaderDataType::Float2, "a_Position"}
        //};

        // 3. Update your mesh or VBO directly with these raw vertices
        // (Ensure your BufferLayout matches 2 floats for a_Position only)

        uint32_t quadIndices[] = { 0, 1, 2, 3, 4, 5 };

          const engine::BufferLayout layout = {
           {engine::ShaderDataType::Float2, "a_Position"}
              //,{engine::ShaderDataType::Float2, "a_TexCoord"}
          };

        m_Mesh = std::make_shared<engine::Mesh>(
            *quadVertices, sizeof(quadVertices),
            layout,
            quadIndices, 6
        );
        //m_Mesh->UpdateVertices(quadVertices, sizeof(quadVertices));

        // 4. Submit the draw command (without binding any textures)
        engine::DrawCommand cmd;
        cmd.modelMatrix = glm::mat4(1.0f);
        cmd.material = std::make_unique<engine::Material>(m_Shader, nullptr);; // No material/texture needed for this test!
        cmd.mesh = m_Mesh;
        renderer.Submit(cmd);
    }


    void Text::Draw(engine::IRenderer& renderer, const std::string& text, float x, float y, float scale, glm::vec3 color)
    {


        Text::TestDrawSquare(renderer);
        // 1. Set up a temporary identity/ortho scene data so it draws on the screen in NDC space (-1 to 1)
       //engine::SceneData uiSceneData;
       //uiSceneData.viewMatrix = glm::mat4(1.0f);
       //uiSceneData.projectionMatrix = glm::mat4(1.0f); // Identity means coordinates range from -1 to 1
       //renderer.SetSceneData(uiSceneData);

  //       m_Shader->Bind();
  //       m_Shader->SetVec3("textColor", color); // Or m_Shader->SetUniform("textColor", color); depending on your wrapper
  //
  // float quadVertices[] = {
  //         -0.5f,  0.5f,  0.0f, 1.0f, // Top-left
  //         -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
  //          0.5f, -0.5f,  1.0f, 0.0f, // Bottom-right
  //
  //         -0.5f,  0.5f,  0.0f, 1.0f, // Top-left
  //          0.5f, -0.5f,  1.0f, 0.0f, // Bottom-right
  //          0.5f,  0.5f,  1.0f, 1.0f  // Top-right
  //     };
  //
  //
  // uint32_t quadIndices[] = { 0, 1, 2, 3, 4, 5 };
  //
  //   const engine::BufferLayout layout = {
  //    {engine::ShaderDataType::Float2, "a_Position"},
  //    {engine::ShaderDataType::Float2, "a_TexCoord"}
  //   };
  //
  // //    // Create a temporary test mesh (or make it static so you don't recreate it every frame)
  // m_Mesh = std::make_shared<engine::Mesh>(
  //     quadVertices, sizeof(quadVertices),
  //     layout,
  //     quadIndices, 6
  // );
  //
  //
  //      //m_Mesh->UpdateVertices(quadVertices, sizeof(quadVertices));
  //
  //        m_Material = std::make_unique<engine::Material>(m_Shader, m_texture);
  //       //
  //       //
  //       //
  //           engine::DrawCommand cmd;
  //           cmd.modelMatrix = glm::mat4(1.0f);
  //           cmd.material = m_Material;
  //           cmd.mesh = m_Mesh;
  //           renderer.Submit(cmd);
  //       // Activate shader and set text color uniform
  //       // Iterate through every character in the string
  //
  //       m_Shader->Bind();
  //       m_Shader->SetVec3("textColor", color); // Or m_Shader->SetUniform("textColor", color); depending on your wrapper
  //
  //       for (char c : text)
  //       {
  //           // Use .find() instead of [] to avoid inserting bad keys accidentally
  //           auto it = m_Characters.find(c);
  //           if (it == m_Characters.end()) continue; // Skip missing characters
  //           Character ch = it->second;
  //
  //           // Skip rendering for characters with no bitmap (like spaces ' ')
  //           if (ch.Texture != nullptr && ch.Size.x > 0 && ch.Size.y > 0)
  //           {
  //               if (engine::Result result = ch.Texture->Bind(); result.IsFailure())
  //               {
  //                   m_Logger->AddResult(result);
  //               }
  //           }
  //           else
  //           {
  //               continue; // Skip draw submission for empty glyphs like spaces
  //           }
  //
  //           float xpos = x + ch.Bearing.x * scale;
  //           float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;
  //
  //           float w = ch.Size.x * scale;
  //           float h = ch.Size.y * scale;
  //
  //           // 6 vertices for a 2D quad (2 triangles)
  //           float vertices[6][4] = {
  //               { xpos,     ypos + h,   0.0f, 0.0f },
  //               { xpos,     ypos,       0.0f, 1.0f },
  //               { xpos + w, ypos,       1.0f, 1.0f },
  //
  //               { xpos,     ypos + h,   0.0f, 0.0f },
  //               { xpos + w, ypos,       1.0f, 1.0f },
  //               { xpos + w, ypos + h,   1.0f, 0.0f }
  //           };
  //
  //           // Update the mesh vertex buffer with this character's quad data
  //           // (Assuming your Mesh class has a method to update buffer data,
  //           // or you bind the mesh's VBO and call glBufferSubData)
  //           m_Mesh->UpdateVertices(vertices, sizeof(vertices));
  //
  //           // Bind this specific character's glyph texture
  //         // if (engine::Result result = engine::CheckAnything(ch.Texture);result.IsFailure())
  //         // {
  //         //     m_Logger->AddResult(result);
  //         // }
  //         //  else
  //       //  if (ch.Texture != nullptr)
  //       //  {
  //       //      if (engine::Result result = ch.Texture->Bind();result.IsFailure()) { m_Logger->AddResult(result);}
  //       //  }
  //       //  else
  //       //  {
  //       //      //m_texture->Bind();
  //       //  }
  //           // // render glyph texture over quad
  //           // glBindTexture(GL_TEXTURE_2D, ch.TextureID);
  //           // // update content of VBO memory
  //           // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  //           // glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
  //           // glBindBuffer(GL_ARRAY_BUFFER, 0);
  //           // // render quad
  //           // glDrawArrays(GL_TRIANGLES, 0, 6);
  //           // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
  //           x += (ch.Advance >> 6) * scale;
  //
  //       //
             // Submit draw command for this character
            // engine::DrawCommand cmd;
           //  cmd.modelMatrix = glm::mat4(1.0f);
           //  cmd.material = m_Material;
           //  cmd.mesh = m_Mesh;
           //  renderer.Submit(cmd);
        //
        //     // Advance the cursor for the next character (bitshift by 6 because FreeType advance is in 1/64th pixels)
            // x += (ch.Advance >> 6) * scale;
        }



       //engine::DrawCommand cmd;
//
        ///cmd.modelMatrix = glm::mat4(1.0f);
        ///cmd.material = m_Material;
        ///cmd.mesh = m_Mesh;
/////
        ///renderer.Submit(cmd);
    //}



} // opengltests
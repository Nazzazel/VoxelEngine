//
// Created by nazzazel on 24.07.2026.
//

#include "tests.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace backends
{
    tests::tests()
    {
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        //
        //
        // float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
        // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
        //
        //
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //
        //
        // int width, height, nrChannels;
        // unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
        //
        // unsigned int texture;
        // glGenTextures(1, &texture);
        // glBindTexture(GL_TEXTURE_2D, texture);
        //
        //
        // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        // glGenerateMipmap(GL_TEXTURE_2D);
        //
        // stbi_image_free(data);

        one();

        std::cout << "chiken\n";

    }

    void tests::one()
    {

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load and generate the texture
        int width, height, nrChannels;
        //unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
        unsigned char *data = stbi_load("/home/nazzazel/Programming/cpp/projects/VoxelEngine/Engine/Res/Assets/Textures/container.jpg", &width, &height, &nrChannels, 0);
        if (data)
        {

            std::cout << "SUccess to load texture" << std::endl;
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);


    }


} // backends
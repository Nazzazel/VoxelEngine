//
// Created by nazzazel on 21.08.2026.
//

#include "OpenGLTexture.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "OpenGL/tests/stb_image.h"

#include "Backends/OpenGL/Debug/GLScope.hpp"
namespace engine
{


    //OpenGLTexture::OpenGLTexture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
    OpenGLTexture::OpenGLTexture()
    {
        type = GL_TEXTURE_2D;


        //glActiveTexture()
        //unsigned int texture;
        glGenTextures(1, &ID);
        glActiveTexture(GL_TEXTURE0);//TODO texture active
        glBindTexture(GL_TEXTURE_2D, ID);
        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load and generate the texture
        int width, height, nrChannels;
        //unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
        stbi_set_flip_vertically_on_load(true);
        // unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
        unsigned char *data = stbi_load("/home/nazzazel/Programming/cpp/projects/VoxelEngine/Engine/Res/Assets/Textures/container.jpg", &width, &height, &nrChannels, 0);


        if (data)
        {
            // uint b = static_cast<uint>(*data);



            std::cout << "SUccess to load texture: \n" << static_cast<int>(*data) << "\n ------------------\n END" << std::endl;
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            //GL_TEXTURE0;

        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
        glBindTexture(type, 0);
    }

    OpenGLTexture::OpenGLTexture(unsigned char* data, int width, int height)
    {
        type = GL_TEXTURE_2D;
        glGenTextures(1, &ID);
        glActiveTexture(GL_TEXTURE0);//TODO texture active
        glBindTexture(GL_TEXTURE_2D, ID);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,//GL_RGB
            width,
            height,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            data);


        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



        glBindTexture(type, 0);
    }

    /*
     *
    *  // Assigns the type of the texture ot the texture object
        type = texType;

        // Stores the width, height, and the number of color channels of the image
        int widthImg, heightImg, numColCh;
        // Flips the image so it appears right side up
        stbi_set_flip_vertically_on_load(true);
        // Reads the image from a file and stores it in bytes
        unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

        // Generates an OpenGL texture object
        glGenTextures(1, &ID);
        // Assigns the texture to a Texture Unit
        glActiveTexture(slot);
        glBindTexture(texType, ID);

        // Configures the type of algorithm that is used to make the image smaller or bigger
        glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // Configures the way the texture repeats (if it does at all)
        glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // Extra lines in case you choose to use GL_CLAMP_TO_BORDER
        // float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
        // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

        // Assigns the image to the OpenGL Texture object
        glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
        // Generates MipMaps
        glGenerateMipmap(texType);

        // Deletes the image data as it is already in the OpenGL Texture object
        stbi_image_free(bytes);

        // Unbinds the OpenGL Texture object so that it can't accidentally be modified
        glBindTexture(texType, 0);
     *
     *
     */


/*
    *         //glActiveTexture()
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
            stbi_set_flip_vertically_on_load(true);
            unsigned char *data = stbi_load("/home/nazzazel/Programming/cpp/projects/VoxelEngine/Engine/Res/Assets/Textures/container.jpg", &width, &height, &nrChannels, 0);
            if (data)
            {
               // uint b = static_cast<uint>(*data);



                std::cout << "SUccess to load texture: \n" << static_cast<int>(*data) << "\n ------------------\n END" << std::endl;
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);

                //GL_TEXTURE0;
            }
            else
            {
                std::cout << "Failed to load texture" << std::endl;
            }
            stbi_image_free(data);


 *
 *
 */


    void OpenGLTexture::SetUniforms(engine::IShader* shader,const char* uniform,GLuint unit )
    {
        // Gets the location of the uniform
      //  GLuint texUni = glGetUniformLocation(shader.ID, uniform);
        // Shader needs to be activated before changing the value of a uniform
        //shader.Activate();
        // Sets the value of the uniform
       // glUniform1i(texUni, unit);

       // shader->Bind();
        shader->SetUInt(uniform,unit);
    }


    Result OpenGLTexture::Bind()
    {
       GL_SCOPE();
        //while (glGetError() != GL_NO_ERROR);

        glBindTexture(GL_TEXTURE_2D, ID);

      //  GLenum err =0 ;
      //  while ((err = glGetError()) != GL_NO_ERROR) {
      //      std::cout << ">>> BIND ERROR DETECTED! Code: " << err << " on Texture ID: " << ID << std::endl;
      //  }
        return Result();

    }

    Result OpenGLTexture::UnBind()
    {
        GL_SCOPE();
        glBindTexture(GL_TEXTURE_2D, 0);
        return Result();
    }

    int OpenGLTexture::GetWidth() const
    {
return 0;
    }

    int OpenGLTexture::GetHeight() const
    {
        return 0;
    }

    int OpenGLTexture::Delete() const
    {
        glDeleteTextures(1, &ID);
    }
} // voxelgame
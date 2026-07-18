#pragma once

#include <string>
#include <GLFW/glfw3.h>

namespace engine
{
    class TextInput
    {
    public:
        static void Init(GLFWwindow* window);

        static void Clear();
        static const std::string& GetBuffer();

    private:
        static std::string s_Buffer;
    };
}
#pragma once

#include <unordered_set>
#include <GLFW/glfw3.h>

namespace engine
{
    class DebugInput
    {
    public:
        static void Init(GLFWwindow* window);

        static const std::unordered_set<int>& GetPressedKeys();
        static const std::unordered_set<int>& GetPressedMouseButtons();

    private:
        static std::unordered_set<int> s_Keys;
        static std::unordered_set<int> s_MouseButtons;
    };
}
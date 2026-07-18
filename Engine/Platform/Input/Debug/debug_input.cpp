#include "debug_input.hpp"

namespace engine
{
    std::unordered_set<int> DebugInput::s_Keys;
    std::unordered_set<int> DebugInput::s_MouseButtons;

    void DebugInput::Init(GLFWwindow* window)
    {
        glfwSetKeyCallback(window,
            [](GLFWwindow*, int key, int scancode, int action, int mods)
            {
                if (action == GLFW_PRESS)
                    s_Keys.insert(key);
                else if (action == GLFW_RELEASE)
                    s_Keys.erase(key);
            });

        glfwSetMouseButtonCallback(window,
            [](GLFWwindow*, int button, int action, int mods)
            {
                if (action == GLFW_PRESS)
                    s_MouseButtons.insert(button);
                else if (action == GLFW_RELEASE)
                    s_MouseButtons.erase(button);
            });
    }

    const std::unordered_set<int>& DebugInput::GetPressedKeys()
    {
        return s_Keys;
    }

    const std::unordered_set<int>& DebugInput::GetPressedMouseButtons()
    {
        return s_MouseButtons;
    }
}
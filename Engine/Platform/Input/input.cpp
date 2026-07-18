#include "input.hpp"
#include <GLFW/glfw3.h>

namespace engine
{
    GLFWwindow* Input::s_Window = nullptr;
    std::unordered_map<Action, Binding> Input::s_Bindings;
    InputMode Input::s_Mode = InputMode::Game;

    void Input::Init(GLFWwindow* window)
    {
        s_Window = window;

        // default bindings (voxel style)
        s_Bindings[Action::MoveForward] = { GLFW_KEY_W, false };
        s_Bindings[Action::MoveBackward] = { GLFW_KEY_S, false };
        s_Bindings[Action::MoveLeft] = { GLFW_KEY_A, false };
        s_Bindings[Action::MoveRight] = { GLFW_KEY_D, false };

        s_Bindings[Action::Jump] = { GLFW_KEY_SPACE, false };
        s_Bindings[Action::Sprint] = { GLFW_KEY_LEFT_SHIFT, false };

        s_Bindings[Action::BreakBlock] = { GLFW_MOUSE_BUTTON_LEFT, true };
        s_Bindings[Action::PlaceBlock] = { GLFW_MOUSE_BUTTON_RIGHT, true };

        s_Bindings[Action::InventoryNext] = { GLFW_KEY_E, false };
        s_Bindings[Action::InventoryPrev] = { GLFW_KEY_Q, false };
    }

    void Input::SetMode(InputMode mode)
    {
        s_Mode = mode;
    }

    InputMode Input::GetMode()
    {
        return s_Mode;
    }

    bool Input::IsKeyPressed(KeyCode key)
    {
        return glfwGetKey(s_Window, key) == GLFW_PRESS;
    }

    bool Input::IsMouseButtonPressed(KeyCode button)
    {
        return glfwGetMouseButton(s_Window, button) == GLFW_PRESS;
    }

    bool Input::IsActionPressed(Action action)
    {
        if (s_Mode != InputMode::Game)
            return false; // IMPORTANT: only game mode triggers actions

        auto it = s_Bindings.find(action);
        if (it == s_Bindings.end())
            return false;

        const Binding& b = it->second;

        return b.isMouse
            ? IsMouseButtonPressed(b.code)
            : IsKeyPressed(b.code);
    }

    void Input::Bind(Action action, KeyCode code, bool isMouse)
    {
        s_Bindings[action] = { code, isMouse };
    }
}
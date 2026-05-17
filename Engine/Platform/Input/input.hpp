#pragma once

#include <unordered_map>
#include "action.hpp"
#include "key_code.hpp"
#include "input_mode.hpp"

struct GLFWwindow;

namespace engine
{
    struct Binding
    {
        KeyCode code;
        bool isMouse;
    };

    class Input
    {
    public:
        static void Init(GLFWwindow* window);

        static bool IsKeyPressed(KeyCode key);
        static bool IsMouseButtonPressed(KeyCode button);

        static bool IsActionPressed(Action action);

        static void Bind(Action action, KeyCode code, bool isMouse);

        static void SetMode(InputMode mode);
        static InputMode GetMode();

    private:
        static GLFWwindow* s_Window;
        static std::unordered_map<Action, Binding> s_Bindings;
        static InputMode s_Mode;
    };
}
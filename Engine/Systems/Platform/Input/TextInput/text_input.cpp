#include "text_input.hpp"

namespace engine
{
    std::string TextInput::s_Buffer;

    void TextInput::Init(GLFWwindow* window)
    {
        glfwSetCharCallback(window,
            [](GLFWwindow*, unsigned int codepoint)
            {
                s_Buffer += static_cast<char>(codepoint);
            }
        );
    }

    void TextInput::Clear()
    {
        s_Buffer.clear();
    }

    const std::string& TextInput::GetBuffer()
    {
        return s_Buffer;
    }
}

//EXAMPLE
/*/*
#include "Input.hpp"
#include "TextInput.hpp"

using namespace engine;

void Update()
{
    if (Input::IsActionPressed(Action::Jump))
        PlayerJump();

    if (Input::IsActionPressed(Action::BreakBlock))
        BreakBlock();

    if (Input::GetMode() == InputMode::Text)
    {
        std::string text = TextInput::GetBuffer();
        // use it for book / TODO / chat
    }
}





*/
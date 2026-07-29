//
// Created by nazzazel on 24.07.2026.
//


#pragma once
#include "IEvent.hpp"

namespace engine
{
    namespace events
    {
        //Window
        struct WindowResizeEvent : public IEvent
        {
            int Width;
            int Height;
            WindowResizeEvent(int width, int height) : Width(width), Height(height) {}
        };

        struct WindowFocusEvent : public IEvent
        {
            bool Focused;
            WindowFocusEvent(bool focused) : Focused(focused) {}
        };

        struct FileDropEvent : public IEvent
        {
            std::vector<std::string> Paths;
            FileDropEvent(int count, const char* paths[])
            {
                for (int i = 0; i < count; ++i) {
                    Paths.push_back(paths[i]);
                }
            }
        };


        //Keyboard
        struct KeyPressedEvent : public IEvent
        {
            int KeyCode; //idk maybe m_ later i dont think so LOL
            KeyPressedEvent(int key) : KeyCode(key) {};

        };

        struct KeyReleasedEvent : public IEvent
        {
            int32_t KeyCode;
            KeyReleasedEvent(int32_t key) : KeyCode(key) {}
        };

        struct KeyTypedEvent : public IEvent
        {
            unsigned int Codepoint; // Unicode codepoint of the typed character
            KeyTypedEvent(unsigned int codepoint) : Codepoint(codepoint) {}
        };

        //Mouse
        struct MouseMovedEvent : public IEvent
        {
            float MouseX;
            float MouseY;
            MouseMovedEvent(float x, float y) : MouseX(x), MouseY(y) {}
        };

        struct MouseButtonPressedEvent : public IEvent
        {
            int Button;
            MouseButtonPressedEvent(int button) : Button(button) {}
        };

        struct MouseButtonReleasedEvent : public IEvent
        {

            int Button;
            MouseButtonReleasedEvent(int button) : Button(button) {}

        };

        struct MouseScrolledEvent : public IEvent
        {
            float XOffset;
            float YOffset;
            MouseScrolledEvent(float xOffset, float yOffset) : XOffset(xOffset), YOffset(yOffset) {}
        };


        //TODO controller
        struct JoystickConnectEvent : public IEvent
        {
            int JID;       // Joystick ID (e.g., GLFW_JOYSTICK_1)
            bool Connected;// True if plugged in, false if unplugged
            JoystickConnectEvent(int jid, bool connected) : JID(jid), Connected(connected) {}
        };





    }

}

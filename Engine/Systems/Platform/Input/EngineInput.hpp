//
// Created by nazzazel on 25.07.2026.
//


#pragma once
#include "InputMapStates.hpp"
#include "Core/Systems/Event/Events.hpp"
#include "Core/Systems/Event/EventSystem.hpp"
#include "Core/Systems/Input/InputSystem.hpp"
#include "Core/Systems/Logger/LoggerSystem.hpp"


namespace engine
{

    class EngineInput
    {
        public:
        EngineInput(SystemManager* systemManager) :
            m_SystemManager(systemManager)
        {
            logger = m_SystemManager->GetSystem<LoggerSystem>();
            event_system = m_SystemManager->GetSystem<EventSystem>();
            timer = m_SystemManager->GetSystem<TimeSystem>();
            window = m_SystemManager->GetSystem<WindowSystem>();
            asset = m_SystemManager->GetSystem<AssetSystem>();
            renderer = m_SystemManager->GetSystem<RendererSystem>();

            input = m_SystemManager->GetSystem<InputSystem>();
        }

        ~EngineInput() = default;

        void Init()
        {
            keyboardInputStateMap = input->GetKeybordInputStateMap();
        }


        void GLFWEventCallbacks()
        {


            //Event Subscriptions
            event_system->GetEventBus()->Subscribe<engine::events::WindowResizeEvent>([this](engine::events::WindowResizeEvent& e){

                logger->AddCallbackMsg("Window resized to: ",e.Width ," x ",e.Height);
                this->renderer->GetRenderer()->OnResize(e.Width ,e.Height);

               // this->

            });




            event_system->GetEventBus()->Subscribe<engine::events::WindowFocusEvent>([this](engine::events::WindowFocusEvent& e){

                logger->AddCallbackMsg("Is Window Focused ",e.Focused );

            });

            event_system->GetEventBus()->Subscribe<engine::events::FileDropEvent>([this](engine::events::FileDropEvent& e){

                for (auto path : e.Paths)
                {
                    logger->AddCallbackMsg("File Paths uploaded to a window", path);
                }

            });

            event_system->GetEventBus()->Subscribe<engine::events::JoystickConnectEvent>([this](engine::events::JoystickConnectEvent& e){


                logger->AddCallbackMsg("Is Controller Connected : -> ",e.Connected);
                logger->AddCallbackMsg("Controller ID : -> ", e.JID);

            if (e.Connected){ logger->AddCallbackMsg("Controller Name : -> ", window->GetWindow()->GetJoystickName(e.JID));}


            });



            event_system->GetEventBus()->Subscribe<engine::events::KeyPressedEvent>([this](engine::events::KeyPressedEvent& e){

                logger->AddCallbackMsg("Key presses:", e.KeyCode);
                keyboardInputStateMap->UpdateInputStates(e.KeyCode,true);


               // switch (e.KeyCode)
               // {
               //     case GLFW_KEY_ESCAPE:  renderer->GetRenderer()
               // }

            });

            event_system->GetEventBus()->Subscribe<engine::events::KeyReleasedEvent>([this](engine::events::KeyReleasedEvent& e){

                logger->AddCallbackMsg("Key released:", e.KeyCode);
                keyboardInputStateMap->UpdateInputStates(e.KeyCode,false);

            });

            event_system->GetEventBus()->Subscribe<engine::events::KeyTypedEvent>([this](engine::events::KeyTypedEvent& e){

                logger->AddCallbackMsg("Char:", e.Codepoint);

            });

            event_system->GetEventBus()->Subscribe<engine::events::MouseMovedEvent>([this](engine::events::MouseMovedEvent& e){

                  logger->AddCallbackMsg("Mouse Moved: X ->", e.MouseX, "      Y ->" ,e.MouseY);

            });

            event_system->GetEventBus()->Subscribe<engine::events::MouseButtonPressedEvent>([this](engine::events::MouseButtonPressedEvent& e){

                  logger->AddCallbackMsg("Mouse Key presses:", e.Button);

            });

            event_system->GetEventBus()->Subscribe<engine::events::MouseButtonReleasedEvent>([this](engine::events::MouseButtonReleasedEvent& e){

                  logger->AddCallbackMsg("Mouse Key released:", e.Button);

            });

            event_system->GetEventBus()->Subscribe<engine::events::KeyReleasedEvent>([this](engine::events::KeyReleasedEvent& e){

                  logger->AddCallbackMsg("Key released:", e.KeyCode);

            });

        }
        private:
        SystemManager* m_SystemManager;

        LoggerSystem* logger          = nullptr;
        EventSystem*  event_system    = nullptr;
        TimeSystem* timer             = nullptr;
        WindowSystem* window          = nullptr;
        AssetSystem* asset            = nullptr;
        RendererSystem* renderer      = nullptr;
        InputSystem* input            = nullptr;



        KeybordInputStateMap* keyboardInputStateMap = nullptr;


    };


}

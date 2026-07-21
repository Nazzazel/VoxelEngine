//
// Created by nazzazel on 21.07.2026.
//
#pragma once
#include "Core/Systems/IEngineSystem.hpp"

namespace engine
{
    class SystemManager {

        private:
            std::vector<std::unique_ptr<engine::IEngineSystem>> m_Systems;


        public:
            template<typename T, typename... Args>
            Result RegisterSystem(Args&&... args)
            {

                    if (GetSystem<T>()!=nullptr) return SYSTEM_RESULT(SystemAlreadyInitialized,Warning); //The System is already initiated//TODO
                    auto system = std::make_unique<T>(std::forward<Args>(args)...);


                    Result SetSystemManagerResult = system->SetSystemManager(this);
                    if (SetSystemManagerResult.IsFailure()  ){ return SetSystemManagerResult;}  //Exit in the first stage

                    m_Systems.push_back(std::move(system));

                    // Result OnInitResult = system->OnInit();                                     //Calling OnInit every single Registered Instance, so it can correctly set itself up.
                    // if (OnInitResult.IsFailure()            ) {return OnInitResult;          }  //Exit in the second stage




                    //TODO CREATE A ERROR HANDELER FOR SYSTEMS.
                    //TODO MAKE RESULTSD HERE



                return {};
            }


            Result InitialiseAll() const{
                for (auto& sys : m_Systems){ if (Result result = sys->OnInit();result.IsFailure()) return result;}
                return {};
            }

            Result UpdateAll(float dt) const{
                for (auto& sys : m_Systems){ if (Result result = sys->OnUpdate(dt);result.IsFailure()) return result;}
                return {};
            }

            template<typename T>
            T* GetSystem()
            {
                for (auto& sys : m_Systems) {
                    if (auto ptr = dynamic_cast<T*>(sys.get())) return ptr;
                }
                return nullptr;
            }

            // I am not implementing the ID CAUSE it is pointless.
            //AFTER the Engine Init this function will probably never be used. //TODO //Maybe in the future //#IF_NECESSARY
            template<typename T>
            const T* GetSystem() const
            {
                for (auto& sys : m_Systems) {
                    if (auto ptr = dynamic_cast<T*>(sys.get())) return ptr;
                }
                return nullptr;
            }

            Result ShutdownAll()
            {
                for (auto it = m_Systems.rbegin(); it != m_Systems.rend(); ++it)
                {
                    if (Result result = (*it)->OnShutdown();result.IsFailure()){return result;}
                }
                m_Systems.clear(); // All systems (including GL objects) are destroyed safely here
                return {};
            }
        };
}
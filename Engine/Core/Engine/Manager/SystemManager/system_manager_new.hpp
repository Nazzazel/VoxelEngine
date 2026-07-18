//
// Created by nazzazel on 13.07.2026.
//

#pragma once
#include <memory>
#include <vector>


#include "i_engine_system.hpp"
//#include "Core/Engine/Manager/Systems/Logger/logger_system.hpp"

namespace engine
{


    class SystemManager {
    private:
        std::vector<std::unique_ptr<IEngineSystem>> m_Systems;


    public:
        template<typename T, typename... Args>
        [[nodiscard]] uint32_t RegisterSystem(Args&&... args) {
            if (GetSystem<T>()!=nullptr) return 0x00000001; //The System is already initiated//TODO

            auto system = std::make_unique<T>(std::forward<Args>(args)...);

            uint32_t error_code = system->OnInit();                             //Calling OnInit every single Registered Instance, so it can correctly set itself up.
           // if (error_code != 0){return error_code;}                            //Exit in first stage

            //auto* base_system = static_cast<IEngineSystem*>(system.get());
            //uint32_t error_code_2 = base_system->SetSystemManager(this);
            //if (error_code_2 != 0){return (error_code_2 << 8 ) | error_code;}   //Exit in 2nd stage plus bit shift //AN:I don't ever have that mayne errors
                                                                                //TODO CREATE A ERROR HANDELER FOR SYSTEMS.

            m_Systems.push_back(std::move(system));
            return 0;
        }

        void UpdateAll(float dt) const{
            for (auto& sys : m_Systems) sys->OnUpdate(dt);
        }

        // I am not implementing the ID CAUSE it is pointless.
        //AFTER the Engine Init this function will probably never be used. //TODO //Maybe in the future //#IF_NECESSARY
        template<typename T>
        const T* GetSystem() const {
            for (auto& sys : m_Systems) {
                if (auto ptr = dynamic_cast<T*>(sys.get())) return ptr;
            }
            return nullptr;
        }
        void ShutdownAll()
        {
            for (auto it = m_Systems.rbegin(); it != m_Systems.rend(); ++it) {
                (*it)->OnShutdown();
            }
            m_Systems.clear(); // All systems (including GL objects) are destroyed safely here
        }
        bool LoggerFLag = false;
    };
}

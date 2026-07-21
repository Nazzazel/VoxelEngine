//
// Created by nazzazel on 20.07.2026.
//

#pragma once
#include <utility>

#include "string"

//Aditional namespace for clarity
//This is used for arg from app using engine

namespace engine
{
    struct EngineConfig
    {
        //TODO deal with this like a file read or smg/// For those are Default values
        //TODO later lol
    };

    struct WindowConfig
    {
        int m_windowWidth;
        int m_windowHeight;
        std::string m_title;

        WindowConfig(
            //---------------------------------------------------------------
            const  int windowWidth,
            const  int windowHeight,
                   std::string title)
            //---------------------------------------------------------------
        : m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_title(std::move(title)) {}

        [[nodiscard]] int GetWindowWidth() const            {return m_windowWidth;}
        [[nodiscard]] int GetWindowHeight() const           {return m_windowHeight;}
        [[nodiscard]] std::string& GetTitle()               {return m_title;}

    };

    struct AdditionalParams {
        const size_t m_memoryBudgetMB = 8000; // Memory size
        //bool enableVSync;      // Example: Graphics flag
        const  bool m_debugMode = false;       // Debugging flag

        // AdditionalParams(
        //     //---------------------------------------------------------------
        //     size_t memoryBudgetMB = 8000,
        //     bool debugMode = false)
        //     //---------------------------------------------------------------
        // : m_memoryBudgetMB(memoryBudgetMB), m_debugMode(debugMode){}


        [[nodiscard]] size_t GetMemoryBudget() const     {return m_memoryBudgetMB;}
        [[nodiscard]] bool IsDebugModeActive() const    { return m_debugMode; }

    };

    struct AppSettings {
        //EngineConfig engine_configuration;
        WindowConfig m_window_configuration;
        AdditionalParams m_extra;

        AppSettings(
            const WindowConfig& window_configuration,
            const AdditionalParams& extra)
            : m_window_configuration(window_configuration), m_extra(extra){}


        [[nodiscard]] WindowConfig GetWindowConfiguration()   const   {return m_window_configuration;}
        [[nodiscard]] AdditionalParams GetExtra()             const   {return m_extra;}
    };
}
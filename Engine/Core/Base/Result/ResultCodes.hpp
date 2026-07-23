//
// Created by nazzazel on 19.07.2026.
//

#pragma once
#include <cstdint>
#include <string_view>

#include "Result.hpp"


namespace engine
{

    constexpr uint64_t Hash(const char* s_ptr) {
        uint32_t hash = 5381;
        //for (const char c : s_ptr) hash = ((hash << 5) + hash) + c;
        while(*s_ptr)
        {
            hash = ((hash << 5) + hash) + *s_ptr++;
        }

        return static_cast<uint64_t>(hash);//For Performance even that is calculated at compile time
    }

    constexpr const char* GetFileName(const char* path)
    {
        const char* fileName = path;
        while(*path)
        {
            if(*path == '/' || *path == '\\')
            {
                fileName = path + 1;
            }
            path++;
        }
        return fileName;
    }

    //err_code is a basic pepresentation of an undelyting message send as a universal "id".
    //The err_code could be both for INFO,ERROR or Warning or any other severity level
    //naming conventin was made due to ussual usecase and avoiding of repetivenes like result_code
    #define ENGINE_RESULT(category, err_code, severity) \
    ::engine::Result::Create(::engine::ResultCategory::category,\
    static_cast<uint16_t>(err_code),\
    ::engine::Severity::severity, \
    (static_cast<uint64_t>(__LINE__) | (::engine::Hash(::engine::GetFileName(__FILE__)) << 16)))


    //$ ARE PLACES where you need to manuallu scecify the Category and class category on which the err_codes will base the judgment on;
    //TEMPLATE :: #define _ERR(err_code,     severity) ENGINE_RESULT($ , ::engine::$::Error::err_code, severity)//

    //#define _RESULT(code, sev) ::engine::memory::MemoryErr(code, sev, __LINE__, __FILE__)
    //FOR First arg("Memory","General") look up result.hpp
    #define GENERAL_RESULT(         err_code, severity) ENGINE_RESULT(General       , ::engine::general::Error::err_code        , severity)//EXAMPLE GENERAL_ERR(None,Info)
    #define SYSTEM_RESULT(          err_code, severity) ENGINE_RESULT(System        , ::engine::system::Error::err_code         , severity)//
    #define PLATFORM_RESULT(        err_code, severity) ENGINE_RESULT(Platform      , ::engine::platform::Error::err_code       , severity)//
    #define CONFIGURATION_RESULT(   err_code, severity) ENGINE_RESULT(Configuration , ::engine::configuration::Error::err_code   , severity)//


    #define MEMORY_RESULT(          err_code, severity) ENGINE_RESULT(Memory        , ::engine::memory::Error::err_code         , severity)//EXAMPLE MEM_ERR(None,1)
    #define GRAPHIC_RESULT(         err_code, severity) ENGINE_RESULT(Graphics      , ::engine::graphics::Error::err_code       , severity)//EXAMPLE MEM_ERR(None,1)

    //#define MEM_ERR(err_code,     severity) ENGINE_RESULT(Memory , ::engine::memory::Error::err_code, severity)//EXAMPLE MEM_ERR(None,1)

    //engine::Severity::Info;

    namespace general
    {
        enum class Error : uint16_t {
            None = 0,
            InvalidParameter,
            NotImplemented,
            Timeout,
            OperationFailed
        };
    }

    namespace system
    {
        enum class Error : uint16_t {
            None = 0,
            SystemAlreadyInitialized,
            DependencyMissing,
            FailedToInitialize,
            SystemManagerNotSet,
            SystemNotFound,
            FileSystemNotSet

        };
    }
    namespace platform
    {
        enum class Error : uint16_t {
            None = 0,
            LibraryLoadFailed,
            GraphicsContextCreationFailed,
            ThreadingError,
            FileSystemAccessDenied,

            //Specific
            GLFWInitiationFail,
            WindowCreationFailed,
            WindowInstanceAlreadyInitialized
        };
    }
    namespace configuration
    {
        enum class Error : uint16_t {
            None = 0,
            FileNotFound,
            ParseError,
            InvalidValue,
            MissingRequiredSection

        };
    }



    namespace memory
    {
        enum class Error : uint16_t {
            None = 0,
            AllocationFailed = 1 ,
            OutOfBounds = 2,
            AlignmentError = 3,
            PoolExhausted = 4
        };
    }

    namespace graphics
    {
        enum class Error : uint16_t {
            None = 0,
            ShaderObjectDoesNotPossessNessesaryShaderStages,
            ShaderObjectAPINotSupportingElementsOfPipeline



        };
    }

    //TODO add the rest of the categories



}

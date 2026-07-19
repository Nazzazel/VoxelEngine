//
// Created by nazzazel on 19.07.2026.
//

#pragma once
#include <cstdint>
#include <string_view>

#include "Core/Engine/Manager/Systems/Result/result.hpp"


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
    ::engine::Result::Create(::engine::ResultCategory::category, err_code, severity, \
    (static_cast<uint64_t>(__LINE__) | (::engine::Hash(::engine::GetFileName(__FILE__)) << 16)))





    //#define MEM_ERR(code, sev) ::engine::memory::MemoryErr(code, sev, __LINE__, __FILE__)
    //FOR First arg("Memory") look up result.hpp
    #define GENERAL_ERR(code, sev)  ENGINE_RESULT(General   , ::engine::general::Error::code  , sev)//EXAMPLE GENERAL_ERR(None,1)
    #define MEM_ERR(code, sev)      ENGINE_RESULT(Memory    , ::engine::memory::Error::code   , sev)//EXAMPLE MEM_ERR(None,1)



    namespace memory
    {
        enum class Error : uint16_t {
            None = 0,
            AllocationFailed,
            OutOfBounds,
            AlignmentError,
            PoolExhausted
        };
    }
    namespace general
    {
        enum class Error : uint16_t {
            None = 0

        };
    }

}

/*
 *
* namespace engine::memory {
    // Local enum for your memory-specific errors
    enum class Error : uint16_t {
        None = 0,
        AllocationFailed,
        OutOfBounds,
        AlignmentError,
        PoolExhausted
    };

    // Helper: Returns a Memory-category result
    inline Result MemoryErr(Error code, uint8_t severity, uint16_t line, const char* file) {
        return Result::Create(static_cast<uint16_t>(code), Category::Memory, severity, line, file);
    }
}
 *
 */
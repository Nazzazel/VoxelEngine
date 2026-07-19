//
// Created by nazzazel on 19.07.2026.
//

#pragma once
#include <cstdint>
#include <string_view>

#include "Core/Engine/Manager/Systems/Result/result.hpp"

namespace engine
{
    class ResultCodeHandler
    {
        std::string_view ErrorMsg(ResultCategory category, uint16_t& code)
        {
            switch (category)
            {
                //case ResultCategory::General: {return }
                //case ResultCategory::System:
            }
        }
    };
   // engine::RC_General::OK
   // engine::ResultCode::General::OK
   // engine::Result::Code::General::OK

}

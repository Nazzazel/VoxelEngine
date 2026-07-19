//
// Created by nazzazel on 19.07.2026.
//

#pragma once
#include <cstdint>
#include <string_view>

namespace engine
{

    enum class RC_General
    {
        OK = 0,
        ERROR
        //other stuff
    };

    class ResultCodesGeneral
    {
        std::string_view GetResultFromCode(std::uint16_t& code)
        {
          //switch (RC_General)
          //{
          //case
          //}
        }
    };
}

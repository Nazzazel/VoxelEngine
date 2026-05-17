#pragma once
#include <string>

namespace engine
{

    class IAssetProvider
    {
    public:
        virtual const std::string& GetAssetRoot() const = 0;
    };

}
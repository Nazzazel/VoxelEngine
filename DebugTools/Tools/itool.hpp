#pragma once

namespace debugtools
{
    class ITool
    {
    public:
        virtual ~ITool() = default;

        virtual void OnUpdate(float dt) {}
        virtual void OnUIRender() = 0;
    };
}
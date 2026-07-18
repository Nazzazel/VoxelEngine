#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace debugtools
{
    struct DebugLine
    {
        glm::vec3 a;
        glm::vec3 b;
    };

    class DebugDraw
    {
    public:
        static void AddLine(const glm::vec3& a, const glm::vec3& b);

        static const std::vector<DebugLine>& GetLines();
        static void Clear();

    private:
        static std::vector<DebugLine> s_Lines;
    };
}
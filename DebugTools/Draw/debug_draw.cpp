#include "debug_draw.hpp"

namespace debugtools
{
    std::vector<DebugLine> DebugDraw::s_Lines;

    void DebugDraw::AddLine(const glm::vec3& a, const glm::vec3& b)
    {
        s_Lines.push_back({ a, b });
    }

    const std::vector<DebugLine>& DebugDraw::GetLines()
    {
        return s_Lines;
    }

    void DebugDraw::Clear()
    {
        s_Lines.clear();
    }
}
//
// Created by nazzazel on 21.08.2026.
//


#pragma once
#include "Systems/Renderer/Renderer/DrawComponents.hpp"


namespace engine
{
    class Model// can load and use mesh and material
    {



        private:
        std::shared_ptr<Mesh> m_Mesh;
        std::shared_ptr<Material> m_Material;

    };
} // Model

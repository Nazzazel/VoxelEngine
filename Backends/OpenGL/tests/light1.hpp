//
// Created by nazzazel on 28.07.2026.
//


#pragma once


namespace backends
{
    class LightTest
    {


    };

    glm::vec3 coral(1.0f, 0.5f, 0.31f);

    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
    glm::vec3 toyColor(1.0f, 0.5f, 0.31f);
    glm::vec3 result = lightColor * toyColor; // = (1.0f, 0.5f, 0.31f);

}
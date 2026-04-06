#pragma once
#include <glm/glm.hpp>

//This is state Representation
struct Body
{
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float mass;

    std::vector<glm::vec3> trail;
};